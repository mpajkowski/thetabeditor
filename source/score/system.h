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

#ifndef SCORE_SYSTEM_H
#define SCORE_SYSTEM_H

#include "alternateending.h"
#include "barline.h"
#include "chordtext.h"
#include "direction.h"
#include "fileversion.h"
#include "playerchange.h"
#include "staff.h"
#include "tempomarker.h"
#include "textitem.h"
#include <boost/range/iterator_range_core.hpp>
#include <vector>

class System
{
public:
  typedef std::vector<Staff>::iterator StaffIterator;
  typedef std::vector<Staff>::const_iterator StaffConstIterator;
  typedef std::vector<Barline>::iterator BarlineIterator;
  typedef std::vector<Barline>::const_iterator BarlineConstIterator;
  typedef std::vector<TempoMarker>::iterator TempoMarkerIterator;
  typedef std::vector<TempoMarker>::const_iterator TempoMarkerConstIterator;
  typedef std::vector<AlternateEnding>::iterator AlternateEndingIterator;
  typedef std::vector<AlternateEnding>::const_iterator AlternateEndingConstIterator;
  typedef std::vector<Direction>::iterator DirectionIterator;
  typedef std::vector<Direction>::const_iterator DirectionConstIterator;
  typedef std::vector<PlayerChange>::iterator PlayerChangeIterator;
  typedef std::vector<PlayerChange>::const_iterator PlayerChangeConstIterator;
  typedef std::vector<ChordText>::iterator ChordTextIterator;
  typedef std::vector<ChordText>::const_iterator ChordTextConstIterator;
  typedef std::vector<TextItem>::iterator TextItemIterator;
  typedef std::vector<TextItem>::const_iterator TextItemConstIterator;

  System();

  bool operator==(System const& other) const;

  template<class Archive>
  void serialize(Archive& ar, const FileVersion version);

  /// Returns the set of staves in the system.
  boost::iterator_range<StaffIterator> getStaves();
  /// Returns the set of staves in the system.
  boost::iterator_range<StaffConstIterator> getStaves() const;

  /// Adds a new staff to the system.
  void insertStaff(Staff const& staff);
  void insertStaff(Staff const& staff, int index);
  /// Removes the specified staff from the system.
  void removeStaff(int index);

  /// Returns the set of barlines in the system.
  boost::iterator_range<BarlineIterator> getBarlines();
  /// Returns the set of barlines in the system.
  boost::iterator_range<BarlineConstIterator> getBarlines() const;

  /// Adds a new barline to the system.
  void insertBarline(Barline const& barline);
  /// Removes the specified barline from the system.
  void removeBarline(Barline const& barline);

  /// Returns the last barline before the given position.
  const Barline* getPreviousBarline(int position) const;
  /// Returns the first barline after the given position.
  const Barline* getNextBarline(int position) const;
  Barline* getNextBarline(int position);

  /// Returns the set of tempo markers in the system.
  boost::iterator_range<TempoMarkerIterator> getTempoMarkers();
  /// Returns the set of tempo markers in the system.
  boost::iterator_range<TempoMarkerConstIterator> getTempoMarkers() const;

  /// Adds a new tempo marker to the system.
  void insertTempoMarker(TempoMarker const& marker);
  /// Removes the specified tempo marker from the system.
  void removeTempoMarker(TempoMarker const& marker);

  /// Returns the set of alternate endings in the system.
  boost::iterator_range<AlternateEndingIterator> getAlternateEndings();
  /// Returns the set of alternate endings in system.
  boost::iterator_range<AlternateEndingConstIterator> getAlternateEndings() const;

  /// Adds a new alternate ending to the system.
  void insertAlternateEnding(AlternateEnding const& ending);
  /// Removes the specified alternate ending from the system.
  void removeAlternateEnding(AlternateEnding const& ending);

  /// Returns the set of musical directions in the system.
  boost::iterator_range<DirectionIterator> getDirections();
  /// Returns the set of musical directions in system.
  boost::iterator_range<DirectionConstIterator> getDirections() const;

  /// Adds a new musical direction to the system.
  void insertDirection(Direction const& direction);
  /// Removes the specified musical direction from the system.
  void removeDirection(Direction const& direction);

  /// Returns the set of player changes in the system.
  boost::iterator_range<PlayerChangeIterator> getPlayerChanges();
  /// Returns the set of player changes in system.
  boost::iterator_range<PlayerChangeConstIterator> getPlayerChanges() const;

  /// Adds a new player change to the system.
  void insertPlayerChange(PlayerChange const& change);
  /// Removes the specified player change from the system.
  void removePlayerChange(PlayerChange const& change);

  /// Returns the set of chord symbols in the system.
  boost::iterator_range<ChordTextIterator> getChords();
  /// Returns the set of chord symbols in system.
  boost::iterator_range<ChordTextConstIterator> getChords() const;

  /// Adds a new chord symbol to the system.
  void insertChord(ChordText const& chord);
  /// Removes the specified chord symbol from the system.
  void removeChord(ChordText const& chord);

  /// Returns the set of text items in the system.
  boost::iterator_range<TextItemIterator> getTextItems();
  /// Returns the set of text items in system.
  boost::iterator_range<TextItemConstIterator> getTextItems() const;

  /// Adds a new text item to the system.
  void insertTextItem(TextItem const& text);
  /// Removes the specified text item from the system.
  void removeTextItem(TextItem const& text);

private:
  std::vector<Staff> myStaves;
  /// List of the barlines in the system. This will always contain at least
  /// two barlines - the start and end bars.
  std::vector<Barline> myBarlines;
  std::vector<TempoMarker> myTempoMarkers;
  std::vector<AlternateEnding> myAlternateEndings;
  std::vector<Direction> myDirections;
  std::vector<PlayerChange> myPlayerChanges;
  std::vector<ChordText> myChords;
  std::vector<TextItem> myTextItems;
};

template<class Archive>
void System::serialize(Archive& ar, const FileVersion version)
{
  ar("staves", myStaves);
  ar("barlines", myBarlines);
  ar("tempo_markers", myTempoMarkers);
  ar("alternate_endings", myAlternateEndings);
  ar("directions", myDirections);
  ar("player_changes", myPlayerChanges);
  ar("chords", myChords);
  if (version >= FileVersion::TEXT_ITEMS)
    ar("text_items", myTextItems);
}

namespace SystemUtils {

/// Shifts everything forward starting from the given position.
void shiftForward(System& system, int position);
/// Shifts everything backward starting from the given position.
void shiftBackward(System& system, int position);
/// Shifts everything by the given offset.
void shift(System& system, int position, int offset);

} // namespace SystemUtils

#endif
