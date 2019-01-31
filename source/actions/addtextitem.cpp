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

#include "addtextitem.h"

#include <score/system.h>

AddTextItem::AddTextItem(ScoreLocation const& location, TextItem const& text)
  : QUndoCommand(QObject::tr("Add Text"))
  , myLocation(location)
  , myText(text)
{}

void AddTextItem::redo()
{
  myLocation.getSystem().insertTextItem(myText);
}

void AddTextItem::undo()
{
  myLocation.getSystem().removeTextItem(myText);
}
