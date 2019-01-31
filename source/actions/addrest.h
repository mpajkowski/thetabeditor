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

#ifndef ACTIONS_ADDREST_H
#define ACTIONS_ADDREST_H

#include <QUndoCommand>
#include <boost/optional.hpp>
#include <score/position.h>
#include <score/scorelocation.h>

class AddRest : public QUndoCommand
{
public:
  AddRest(ScoreLocation const& location, Position::DurationType duration);

  virtual void redo() override;
  virtual void undo() override;

private:
  ScoreLocation myLocation;
  boost::optional<Position> myOriginalPosition;
  const Position::DurationType myDuration;
};

#endif
