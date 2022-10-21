/*
  ==============================================================================

    Constants.cpp
    Created: 19 Sep 2022 7:40:18am
    Author:  tytu1

  ==============================================================================
*/

#include "Constants.h"

// String constants pointing to their respective parameter paths in Faust
// NON-GUI

// String values are Faust variable names
const char* const PANIC = "Panic";
const char* const FREQ = "freq";
const char* const FINAL_FREQ = "finalFreq";
const char* const PREV_FREQ = "prevFreq";
const char* const GATE = "gate";

// CONTROLLERS
const char* const GLOBAL_DETUNE = "globalDetune";
const char* const GLIDE_RATE = "glide";

// ToDos
const char* const MOD_MIX = "modMix";
const char* const OSC3_FILTEG_MOD = "osc3_filterEg_modSrc";
const char* const NOISE_LFO_MOD = "noise_lfo_modSrc";

//KEYBOARD
//Todo
const char* const LFO_RATE = "lfoRate";
const char* const GLIDE_ON = "glideOn";
const char* const DECAY_ON = "decayOn";
const char* const PITCH_BEND = "pitchBend";
const char* const MOD_BEND = "modBend";

// In-Between
const char* const OSC_MOD_ON = "oscModOn";

//OscillatorBank
const char* const OSC1_RANGE = "rangeOne";
const char* const OSC1_WAVE = "waveOne";

const char* const OSC2_RANGE = "rangeTwo";
const char* const OSC2_DETUNE = "detuneTwo";
const char* const OSC2_WAVE = "waveTwo";

const char* const OSC3_RANGE = "rangeThree";
const char* const OSC3_DETUNE = "detuneThree";
const char* const OSC3_WAVE = "waveThree";
//ToDo
const char* const OSC3_CTRL = "osc3Ctrl";

//Mixer
const char* const LOAD = "load";

const char* const OSC1_ON = "oscOnePower";
const char* const OSC1_GAIN = "oscOneGain";

const char* const FEEDBACK_ON = "feedbackOn";
const char* const FEEDBACK_GAIN = "feedbackGain";

const char* const OSC2_ON = "oscTwoPower";
const char* const OSC2_GAIN = "oscTwoGain";

const char* const NOISE_ON = "noiseOn";
const char* const NOISE_GAIN = "noiseGain";
const char* const NOISE_TYPE = "noiseType";

const char* const OSC3_ON = "oscThreePower";
const char* const OSC3_GAIN = "oscThreeGain";

//In-Between
const char* const F_MOD_ON = "filterModOn";
const char* const KEY_TRK1 = "keyTrackOne";
const char* const KEY_TRK2 = "keyTrackTwo";

// FILTER PARAMS
const char* const F_CUTOFF = "cutoff";
const char* const F_Q = "emphasis";
const char* const F_ENV_AMOUNT = "contourAmount";
const char* const F_ENV_DIRECTION = "contourDirection";
const char* const F_ATTACK = "fAttack";
const char* const F_DECAY = "fDecay";
const char* const F_SUSTAIN = "fSustain";

// ENVELOPE PARAMS
const char* const ATTACK = "attack";
const char* const DECAY = "decay";
const char* const SUSTAIN = "sustain";

// Power
const char * const VOLUME = "masterVolume";
const char * const ON = "on";