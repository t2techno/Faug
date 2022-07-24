#pragma once

// String constants pointing to their respective parameter paths in Faust
const char * const PANIC = "Panic";

// OSC1 PARAMS
const char * const OSC1_RANGE = "/faug/faug/osc_bank/osc-1/range";
const char * const OSC1_FREQ = "/faug/faug/osc_bank/osc-1/freq";
const char * const OSC1_DETUNE = "/faug/faug/osc_bank/osc-1/detune";
const char * const OSC1_DRIFT = "/faug/faug/osc_bank/osc-1/drift_amount";
const char * const OSC1_DRATE = "/faug/faug/osc_bank/osc-1/drift_rate";
const char * const OSC1_WAVE = "/faug/faug/osc_bank/osc-1/wave";

// OSC2 PARAMS
const char * const OSC2_RANGE = "/faug/faug/osc_bank/osc-2/range";
const char * const OSC2_FREQ = "/faug/faug/osc_bank/osc-2/freq";
const char * const OSC2_DETUNE = "/faug/faug/osc_bank/osc-2/detune";
const char * const OSC2_DRIFT = "/faug/faug/osc_bank/osc-2/drift_amount";
const char * const OSC2_DRATE = "/faug/faug/osc_bank/osc-2/drift_rate";
const char * const OSC2_WAVE = "/faug/faug/osc_bank/osc-2/wave";

// OSC3 PARAMS
const char * const OSC3_RANGE = "/faug/faug/osc_bank/osc-3/range";
const char * const OSC3_FREQ = "/faug/faug/osc_bank/osc-3/freq";
const char * const OSC3_DETUNE = "/faug/faug/osc_bank/osc-3/detune";
const char * const OSC3_DRIFT = "/faug/faug/osc_bank/osc-3/drift_amount";
const char * const OSC3_DRATE = "/faug/faug/osc_bank/osc-3/drift_rate";
const char * const OSC3_WAVE = "/faug/faug/osc_bank/osc-3/wave";

// ENVELOPE PARAMS
const char * const GAIN = "/faug/gain";
const char * const ATTACK = "/faug/faug/envelope/attack";
const char * const DECAY = "/faug/faug/envelope/decay";
const char * const SUSTAIN = "/faug/faug/envelope/sustain";
const char * const GATE = "/faug/faug/envelope/gate";

// FILTER PARAMS
const char * const F_CUTOFF = "/faug/faug/filter/cutoff";
const char * const F_Q = "/faug/faug/filter/emphasis";
const char * const F_ATTACK = "/faug/faug/filter/filter_contour/attack";
const char * const F_ENV_AMOUNT = "/faug/faug/filter/filter_contour/amount";
const char * const F_DECAY = "/faug/faug/filter/filter_contour/decay";
const char * const F_SUSTAIN = "/faug/faug/filter/filter_contour/sustain";
const char * const F_ENV_GATE = "/faug/faug/filter/filter_contour/gate";

// FEEDBACK PARAMS
const char * const FEEDBACK1 = "/faug/faug/feedback";
const char * const FEEDBACK2 = "/faug/feedback";

const char * const PARAMS_LIST[] = {
	OSC1_RANGE, OSC1_FREQ, OSC1_DETUNE, OSC1_DRIFT, OSC1_DRATE, OSC1_WAVE,
	OSC2_RANGE, OSC2_FREQ, OSC2_DETUNE, OSC2_DRIFT, OSC2_DRATE, OSC2_WAVE,
	OSC3_RANGE, OSC3_FREQ, OSC3_DETUNE, OSC3_DRIFT, OSC3_DRATE, OSC3_WAVE,
	GAIN, ATTACK, DECAY, SUSTAIN, GATE, 
	F_CUTOFF, F_Q, F_ATTACK, F_ENV_AMOUNT, F_DECAY, F_SUSTAIN, F_ENV_GATE,
	FEEDBACK1, FEEDBACK2
};

const char * const KEY_PARAMS[] = {
	GAIN, GATE, OSC1_FREQ
};
const int NUM_KEY = 3;