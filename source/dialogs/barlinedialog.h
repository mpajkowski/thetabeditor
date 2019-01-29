/*
 * Copyright (C) 2012 Cameron White
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

#ifndef DIALOGS_BARLINEDIALOG_H
#define DIALOGS_BARLINEDIALOG_H

#include <QDialog>
#include <score/barline.h>

namespace Ui
{
class BarlineDialog;
}

class BarlineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BarlineDialog(QWidget *parent, Barline::BarType type, int repeats,
                           bool isStartBar, bool isEndBar);
    ~BarlineDialog();

    Barline::BarType getBarType() const;
    int getRepeatCount() const;

private slots:
    void onBarlineTypeChanged(int);

private:
    Ui::BarlineDialog *ui;
};

#endif
