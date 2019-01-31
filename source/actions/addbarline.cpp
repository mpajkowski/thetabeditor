/*
 * Copyright (C) 2011 Cameron White
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

#include "addbarline.h"

#include <score/system.h>

AddBarline::AddBarline(ScoreLocation const& location, Barline const& barline)
  : QUndoCommand(QObject::tr("Insert Barline"))
  , myLocation(location)
  , myBarline(barline)
{
  // Use the same time signature and key signature from the previous bar.
  const Barline* prev = myLocation.getSystem().getPreviousBarline(barline.getPosition());
  Q_ASSERT(prev);

  KeySignature key = prev->getKeySignature();
  key.setVisible(false);
  myBarline.setKeySignature(key);

  TimeSignature time = prev->getTimeSignature();
  time.setVisible(false);
  myBarline.setTimeSignature(time);
}

void AddBarline::redo()
{
  myLocation.getSystem().insertBarline(myBarline);
}

void AddBarline::undo()
{
  myLocation.getSystem().removeBarline(myBarline);
}
