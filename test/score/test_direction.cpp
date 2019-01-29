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
#include <score/direction.h>

TEST_CASE("Score/Direction/Symbols", "")
{
    Direction direction;
    REQUIRE(!direction.getSymbols().size());

    DirectionSymbol symbol(DirectionSymbol::Segno);
    direction.insertSymbol(symbol);
    REQUIRE(direction.getSymbols().size() == 1);

    direction.removeSymbol(0);
    REQUIRE(direction.getSymbols().size() == 0);
}

TEST_CASE("Score/Direction/Serialization", "")
{
    Direction direction;
    direction.setPosition(42);
    direction.insertSymbol(DirectionSymbol(DirectionSymbol::DaCapo));

    Serialization::test("direction", direction);
}
