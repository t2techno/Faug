/* ------------------------------------------------------------
name: "FaugExp", "FaustDSP"
version: "2.52.3"
Code generated with Faust 2.49.1 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include "FaustIncludes.h"

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

class mydspSIG0 {
	
  private:
	
	int iVec4[2];
	int iRec26[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			iVec4[l22] = 0;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			iRec26[l23] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec4[0] = 1;
			iRec26[0] = (iVec4[1] + iRec26[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec26[0]));
			iVec4[1] = iVec4[0];
			iRec26[1] = iRec26[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float mydsp_faustpower4_f(float value) {
	return value * value * value * value;
}
static float ftbl0mydspSIG0[65536];
static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fCheckbox0;
	int iVec0[2];
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider0;
	float fConst4;
	float fRec2[2];
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec3[2];
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	float fRec5[2];
	FAUSTFLOAT fHslider2;
	float fRec6[2];
	float fRec7[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT fEntry0;
	float fVec2[2];
	float fVec3[2];
	FAUSTFLOAT fHslider4;
	float fConst5;
	FAUSTFLOAT fHslider5;
	float fRec13[2];
	int iRec14[2];
	FAUSTFLOAT fHslider6;
	float fRec15[2];
	float fRec16[2];
	FAUSTFLOAT fHslider7;
	float fRec17[2];
	FAUSTFLOAT fHslider8;
	float fRec18[2];
	FAUSTFLOAT fHslider9;
	float fRec19[2];
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fCheckbox3;
	FAUSTFLOAT fCheckbox4;
	int iRec20[2];
	float fRec21[4];
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fCheckbox5;
	FAUSTFLOAT fHslider12;
	float fRec22[2];
	FAUSTFLOAT fCheckbox6;
	FAUSTFLOAT fHslider13;
	float fRec23[2];
	FAUSTFLOAT fCheckbox7;
	FAUSTFLOAT fHslider14;
	float fRec24[2];
	FAUSTFLOAT fCheckbox8;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	float fConst6;
	float fRec27[2];
	float fConst7;
	float fRec28[2];
	int IOTA0;
	float fVec5[131072];
	int iConst8;
	float fConst9;
	float fRec29[2];
	float fVec6[65536];
	int iConst10;
	float fVec7[65536];
	int iConst11;
	FAUSTFLOAT fEntry1;
	FAUSTFLOAT fHslider17;
	int iVec8[2];
	int iRec31[2];
	int iRec30[2];
	FAUSTFLOAT fHslider18;
	float fRec32[2];
	FAUSTFLOAT fCheckbox9;
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider19;
	float fRec34[2];
	FAUSTFLOAT fHslider20;
	float fRec33[2];
	float fRec25[2];
	float fRec36[2];
	float fVec9[2];
	float fVec10[4096];
	float fConst12;
	float fRec35[2];
	float fConst13;
	float fRec37[2];
	float fConst14;
	float fConst15;
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	FAUSTFLOAT fHslider23;
	float fRec40[2];
	float fRec39[2];
	float fRec42[2];
	float fVec11[2];
	float fVec12[4096];
	float fRec41[2];
	float fRec43[2];
	FAUSTFLOAT fHslider24;
	FAUSTFLOAT fHslider25;
	float fRec45[2];
	float fRec47[2];
	float fVec13[2];
	float fVec14[4096];
	float fRec46[2];
	float fRec48[2];
	FAUSTFLOAT fHslider26;
	float fRec8[2];
	float fRec9[2];
	float fRec10[2];
	float fRec11[2];
	float fRec1[2];
	float fVec15[4];
	float fRec0[6];
	float fVec16[2];
	FAUSTFLOAT fCheckbox10;
	FAUSTFLOAT fHslider27;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("aanl_lib_ADAA1_author", "Dario Sanfilippo");
		m->declare("aanl_lib_ADAA1_copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl_lib_ADAA1_license", "LGPL v3.0 license");
		m->declare("aanl_lib_name", "Faust Antialiased Nonlinearities");
		m->declare("aanl_lib_tanh1_author", "Dario Sanfilippo");
		m->declare("aanl_lib_tanh1_copyright", "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>");
		m->declare("aanl_lib_tanh1_license", "LGPL v3.0 license");
		m->declare("aanl_lib_version", "0.3");
		m->declare("basics_lib_name", "Faust Basic Element Library");
		m->declare("basics_lib_version", "0.8");
		m->declare("compile_options", "-single -scal -I libraries/ -I project/ -lang wasm");
		m->declare("envelopes_lib_adsr_author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes_lib_author", "GRAME");
		m->declare("envelopes_lib_copyright", "GRAME");
		m->declare("envelopes_lib_license", "LGPL with exception");
		m->declare("envelopes_lib_name", "Faust Envelope Library");
		m->declare("envelopes_lib_version", "0.2");
		m->declare("filename", "FaugExp.dsp");
		m->declare("filters_lib_fir_author", "Julius O. Smith III");
		m->declare("filters_lib_fir_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_fir_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_iir_author", "Julius O. Smith III");
		m->declare("filters_lib_iir_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_iir_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_name", "Faust Filters Library");
		m->declare("filters_lib_pole_author", "Julius O. Smith III");
		m->declare("filters_lib_pole_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_pole_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_version", "0.3");
		m->declare("library_path0", "/libraries/stdfaust.lib");
		m->declare("library_path1", "/libraries/aanl.lib");
		m->declare("library_path10", "/libraries/envelopes.lib");
		m->declare("library_path2", "/libraries/basics.lib");
		m->declare("library_path3", "/libraries/maths.lib");
		m->declare("library_path4", "/libraries/platform.lib");
		m->declare("library_path5", "/libraries/signals.lib");
		m->declare("library_path6", "/libraries/oscillators.lib");
		m->declare("library_path7", "/libraries/filters.lib");
		m->declare("library_path8", "/libraries/noises.lib");
		m->declare("library_path9", "/libraries/vaeffects.lib");
		m->declare("maths_lib_author", "GRAME");
		m->declare("maths_lib_copyright", "GRAME");
		m->declare("maths_lib_license", "LGPL with exception");
		m->declare("maths_lib_name", "Faust Math Library");
		m->declare("maths_lib_version", "2.5");
		m->declare("name", "FaugExp");
		m->declare("noises_lib_name", "Faust Noise Generator Library");
		m->declare("noises_lib_version", "0.4");
		m->declare("oscillators_lib_lf_sawpos_author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators_lib_lf_sawpos_licence", "STK-4.3");
		m->declare("oscillators_lib_lf_triangle_author", "Bart Brouns");
		m->declare("oscillators_lib_lf_triangle_licence", "STK-4.3");
		m->declare("oscillators_lib_name", "Faust Oscillator Library");
		m->declare("oscillators_lib_saw1_author", "Bart Brouns");
		m->declare("oscillators_lib_saw1_licence", "STK-4.3");
		m->declare("oscillators_lib_version", "0.3");
		m->declare("platform_lib_name", "Generic Platform Library");
		m->declare("platform_lib_version", "0.2");
		m->declare("signals_lib_name", "Faust Signal Routing Library");
		m->declare("signals_lib_version", "0.3");
		m->declare("vaeffects_lib_moogLadder_author", "Dario Sanfilippo");
		m->declare("vaeffects_lib_moogLadder_license", "MIT-style STK-4.3 license");
		m->declare("vaeffects_lib_name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects_lib_version", "0.2");
		m->declare("version", "2.52.3");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 1.0f / fConst0;
		fConst2 = 44.1f / fConst0;
		fConst3 = 1.0f - fConst2;
		fConst4 = 0.0441f / fConst0;
		fConst5 = 0.5f * fConst0;
		fConst6 = 0.25f / fConst0;
		fConst7 = 0.05f / fConst0;
		iConst8 = int(fConst5);
		fConst9 = 0.1f / fConst0;
		iConst10 = int(0.33333334f * fConst0);
		iConst11 = int(0.2f * fConst0);
		fConst12 = 0.25f * fConst0;
		fConst13 = 4.0f / fConst0;
		fConst14 = 0.7f * fConst0;
		fConst15 = 0.85f * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(5e+01f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(5e+01f);
		fHslider2 = FAUSTFLOAT(0.8f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fCheckbox2 = FAUSTFLOAT(0.0f);
		fEntry0 = FAUSTFLOAT(4.4e+02f);
		fHslider4 = FAUSTFLOAT(0.5f);
		fHslider5 = FAUSTFLOAT(5e+01f);
		fHslider6 = FAUSTFLOAT(5e+01f);
		fHslider7 = FAUSTFLOAT(0.8f);
		fHslider8 = FAUSTFLOAT(0.0f);
		fHslider9 = FAUSTFLOAT(1.0f);
		fHslider10 = FAUSTFLOAT(0.0f);
		fCheckbox3 = FAUSTFLOAT(0.0f);
		fCheckbox4 = FAUSTFLOAT(0.0f);
		fHslider11 = FAUSTFLOAT(0.0f);
		fCheckbox5 = FAUSTFLOAT(0.0f);
		fHslider12 = FAUSTFLOAT(1.0f);
		fCheckbox6 = FAUSTFLOAT(0.0f);
		fHslider13 = FAUSTFLOAT(1.0f);
		fCheckbox7 = FAUSTFLOAT(0.0f);
		fHslider14 = FAUSTFLOAT(1.0f);
		fCheckbox8 = FAUSTFLOAT(0.0f);
		fHslider15 = FAUSTFLOAT(1.0f);
		fHslider16 = FAUSTFLOAT(2.0f);
		fEntry1 = FAUSTFLOAT(4.4e+02f);
		fHslider17 = FAUSTFLOAT(0.01f);
		fHslider18 = FAUSTFLOAT(0.0f);
		fCheckbox9 = FAUSTFLOAT(0.0f);
		fHslider19 = FAUSTFLOAT(0.0f);
		fHslider20 = FAUSTFLOAT(0.0f);
		fHslider21 = FAUSTFLOAT(1.0f);
		fHslider22 = FAUSTFLOAT(2.0f);
		fHslider23 = FAUSTFLOAT(0.0f);
		fHslider24 = FAUSTFLOAT(1.0f);
		fHslider25 = FAUSTFLOAT(2.0f);
		fHslider26 = FAUSTFLOAT(1.0f);
		fCheckbox10 = FAUSTFLOAT(0.0f);
		fHslider27 = FAUSTFLOAT(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec3[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec5[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec7[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fVec2[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fVec3[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec13[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iRec14[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec15[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec16[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec17[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec18[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec19[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			iRec20[l17] = 0;
		}
		for (int l18 = 0; l18 < 4; l18 = l18 + 1) {
			fRec21[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec22[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec23[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec24[l21] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec27[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec28[l25] = 0.0f;
		}
		IOTA0 = 0;
		for (int l26 = 0; l26 < 131072; l26 = l26 + 1) {
			fVec5[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec29[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 65536; l28 = l28 + 1) {
			fVec6[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 65536; l29 = l29 + 1) {
			fVec7[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			iVec8[l30] = 0;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			iRec31[l31] = 0;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			iRec30[l32] = 0;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec32[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec34[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec33[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec25[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec36[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fVec9[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 4096; l39 = l39 + 1) {
			fVec10[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec35[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec37[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec40[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec39[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fRec42[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fVec11[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 4096; l46 = l46 + 1) {
			fVec12[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fRec41[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fRec43[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec45[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fRec47[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = l51 + 1) {
			fVec13[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 4096; l52 = l52 + 1) {
			fVec14[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			fRec46[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			fRec48[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			fRec8[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec9[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec10[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			fRec11[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			fRec1[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 4; l60 = l60 + 1) {
			fVec15[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 6; l61 = l61 + 1) {
			fRec0[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			fVec16[l62] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openHorizontalBox("faug");
		ui_interface->declare(&fButton0, "00", "");
		ui_interface->addButton("gate", &fButton0);
		ui_interface->declare(&fEntry0, "01", "");
		ui_interface->declare(&fEntry0, "unit", "Hz");
		ui_interface->addNumEntry("freq", &fEntry0, FAUSTFLOAT(4.4e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fEntry1, "02", "");
		ui_interface->declare(&fEntry1, "unit", "Hz");
		ui_interface->addNumEntry("prevFreq", &fEntry1, FAUSTFLOAT(4.4e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider18, "03", "");
		ui_interface->declare(&fHslider18, "style", "knob");
		ui_interface->addHorizontalSlider("pitchBend", &fHslider18, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2.5f), FAUSTFLOAT(2.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider17, "04", "");
		ui_interface->declare(&fHslider17, "style", "knob");
		ui_interface->addHorizontalSlider("glide", &fHslider17, FAUSTFLOAT(0.01f), FAUSTFLOAT(0.001f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fCheckbox9, "05", "");
		ui_interface->addCheckButton("glideOn", &fCheckbox9);
		ui_interface->declare(&fCheckbox7, "06", "");
		ui_interface->addCheckButton("oscOnePower", &fCheckbox7);
		ui_interface->declare(&fCheckbox6, "07", "");
		ui_interface->addCheckButton("oscTwoPower", &fCheckbox6);
		ui_interface->declare(&fCheckbox8, "08", "");
		ui_interface->addCheckButton("oscThreePower", &fCheckbox8);
		ui_interface->declare(&fHslider13, "09", "");
		ui_interface->declare(&fHslider13, "style", "knob");
		ui_interface->addHorizontalSlider("oscOneGain", &fHslider13, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider12, "10", "");
		ui_interface->declare(&fHslider12, "style", "knob");
		ui_interface->addHorizontalSlider("oscTwoGain", &fHslider12, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider14, "11", "");
		ui_interface->declare(&fHslider14, "style", "knob");
		ui_interface->addHorizontalSlider("oscThreeGain", &fHslider14, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider24, "13", "");
		ui_interface->declare(&fHslider24, "style", "knob");
		ui_interface->addHorizontalSlider("waveOne", &fHslider24, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider21, "14", "");
		ui_interface->declare(&fHslider21, "style", "knob");
		ui_interface->addHorizontalSlider("waveTwo", &fHslider21, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider15, "15", "");
		ui_interface->declare(&fHslider15, "style", "knob");
		ui_interface->addHorizontalSlider("waveThree", &fHslider15, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider25, "16", "");
		ui_interface->declare(&fHslider25, "style", "knob");
		ui_interface->addHorizontalSlider("rangeOne", &fHslider25, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider22, "17", "");
		ui_interface->declare(&fHslider22, "style", "knob");
		ui_interface->addHorizontalSlider("rangeTwo", &fHslider22, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider16, "18", "");
		ui_interface->declare(&fHslider16, "style", "knob");
		ui_interface->addHorizontalSlider("rangeThree", &fHslider16, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider19, "19", "");
		ui_interface->declare(&fHslider19, "style", "knob");
		ui_interface->addHorizontalSlider("globalDetune", &fHslider19, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2.5f), FAUSTFLOAT(2.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider23, "20", "");
		ui_interface->declare(&fHslider23, "style", "knob");
		ui_interface->addHorizontalSlider("detuneTwo", &fHslider23, FAUSTFLOAT(0.0f), FAUSTFLOAT(-7.5f), FAUSTFLOAT(7.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider20, "21", "");
		ui_interface->declare(&fHslider20, "style", "knob");
		ui_interface->addHorizontalSlider("detuneThree", &fHslider20, FAUSTFLOAT(0.0f), FAUSTFLOAT(-7.5f), FAUSTFLOAT(7.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox0, "22", "");
		ui_interface->addCheckButton("decayOn", &fCheckbox0);
		ui_interface->declare(&fHslider1, "23", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("attack", &fHslider1, FAUSTFLOAT(5e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "24", "");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("decay", &fHslider0, FAUSTFLOAT(5e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(2.4e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "25", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("sustain", &fHslider2, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider4, "26", "");
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->addHorizontalSlider("cutoff", &fHslider4, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fCheckbox2, "27", "");
		ui_interface->addCheckButton("keyTrackOne", &fCheckbox2);
		ui_interface->declare(&fCheckbox1, "28", "");
		ui_interface->addCheckButton("keyTrackTwo", &fCheckbox1);
		ui_interface->declare(&fHslider3, "29", "");
		ui_interface->declare(&fHslider3, "style", "radio{'+':0;'-':1}");
		ui_interface->addHorizontalSlider("contour_direction", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider8, "30", "");
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("contourAmount", &fHslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider6, "31", "");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->addHorizontalSlider("fAttack", &fHslider6, FAUSTFLOAT(5e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(7e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider5, "32", "");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("fDecay", &fHslider5, FAUSTFLOAT(5e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(3e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider7, "33", "");
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->addHorizontalSlider("fSustain", &fHslider7, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider9, "34", "");
		ui_interface->declare(&fHslider9, "style", "knob");
		ui_interface->addHorizontalSlider("emphasis", &fHslider9, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.707f), FAUSTFLOAT(25.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fCheckbox4, "35", "");
		ui_interface->addCheckButton("noiseType", &fCheckbox4);
		ui_interface->declare(&fCheckbox5, "36", "");
		ui_interface->addCheckButton("noiseOn", &fCheckbox5);
		ui_interface->declare(&fHslider11, "37", "");
		ui_interface->declare(&fHslider11, "style", "knob");
		ui_interface->addHorizontalSlider("noiseGain", &fHslider11, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider26, "44", "");
		ui_interface->declare(&fHslider26, "style", "knob");
		ui_interface->addHorizontalSlider("load", &fHslider26, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider10, "style", "knob");
		ui_interface->addHorizontalSlider("feedbackGain", &fHslider10, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addCheckButton("feedbackOn", &fCheckbox3);
		ui_interface->declare(&fVbargraph0, "style", "numerical");
		ui_interface->addVerticalBargraph("finalFreq", &fVbargraph0, FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f));
		ui_interface->declare(&fHslider27, "style", "knob");
		ui_interface->addHorizontalSlider("masterVolume", &fHslider27, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addCheckButton("on", &fCheckbox10);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		int iSlow0 = int(float(fCheckbox0));
		float fSlow1 = fConst4 * float(fHslider0);
		float fSlow2 = float(fButton0);
		int iSlow3 = fSlow2 == 0.0f;
		float fSlow4 = fConst4 * float(fHslider1);
		float fSlow5 = fConst2 * float(fHslider2);
		int iSlow6 = int(float(fHslider3));
		float fSlow7 = float(fEntry0);
		float fSlow8 = (fSlow7 + -130.81f) * (float(fCheckbox2) + 2.0f * float(fCheckbox1));
		float fSlow9 = 0.33333334f * fSlow8;
		float fSlow10 = float(fHslider4);
		float fThen2 = std::min<float>(16.0f * fSlow10, fConst5);
		float fElse2 = 0.0625f * fSlow10;
		float fSlow11 = ((iSlow6) ? fElse2 : fThen2);
		float fSlow12 = fSlow11 - fSlow9;
		float fSlow13 = fConst2 * float(fHslider5);
		int iSlow14 = fSlow9 == 0.0f;
		float fSlow15 = fConst2 * float(fHslider6);
		float fSlow16 = fConst2 * float(fHslider7);
		float fSlow17 = fConst2 * float(fHslider8);
		float fSlow18 = fSlow9 - fSlow11;
		float fSlow19 = fConst2 * float(fHslider9);
		float fSlow20 = float(fHslider10);
		float fSlow21 = float(fCheckbox3);
		float fSlow22 = fSlow21 * fSlow20;
		int iSlow23 = int(float(fCheckbox4));
		float fSlow24 = float(fCheckbox5) * float(fHslider11);
		float fSlow25 = fConst2 * float(fHslider12);
		float fSlow26 = float(fCheckbox6);
		float fSlow27 = fConst2 * float(fHslider13);
		float fSlow28 = float(fCheckbox7);
		float fSlow29 = fConst2 * float(fHslider14);
		float fSlow30 = float(fCheckbox8);
		float fSlow31 = float(fHslider15);
		int iSlow32 = fSlow31 >= 3.0f;
		int iSlow33 = fSlow31 >= 2.0f;
		int iSlow34 = fSlow31 >= 1.0f;
		float fSlow35 = float(fHslider16);
		int iSlow36 = int(fSlow35);
		float fSlow37 = float(fEntry1);
		float fSlow38 = float(fHslider17);
		float fElse6 = 0.5555556f * fSlow38;
		float fSlow39 = ((fSlow7 > fSlow37) ? fElse6 : fSlow38);
		float fSlow40 = fConst2 * std::pow(2.0f, 0.083333336f * float(fHslider18));
		float fSlow41 = ((int(float(fCheckbox9))) ? fSlow37 : fSlow7);
		float fSlow42 = fConst2 * std::pow(2.0f, 0.083333336f * float(fHslider19));
		float fSlow43 = std::pow(2.0f, 0.083333336f * float(fHslider20));
		float fSlow44 = std::pow(2.0f, fSlow35 + -4.0f);
		int iSlow45 = fSlow31 >= 5.0f;
		int iSlow46 = fSlow31 >= 4.0f;
		float fSlow47 = float(fHslider21);
		int iSlow48 = fSlow47 >= 3.0f;
		int iSlow49 = fSlow47 >= 2.0f;
		int iSlow50 = fSlow47 >= 1.0f;
		float fSlow51 = float(fHslider22);
		int iSlow52 = int(fSlow51);
		float fSlow53 = std::pow(2.0f, 0.083333336f * float(fHslider23));
		float fSlow54 = std::pow(2.0f, fSlow51 + -4.0f);
		int iSlow55 = fSlow47 >= 5.0f;
		int iSlow56 = fSlow47 >= 4.0f;
		float fSlow57 = float(fHslider24);
		int iSlow58 = fSlow57 >= 3.0f;
		int iSlow59 = fSlow57 >= 2.0f;
		int iSlow60 = fSlow57 >= 1.0f;
		float fSlow61 = float(fHslider25);
		int iSlow62 = int(fSlow61);
		float fSlow63 = std::pow(2.0f, fSlow61 + -4.0f);
		int iSlow64 = fSlow57 >= 5.0f;
		int iSlow65 = fSlow57 >= 4.0f;
		float fSlow66 = float(fHslider26);
		int iSlow67 = int(fSlow21);
		float fSlow68 = 1.0f - fSlow20;
		float fSlow69 = ((int(float(fCheckbox10))) ? 0.0f : 1.0f);
		float fSlow70 = float(fHslider27);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fRec2[0] = fSlow1 + fConst3 * fRec2[1];
			fVec1[0] = fSlow2;
			iRec3[0] = iSlow3 * (iRec3[1] + 1);
			fRec4[0] = fSlow4 + fConst3 * fRec4[1];
			float fTemp0 = std::max<float>(1.0f, fConst0 * fRec4[0]);
			fRec5[0] = fSlow2 + fRec5[1] * float(fVec1[1] >= fSlow2);
			fRec6[0] = fSlow5 + fConst3 * fRec6[1];
			float fTemp1 = std::max<float>(0.0f, std::min<float>(fRec5[0] / fTemp0, std::max<float>((1.0f - fRec6[0]) * (fTemp0 - fRec5[0]) / std::max<float>(1.0f, fConst0 * fRec2[0]) + 1.0f, fRec6[0])) * (1.0f - float(iRec3[0]) / std::max<float>(1.0f, fConst0 * ((iSlow0) ? fRec2[0] : 0.01f))));
			fRec7[0] = fConst2 * fTemp1 + fConst3 * fRec7[1];
			fVec2[0] = fSlow7;
			fVec3[0] = fSlow8;
			fRec13[0] = fSlow13 + fConst3 * fRec13[1];
			iRec14[0] = iSlow14 * (iRec14[1] + 1);
			fRec15[0] = fSlow15 + fConst3 * fRec15[1];
			float fTemp2 = std::max<float>(1.0f, fConst0 * fRec15[0]);
			fRec16[0] = fSlow9 + fRec16[1] * float((0.33333334f * fVec3[1]) >= fSlow9);
			fRec17[0] = fSlow16 + fConst3 * fRec17[1];
			fRec18[0] = fSlow17 + fConst3 * fRec18[1];
			float fTemp3 = fRec18[0] * std::max<float>(0.0f, std::min<float>(fRec16[0] / fTemp2, std::max<float>((1.0f - fRec17[0]) * (fTemp2 - fRec16[0]) / std::max<float>(1.0f, fConst0 * fRec13[0]) + 1.0f, fRec17[0])) * (1.0f - float(iRec14[0]) / std::max<float>(1.0f, fConst0 * ((iSlow0) ? fRec13[0] : 1e+01f))));
			float fThen4 = fSlow9 + fTemp3 * fSlow12;
			float fElse4 = fSlow9 - fTemp3 * fSlow18;
			float fTemp4 = std::tan(1.5707964f * std::min<float>(std::max<float>(fSlow10 + fConst1 * ((iSlow6) ? fElse4 : fThen4), 0.0f), 1.0f));
			float fTemp5 = fTemp4 + 1.0f;
			fRec19[0] = fSlow19 + fConst3 * fRec19[1];
			float fTemp6 = fRec19[0] + -0.707f;
			iRec20[0] = 1103515245 * iRec20[1] + 12345;
			float fTemp7 = 4.656613e-10f * float(iRec20[0]);
			fRec21[0] = 0.5221894f * fRec21[3] + fTemp7 + 2.494956f * fRec21[1] - 2.0172658f * fRec21[2];
			float fElse5 = 0.049922034f * fRec21[0] + 0.0506127f * fRec21[2] - (0.095993534f * fRec21[1] + 0.004408786f * fRec21[3]);
			fRec22[0] = fSlow25 + fConst3 * fRec22[1];
			fRec23[0] = fSlow27 + fConst3 * fRec23[1];
			fRec24[0] = fSlow29 + fConst3 * fRec24[1];
			fRec27[0] = fConst6 + (fRec27[1] - std::floor(fConst6 + fRec27[1]));
			fRec28[0] = fConst7 + (fRec28[1] - std::floor(fConst7 + fRec28[1]));
			fVec5[IOTA0 & 131071] = ftbl0mydspSIG0[int(65536.0f * fRec28[0])];
			fRec29[0] = fConst9 + (fRec29[1] - std::floor(fConst9 + fRec29[1]));
			fVec6[IOTA0 & 65535] = 0.005f * ftbl0mydspSIG0[int(65536.0f * fRec29[0])] + 0.01f * fVec5[(IOTA0 - iConst8) & 131071];
			float fTemp8 = fVec6[(IOTA0 - iConst10) & 65535];
			fVec7[IOTA0 & 65535] = fTemp8 + 0.0025f * ftbl0mydspSIG0[int(65536.0f * fRec27[0])];
			int iTemp9 = fSlow7 != fVec2[1];
			iVec8[0] = iTemp9;
			int iTemp10 = (iVec8[1] <= 0) & (iTemp9 > 0);
			iRec31[0] = iRec31[1] + 1;
			iRec30[0] = iRec30[1] * (1 - iTemp10) + (iRec31[0] + -1) * iTemp10;
			float fTemp11 = std::max<float>(std::exp(fConst1 * (float(-1 * (iRec31[0] + (-1 - iRec30[0]))) / fSlow39)), 0.01f);
			fRec32[0] = fSlow40 + fConst3 * fRec32[1];
			float fTemp12 = fSlow41 * fTemp11 + fRec32[0] + fSlow7 * (1.0f - fTemp11);
			fVbargraph0 = FAUSTFLOAT(fTemp12);
			float fTemp13 = fTemp12;
			fRec34[0] = fSlow42 + fConst3 * fRec34[1];
			fRec33[0] = fConst2 * (fSlow43 + fRec34[0]) + fConst3 * fRec33[1];
			float fTemp14 = fSlow44 * fRec33[0] * fTemp13 + fVec7[(IOTA0 - iConst11) & 65535];
			float fTemp15 = fRec25[1] + fConst1 * fTemp14;
			fRec25[0] = fTemp15 - std::floor(fTemp15);
			float fTemp16 = 2.0f * fRec25[0] + -1.0f;
			float fTemp17 = std::max<float>(fTemp14, 23.44895f);
			float fTemp18 = std::max<float>(2e+01f, std::fabs(fTemp17));
			float fTemp19 = fRec36[1] + fConst1 * fTemp18;
			fRec36[0] = fTemp19 - std::floor(fTemp19);
			float fTemp20 = mydsp_faustpower2_f(2.0f * fRec36[0] + -1.0f);
			fVec9[0] = fTemp20;
			float fTemp21 = float(iVec0[1]);
			float fTemp22 = fTemp21 * (fTemp20 - fVec9[1]) / fTemp18;
			fVec10[IOTA0 & 4095] = fTemp22;
			float fTemp23 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst5 / fTemp17));
			int iTemp24 = int(fTemp23);
			float fTemp25 = std::floor(fTemp23);
			float fTemp26 = fConst12 * (fTemp22 - fVec10[(IOTA0 - iTemp24) & 4095] * (fTemp25 + (1.0f - fTemp23)) - (fTemp23 - fTemp25) * fVec10[(IOTA0 - (iTemp24 + 1)) & 4095]);
			fRec35[0] = 0.999f * fRec35[1] + fTemp26;
			float fThen8 = 2.0f * (1.0f - std::fabs(fTemp16)) + -1.0f;
			float fElse8 = fConst13 * fRec35[0] * fTemp14;
			float fTemp27 = std::max<float>(1.1920929e-07f, std::fabs(fTemp14));
			float fTemp28 = fRec37[1] + fConst1 * fTemp27;
			float fTemp29 = fTemp28 + -1.0f;
			int iTemp30 = fTemp29 < 0.0f;
			fRec37[0] = ((iTemp30) ? fTemp28 : fTemp29);
			float fThen10 = fTemp28 + fTemp29 * (1.0f - fConst0 / fTemp27);
			float fRec38 = ((iTemp30) ? fTemp28 : fThen10);
			float fElse11 = 2.0f * fRec38 + -1.0f;
			float fTemp31 = ((iSlow36) ? fElse11 : fTemp16);
			float fThen12 = ((iSlow36) ? fElse8 : fThen8);
			float fThen13 = ((iSlow34) ? fTemp31 : fThen12);
			float fElse13 = 0.0f - fTemp31;
			float fThen14 = 2.0f * float(fRec25[0] <= 0.5f) + -1.0f;
			float fTemp32 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst14 / fTemp17));
			int iTemp33 = int(fTemp32);
			float fTemp34 = std::floor(fTemp32);
			float fThen15 = 2.0f * float(fRec25[0] <= 0.7f) + -1.0f;
			float fElse15 = fConst12 * (fTemp22 - fVec10[(IOTA0 - iTemp33) & 4095] * (fTemp34 + (1.0f - fTemp32)) - (fTemp32 - fTemp34) * fVec10[(IOTA0 - (iTemp33 + 1)) & 4095]);
			float fThen16 = ((iSlow36) ? fTemp26 : fThen14);
			float fElse16 = ((iSlow36) ? fElse15 : fThen15);
			float fTemp35 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst15 / fTemp17));
			int iTemp36 = int(fTemp35);
			float fTemp37 = std::floor(fTemp35);
			float fThen17 = 2.0f * float(fRec25[0] <= 0.85f) + -1.0f;
			float fElse17 = fConst12 * (fTemp22 - fVec10[(IOTA0 - iTemp36) & 4095] * (fTemp37 + (1.0f - fTemp35)) - (fTemp35 - fTemp37) * fVec10[(IOTA0 - (iTemp36 + 1)) & 4095]);
			float fThen18 = ((iSlow46) ? fElse16 : fThen16);
			float fElse18 = ((iSlow36) ? fElse17 : fThen17);
			float fThen19 = ((iSlow33) ? fElse13 : fThen13);
			float fElse19 = ((iSlow45) ? fElse18 : fThen18);
			fRec40[0] = fConst2 * (fSlow53 + fRec34[0]) + fConst3 * fRec40[1];
			float fTemp38 = fSlow54 * fRec40[0] * fTemp13 + fTemp8;
			float fTemp39 = fRec39[1] + fConst1 * fTemp38;
			fRec39[0] = fTemp39 - std::floor(fTemp39);
			float fTemp40 = 2.0f * fRec39[0] + -1.0f;
			float fTemp41 = std::max<float>(fTemp38, 23.44895f);
			float fTemp42 = std::max<float>(2e+01f, std::fabs(fTemp41));
			float fTemp43 = fRec42[1] + fConst1 * fTemp42;
			fRec42[0] = fTemp43 - std::floor(fTemp43);
			float fTemp44 = mydsp_faustpower2_f(2.0f * fRec42[0] + -1.0f);
			fVec11[0] = fTemp44;
			float fTemp45 = fTemp21 * (fTemp44 - fVec11[1]) / fTemp42;
			fVec12[IOTA0 & 4095] = fTemp45;
			float fTemp46 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst5 / fTemp41));
			int iTemp47 = int(fTemp46);
			float fTemp48 = std::floor(fTemp46);
			float fTemp49 = fConst12 * (fTemp45 - fVec12[(IOTA0 - iTemp47) & 4095] * (fTemp48 + (1.0f - fTemp46)) - (fTemp46 - fTemp48) * fVec12[(IOTA0 - (iTemp47 + 1)) & 4095]);
			fRec41[0] = 0.999f * fRec41[1] + fTemp49;
			float fThen20 = 2.0f * (1.0f - std::fabs(fTemp40)) + -1.0f;
			float fElse20 = fConst13 * fRec41[0] * fTemp38;
			float fTemp50 = ((iSlow52) ? fElse20 : fThen20);
			float fTemp51 = std::max<float>(1.1920929e-07f, std::fabs(fTemp38));
			float fTemp52 = fRec43[1] + fConst1 * fTemp51;
			float fTemp53 = fTemp52 + -1.0f;
			int iTemp54 = fTemp53 < 0.0f;
			fRec43[0] = ((iTemp54) ? fTemp52 : fTemp53);
			float fThen22 = fTemp52 + fTemp53 * (1.0f - fConst0 / fTemp51);
			float fRec44 = ((iTemp54) ? fTemp52 : fThen22);
			float fElse23 = 2.0f * fRec44 + -1.0f;
			float fTemp55 = ((iSlow52) ? fElse23 : fTemp40);
			float fThen25 = ((iSlow50) ? fTemp55 : fTemp50);
			float fElse25 = 0.5f * (fTemp50 + fTemp55);
			float fThen26 = 2.0f * float(fRec39[0] <= 0.5f) + -1.0f;
			float fTemp56 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst14 / fTemp41));
			int iTemp57 = int(fTemp56);
			float fTemp58 = std::floor(fTemp56);
			float fThen27 = 2.0f * float(fRec39[0] <= 0.7f) + -1.0f;
			float fElse27 = fConst12 * (fTemp45 - fVec12[(IOTA0 - iTemp57) & 4095] * (fTemp58 + (1.0f - fTemp56)) - (fTemp56 - fTemp58) * fVec12[(IOTA0 - (iTemp57 + 1)) & 4095]);
			float fThen28 = ((iSlow52) ? fTemp49 : fThen26);
			float fElse28 = ((iSlow52) ? fElse27 : fThen27);
			float fTemp59 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst15 / fTemp41));
			int iTemp60 = int(fTemp59);
			float fTemp61 = std::floor(fTemp59);
			float fThen29 = 2.0f * float(fRec39[0] <= 0.85f) + -1.0f;
			float fElse29 = fConst12 * (fTemp45 - fVec12[(IOTA0 - iTemp60) & 4095] * (fTemp61 + (1.0f - fTemp59)) - (fTemp59 - fTemp61) * fVec12[(IOTA0 - (iTemp60 + 1)) & 4095]);
			float fThen30 = ((iSlow56) ? fElse28 : fThen28);
			float fElse30 = ((iSlow52) ? fElse29 : fThen29);
			float fThen31 = ((iSlow49) ? fElse25 : fThen25);
			float fElse31 = ((iSlow55) ? fElse30 : fThen30);
			float fTemp62 = ((iSlow48) ? fElse31 : fThen31);
			float fTemp63 = fSlow63 * fRec34[0] * fTemp13 + 0.01f * fTemp62;
			float fTemp64 = fRec45[1] + fConst1 * fTemp63;
			fRec45[0] = fTemp64 - std::floor(fTemp64);
			float fTemp65 = 2.0f * fRec45[0] + -1.0f;
			float fTemp66 = std::max<float>(fTemp63, 23.44895f);
			float fTemp67 = std::max<float>(2e+01f, std::fabs(fTemp66));
			float fTemp68 = fRec47[1] + fConst1 * fTemp67;
			fRec47[0] = fTemp68 - std::floor(fTemp68);
			float fTemp69 = mydsp_faustpower2_f(2.0f * fRec47[0] + -1.0f);
			fVec13[0] = fTemp69;
			float fTemp70 = fTemp21 * (fTemp69 - fVec13[1]) / fTemp67;
			fVec14[IOTA0 & 4095] = fTemp70;
			float fTemp71 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst5 / fTemp66));
			int iTemp72 = int(fTemp71);
			float fTemp73 = std::floor(fTemp71);
			float fTemp74 = fConst12 * (fTemp70 - fVec14[(IOTA0 - iTemp72) & 4095] * (fTemp73 + (1.0f - fTemp71)) - (fTemp71 - fTemp73) * fVec14[(IOTA0 - (iTemp72 + 1)) & 4095]);
			fRec46[0] = 0.999f * fRec46[1] + fTemp74;
			float fThen32 = 2.0f * (1.0f - std::fabs(fTemp65)) + -1.0f;
			float fElse32 = fConst13 * fRec46[0] * fTemp63;
			float fTemp75 = ((iSlow62) ? fElse32 : fThen32);
			float fTemp76 = std::max<float>(1.1920929e-07f, std::fabs(fTemp63));
			float fTemp77 = fRec48[1] + fConst1 * fTemp76;
			float fTemp78 = fTemp77 + -1.0f;
			int iTemp79 = fTemp78 < 0.0f;
			fRec48[0] = ((iTemp79) ? fTemp77 : fTemp78);
			float fThen34 = fTemp77 + fTemp78 * (1.0f - fConst0 / fTemp76);
			float fRec49 = ((iTemp79) ? fTemp77 : fThen34);
			float fElse35 = 2.0f * fRec49 + -1.0f;
			float fTemp80 = ((iSlow62) ? fElse35 : fTemp65);
			float fThen37 = ((iSlow60) ? fTemp80 : fTemp75);
			float fElse37 = 0.5f * (fTemp75 + fTemp80);
			float fThen38 = 2.0f * float(fRec45[0] <= 0.5f) + -1.0f;
			float fTemp81 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst14 / fTemp66));
			int iTemp82 = int(fTemp81);
			float fTemp83 = std::floor(fTemp81);
			float fThen39 = 2.0f * float(fRec45[0] <= 0.7f) + -1.0f;
			float fElse39 = fConst12 * (fTemp70 - fVec14[(IOTA0 - iTemp82) & 4095] * (fTemp83 + (1.0f - fTemp81)) - (fTemp81 - fTemp83) * fVec14[(IOTA0 - (iTemp82 + 1)) & 4095]);
			float fThen40 = ((iSlow62) ? fTemp74 : fThen38);
			float fElse40 = ((iSlow62) ? fElse39 : fThen39);
			float fTemp84 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst15 / fTemp66));
			int iTemp85 = int(fTemp84);
			float fTemp86 = std::floor(fTemp84);
			float fThen41 = 2.0f * float(fRec45[0] <= 0.85f) + -1.0f;
			float fElse41 = fConst12 * (fTemp70 - fVec14[(IOTA0 - iTemp85) & 4095] * (fTemp86 + (1.0f - fTemp84)) - (fTemp84 - fTemp86) * fVec14[(IOTA0 - (iTemp85 + 1)) & 4095]);
			float fThen42 = ((iSlow65) ? fElse40 : fThen40);
			float fElse42 = ((iSlow62) ? fElse41 : fThen41);
			float fThen43 = ((iSlow59) ? fElse37 : fThen37);
			float fElse43 = ((iSlow64) ? fElse42 : fThen42);
			float fTemp87 = fTemp4 * ((fSlow66 * ((fSlow28 * fRec23[0] * ((iSlow58) ? fElse43 : fThen43) + fSlow26 * fRec22[0] * fTemp62 + fSlow30 * fRec24[0] * ((iSlow32) ? fElse19 : fThen19)) / std::max<float>(1.0f, 0.8f * (fSlow30 * fRec24[0] + fSlow28 * fRec23[0] + fSlow26 * fRec22[0])) + fSlow24 * ((iSlow23) ? fElse5 : fTemp7)) + fSlow22 * fRec1[1] - 0.16465649f * fTemp6 * (1.0f - fTemp4 / fTemp5) * (fRec11[1] + fTemp4 * (fRec10[1] + fTemp4 * (fRec9[1] + fTemp4 * fRec8[1] / fTemp5) / fTemp5) / fTemp5)) / (0.16465649f * (mydsp_faustpower4_f(fTemp4) * fTemp6 / mydsp_faustpower4_f(fTemp5)) + 1.0f) - fRec8[1]) / fTemp5;
			fRec8[0] = fRec8[1] + 2.0f * fTemp87;
			float fTemp88 = fTemp4 * (fRec8[1] + fTemp87 - fRec9[1]) / fTemp5;
			fRec9[0] = fRec9[1] + 2.0f * fTemp88;
			float fTemp89 = fTemp4 * (fRec9[1] + fTemp88 - fRec10[1]) / fTemp5;
			fRec10[0] = fRec10[1] + 2.0f * fTemp89;
			float fTemp90 = fTemp4 * (fRec10[1] + fTemp89 - fRec11[1]) / fTemp5;
			fRec11[0] = fRec11[1] + 2.0f * fTemp90;
			float fRec12 = fRec11[1] + fTemp90;
			fRec1[0] = fRec12 * ((iSlow0) ? fRec7[0] : fTemp1);
			float fTemp91 = fSlow22 * fRec1[0];
			fVec15[0] = fTemp91;
			fRec0[0] = 0.0f - (0.1f * (fRec0[4] - fVec15[1]) + 0.5f * (fRec0[5] - fVec15[3]));
			float fTemp92 = fRec0[0] - fRec0[1];
			float fThen44 = (std::log(std::min<float>(3.4028235e+38f, coshf(fRec0[0]))) - std::log(std::min<float>(3.4028235e+38f, coshf(fRec0[1])))) / fTemp92;
			float fElse44 = tanhf(0.5f * (fRec0[0] + fRec0[1]));
			float fElse45 = fSlow68 * fRec1[0];
			float fTemp93 = ((iSlow67) ? fElse45 : fRec1[0]);
			fVec16[0] = fTemp93;
			float fTemp94 = fTemp93 - fVec16[1];
			float fThen46 = (std::log(std::min<float>(3.4028235e+38f, coshf(fTemp93))) - std::log(std::min<float>(3.4028235e+38f, coshf(fVec16[1])))) / fTemp94;
			float fElse46 = tanhf(0.5f * (fTemp93 + fVec16[1]));
			float fTemp95 = fSlow70 * fSlow69 * (((std::fabs(fTemp94) <= fConst1) ? fElse46 : fThen46) + ((std::fabs(fTemp92) <= fConst1) ? fElse44 : fThen44));
			output0[i0] = FAUSTFLOAT(fTemp95);
			output1[i0] = FAUSTFLOAT(fTemp95);
			iVec0[1] = iVec0[0];
			fRec2[1] = fRec2[0];
			fVec1[1] = fVec1[0];
			iRec3[1] = iRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fVec2[1] = fVec2[0];
			fVec3[1] = fVec3[0];
			fRec13[1] = fRec13[0];
			iRec14[1] = iRec14[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec18[1] = fRec18[0];
			fRec19[1] = fRec19[0];
			iRec20[1] = iRec20[0];
			for (int j0 = 3; j0 > 0; j0 = j0 - 1) {
				fRec21[j0] = fRec21[j0 - 1];
			}
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			fRec24[1] = fRec24[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			IOTA0 = IOTA0 + 1;
			fRec29[1] = fRec29[0];
			iVec8[1] = iVec8[0];
			iRec31[1] = iRec31[0];
			iRec30[1] = iRec30[0];
			fRec32[1] = fRec32[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec25[1] = fRec25[0];
			fRec36[1] = fRec36[0];
			fVec9[1] = fVec9[0];
			fRec35[1] = fRec35[0];
			fRec37[1] = fRec37[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec42[1] = fRec42[0];
			fVec11[1] = fVec11[0];
			fRec41[1] = fRec41[0];
			fRec43[1] = fRec43[0];
			fRec45[1] = fRec45[0];
			fRec47[1] = fRec47[0];
			fVec13[1] = fVec13[0];
			fRec46[1] = fRec46[0];
			fRec48[1] = fRec48[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec1[1] = fRec1[0];
			for (int j1 = 3; j1 > 0; j1 = j1 - 1) {
				fVec15[j1] = fVec15[j1 - 1];
			}
			for (int j2 = 5; j2 > 0; j2 = j2 - 1) {
				fRec0[j2] = fRec0[j2 - 1];
			}
			fVec16[1] = fVec16[0];
		}
	}

};

#endif
