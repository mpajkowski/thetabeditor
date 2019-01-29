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

#ifndef WIDGETS_CLICKABLELABEL_H
#define WIDGETS_CLICKABLELABEL_H

#include <QLabel>

/// A subclass of QLabel that emits signals when it is clicked.
class ClickableLabel : public QLabel
{
  Q_OBJECT

public:
  ClickableLabel(QWidget* parent);

signals:
  void clicked();
  void doubleClicked();

protected:
  virtual void enterEvent(QEvent*) override;
  virtual void leaveEvent(QEvent*) override;
  virtual void mouseReleaseEvent(QMouseEvent*) override;
  virtual void mouseDoubleClickEvent(QMouseEvent*) override;
};

#endif
