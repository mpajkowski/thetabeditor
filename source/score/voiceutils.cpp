/*
 * Copyright (C) 2013 Cameron White
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "voiceutils.h"

#include "score.h"
#include "scorelocation.h"
#include "utils.h"
#include <boost/range/adaptor/reversed.hpp>

namespace VoiceUtils {

const Voice* getAdjacentVoice(ScoreLocation const& location, int offset)
{
  const int systemIndex = location.getSystemIndex() + offset;
  const int staffIndex = location.getStaffIndex();
  const int voiceIndex = location.getVoiceIndex();

  if (systemIndex >= 0 && systemIndex < location.getScore().getSystems().size()) {
    System const& nextSystem = location.getScore().getSystems()[systemIndex];
    if (staffIndex < nextSystem.getStaves().size()) {
      Staff const& nextStaff = nextSystem.getStaves()[staffIndex];
      return &nextStaff.getVoices()[voiceIndex];
    }
  }

  return nullptr;
}

const Position* getNextPosition(Voice const& voice, int position)
{
  for (Position const& pos : voice.getPositions()) {
    if (pos.getPosition() > position)
      return &pos;
  }

  return nullptr;
}

const Position* getPreviousPosition(Voice const& voice, int position)
{
  for (Position const& pos : boost::adaptors::reverse(voice.getPositions())) {
    if (pos.getPosition() < position)
      return &pos;
  }

  return nullptr;
}

const Note* getNextNote(Voice const& voice, int position, int string, const Voice* nextVoice)
{
  const Position* nextPos = getNextPosition(voice, position);
  if (!nextPos && nextVoice)
    nextPos = getNextPosition(*nextVoice, -1);
  return nextPos ? Utils::findByString(*nextPos, string) : nullptr;
}

const Note* getPreviousNote(Voice const& voice, int position, int string, const Voice* prevVoice)
{
  const Position* prevPos = getPreviousPosition(voice, position);
  if (!prevPos && prevVoice)
    prevPos = getPreviousPosition(*prevVoice, std::numeric_limits<int>::max());
  return prevPos ? Utils::findByString(*prevPos, string) : nullptr;
}

bool canTieNote(Voice const& voice, int position, Note const& note)
{
  const Note* prevNote = getPreviousNote(voice, position, note.getString());
  return prevNote && prevNote->getFretNumber() == note.getFretNumber();
}

bool canHammerOnOrPullOff(Voice const& voice, int position, Note const& note)
{
  const Note* nextNote = getNextNote(voice, position, note.getString());
  return nextNote && nextNote->getFretNumber() != note.getFretNumber();
}

bool hasNoteWithHammerOn(Voice const& voice, Position const& pos)
{
  for (Note const& note : pos.getNotes()) {
    if (note.hasProperty(Note::HammerOnOrPullOff)) {
      const Note* nextNote = getNextNote(voice, pos.getPosition(), note.getString());
      return nextNote && nextNote->getFretNumber() > note.getFretNumber();
    }
  }

  return false;
}

std::vector<const IrregularGrouping*> getIrregularGroupsInRange(Voice const& voice, int left, int right)
{
  std::vector<const IrregularGrouping*> groups;

  for (IrregularGrouping const& group : voice.getIrregularGroupings()) {
    const int groupLeft = group.getPosition();
    const int groupRight =
      voice
        .getPositions()[ScoreUtils::findIndexByPosition(voice.getPositions(), groupLeft) + group.getLength() -
                        1]
        .getPosition();

    if (groupLeft <= right && groupRight >= left)
      groups.push_back(&group);
  }

  return groups;
}

boost::rational<int> getDurationTime(Voice const& voice, Position const& pos)
{
  if (pos.hasProperty(Position::Acciaccatura))
    return 0;

  boost::rational<int> duration(4, static_cast<int>(pos.getDurationType()));

  // Adjust for dotted notes.
  if (pos.hasProperty(Position::Dotted))
    duration += (duration / 2);
  if (pos.hasProperty(Position::DoubleDotted))
    duration += duration * boost::rational<int>(3, 4);

  // Adjust for irregular groups.
  for (const IrregularGrouping* group :
       getIrregularGroupsInRange(voice, pos.getPosition(), pos.getPosition())) {
    // As an example, with triplets we have 3 notes played in the time of 2,
    // so each note is 2/3 of its normal duration.
    duration *= boost::rational<int>(group->getNotesPlayedOver(), group->getNotesPlayed());
  }

  return duration;
}
} // namespace VoiceUtils
