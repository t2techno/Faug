/*
  ==============================================================================

	File generated with svg2gui
	Contains the name, x/y position and width/height for each gui element from a single layer in the source SVG
	All values are relative to total gui width/height(in range 0 <= ... <= 1)
	VAR_NAME should be defined and imported from somewhere as a string constant. eg. #include "../Constants.h"
	Declare guiPositions in the same file as the string constants

  ==============================================================================
*/

#include <map>;
#include <array>;
#include <string>;

#include "../Constants.h"

//  VAR_NAME should be useable everywhere (keep your naming consistent)
// {VAR_NAME: [x_position, y_position, width, height]}
const std::map<std::string, std::array<float,4>> guiPositions = {
	{ATTACK,{0.7135146588541667,0.5133405672222222,0.040087898437500005,0.07126338888888889}},
	{DECAY,{0.7939367421875,0.5133406135185185,0.040087898437500005,0.07126338888888889}},
	{DECAY_ON,{0.11747125520833332,0.8051734375925925,0.032820416666666664,0.028113022685185184}},
	{FEEDBACK_GAIN,{0.5818597109375001,0.19520999777777778,0.040087898437500005,0.07126338888888889}},
	{FEEDBACK_ON,{0.5128021328125,0.2132592662962963,0.042990479166666665,0.03516484722222222}},
	{F_ATTACK,{0.7135145807291666,0.3184446412962963,0.040087898437500005,0.07126338888888889}},
	{F_CUTOFF,{0.7135146588541667,0.1598839237037037,0.040087898437500005,0.07126338888888889}},
	{F_DECAY,{0.7939367421875,0.3184446412962963,0.040087898437500005,0.07126338888888889}},
	{F_ENV_AMOUNT,{0.8746219765625,0.1598839237037037,0.040087898437500005,0.07126338888888889}},
	{F_MOD_ON,{0.6513340598958333,0.12026953481481481,0.0366477734375,0.030026591203703705}},
	{F_Q,{0.7939367421875,0.1598839237037037,0.040087898437500005,0.07126338888888889}},
	{F_SUSTAIN,{0.8746219765625,0.3184446412962963,0.040087898437500005,0.07126338888888889}},
	{GLIDE_ON,{0.11747125520833332,0.7381990857407408,0.032820416666666664,0.028113022685185184}},
	{GLIDE_RATE,{0.05453968489583334,0.2625420625925926,0.040087898437500005,0.07126338888888889}},
	{GLOBAL_DETUNE,{0.05453968489583334,0.10592078018518519,0.040087898437500005,0.07126249537037037}},
	{KEY_TRK1,{0.6513340598958333,0.18622792833333332,0.0366477734375,0.030026591203703705}},
	{KEY_TRK2,{0.6513340598958333,0.25864691907407406,0.0366477734375,0.030026591203703705}},
	{LFO_RATE,{0.02235023697916667,0.7624050579629629,0.030604442708333335,0.05440486111111111}},
	{LOAD,{0.5918649192708333,0.06608752555555557,0.020077498697916665,0.035691335648148144}},
	{MOD_BEND,{0.10671571614583332,0.8215823727777778,0.017539445572916666,0.14484652777777776}},
	{MOD_MIX,{0.05453968489583334,0.4364603264814815,0.040087898437500005,0.07126338888888889}},
	{NOISE_GAIN,{0.5818597109375001,0.388284007037037,0.040087898437500005,0.07126338888888889}},
	{NOISE_LFO_MOD,{0.08424964583333333,0.553177557962963,0.042990541666666666,0.036815237037037034}},
	{NOISE_ON,{0.5128021328125,0.40633326166666667,0.042990479166666665,0.03516484722222222}},
	{NOISE_TYPE,{0.6117942942708333,0.5469835764814813,0.042988078125,0.03516681481481481}},
	{ON,{0.9721523932291667,0.5178360764814813,0.04298813802083334,0.0368172962962963}},
	{OSC1_GAIN,{0.4427580442708334,0.0982219237037037,0.040087898437500005,0.07126338888888889}},
	{OSC1_ON,{0.5128021328125,0.11627119685185186,0.042990479166666665,0.03516484722222222}},
	{OSC1_RANGE,{0.19176904893753247,0.09760207090456717,0.047211130208333334,0.08392802314814814}},
	{OSC1_WAVE,{0.35307302019554304,0.09760205628050658,0.047211130208333334,0.08392802314814814}},
	{OSC2_DETUNE,{0.2731150755208333,0.2814116181481482,0.04532498958333333,0.08057325925925926}},
	{OSC2_GAIN,{0.4427580442708334,0.29551339592592596,0.040087898437500005,0.07126338888888889}},
	{OSC2_ON,{0.5128021328125,0.31356267833333334,0.042990479166666665,0.03516484722222222}},
	{OSC2_RANGE,{0.1917688556928576,0.27973280931900296,0.047211294270833336,0.0839288425925926}},
	{OSC2_WAVE,{0.35307279309824857,0.27973279741540963,0.047211294270833336,0.0839288425925926}},
	{OSC3_CTRL,{0.16305505989583338,0.45485146074074073,0.046371125,0.03799746851851852}},
	{OSC3_DETUNE,{0.2731150755208333,0.4449709144444444,0.04532498958333333,0.08057325925925926}},
	{OSC3_FILTEG_MOD,{0.019888867187500003,0.553177557962963,0.042990541666666666,0.036815237037037034}},
	{OSC3_GAIN,{0.4427580442708334,0.48584112277777775,0.040087898437500005,0.07126338888888889}},
	{OSC3_ON,{0.5128021328125,0.5038903357407407,0.042990479166666665,0.03516484722222222}},
	{OSC3_RANGE,{0.1917688715549476,0.4432921379276213,0.047211294270833336,0.0839288425925926}},
	{OSC3_WAVE,{0.3542915078125001,0.4463541551851852,0.045325,0.08057777777777778}},
	{OSC_MOD_ON,{0.10875486197916666,0.21968109962962962,0.046373716145833334,0.03799534537037037}},
	{PITCH_BEND,{0.0631847109375,0.8215823727777778,0.017539445572916666,0.14484652777777776}},
	{SUSTAIN,{0.8746219765625,0.5133406135185185,0.040087898437500005,0.07126338888888889}},
	{VOLUME,{0.9482056223958334,0.25688472462962963,0.027183705729166667,0.04832388888888889}},
};
