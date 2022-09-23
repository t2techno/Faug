#pragma once

#include <map>
#include <array>
#include <string>

// String constants pointing to their respective parameter paths in Faust
// NON-GUI
extern const char * const PANIC;
extern const char * const GATE;
extern const char * const FREQ;
extern const char * const FINAL_FREQ;
extern const char * const PREV_FREQ;

// CONTROLLERS
extern const char * const GLOBAL_DETUNE;
extern const char * const GLIDE_RATE;
// ToDos
extern const char * const MOD_MIX;
extern const char * const OSC3_FILTEG_MOD;
extern const char * const NOISE_LFO_MOD;

//KEYBOARD
extern const char * const LFO_RATE;
extern const char * const GLIDE_ON;
extern const char * const DECAY_ON;
//Todo
//move wheel shadow from guiElement to background
extern const char * const PITCH_BEND;
extern const char * const MOD_BEND;

// In-Between
extern const char * const OSC_MOD_ON;

//OscillatorBank
extern const char * const OSC1_RANGE;
extern const char * const OSC1_WAVE;

extern const char * const OSC2_RANGE;
extern const char * const OSC2_DETUNE;
extern const char * const OSC2_WAVE;

extern const char * const OSC3_RANGE;
extern const char * const OSC3_DETUNE;
extern const char * const OSC3_WAVE;
//ToDo
extern const char * const OSC3_CTRL;

//Mixer
extern const char * const LOAD;

extern const char * const OSC1_ON;
extern const char * const OSC1_GAIN;

extern const char * const FEEDBACK_ON;
extern const char * const FEEDBACK_GAIN;

extern const char * const OSC2_ON;
extern const char * const OSC2_GAIN;

extern const char * const NOISE_ON;
extern const char * const NOISE_GAIN;
extern const char * const NOISE_TYPE;

extern const char * const OSC3_ON;
extern const char * const OSC3_GAIN;

//In-Between
extern const char * const F_MOD_ON;
extern const char * const KEY_TRK1;
extern const char * const KEY_TRK2;

// FILTER PARAMS
extern const char * const F_CUTOFF;
extern const char * const F_Q;
extern const char * const F_ENV_AMOUNT;
extern const char * const F_ATTACK;
extern const char * const F_DECAY;
extern const char * const F_SUSTAIN;

// ENVELOPE PARAMS
extern const char * const ATTACK;
extern const char * const DECAY;
extern const char * const SUSTAIN;

//Power
extern const char * const VOLUME;
extern const char * const ON;

extern const std::map<std::string, std::array<float, 4>> guiPositions;