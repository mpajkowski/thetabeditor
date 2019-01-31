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

#ifndef SCORE_DIRECTION_H
#define SCORE_DIRECTION_H

#include "fileversion.h"
#include <boost/range/iterator_range_core.hpp>
#include <vector>

class DirectionSymbol
{
public:
  enum SymbolType
  {
    Coda,
    DoubleCoda,
    Segno,
    SegnoSegno,
    Fine,
    DaCapo,
    DalSegno,
    DalSegnoSegno,
    ToCoda,
    ToDoubleCoda,
    DaCapoAlCoda,
    DaCapoAlDoubleCoda,
    DalSegnoAlCoda,
    DalSegnoAlDoubleCoda,
    DalSegnoSegnoAlCoda,
    DalSegnoSegnoAlDoubleCoda,
    DaCapoAlFine,
    DalSegnoAlFine,
    DalSegnoSegnoAlFine,
    NumSymbolTypes
  };

  enum ActiveSymbolType
  {
    ActiveNone,
    ActiveDaCapo,
    ActiveDalSegno,
    ActiveDalSegnoSegno
  };

  DirectionSymbol();
  DirectionSymbol(SymbolType type, ActiveSymbolType activeType = ActiveNone, int repeatNumber = 0);

  bool operator==(DirectionSymbol const& other) const;

  template<class Archive>
  void serialize(Archive& ar, const FileVersion version);

  /// Return the type of this symbol.
  SymbolType getSymbolType() const;
  /// Return the symbol type that this symbol is active for.
  ActiveSymbolType getActiveSymbolType() const;
  /// Return the repeat number that this symbol is active on.
  int getRepeatNumber() const;

private:
  SymbolType mySymbolType;
  ActiveSymbolType myActiveSymbolType;
  int myRepeatNumber;
};

class Direction
{
public:
  typedef std::vector<DirectionSymbol>::iterator SymbolIterator;
  typedef std::vector<DirectionSymbol>::const_iterator SymbolConstIterator;

  Direction();
  explicit Direction(int position);

  bool operator==(Direction const& other) const;

  template<class Archive>
  void serialize(Archive& ar, const FileVersion version);

  /// Returns the position within the system where the direction is anchored.
  int getPosition() const;
  /// Sets the position within the system where the direction is anchored.
  void setPosition(int position);

  /// Returns the set of symbols in the direction.
  boost::iterator_range<SymbolIterator> getSymbols();
  /// Returns the set of symbols in the direction.
  boost::iterator_range<SymbolConstIterator> getSymbols() const;

  /// Adds a new symbol to the direction.
  void insertSymbol(DirectionSymbol const& symbol);
  /// Removes a symbol from the direction.
  void removeSymbol(int index);

private:
  int myPosition;
  std::vector<DirectionSymbol> mySymbols;
};

template<class Archive>
void DirectionSymbol::serialize(Archive& ar, const FileVersion /*version*/)
{
  ar("symbol_type", mySymbolType);
  ar("active_symbol", myActiveSymbolType);
  ar("repeat_number", myRepeatNumber);
}

template<class Archive>
void Direction::serialize(Archive& ar, const FileVersion /*version*/)
{
  ar("position", myPosition);
  ar("symbols", mySymbols);
}

#endif
