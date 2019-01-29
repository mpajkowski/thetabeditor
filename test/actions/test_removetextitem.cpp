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

#include <catch.hpp>

#include <actions/removetextitem.h>
#include <score/score.h>

TEST_CASE("Actions/RemoveTextItem", "")
{
  Score score;
  System system;
  TextItem text(7, "foo");
  system.insertTextItem(text);
  score.insertSystem(system);

  ScoreLocation location(score, 0, 0, 7);
  RemoveTextItem action(location);

  action.redo();
  REQUIRE(location.getSystem().getTextItems().empty());

  action.undo();
  REQUIRE(location.getSystem().getTextItems().size() == 1);
  REQUIRE(location.getSystem().getTextItems().front() == text);
}
