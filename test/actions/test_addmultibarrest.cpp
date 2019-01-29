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

#include <catch.hpp>

#include <actions/addmultibarrest.h>
#include <score/score.h>

TEST_CASE("Actions/AddMultiBarRest", "")
{
  Score score;
  System system;
  Staff staff;
  system.insertStaff(staff);
  score.insertSystem(system);

  ScoreLocation location(score, 0, 0, 6);

  AddMultiBarRest action(location, 3);

  action.redo();
  REQUIRE(location.getPosition());
  REQUIRE(location.getPosition()->hasMultiBarRest());
  REQUIRE(location.getPosition()->getMultiBarRestCount() == 3);

  action.undo();
  REQUIRE(!location.getPosition());
}
