/*
 * Copyright (C) 2013 Cameron White
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

#ifndef SCORE_GENERALMIDI_H
#define SCORE_GENERALMIDI_H

#include <cstdint>
#include <string>
#include <vector>

namespace Midi
{
// MIDI Duration constants.
const uint32_t MIDI_WHOLE = 2880;
const uint32_t MIDI_HALF_DOTTED = 2160;
const uint32_t MIDI_HALF = 1440;
const uint32_t MIDI_QUARTER_DOTTED = 1080;
const uint32_t MIDI_QUARTER = 720;
const uint32_t MIDI_8TH_DOTTED = 540;
const uint32_t MIDI_8TH = 360;
const uint32_t MIDI_16TH_DOTTED = 270;
const uint32_t MIDI_16TH = 180;
const uint32_t MIDI_32ND_DOTTED = 120;
const uint32_t MIDI_32ND = 90;
const uint32_t MIDI_64TH = 45;
/// MIDI PPQN = amount of "MIDI time" per quarter note.
const uint32_t MIDI_PPQN = MIDI_QUARTER;

/// Time in microseconds for a beat at 120bpm.
const int BEAT_DURATION_120_BPM = 500000;

/// Number of MIDI channels per port.
const uint8_t NUM_MIDI_CHANNELS_PER_PORT = 16;
/// First MIDI channel.
const uint8_t FIRST_MIDI_CHANNEL = 0;
/// Last MIDI channel.
const uint8_t LAST_MIDI_CHANNEL = 15;

/// Minimum volume level for a MIDI channel.
const uint8_t MIN_MIDI_CHANNEL_VOLUME = 0;
/// Maximum volume level for a MIDI channel.
const uint8_t MAX_MIDI_CHANNEL_VOLUME = 0x7f;

/// Miniumum level for channel effects (chorus, reverb, etc.).
const uint8_t MIN_MIDI_CHANNEL_EFFECT_LEVEL = 0;
/// Maximum level for channel effects (chorus, reverb, etc.).
const uint8_t MAX_MIDI_CHANNEL_EFFECT_LEVEL = 0x7f;

/// Number of allowable notes.
const uint8_t NUM_MIDI_NOTES = 128;
/// Lowest note = C-1.
const uint8_t MIN_MIDI_NOTE = 0;
/// Highest note = G9.
const uint8_t MAX_MIDI_NOTE = 127;

const uint8_t MIDI_NOTE_KEY_C = 0;
const uint8_t MIDI_NOTE_KEY_CSHARP = 1;
const uint8_t MIDI_NOTE_KEY_DFLAT = 1;
const uint8_t MIDI_NOTE_KEY_D = 2;
const uint8_t MIDI_NOTE_KEY_DSHARP = 3;
const uint8_t MIDI_NOTE_KEY_EFLAT = 3;
const uint8_t MIDI_NOTE_KEY_E = 4;
const uint8_t MIDI_NOTE_KEY_F = 5;
const uint8_t MIDI_NOTE_KEY_FSHARP = 6;
const uint8_t MIDI_NOTE_KEY_GFLAT = 6;
const uint8_t MIDI_NOTE_KEY_G = 7;
const uint8_t MIDI_NOTE_KEY_GSHARP = 8;
const uint8_t MIDI_NOTE_KEY_AFLAT = 8;
const uint8_t MIDI_NOTE_KEY_A = 9;
const uint8_t MIDI_NOTE_KEY_ASHARP = 10;
const uint8_t MIDI_NOTE_KEY_BFLAT = 10;
const uint8_t MIDI_NOTE_KEY_B = 11;
const uint8_t MIN_MIDI_NOTE_KEY = MIDI_NOTE_KEY_C;
const uint8_t MAX_MIDI_NOTE_KEY = MIDI_NOTE_KEY_B;

const uint8_t MIDI_NOTE_CN1 = 0;
const uint8_t MIDI_NOTE_CSHARPN1 = 1;
const uint8_t MIDI_NOTE_DFLATN1 = 1;
const uint8_t MIDI_NOTE_DN1 = 2;
const uint8_t MIDI_NOTE_DSHARPN1 = 3;
const uint8_t MIDI_NOTE_EFLATN1 = 3;
const uint8_t MIDI_NOTE_EN1 = 4;
const uint8_t MIDI_NOTE_FN1 = 5;
const uint8_t MIDI_NOTE_FSHARPN1 = 6;
const uint8_t MIDI_NOTE_GFLATN1 = 6;
const uint8_t MIDI_NOTE_GN1 = 7;
const uint8_t MIDI_NOTE_GSHARPN1 = 8;
const uint8_t MIDI_NOTE_AFLATN1 = 8;
const uint8_t MIDI_NOTE_AN1 = 9;
const uint8_t MIDI_NOTE_ASHARPN1 = 10;
const uint8_t MIDI_NOTE_BFLATN1 = 10;
const uint8_t MIDI_NOTE_BN1 = 11;
const uint8_t MIDI_NOTE_C0 = 12;
const uint8_t MIDI_NOTE_CSHARP0 = 13;
const uint8_t MIDI_NOTE_DFLAT0 = 13;
const uint8_t MIDI_NOTE_D0 = 14;
const uint8_t MIDI_NOTE_DSHARP0 = 15;
const uint8_t MIDI_NOTE_EFLAT0 = 15;
const uint8_t MIDI_NOTE_E0 = 16;
const uint8_t MIDI_NOTE_F0 = 17;
const uint8_t MIDI_NOTE_FSHARP0 = 18;
const uint8_t MIDI_NOTE_GFLAT0 = 18;
const uint8_t MIDI_NOTE_G0 = 19;
const uint8_t MIDI_NOTE_GSHARP0 = 20;
const uint8_t MIDI_NOTE_AFLAT0 = 20;
const uint8_t MIDI_NOTE_A0 = 21;
const uint8_t MIDI_NOTE_ASHARP0 = 22;
const uint8_t MIDI_NOTE_BFLAT0 = 22;
const uint8_t MIDI_NOTE_B0 = 23;
const uint8_t MIDI_NOTE_C1 = 24;
const uint8_t MIDI_NOTE_CSHARP1 = 25;
const uint8_t MIDI_NOTE_DFLAT1 = 25;
const uint8_t MIDI_NOTE_D1 = 26;
const uint8_t MIDI_NOTE_DSHARP1 = 27;
const uint8_t MIDI_NOTE_EFLAT1 = 27;
const uint8_t MIDI_NOTE_E1 = 28;
const uint8_t MIDI_NOTE_F1 = 29;
const uint8_t MIDI_NOTE_FSHARP1 = 30;
const uint8_t MIDI_NOTE_GFLAT1 = 30;
const uint8_t MIDI_NOTE_G1 = 31;
const uint8_t MIDI_NOTE_GSHARP1 = 32;
const uint8_t MIDI_NOTE_AFLAT1 = 32;
const uint8_t MIDI_NOTE_A1 = 33;
const uint8_t MIDI_NOTE_ASHARP1 = 34;
const uint8_t MIDI_NOTE_BFLAT1 = 34;
const uint8_t MIDI_NOTE_B1 = 35;
const uint8_t MIDI_NOTE_C2 = 36;
const uint8_t MIDI_NOTE_CSHARP2 = 37;
const uint8_t MIDI_NOTE_DFLAT2 = 37;
const uint8_t MIDI_NOTE_D2 = 38;
const uint8_t MIDI_NOTE_DSHARP2 = 39;
const uint8_t MIDI_NOTE_EFLAT2 = 39;
const uint8_t MIDI_NOTE_E2 = 40;
const uint8_t MIDI_NOTE_F2 = 41;
const uint8_t MIDI_NOTE_FSHARP2 = 42;
const uint8_t MIDI_NOTE_GFLAT2 = 42;
const uint8_t MIDI_NOTE_G2 = 43;
const uint8_t MIDI_NOTE_GSHARP2 = 44;
const uint8_t MIDI_NOTE_AFLAT2 = 44;
const uint8_t MIDI_NOTE_A2 = 45;
const uint8_t MIDI_NOTE_ASHARP2 = 46;
const uint8_t MIDI_NOTE_BFLAT2 = 46;
const uint8_t MIDI_NOTE_B2 = 47;
const uint8_t MIDI_NOTE_C3 = 48;
const uint8_t MIDI_NOTE_CSHARP3 = 49;
const uint8_t MIDI_NOTE_DFLAT3 = 49;
const uint8_t MIDI_NOTE_D3 = 50;
const uint8_t MIDI_NOTE_DSHARP3 = 51;
const uint8_t MIDI_NOTE_EFLAT3 = 51;
const uint8_t MIDI_NOTE_E3 = 52;
const uint8_t MIDI_NOTE_F3 = 53;
const uint8_t MIDI_NOTE_FSHARP3 = 54;
const uint8_t MIDI_NOTE_GFLAT3 = 54;
const uint8_t MIDI_NOTE_G3 = 55;
const uint8_t MIDI_NOTE_GSHARP3 = 56;
const uint8_t MIDI_NOTE_AFLAT3 = 56;
const uint8_t MIDI_NOTE_A3 = 57;
const uint8_t MIDI_NOTE_ASHARP3 = 58;
const uint8_t MIDI_NOTE_BFLAT3 = 58;
const uint8_t MIDI_NOTE_B3 = 59;
const uint8_t MIDI_NOTE_C4 = 60;
const uint8_t MIDI_NOTE_MIDDLE_C = MIDI_NOTE_C4;
const uint8_t MIDI_NOTE_CSHARP4 = 61;
const uint8_t MIDI_NOTE_DFLAT4 = 61;
const uint8_t MIDI_NOTE_D4 = 62;
const uint8_t MIDI_NOTE_DSHARP4 = 63;
const uint8_t MIDI_NOTE_EFLAT4 = 63;
const uint8_t MIDI_NOTE_E4 = 64;
const uint8_t MIDI_NOTE_F4 = 65;
const uint8_t MIDI_NOTE_FSHARP4 = 66;
const uint8_t MIDI_NOTE_GFLAT4 = 66;
const uint8_t MIDI_NOTE_G4 = 67;
const uint8_t MIDI_NOTE_GSHARP4 = 68;
const uint8_t MIDI_NOTE_AFLAT4 = 68;
const uint8_t MIDI_NOTE_A4 = 69;
const uint8_t MIDI_NOTE_ASHARP4 = 70;
const uint8_t MIDI_NOTE_BFLAT4 = 70;
const uint8_t MIDI_NOTE_B4 = 71;
const uint8_t MIDI_NOTE_C5 = 72;
const uint8_t MIDI_NOTE_CSHARP5 = 73;
const uint8_t MIDI_NOTE_DFLAT5 = 73;
const uint8_t MIDI_NOTE_D5 = 74;
const uint8_t MIDI_NOTE_DSHARP5 = 75;
const uint8_t MIDI_NOTE_EFLAT5 = 75;
const uint8_t MIDI_NOTE_E5 = 76;
const uint8_t MIDI_NOTE_F5 = 77;
const uint8_t MIDI_NOTE_FSHARP5 = 78;
const uint8_t MIDI_NOTE_GFLAT5 = 78;
const uint8_t MIDI_NOTE_G5 = 79;
const uint8_t MIDI_NOTE_GSHARP5 = 80;
const uint8_t MIDI_NOTE_AFLAT5 = 80;
const uint8_t MIDI_NOTE_A5 = 81;
const uint8_t MIDI_NOTE_ASHARP5 = 82;
const uint8_t MIDI_NOTE_BFLAT5 = 82;
const uint8_t MIDI_NOTE_B5 = 83;
const uint8_t MIDI_NOTE_C6 = 84;
const uint8_t MIDI_NOTE_CSHARP6 = 85;
const uint8_t MIDI_NOTE_DFLAT6 = 85;
const uint8_t MIDI_NOTE_D6 = 86;
const uint8_t MIDI_NOTE_DSHARP6 = 87;
const uint8_t MIDI_NOTE_EFLAT6 = 87;
const uint8_t MIDI_NOTE_E6 = 88;
const uint8_t MIDI_NOTE_F6 = 89;
const uint8_t MIDI_NOTE_FSHARP6 = 90;
const uint8_t MIDI_NOTE_GFLAT6 = 90;
const uint8_t MIDI_NOTE_G6 = 91;
const uint8_t MIDI_NOTE_GSHARP6 = 92;
const uint8_t MIDI_NOTE_AFLAT6 = 92;
const uint8_t MIDI_NOTE_A6 = 93;
const uint8_t MIDI_NOTE_ASHARP6 = 94;
const uint8_t MIDI_NOTE_BFLAT6 = 94;
const uint8_t MIDI_NOTE_B6 = 95;
const uint8_t MIDI_NOTE_C7 = 96;
const uint8_t MIDI_NOTE_CSHARP7 = 97;
const uint8_t MIDI_NOTE_DFLAT7 = 97;
const uint8_t MIDI_NOTE_D7 = 98;
const uint8_t MIDI_NOTE_DSHARP7 = 99;
const uint8_t MIDI_NOTE_EFLAT7 = 99;
const uint8_t MIDI_NOTE_E7 = 100;
const uint8_t MIDI_NOTE_F7 = 101;
const uint8_t MIDI_NOTE_FSHARP7 = 102;
const uint8_t MIDI_NOTE_GFLAT7 = 102;
const uint8_t MIDI_NOTE_G7 = 103;
const uint8_t MIDI_NOTE_GSHARP7 = 104;
const uint8_t MIDI_NOTE_AFLAT7 = 104;
const uint8_t MIDI_NOTE_A7 = 105;
const uint8_t MIDI_NOTE_ASHARP7 = 106;
const uint8_t MIDI_NOTE_BFLAT7 = 106;
const uint8_t MIDI_NOTE_B7 = 107;
const uint8_t MIDI_NOTE_C8 = 108;
const uint8_t MIDI_NOTE_CSHARP8 = 109;
const uint8_t MIDI_NOTE_DFLAT8 = 109;
const uint8_t MIDI_NOTE_D8 = 110;
const uint8_t MIDI_NOTE_DSHARP8 = 111;
const uint8_t MIDI_NOTE_EFLAT8 = 111;
const uint8_t MIDI_NOTE_E8 = 112;
const uint8_t MIDI_NOTE_F8 = 113;
const uint8_t MIDI_NOTE_FSHARP8 = 114;
const uint8_t MIDI_NOTE_GFLAT8 = 114;
const uint8_t MIDI_NOTE_G8 = 115;
const uint8_t MIDI_NOTE_GSHARP8 = 116;
const uint8_t MIDI_NOTE_AFLAT8 = 116;
const uint8_t MIDI_NOTE_A8 = 117;
const uint8_t MIDI_NOTE_ASHARP8 = 118;
const uint8_t MIDI_NOTE_BFLAT8 = 118;
const uint8_t MIDI_NOTE_B8 = 119;
const uint8_t MIDI_NOTE_C9 = 120;
const uint8_t MIDI_NOTE_CSHARP9 = 121;
const uint8_t MIDI_NOTE_DFLAT9 = 121;
const uint8_t MIDI_NOTE_D9 = 122;
const uint8_t MIDI_NOTE_DSHARP9 = 123;
const uint8_t MIDI_NOTE_EFLAT9 = 123;
const uint8_t MIDI_NOTE_E9 = 124;
const uint8_t MIDI_NOTE_F9 = 125;
const uint8_t MIDI_NOTE_FSHARP9 = 126;
const uint8_t MIDI_NOTE_GFLAT9 = 126;
const uint8_t MIDI_NOTE_G9 = 127;

/// Minimum volume level for a MIDI note.
const uint8_t MIN_MIDI_NOTE_VOLUME = 0;
/// Maximum volume level for a MIDI note.
const uint8_t MAX_MIDI_NOTE_VOLUME = 0x7f;

// MIDI Preset constants.
const uint8_t NUM_MIDI_PRESETS = 128;
const uint8_t MIDI_PRESET_ACOUSTIC_GRAND = 0;
const uint8_t MIDI_PRESET_BRIGHT_ACOUSTIC = 1;
const uint8_t MIDI_PRESET_ELECTRIC_GRAND = 2;
const uint8_t MIDI_PRESET_HONKY_TONK = 3;
const uint8_t MIDI_PRESET_ELECTRIC_PIANO1 = 4;
const uint8_t MIDI_PRESET_ELECTRIC_PIANO2 = 5;
const uint8_t MIDI_PRESET_HARPSICHORD = 6;
const uint8_t MIDI_PRESET_CLAV = 7;
const uint8_t MIDI_PRESET_CELESTA = 8;
const uint8_t MIDI_PRESET_GLOCKENSPIEL = 9;
const uint8_t MIDI_PRESET_MUSIC_BOX = 10;
const uint8_t MIDI_PRESET_VIBRAPHONE = 11;
const uint8_t MIDI_PRESET_MARIMBA = 12;
const uint8_t MIDI_PRESET_XYLOPHONE = 13;
const uint8_t MIDI_PRESET_TUBULAR_BELLS = 14;
const uint8_t MIDI_PRESET_DULCIMER = 15;
const uint8_t MIDI_PRESET_DRAWBAR_ORGAN = 16;
const uint8_t MIDI_PRESET_PERCUSSIVE_ORGAN = 17;
const uint8_t MIDI_PRESET_ROCK_ORGAN = 18;
const uint8_t MIDI_PRESET_CHURCH_ORGAN = 19;
const uint8_t MIDI_PRESET_REED_ORGAN = 20;
const uint8_t MIDI_PRESET_ACCORDIAN = 21;
const uint8_t MIDI_PRESET_HARMONICA = 22;
const uint8_t MIDI_PRESET_TANGO_ACCORDIAN = 23;
const uint8_t MIDI_PRESET_ACOUSTIC_GUITAR_NYLON = 24;
const uint8_t MIDI_PRESET_ACOUSTIC_GUITAR_STEEL = 25;
const uint8_t MIDI_PRESET_ELECTRIC_GUITAR_JAZZ = 26;
const uint8_t MIDI_PRESET_ELECTRIC_GUITAR_CLEAN = 27;
const uint8_t MIDI_PRESET_ELECTRIC_GUITAR_MUTED = 28;
const uint8_t MIDI_PRESET_OVERDRIVEN_GUITAR = 29;
const uint8_t MIDI_PRESET_DISTORTION_GUITAR = 30;
const uint8_t MIDI_PRESET_GUITAR_HARMONICS = 31;
const uint8_t MIDI_PRESET_ACOUSTIC_BASS = 32;
const uint8_t MIDI_PRESET_ELECTRIC_BASS_FINGER = 33;
const uint8_t MIDI_PRESET_ELECTRIC_BASS_PICK = 34;
const uint8_t MIDI_PRESET_FRETLESS_BASS = 35;
const uint8_t MIDI_PRESET_SLAP_BASS1 = 36;
const uint8_t MIDI_PRESET_SLAP_BASS2 = 37;
const uint8_t MIDI_PRESET_SYNTH_BASS1 = 38;
const uint8_t MIDI_PRESET_SYNTH_BASS2 = 39;
const uint8_t MIDI_PRESET_VIOLIN = 40;
const uint8_t MIDI_PRESET_VIOLA = 41;
const uint8_t MIDI_PRESET_CELLO = 42;
const uint8_t MIDI_PRESET_CONTRABASS = 43;
const uint8_t MIDI_PRESET_TREMOLO_STRINGS = 44;
const uint8_t MIDI_PRESET_PIZZICATO_STRINGS = 45;
const uint8_t MIDI_PRESET_ORCHESTRAL_STRINGS = 46;
const uint8_t MIDI_PRESET_TIMPANI = 47;
const uint8_t MIDI_PRESET_STRING_ENSEMBLE1 = 48;
const uint8_t MIDI_PRESET_STRING_ENSEMBLE2 = 49;
const uint8_t MIDI_PRESET_SYNTHSTRINGS1 = 50;
const uint8_t MIDI_PRESET_SYNTHSTRINGS2 = 51;
const uint8_t MIDI_PRESET_CHOIR_AAHS = 52;
const uint8_t MIDI_PRESET_VOICE_OOHS = 53;
const uint8_t MIDI_PRESET_SYNTH_VOICE = 54;
const uint8_t MIDI_PRESET_ORCHESTRA_HIT = 55;
const uint8_t MIDI_PRESET_TRUMPET = 56;
const uint8_t MIDI_PRESET_TROMBONE = 57;
const uint8_t MIDI_PRESET_TUBA = 58;
const uint8_t MIDI_PRESET_MUTED_TRUMPET = 59;
const uint8_t MIDI_PRESET_FRENCH_HORN = 60;
const uint8_t MIDI_PRESET_BRASS_SECTION = 61;
const uint8_t MIDI_PRESET_SYNTHBRASS1 = 62;
const uint8_t MIDI_PRESET_SYNTHBRASS2 = 63;
const uint8_t MIDI_PRESET_SOPRANO_SAX = 64;
const uint8_t MIDI_PRESET_ALTO_SAX = 65;
const uint8_t MIDI_PRESET_TENOR_SAX = 66;
const uint8_t MIDI_PRESET_BARITONE_SAX = 67;
const uint8_t MIDI_PRESET_OBOE = 68;
const uint8_t MIDI_PRESET_ENGLISH_HORN = 69;
const uint8_t MIDI_PRESET_BASSOON = 70;
const uint8_t MIDI_PRESET_CLARINET = 71;
const uint8_t MIDI_PRESET_PICCOLO = 72;
const uint8_t MIDI_PRESET_FLUTE = 73;
const uint8_t MIDI_PRESET_RECORDER = 74;
const uint8_t MIDI_PRESET_PAN_FLUTE = 75;
const uint8_t MIDI_PRESET_BLOWN_BOTTLE = 76;
const uint8_t MIDI_PRESET_SKAKUHACHI = 77;
const uint8_t MIDI_PRESET_WHISTLE = 78;
const uint8_t MIDI_PRESET_OCARINA = 79;
const uint8_t MIDI_PRESET_LEAD1_SQUARE = 80;
const uint8_t MIDI_PRESET_LEAD2_SAWTOOTH = 81;
const uint8_t MIDI_PRESET_LEAD3_CALLIOPE = 82;
const uint8_t MIDI_PRESET_LEAD4_CHIFF = 83;
const uint8_t MIDI_PRESET_LEAD5_CHARANG = 84;
const uint8_t MIDI_PRESET_LEAD6_VOICE = 85;
const uint8_t MIDI_PRESET_LEAD7_FIFTHS = 86;
const uint8_t MIDI_PRESET_LEAD8_BASSLEAD = 87;
const uint8_t MIDI_PRESET_PAD1_NEWAGE = 88;
const uint8_t MIDI_PRESET_PAD2_WARM = 89;
const uint8_t MIDI_PRESET_PAD3_POLYSYNTH = 90;
const uint8_t MIDI_PRESET_PAD4_CHOIR = 91;
const uint8_t MIDI_PRESET_PAD5_BOWED = 92;
const uint8_t MIDI_PRESET_PAD6_METALLIC = 93;
const uint8_t MIDI_PRESET_PAD7_HALO = 94;
const uint8_t MIDI_PRESET_PAD8_SWEEP = 95;
const uint8_t MIDI_PRESET_FX1_RAIN = 96;
const uint8_t MIDI_PRESET_FX2_SOUNDTRACK = 97;
const uint8_t MIDI_PRESET_FX3_CRYSTAL = 98;
const uint8_t MIDI_PRESET_FX4_ATMOSPHERE = 99;
const uint8_t MIDI_PRESET_FX5_BRIGHTNESS = 100;
const uint8_t MIDI_PRESET_FX6_GOBLINS = 101;
const uint8_t MIDI_PRESET_FX7_ECHOES = 102;
const uint8_t MIDI_PRESET_FX8_SCIFI = 103;
const uint8_t MIDI_PRESET_SITAR = 104;
const uint8_t MIDI_PRESET_BANJO = 105;
const uint8_t MIDI_PRESET_SHAMISEN = 106;
const uint8_t MIDI_PRESET_KOTO = 107;
const uint8_t MIDI_PRESET_KALIMBA = 108;
const uint8_t MIDI_PRESET_BAGPIPE = 109;
const uint8_t MIDI_PRESET_FIDDLE = 110;
const uint8_t MIDI_PRESET_SHANAI = 111;
const uint8_t MIDI_PRESET_TINKLE_BELL = 112;
const uint8_t MIDI_PRESET_AGOGO = 113;
const uint8_t MIDI_PRESET_STEEL_DRUMS = 114;
const uint8_t MIDI_PRESET_WOODBLOCK = 115;
const uint8_t MIDI_PRESET_TAIKO_DRUM = 116;
const uint8_t MIDI_PRESET_MELODIC_TOM = 117;
const uint8_t MIDI_PRESET_SYNTH_DRUM = 118;
const uint8_t MIDI_PRESET_REVERSE_CYMBAL = 119;
const uint8_t MIDI_PRESET_GUITAR_FRET_NOISE = 120;
const uint8_t MIDI_PRESET_BREATH_NOISE = 121;
const uint8_t MIDI_PRESET_SEASHORE = 122;
const uint8_t MIDI_PRESET_BIRD_TWEET = 123;
const uint8_t MIDI_PRESET_TELEPHONE_RING = 124;
const uint8_t MIDI_PRESET_HELICOPTER = 125;
const uint8_t MIDI_PRESET_APPLAUSE = 126;
const uint8_t MIDI_PRESET_GUNSHOT = 127;
const uint8_t FIRST_MIDI_PRESET = MIDI_PRESET_ACOUSTIC_GRAND;
const uint8_t LAST_MIDI_PRESET = MIDI_PRESET_GUNSHOT;

// Percussion Sounds constants.
const uint8_t NUM_MIDI_PERCUSSION_PRESETS = 47;
const uint8_t MIDI_PERCUSSION_PRESET_ACOUSTIC_BASS_DRUM = 0;
const uint8_t MIDI_PERCUSSION_PRESET_BASS_DRUM1 = 1;
const uint8_t MIDI_PERCUSSION_PRESET_SIDE_STICK = 2;
const uint8_t MIDI_PERCUSSION_PRESET_ACOUSTIC_SNARE = 3;
const uint8_t MIDI_PERCUSSION_PRESET_HAND_CLAP = 4;
const uint8_t MIDI_PERCUSSION_PRESET_ELECTRIC_SNARE = 5;
const uint8_t MIDI_PERCUSSION_PRESET_LOW_FLOOR_TOM = 6;
const uint8_t MIDI_PERCUSSION_PRESET_CLOSED_HI_HAT = 7;
const uint8_t MIDI_PERCUSSION_PRESET_HIGH_FLOOR_TOM = 8;
const uint8_t MIDI_PERCUSSION_PRESET_PEDAL_HI_HAT = 9;
const uint8_t MIDI_PERCUSSION_PRESET_LOW_TOM = 10;
const uint8_t MIDI_PERCUSSION_PRESET_OPEN_HI_HAT = 11;
const uint8_t MIDI_PERCUSSION_PRESET_LOW_MID_TOM = 12;
const uint8_t MIDI_PERCUSSION_PRESET_HI_MID_TOM = 13;
const uint8_t MIDI_PERCUSSION_PRESET_CRASH_CYMBAL1 = 14;
const uint8_t MIDI_PERCUSSION_PRESET_HIGH_TOM = 15;
const uint8_t MIDI_PERCUSSION_PRESET_RIDE_CYMBAL1 = 16;
const uint8_t MIDI_PERCUSSION_PRESET_CHINESE_CYMBAL = 17;
const uint8_t MIDI_PERCUSSION_PRESET_RIDE_BELL = 18;
const uint8_t MIDI_PERCUSSION_PRESET_TAMBOURINE = 19;
const uint8_t MIDI_PERCUSSION_PRESET_SPLASH_CYMBAL = 20;
const uint8_t MIDI_PERCUSSION_PRESET_COWBELL = 21;
const uint8_t MIDI_PERCUSSION_PRESET_CRASH_CYMBAL2 = 22;
const uint8_t MIDI_PERCUSSION_PRESET_VIBRASLAP = 23;
const uint8_t MIDI_PERCUSSION_PRESET_RIDE_CYMBAL2 = 24;
const uint8_t MIDI_PERCUSSION_PRESET_HI_BONGO = 25;
const uint8_t MIDI_PERCUSSION_PRESET_LOW_BONGO = 26;
const uint8_t MIDI_PERCUSSION_PRESET_MUTE_HI_CONGA = 27;
const uint8_t MIDI_PERCUSSION_PRESET_OPEN_HI_CONGA = 28;
const uint8_t MIDI_PERCUSSION_PRESET_LOW_CONGA = 29;
const uint8_t MIDI_PERCUSSION_PRESET_HIGH_TIMBALE = 30;
const uint8_t MIDI_PERCUSSION_PRESET_LOW_TIMBALE = 31;
const uint8_t MIDI_PERCUSSION_PRESET_HIGH_AGOGO = 32;
const uint8_t MIDI_PERCUSSION_PRESET_LOW_AGOGO = 33;
const uint8_t MIDI_PERCUSSION_PRESET_CABASA = 34;
const uint8_t MIDI_PERCUSSION_PRESET_MARACAS = 35;
const uint8_t MIDI_PERCUSSION_PRESET_SHORT_WHISTLE = 36;
const uint8_t MIDI_PERCUSSION_PRESET_LONG_WHISTLE = 37;
const uint8_t MIDI_PERCUSSION_PRESET_SHORT_GUIRO = 38;
const uint8_t MIDI_PERCUSSION_PRESET_LONG_GUIRO = 39;
const uint8_t MIDI_PERCUSSION_PRESET_CLAVES = 40;
const uint8_t MIDI_PERCUSSION_PRESET_HI_WOOD_BLOCK = 41;
const uint8_t MIDI_PERCUSSION_PRESET_LOW_WOOD_BLOCK = 42;
const uint8_t MIDI_PERCUSSION_PRESET_MUTE_CUICA = 43;
const uint8_t MIDI_PERCUSSION_PRESET_OPEN_CUICA = 44;
const uint8_t MIDI_PERCUSSION_PRESET_MUTE_TRIANGLE = 45;
const uint8_t MIDI_PERCUSSION_PRESET_OPEN_TRIANGLE = 46;
const uint8_t FIRST_MIDI_PERCUSSION_PRESET =
    MIDI_PERCUSSION_PRESET_ACOUSTIC_BASS_DRUM;
const uint8_t LAST_MIDI_PERCUSSION_PRESET =
    MIDI_PERCUSSION_PRESET_OPEN_TRIANGLE;
/// The first percussion preset starts at 35.
const uint8_t MIDI_PERCUSSION_PRESET_OFFSET = 35;

/// Determines if a MIDI channel is valid.
bool isValidMidiChannel(uint8_t channel);
/// Determines if a MIDI channel volume is valid.
bool isValidMidiChannelVolume(uint8_t volume);
/// Determines if a MIDI channel effect level is valid.
bool isValidMidiChannelEffectLevel(uint8_t level);

/// Determines if a MIDI note value is valid.
bool isValidMidiNote(uint8_t note);
/// Determines if a MIDI note key is valid.
bool isValidMidiNoteKey(uint8_t key);
/// Returns the pitch value for a MIDI note.
uint8_t getMidiNotePitch(uint8_t note);
/// Returns the octave value for a MIDI note.
/// @param note MIDI note to get the octave value for.
/// @param noteText Text representation of the note, without accidentals.
/// This is used for handling unusual accidentals like B# or Cb.
int32_t getMidiNoteOctave(uint8_t note, char noteText = 0);

/// Returns an accurate text representation of a note, given a key
/// signature.
/// @param note A MIDI pitch.
/// @param usesSharps Whether the key signature uses sharps or flats.
/// @param numAccidentals The number of accidentals in the key signature.
/// @param forceAccidentals Whether to display accidentals for notes that
/// are in the key signature (useful for e.g. reinstating a flat or sharp
/// in the key signature after a natural sign).
std::string getMidiNoteText(uint8_t note, bool minor, bool usesSharps,
                            uint8_t numAccidentals,
                            bool forceAccidentals = false);

/// Returns a text representation of a MIDI note. This is less accurate than
/// GetMidiNoteText, which takes the key signature into account. However, it
/// is useful for things like displaying the notes of a tuning.
/// @param note MIDI note to get the text representation for.
/// @param sharps True to get the sharp representation of the note, false to
/// get the flat representation of the note.
std::string getMidiNoteTextSimple(uint8_t note, bool sharps);

/// Offsets a MIDI note by an amount.
uint8_t offsetMidiNote(uint8_t note, int8_t offset);
/// Determines if a MIDI note volume is valid.
bool isValidMidiNoteVolume(uint8_t volume);

/// Returns a string representation of the tonic note of the given key
/// e.g. GetKeyText(true, false, 1) -> F
std::string getKeyText(bool minor, bool usesSharps, uint8_t numAccidentals);

/// Returns a list of all MIDI preset names.
std::vector<std::string> getPresetNames();

/// Returns a list of all MIDI percussion preset names.
std::vector<std::string> getPercussionPresetNames();
} // namespace Midi

#endif
