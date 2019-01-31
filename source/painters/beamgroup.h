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

#ifndef PAINTERS_BEAMGROUP_H
#define PAINTERS_BEAMGROUP_H

#include <painters/notestem.h>
#include <vector>

struct LayoutInfo;
class QFont;
class QFontMetricsF;
class QGraphicsItem;
class QPainterPath;

class BeamGroup
{
public:
  BeamGroup(NoteStem::StemType direction, const std::vector<size_t>& stems);

  /// Draws the stems for each note in the group.
  void drawStems(QGraphicsItem* parent,
                 const std::vector<NoteStem>& stems,
                 QFont const& musicFont,
                 QFontMetricsF const& fm,
                 LayoutInfo const& layout) const;

private:
  /// Draws the extra beams required for sixteenth notes, etc.
  void drawExtraBeams(QPainterPath& path,
                      std::vector<NoteStem>::const_iterator begin,
                      std::vector<NoteStem>::const_iterator end) const;

  /// Creates and positions a staccato symbol.
  static QGraphicsItem* createStaccato(NoteStem const& stem, QFont const& musicFont, QFontMetricsF const& fm);

  /// Creates and positions a fermata symbol.
  static QGraphicsItem* createFermata(NoteStem const& noteStem,
                                      QFont const& musicFont,
                                      LayoutInfo const& layout);

  /// Creates and positions an accent symbol.
  static QGraphicsItem* createAccent(NoteStem const& stem, QFont const& musicFont, LayoutInfo const& layout);

  static QGraphicsItem* createNoteFlag(NoteStem const& stem, QFont const& musicFont, QFontMetricsF const& fm);

  NoteStem::StemType myStemDirection;
  std::vector<size_t> myStems;
};

#endif
