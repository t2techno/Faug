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
const char* const OSC3_FILTEG_MOD = "oscThree_filterEg";
const char* const NOISE_LFO_MOD = "noise_lfo";

//KEYBOARD
//Todo
const char* const LFO_RATE = "lfoRate";
const char* const GLIDE_ON = "glideOn";
const char* const DECAY_ON = "decayOn";
const char* const PITCH_BEND = "pitchBend";
const char* const MOD_AMOUNT = "modAmount";

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
const char* const OSC3_CTRL = "oscThreeKeyTrack";

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

// for sizing look and feels
const char * const FLOAT_KNOB_EX = OSC1_GAIN;
const char * const BIG_FLOAT_KNOB_EX = OSC2_DETUNE;
const char * const TINY_FLOAT_KNOB_EX = VOLUME;
const char * const INT_KNOB_EX = OSC1_RANGE;
const char * const SCREW_FLOAT_EX = LOAD;

const std::map<std::string, double> skewMap = 
{
  {VOLUME,0.5},
  {OSC1_GAIN,0.5},
  {OSC2_GAIN,0.5},
  {OSC3_GAIN,0.5},
  {ATTACK, 0.5},
  {DECAY, 0.5},
  {F_ATTACK, 0.5},
  {F_DECAY, 0.5},
  {F_CUTOFF, 0.75},
  {GLIDE_RATE, 0.5}
};

const enum AssetType {
    KNOB_ONE, BIG_KNOB_ONE, TINY_KNOB_ONE, KNOB_TWO,

};

const std::map<std::string, AssetType> assetTypeMap =
{
    {GLOBAL_DETUNE, KNOB_ONE},
    {GLIDE_RATE, KNOB_ONE},
    {MOD_MIX, KNOB_ONE},

    {LFO_RATE, TINY_KNOB_ONE}
};