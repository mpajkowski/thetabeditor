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

#include "barline.h"

const int Barline::MIN_REPEAT_COUNT = 2;

Barline::Barline()
  : myPosition(0)
  , myBarType(SingleBar)
  , myRepeatCount(0)
{}

Barline::Barline(int position, BarType type, int repeatCount)
  : myPosition(position)
  , myBarType(type)
  , myRepeatCount(repeatCount)
{}

bool Barline::operator==(Barline const& other) const
{
  return myPosition == other.myPosition && myBarType == other.myBarType &&
         myRepeatCount == other.myRepeatCount && myKeySignature == other.myKeySignature &&
         myTimeSignature == other.myTimeSignature && myRehearsalSign == other.myRehearsalSign;
}

int Barline::getPosition() const
{
  return myPosition;
}

void Barline::setPosition(int position)
{
  myPosition = position;
}

Barline::BarType Barline::getBarType() const
{
  return myBarType;
}

void Barline::setBarType(BarType type)
{
  myBarType = type;
}

int Barline::getRepeatCount() const
{
  return myRepeatCount;
}

void Barline::setRepeatCount(int count)
{
  myRepeatCount = count;
}

KeySignature const& Barline::getKeySignature() const
{
  return myKeySignature;
}

void Barline::setKeySignature(KeySignature const& key)
{
  myKeySignature = key;
}

TimeSignature const& Barline::getTimeSignature() const
{
  return myTimeSignature;
}

void Barline::setTimeSignature(TimeSignature const& time)
{
  myTimeSignature = time;
}

bool Barline::hasRehearsalSign() const
{
  return myRehearsalSign.is_initialized();
}

RehearsalSign const& Barline::getRehearsalSign() const
{
  return *myRehearsalSign;
}

RehearsalSign& Barline::getRehearsalSign()
{
  return *myRehearsalSign;
}

void Barline::setRehearsalSign(RehearsalSign const& sign)
{
  myRehearsalSign = sign;
}

void Barline::clearRehearsalSign()
{
  myRehearsalSign.reset();
}
