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

#include "playerchange.h"

#include <algorithm>

PlayerChange::PlayerChange()
  : myPosition(0)
{}

PlayerChange::PlayerChange(int position)
  : myPosition(position)
{}

bool PlayerChange::operator==(PlayerChange const& other) const
{
  return myPosition == other.myPosition && myActivePlayers == other.myActivePlayers;
}

int PlayerChange::getPosition() const
{
  return myPosition;
}

void PlayerChange::setPosition(int position)
{
  myPosition = position;
}

std::vector<int> PlayerChange::getActivePlayers(int staff) const
{
  if (myActivePlayers.find(staff) != myActivePlayers.end())
    return myActivePlayers.find(staff)->second;
  else
    return {};
}

void PlayerChange::insertActivePlayer(int staff, int player)
{
  myActivePlayers[staff].push_back(player);
}

void PlayerChange::removeActivePlayer(int staff, int player)
{
  auto& playerList = myActivePlayers[staff];
  playerList.erase(std::remove(playerList.begin(), playerList.end(), player), playerList.end());
}
