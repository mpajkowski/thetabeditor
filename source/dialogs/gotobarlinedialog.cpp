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

#include "gotobarlinedialog.h"
#include "ui_gotobarlinedialog.h"

#include <score/score.h>

GoToBarlineDialog::GoToBarlineDialog(QWidget* parent, Score const& score)
  : QDialog(parent)
  , ui(new Ui::GoToBarlineDialog)
{
  ui->setupUi(this);

  for (int system_index = 0; system_index < score.getSystems().size(); ++system_index) {
    System const& system = score.getSystems()[system_index];
    // Index all barlines except for the end bar.
    for (int i = 0; i < system.getBarlines().size() - 1; ++i) {
      myLocations.push_back(ScoreLocation(score, system_index, 0, system.getBarlines()[i].getPosition()));
    }
  }

  ui->barlineSpinBox->setValue(1);
  ui->barlineSpinBox->setMinimum(1);
  ui->barlineSpinBox->setMaximum(static_cast<int>(myLocations.size()));

  ui->barlineSpinBox->selectAll();
}

GoToBarlineDialog::~GoToBarlineDialog()
{
  delete ui;
}

/// Returns the location of the selected barline.
ScoreLocation GoToBarlineDialog::getLocation() const
{
  const int index = ui->barlineSpinBox->value();
  return myLocations.at(index - 1);
}
