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

#ifndef ACTIONS_POLISHSYSTEM_H
#define ACTIONS_POLISHSYSTEM_H

#include <QUndoCommand>

#include <boost/optional/optional.hpp>
#include <score/scorelocation.h>
#include <score/system.h>

class PolishSystem : public QUndoCommand
{
public:
  PolishSystem(const ScoreLocation& location);

  virtual void redo() override;
  virtual void undo() override;

private:
  ScoreLocation myLocation;
  boost::optional<System> myOriginalSystem;
};

#endif
