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

#ifndef SCORE_CHORDTEXT_H
#define SCORE_CHORDTEXT_H

#include "chordname.h"
#include "fileversion.h"

class ChordText
{
public:
  ChordText();
  ChordText(int position, ChordName const& name);

  bool operator==(ChordText const& other) const;

  template<class Archive>
  void serialize(Archive& ar, const FileVersion version);

  int getPosition() const;
  void setPosition(int position);

  ChordName const& getChordName() const;
  void setChordName(ChordName const& name);

private:
  int myPosition;
  ChordName myChordName;
};

template<class Archive>
void ChordText::serialize(Archive& ar, const FileVersion /*version*/)
{
  ar("position", myPosition);
  ar("chord_name", myChordName);
}

#endif
