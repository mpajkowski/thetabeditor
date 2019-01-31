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

#ifndef PAINTERS_CLICKABLEGROUP_H
#define PAINTERS_CLICKABLEGROUP_H

#include <QGraphicsItemGroup>
#include <functional>

class ClickableGroup : public QGraphicsItemGroup
{
public:
  typedef std::function<void()> Callback;
  ClickableGroup(QString const& tooltip, Callback const& callback);

  virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
  virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
  virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

private:
  Callback myCallback;
};

#endif
