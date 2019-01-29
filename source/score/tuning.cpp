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

#include "tuning.h"

#include "generalmidi.h"
#include <sstream>
#include <stdexcept>

const int8_t Tuning::MIN_MUSIC_NOTATION_OFFSET = -12;
const int8_t Tuning::MAX_MUSIC_NOTATION_OFFSET = 12;
const int Tuning::MIN_STRING_COUNT = 3;
const int Tuning::MAX_STRING_COUNT = 8;
const int Tuning::MIN_CAPO = 0;
const int Tuning::MAX_CAPO = 12;

Tuning::Tuning()
  : myName("Standard")
  , myMusicNotationOffset(0)
  , myUsesSharps(true)
  , myCapo(0)
{
  // Initialize to standard tuning.
  myNotes.push_back(Midi::MIDI_NOTE_E4);
  myNotes.push_back(Midi::MIDI_NOTE_B3);
  myNotes.push_back(Midi::MIDI_NOTE_G3);
  myNotes.push_back(Midi::MIDI_NOTE_D3);
  myNotes.push_back(Midi::MIDI_NOTE_A2);
  myNotes.push_back(Midi::MIDI_NOTE_E2);
}

bool Tuning::operator==(const Tuning& other) const
{
  return myName == other.myName && isSameTuning(other);
}

bool Tuning::isSameTuning(const Tuning& other) const
{
  return myNotes == other.myNotes && myMusicNotationOffset == other.myMusicNotationOffset &&
         myUsesSharps == other.myUsesSharps && myCapo == other.myCapo;
}

const std::string& Tuning::getName() const
{
  return myName;
}

void Tuning::setName(const std::string& name)
{
  myName = name;
}

bool Tuning::isValidStringCount(int count)
{
  return count >= MIN_STRING_COUNT && count <= MAX_STRING_COUNT;
}

int Tuning::getStringCount() const
{
  return static_cast<int>(myNotes.size());
}

uint8_t Tuning::getNote(int string, bool includeMusicNotationOffset) const
{
  if (string >= getStringCount())
    throw std::out_of_range("Invalid string number");

  uint8_t note = myNotes[string];
  if (includeMusicNotationOffset)
    note = Midi::offsetMidiNote(note, myMusicNotationOffset);

  return note;
}

std::vector<uint8_t> Tuning::getNotes() const
{
  return myNotes;
}

void Tuning::setNote(int string, uint8_t note)
{
  if (string >= getStringCount())
    throw std::out_of_range("Invalid string number");
  if (!Midi::isValidMidiNote(note))
    throw std::out_of_range("Invalid MIDI note");

  myNotes[string] = note;
}

void Tuning::setNotes(const std::vector<uint8_t>& notes)
{
  if (!isValidStringCount(static_cast<int>(notes.size())))
    throw std::out_of_range("Invalid string count");

  for (auto& note : notes) {
    if (!Midi::isValidMidiNote(note))
      throw std::out_of_range("Invalid MIDI note");
  }

  myNotes = notes;
}

int8_t Tuning::getMusicNotationOffset() const
{
  return myMusicNotationOffset;
}

void Tuning::setMusicNotationOffset(int8_t offset)
{
  if (offset < MIN_MUSIC_NOTATION_OFFSET || offset > MAX_MUSIC_NOTATION_OFFSET) {
    throw std::out_of_range("Invalid music notation offset");
  }

  myMusicNotationOffset = offset;
}

bool Tuning::usesSharps() const
{
  return myUsesSharps;
}

void Tuning::setSharps(bool set)
{
  myUsesSharps = set;
}

int Tuning::getCapo() const
{
  return myCapo;
}

void Tuning::setCapo(int capo)
{
  if (capo > MAX_CAPO)
    throw std::out_of_range("Invalid capo");

  myCapo = capo;
}

std::ostream& operator<<(std::ostream& os, const Tuning& t)
{
  // Go from lowest to highest string
  for (int i = t.getStringCount(); i > 0; i--) {
    if (i != t.getStringCount())
      os << " ";

    os << Midi::getMidiNoteTextSimple(t.getNote(i - 1, false), t.usesSharps());
  }

  return os;
}
