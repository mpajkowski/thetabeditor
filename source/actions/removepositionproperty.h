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

#ifndef ACTIONS_REMOVEPOSITIONPROPERTY_H
#define ACTIONS_REMOVEPOSITIONPROPERTY_H

#include <QUndoCommand>
#include <score/position.h>
#include <score/scorelocation.h>

/// Removes a simple position property for each of the selected notes.
class RemovePositionProperty : public QUndoCommand
{
public:
  RemovePositionProperty(ScoreLocation const& location,
                         Position::SimpleProperty property,
                         QString const& positionDescription);

  virtual void redo() override;
  virtual void undo() override;

private:
  ScoreLocation myLocation;
  const Position::SimpleProperty myProperty;
};

#endif
