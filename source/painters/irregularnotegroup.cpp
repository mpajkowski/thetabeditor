/*
 * Copyright (C) 2011 Cameron White
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

#include "irregularnotegroup.h"

#include <QBrush>
#include <QFontMetricsF>
#include <QGraphicsItem>
#include <QPen>

#include <algorithm>
#include <painters/musicfont.h>
#include <powertabdocument/position.h>

IrregularNoteGroup::IrregularNoteGroup(const std::vector<NoteStem>& noteStems)
  : noteStems(noteStems)
{}

void IrregularNoteGroup::draw(QGraphicsItem* parent)
{
  const NoteStem::StemDirection direction = NoteStem::findDirectionForGroup(noteStems);

  double y1 = 0, y2 = 0;

  if (direction == NoteStem::StemUp) {
    NoteStem highestStem = NoteStem::findHighestStem(noteStems);

    y1 = y2 = highestStem.stemTop - GROUP_SPACING;
    y2 -= GROUP_HEIGHT;
  } else {
    NoteStem lowestStem = NoteStem::findLowestStem(noteStems);

    y1 = y2 = lowestStem.stemBottom + GROUP_SPACING;
    y2 += GROUP_HEIGHT;
  }

  const double leftX = noteStems.front().xPosition;
  const double rightX = noteStems.back().xPosition;

  // draw the value of the irregular grouping
  const QString text = QString::fromStdString(noteStems.front().position->GetIrregularGroupingText());

  QFont font = MusicFont().getFont();
  font.setItalic(true);
  font.setPixelSize(18);

  QFontMetricsF fm(font);
  const double textWidth = fm.width(text);
  const double centreX = leftX + (rightX - (leftX + textWidth)) / 2.0;

  QGraphicsSimpleTextItem* textItem = new QGraphicsSimpleTextItem(text);
  textItem->setPos(centreX, y2 - font.pixelSize());
  textItem->setFont(font);
  textItem->setParentItem(parent);

  const double lineWidth = std::max(0.0, 0.5 * (rightX - leftX - textWidth - 10));

  // draw the two horizontal line segments across the group, and the two
  // vertical lines on either end
  QGraphicsLineItem* horizLine1 = new QGraphicsLineItem;
  horizLine1->setLine(leftX, y2, leftX + lineWidth, y2);
  horizLine1->setParentItem(parent);

  QGraphicsLineItem* horizLine2 = new QGraphicsLineItem;
  horizLine2->setLine(rightX - lineWidth, y2, rightX, y2);
  horizLine2->setParentItem(parent);

  QGraphicsLineItem* vertLine1 = new QGraphicsLineItem;
  vertLine1->setLine(leftX, y1, leftX, y2);
  vertLine1->setParentItem(parent);

  QGraphicsLineItem* vertLine2 = new QGraphicsLineItem;
  vertLine2->setLine(rightX, y1, rightX, y2);
  vertLine2->setParentItem(parent);
}
