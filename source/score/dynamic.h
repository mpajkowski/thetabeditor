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

#ifndef SCORE_DYNAMIC_H
#define SCORE_DYNAMIC_H

#include "fileversion.h"

class Dynamic
{
public:
  enum VolumeLevel
  {
    Off = 0,
    ppp = 13,
    pp = 26,
    p = 39,
    mp = 52,
    mf = 65,
    f = 78,
    ff = 91,
    fff = 104
  };

  Dynamic();
  Dynamic(int position, VolumeLevel level);

  bool operator==(Dynamic const& other) const;

  template<class Archive>
  void serialize(Archive& ar, const FileVersion version);

  /// Returns the position within the staff where the dynamic is anchored.
  int getPosition() const;
  /// Sets the position within the staff where the dynamic is anchored.
  void setPosition(int position);

  /// Return the new volume that will be set.
  VolumeLevel getVolume() const;
  /// Set the new volume.
  void setVolume(VolumeLevel level);

private:
  int myPosition;
  VolumeLevel myVolume;
};

template<class Archive>
void Dynamic::serialize(Archive& ar, const FileVersion /*version*/)
{
  ar("position", myPosition);
  ar("volume", myVolume);
}

#endif
