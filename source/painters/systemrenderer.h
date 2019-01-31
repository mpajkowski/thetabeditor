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

#ifndef PAINTERS_SYSTEMRENDERER_H
#define PAINTERS_SYSTEMRENDERER_H

#include <QFontMetricsF>
#include <map>
#include <painters/layoutinfo.h>
#include <painters/musicfont.h>
#include <score/staff.h>

class QGraphicsItem;
class QGraphicsItemGroup;
class QGraphicsRectItem;
class Score;
class ScoreArea;
class ScoreLocation;
class System;
class ViewOptions;

class SystemRenderer
{
public:
  SystemRenderer(const ScoreArea* score_area, Score const& score, ViewOptions const& view_options);

  QGraphicsItem* operator()(System const& system, int systemIndex);

private:
  /// Draws the tab clef.
  void drawTabClef(double x, LayoutInfo const& layout, ScoreLocation const& location);

  /// Draws barlines, along with time signatures, rehearsal signs, etc.
  void drawBarlines(System const& system, int systemIndex, LayoutConstPtr const& layout, bool isFirstStaff);

  /// Draws the tab notes for all notes in the staff.
  void drawTabNotes(Staff const& staff, LayoutConstPtr const& layout);

  /// Centers an item, by using its width to calculate the necessary
  /// offset from xmin.
  static void centerHorizontally(QGraphicsItem& item, double xmin, double xmax);

  /// Vertically centers a system symbol between y and y +
  /// LayoutInfo::SYSTEM_SYMBOL_SPACING.
  static void centerSymbolVertically(QGraphicsItem& item, double y);

  /// Draws a arpeggio up/down at the given position.
  void drawArpeggio(Position const& position, double x, LayoutInfo const& layout);

  /// Draws system-level symbols such as alternate endings and tempo markers.
  void drawSystemSymbols(System const& system, LayoutInfo const& layout);

  /// Draws the bar number for the first bar in the system.
  void drawBarNumber(int systemIndex, LayoutInfo const& layout);

  /// Draws a divider line between system symbols.
  void drawDividerLine(double y);

  /// Draws all of the alternate endings in the system.
  void drawAlternateEndings(System const& system, LayoutInfo const& layout, double height);

  /// Draws all of the tempo markers in the system.
  void drawTempoMarkers(System const& system, LayoutInfo const& layout, double height);

  /// Draws all of the directions in the system.
  double drawDirections(System const& system, LayoutInfo const& layout, double height);

  /// Draws all of the chord names in the system.
  void drawChordText(System const& system, LayoutInfo const& layout, double height);

  /// Draws all of the text items in the system.
  void drawTextItems(System const& system, LayoutInfo const& layout, double height);

  /// Draws the text symbols that appear below the tab staff
  /// (hammerons, slides, etc).
  void drawSymbolsBelowTabStaff(LayoutInfo const& layout);

  /// Creates a pick stroke symbol using the given character.
  QGraphicsItem* createPickStroke(QString const& text);

  /// Creates a plain text item - useful for symbols that don't use the
  /// music font (hammerons, slides, etc).
  QGraphicsItem* createPlainTextSymbol(QString const& text, QFont::Style style);

  /// Draws symbols that appear above the standard notation staff (e.g. 8va).
  void drawSymbolsAboveStdNotationStaff(LayoutInfo const& layout);

  /// Draws symbols that are grouped across multiple positions
  /// (i.e. consecutive "let ring" symbols).
  QGraphicsItem* createConnectedSymbolGroup(QString const& text,
                                            QFont::Style style,
                                            double width,
                                            LayoutInfo const& layout);

  /// Create a dashed line in the given location.
  void createDashedLine(QGraphicsItemGroup* group, double left, double right, double y);

  /// Draws symbols that appear below the standard notation staff (e.g. 8vb).
  void drawSymbolsBelowStdNotationStaff(LayoutInfo const& layout);

  /// Draws hammerons, pulloffs, etc in the tab staff.
  void drawLegato(Staff const& staff, LayoutInfo const& layout);

  /// Draws player changes for the given staff.
  void drawPlayerChanges(System const& system, int staffIndex, LayoutInfo const& layout);

  /// Draws the symbols that appear above the tab staff (e.g. vibrato).
  void drawSymbolsAboveTabStaff(Staff const& staff, LayoutInfo const& layout);

  /// Draws a sequence of continuous music symbols (e.g. vibrato).
  QGraphicsItem* drawContinuousFontSymbols(QChar symbol, int width);

  /// Creates a tremolo picking symbol.
  QGraphicsItem* createTremoloPicking(LayoutInfo const& layout);

  /// Creates a trill symbol.
  QGraphicsItem* createTrill(LayoutInfo const& layout);

  /// Creates an artificial harmonic symbol.
  QGraphicsItem* createArtificialHarmonicText(Position const& position);

  /// Creates a dynamic symbol.
  QGraphicsItem* createDynamic(Dynamic const& dynamic);

  /// Draws a group of bends.
  QGraphicsItem* createBendGroup(SymbolGroup const& group, LayoutInfo const& layout);

  /// Draws a single bend.
  void createBend(QGraphicsItemGroup* group,
                  double left,
                  double right,
                  double yStart,
                  double yEnd,
                  int pitch,
                  bool prebend);

  /// Draws notes, beams, and rests.
  void drawStdNotation(System const& system, Staff const& staff, LayoutInfo const& layout);

  /// Draws all ties in the voice.
  void drawTies(Voice const& voice,
                const std::vector<StdNotationNote>& notes,
                const std::vector<NoteStem>& stems,
                LayoutInfo const& layout);

  /// Draws all irregular groups in the voice.
  void drawIrregularGroups(Voice const& voice, const std::vector<NoteStem>& stems);

  /// Draws a multi-bar rest symbol.
  void drawMultiBarRest(System const& system,
                        Barline const& leftBar,
                        LayoutInfo const& layout,
                        int measureCount);

  /// Draws a rest symbol.
  void drawRest(Position const& pos, double x, LayoutInfo const& layout);

  /// Draws ledger lines for all positions in the staff.
  void drawLedgerLines(LayoutInfo const& layout,
                       const std::map<int, double>& minNoteLocations,
                       const std::map<int, double>& maxNoteLocations,
                       const std::map<int, double>& noteHeadWidths);

  /// Draws all slides in a staff.
  void drawSlides(Staff const& staff, LayoutInfo const& layout);

  /// Draws a single slide between the given positions.
  void drawSlide(LayoutInfo const& layout, int string, bool slideUp, int position1, int position2) const;

  const ScoreArea* myScoreArea;
  Score const& myScore;
  ViewOptions const& myViewOptions;

  QGraphicsRectItem* myParentSystem;
  QGraphicsItem* myParentStaff;

  QFont myMusicNotationFont;
  QFontMetricsF myMusicFontMetrics;
  QFont myPlainTextFont;
  QFont mySymbolTextFont;
  QFont myRehearsalSignFont;
};

#endif
