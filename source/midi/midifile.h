/*
 * Copyright (C) 2015 Cameron White
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

#ifndef MIDI_MIDIFILE_H
#define MIDI_MIDIFILE_H

#include <midi/midieventlist.h>

#include <cstdint>
#include <vector>

class Barline;
class Score;
class Staff;
class System;
class SystemLocation;
class Voice;

class MidiFile
{
public:
  struct LoadOptions
  {
    LoadOptions()
      : myVibratoStrength(0)
      , myWideVibratoStrength(0)
      , myEnableMetronome(false)
      , myStrongAccentVel(0)
      , myWeakAccentVel(0)
      , myMetronomePreset(0)
      , myRecordPositionChanges(false)
    {}

    uint8_t myVibratoStrength;
    uint8_t myWideVibratoStrength;
    bool myEnableMetronome;
    uint8_t myStrongAccentVel;
    uint8_t myWeakAccentVel;
    uint8_t myMetronomePreset;
    bool myRecordPositionChanges;
  };

  MidiFile();

  void load(Score const& score, LoadOptions const& options);

  int getTicksPerBeat() const { return myTicksPerBeat; }
  std::vector<MidiEventList>& getTracks() { return myTracks; }
  const std::vector<MidiEventList>& getTracks() const { return myTracks; }

private:
  int generateMetronome(MidiEventList& event_list,
                        int current_tick,
                        System const& system,
                        Barline const& current_bar,
                        Barline const& next_bar,
                        SystemLocation const& location,
                        LoadOptions const& options);

  int addTempoEvent(MidiEventList& event_list,
                    int current_tick,
                    int current_tempo,
                    System const& system,
                    int bar_start,
                    int bar_end);

  int addEventsForBar(std::vector<MidiEventList>& tracks,
                      uint8_t& active_bend,
                      int current_tick,
                      int current_tempo,
                      Score const& score,
                      System const& system,
                      int system_index,
                      Staff const& staff,
                      int staff_index,
                      Voice const& voice,
                      int voice_index,
                      int bar_start,
                      int bar_end,
                      LoadOptions const& options);

  int myTicksPerBeat;
  std::vector<MidiEventList> myTracks;
};

#endif
