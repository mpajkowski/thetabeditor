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

#ifndef ACTIONS_EDITKEYSIGNATURE_H
#define ACTIONS_EDITKEYSIGNATURE_H

#include <QUndoCommand>
#include <score/keysignature.h>
#include <score/scorelocation.h>

class EditKeySignature : public QUndoCommand
{
public:
  EditKeySignature(ScoreLocation const& location, KeySignature const& newKey);

  virtual void redo() override;
  virtual void undo() override;

private:
  /// Updates all of the key signatures following myLocation until a different
  /// key signature is reached.
  void updateFollowingKeySignatures(KeySignature const& oldKey, KeySignature const& newKey);

  ScoreLocation myLocation;
  const KeySignature myNewKey;
  const KeySignature myOldKey;
};

#endif
