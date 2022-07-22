#pragma once

// String constants pointing to their respective parameter paths in Faust
const char * const PANIC = "Panic";

// OSC1 PARAMS
const char * const OSC1_RANGE = "Faug/Faug/OscBank/Osc-1/range";
const char * const OSC1_FREQ = "Faug/Faug/OscBank/Osc-1/freq";
const char * const OSC1_DETUNE = "Faug/Faug/OscBank/Osc-1/detune";
const char * const OSC1_DRIFT = "Faug/Faug/OscBank/Osc-1/driftAmount";
const char * const OSC1_DRATE = "Faug/Faug/OscBank/Osc-1/driftRate";
const char * const OSC1_WAVE = "Faug/Faug/OscBank/Osc-1/wave";

// OSC2 PARAMS
const char * const OSC2_RANGE = "Faug/Faug/OscBank/Osc-2/range";
const char * const OSC2_FREQ = "Faug/Faug/OscBank/Osc-2/freq";
const char * const OSC2_DETUNE = "Faug/Faug/OscBank/Osc-2/detune";
const char * const OSC2_DRIFT = "Faug/Faug/OscBank/Osc-2/driftAmount";
const char * const OSC2_DRATE = "Faug/Faug/OscBank/Osc-2/driftRate";
const char * const OSC2_WAVE = "Faug/Faug/OscBank/Osc-2/wave";

// OSC3 PARAMS
const char * const OSC3_RANGE = "Faug/Faug/OscBank/Osc-3/range";
const char * const OSC3_FREQ = "Faug/Faug/OscBank/Osc-3/freq";
const char * const OSC3_DETUNE = "Faug/Faug/OscBank/Osc-3/detune";
const char * const OSC3_DRIFT = "Faug/Faug/OscBank/Osc-3/driftAmount";
const char * const OSC3_DRATE = "Faug/Faug/OscBank/Osc-3/driftRate";
const char * const OSC3_WAVE = "Faug/Faug/OscBank/Osc-3/wave";

// ENVELOPE PARAMS
const char * const GAIN = "Faug/Gain";
const char * const ATTACK = "Faug/Faug/Envelope/Attack";
const char * const DECAY = "Faug/Faug/Envelope/Decay";
const char * const SUSTAIN = "Faug/Faug/Envelope/Sustain";
const char * const GATE = "Faug/Faug/Envelope/gate";

// FILTER PARAMS
const char * const F_CUTOFF = "Faug/Faug/Filter/cutoff";
const char * const F_Q = "Faug/Faug/Filter/Emphasis";
const char * const F_ATTACK = "Faug/Faug/Filter/FilterContour/Attack";
const char * const F_ENV_AMOUNT = "Faug/Faug/Filter/FilterContour/Amount";
const char * const F_DECAY = "Faug/Faug/Filter/FilterContour/Decay";
const char * const F_SUSTAIN = "Faug/Faug/Filter/FilterContour/Sustain";
const char * const F_ENV_GATE = "Faug/Faug/Filter/FilterContour/gate";

// FEEDBACK PARAMS
const char * const FEEDBACK1 = "Faug/Faug/feedback";
const char * const FEEDBACK2 = "Faug/feedback";

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