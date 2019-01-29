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

#ifndef ACTIONS_ADDPLAYER_H
#define ACTIONS_ADDPLAYER_H

#include <QUndoCommand>
#include <score/player.h>

class Score;

class AddPlayer : public QUndoCommand
{
public:
  AddPlayer(Score& score, const Player& player);

  virtual void redo() override;
  virtual void undo() override;

private:
  Score& myScore;
  const Player myPlayer;
  const int myPlayerIndex;
};

#endif
