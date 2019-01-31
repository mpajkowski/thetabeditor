/*
 * Copyright (C) 2014 Cameron White
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

#ifndef SCORE_UTILS_REPEATINDEXER_H
#define SCORE_UTILS_REPEATINDEXER_H

#include <boost/optional.hpp>
#include <boost/range/iterator_range.hpp>
#include <map>
#include <score/systemlocation.h>
#include <set>
#include <unordered_map>

class AlternateEnding;
class Score;
class System;

class RepeatedSection
{
public:
  RepeatedSection(SystemLocation const& startBar);

  /// Repeated sections are ordered by the position of their start bar.
  bool operator<(RepeatedSection const& other) const;

  /// Adds a new end bar to the repeated section.
  void addRepeatEndBar(SystemLocation const& location, int repeatCount);
  /// Adds a new alternate ending to the repeated section.
  void addAlternateEnding(System const& system, int system_index, AlternateEnding const& ending);

  /// Returns the location of the start bar.
  SystemLocation const& getStartBarLocation() const;
  /// Returns the location of the final end bar in the repeated section.
  SystemLocation const& getLastEndBarLocation() const;

  /// Returns the number of alternate endings in the section.
  int getAlternateEndingCount() const;
  /// Returns the total number of times that the section is repeated.
  int getTotalRepeatCount() const;

  /// Returns a list of repeat end bars in the section, along with
  /// their repeat counts.
  const std::map<SystemLocation, int>& getRepeatEndBars() const { return myRepeatEndBars; }

  /// Attempt to find the location to jump to for the nth alternate ending.
  boost::optional<SystemLocation> findAlternateEnding(int number) const;

  /// Reset the repeat counters.
  void reset();
  int getCurrentRepeatNumber() const { return myActiveRepeat; }
  SystemLocation performRepeat(SystemLocation const& loc);

private:
  SystemLocation myStartBarLocation;
  std::map<SystemLocation, int> myRepeatEndBars;
  std::unordered_map<int, SystemLocation> myAlternateEndings;
  int myActiveRepeat;
};

class RepeatIndexer
{
public:
  typedef std::set<RepeatedSection>::const_iterator RepeatedSectionIterator;

  RepeatIndexer(Score const& score);

  /// Given a location in the score, find the repeat that
  /// surrounds it (if possible).
  const RepeatedSection* findRepeat(SystemLocation const& loc) const;
  RepeatedSection* findRepeat(SystemLocation const& loc);

  /// Returns a list of the repeated sections in the score.
  boost::iterator_range<RepeatedSectionIterator> getRepeats() const;

private:
  std::set<RepeatedSection> myRepeats;
};

#endif
