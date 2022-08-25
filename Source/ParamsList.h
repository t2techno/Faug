#pragma once

// String constants pointing to their respective parameter paths in Faust
const char * const PANIC       = "Panic";

// FREQ
const char * const FREQ        = "freq";
const char * const FINAL_FREQ  = "finalFreq";
const char * const PREV_FREQ   = "prevFreq";
const char * const GLIDE       = "glide";
const char * const PITCH_BEND  = "pitchBend";

// FEEDBACK PARAMS
const char * const FEEDBACK_ON     = "feedbackOn";
const char * const FEEDBACK_GAIN   = "feedbackGain";
const char * const LOAD            = "load";

// GLOBAL DETUNE
const char * const GLOBAL_DETUNE   = "globalDetune";

const char * const NOISE_ON    = "noiseOn";
const char * const NOISE_GAIN  = "noiseGain";
const char * const NOISE_TYPE  = "noiseType";

// OSC1 PARAMS
const char * const OSC1_POWER  = "oscOnePower";
const char * const OSC1_GAIN   = "oscOneGain";
const char * const OSC1_RANGE  = "rangeOne";
const char * const OSC1_WAVE   = "waveOne";

// OSC2 PARAMS
const char * const OSC2_POWER  = "oscTwoPower";
const char * const OSC2_GAIN   = "oscTwoGain";
const char * const OSC2_RANGE  = "rangeTwo";
const char * const OSC2_DETUNE = "detuneTwo";
const char * const OSC2_WAVE   = "waveTwo";

// OSC3 PARAMS
const char * const OSC3_POWER  = "oscThreePower";
const char * const OSC3_GAIN   = "oscThreeGain";
const char * const OSC3_RANGE  = "rangeThree";
const char * const OSC3_DETUNE = "detuneThree";
const char * const OSC3_WAVE   = "waveThree";

// ENVELOPE PARAMS
const char * const ATTACK      = "attack";
const char * const DECAY       = "decay";
const char * const SUSTAIN     = "sustain";
const char * const GATE        = "gate";

// FILTER PARAMS
const char * const F_CUTOFF    = "cutoff";
const char * const F_Q         = "emphasis";
const char * const F_ENV_AMOUNT= "contourAmount";
const char * const F_ATTACK    = "fAttack";
const char * const F_DECAY     = "fDecay";
const char * const F_SUSTAIN   = "fSustain";