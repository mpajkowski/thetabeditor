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

#ifndef ACTIONS_REMOVEIRREGULARGROUPING_H
#define ACTIONS_REMOVEIRREGULARGROUPING_H

#include <QUndoCommand>
#include <score/irregulargrouping.h>
#include <score/scorelocation.h>

class RemoveIrregularGrouping : public QUndoCommand
{
public:
  RemoveIrregularGrouping(ScoreLocation const& location, IrregularGrouping const& group);

  virtual void redo() override;
  virtual void undo() override;

private:
  ScoreLocation myLocation;
  const IrregularGrouping myGroup;
};

#endif
