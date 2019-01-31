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

#ifndef SCORE_TEXTITEM_H
#define SCORE_TEXTITEM_H

#include "fileversion.h"
#include <string>

class TextItem
{
public:
  TextItem();
  TextItem(int position, const std::string& contents);

  bool operator==(TextItem const& other) const;

  template<class Archive>
  void serialize(Archive& ar, const FileVersion version);

  int getPosition() const;
  void setPosition(int position);

  const std::string& getContents() const;
  void setContents(const std::string& contents);

private:
  int myPosition;
  std::string myContents;
};

template<class Archive>
void TextItem::serialize(Archive& ar, const FileVersion /*version*/)
{
  ar("position", myPosition);
  ar("contents", myContents);
}

#endif
