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

#include "barlinepainter.h"

#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <app/pubsub/clickpubsub.h>
#include <score/barline.h>

const double BarlinePainter::DOUBLE_BAR_WIDTH = 4;

BarlinePainter::BarlinePainter(const LayoutConstPtr& layout,
                               const Barline& barline,
                               const ScoreLocation& location,
                               const std::shared_ptr<ClickPubSub>& pubsub)
  : myLayout(layout)
  , myBarline(barline)
  , myLocation(location)
  , myPubSub(pubsub)
  , myX(0)
  , myWidth(0)
{
  setAcceptHoverEvents(true);
  setToolTip(QObject::tr("Click to edit barline."));

  switch (barline.getBarType()) {
    case Barline::SingleBar:
      myWidth = 1;
      break;
    case Barline::RepeatStart:
      myWidth = -DOUBLE_BAR_WIDTH;
      break;
    default:
      myWidth = DOUBLE_BAR_WIDTH;
      break;
  }

  myX = LayoutInfo::centerItem(myX, myX + layout->getPositionSpacing(), myWidth);

  // Adjust alignment for repeat barlines.
  if (barline.getBarType() == Barline::RepeatStart || barline.getBarType() == Barline::RepeatEnd) {
    myX += myWidth;
  }
  // Adjust for double barlines.
  else if (barline.getBarType() == Barline::DoubleBar || barline.getBarType() == Barline::DoubleBarFine) {
    myX -= 2;
  }

  myBounds = QRectF(0, 0, layout->getPositionSpacing(), layout->getStaffHeight());
}

void BarlinePainter::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  // Only handle clicks that occur in the standard notation staff.
  if (!isInStdNotationStaff(event->pos().y()))
    event->ignore();
}

void BarlinePainter::mouseReleaseEvent(QGraphicsSceneMouseEvent*)
{
  myPubSub->publish(ClickType::Barline, myLocation);
}

void BarlinePainter::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
{
  if (isInStdNotationStaff(event->pos().y()))
    setCursor(Qt::PointingHandCursor);
  else
    unsetCursor();
}

void BarlinePainter::hoverLeaveEvent(QGraphicsSceneHoverEvent*)
{
  unsetCursor();
}

bool BarlinePainter::isInStdNotationStaff(double y)
{
  return (y <= myLayout->getBottomStdNotationLine()) && (y >= myLayout->getTopStdNotationLine());
}

void BarlinePainter::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
  painter->setPen(QPen(Qt::black, 0.75));
  painter->setBrush(Qt::black);

  const Barline::BarType barType = myBarline.getBarType();

  if (barType == Barline::FreeTimeBar)
    painter->setPen(Qt::DashLine);

  // Print the repeat count for repeat end bars.
  if (barType == Barline::RepeatEnd && myBarline.getRepeatCount() > Barline::MIN_REPEAT_COUNT) {
    QFont repeatFont("Liberation Sans");
    repeatFont.setPixelSize(8);
    painter->setFont(repeatFont);

    const QString message = QString::number(myBarline.getRepeatCount()) + "x";
    painter->drawText(3, myLayout->getTopStdNotationLine() - 3, message);
  }

  // Draw a single bar line.
  drawVerticalLines(painter, myX);

  // Draw a second line depending on the bar type.
  if (barType == Barline::DoubleBar || barType == Barline::DoubleBarFine || barType == Barline::RepeatEnd ||
      barType == Barline::RepeatStart) {
    // Make the line thicker for certain bar types.
    if (barType != Barline::DoubleBar)
      painter->setPen(QPen(Qt::black, 2));

    // Draw the second barline with an offset of the specified width.
    drawVerticalLines(painter, myX + myWidth);
  }

  // Draw the dots for repeats.
  if (barType == Barline::RepeatEnd || barType == Barline::RepeatStart) {
    painter->setPen(QPen(Qt::black, 0.75));
    const double radius = 1.0;
    // x-coordinate for the location of the dots.
    const double dotLocation = myX - 1.5 * myWidth;
    double height = 0;
    // Middle line for std. notation staff.
    const double centreStaffLine = 3;

    // Draw dots for standard notation staff, on either side of the centre.
    height =
      (myLayout->getStdNotationLine(centreStaffLine) + myLayout->getStdNotationLine(centreStaffLine + 1)) /
      2.0;
    painter->drawRect(QRectF(dotLocation, height, radius, radius));

    height =
      (myLayout->getStdNotationLine(centreStaffLine) + myLayout->getStdNotationLine(centreStaffLine - 1)) /
      2.0;
    painter->drawRect(QRectF(dotLocation, height, radius, radius));

    // Offset the repeat dots 2 lines from the edge of the tab staff if
    // we have a large number of strings, otherwise, only offset by 1 line.
    const int offsetFromEdge = (myLayout->getStringCount() > 4) ? 2 : 1;

    // Draw dots for tab staff.
    height = (myLayout->getTabLine(offsetFromEdge) + myLayout->getTabLine(offsetFromEdge + 1)) / 2.0;
    painter->drawRect(QRectF(dotLocation, height, radius, radius));

    height = (myLayout->getTabLine(myLayout->getStringCount() - offsetFromEdge) +
              myLayout->getTabLine(myLayout->getStringCount() - offsetFromEdge + 1)) /
             2.0;
    painter->drawRect(QRectF(dotLocation, height, radius, radius));
  }
}

void BarlinePainter::drawVerticalLines(QPainter* painter, double x)
{
  QVector<QLine> lines(2);

  // Draw a single bar line.
  lines[0] = QLine(x, myLayout->getTopStdNotationLine() + 1, x, myLayout->getBottomStdNotationLine());
  lines[1] = QLine(x, myLayout->getTopTabLine() + 1, x, myLayout->getBottomTabLine());

  painter->drawLines(lines);
}
