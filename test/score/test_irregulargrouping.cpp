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

#include "test_serialization.h"
#include <score/irregulargrouping.h>

TEST_CASE("Score/IrregularGrouping/Serialization", "")
{
  IrregularGrouping group(42, 5, 3, 2);
  Serialization::test("irregular_grouping", group);
}

TEST_CASE("Score/IrregularGrouping/ToString")
{
  IrregularGrouping group(0, 1, 3, 2);

  REQUIRE(boost::lexical_cast<std::string>(group) == "3");

  group.setNotesPlayed(7);
  group.setNotesPlayedOver(5);
  REQUIRE(boost::lexical_cast<std::string>(group) == "7:5");
}
