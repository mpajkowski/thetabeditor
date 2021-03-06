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

#ifndef ACTIONS_EDITFILEINFORMATION_H
#define ACTIONS_EDITFILEINFORMATION_H

#include <QUndoCommand>
#include <score/scoreinfo.h>
#include <score/scorelocation.h>

class EditFileInformation : public QUndoCommand
{
public:
  EditFileInformation(ScoreLocation const& location, ScoreInfo const& scoreInfo);

  virtual void redo() override;
  virtual void undo() override;

private:
  ScoreLocation myLocation;
  const ScoreInfo myScoreInfo;
  const ScoreInfo myOriginalScoreInfo;
};

#endif
