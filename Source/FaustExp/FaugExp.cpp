/* ------------------------------------------------------------
name: "Faug"
Code generated with Faust 2.53.2 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -mcd 16 -single -ftz 0 -vec -lv 0 -vs 8 -g
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include "./FaustIncludes.h"

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
	
	int iVec3[2];
	int iRec13[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			iVec3[l10] = 0;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iRec13[l11] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec3[0] = 1;
			iRec13[0] = (iVec3[1] + iRec13[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec13[0]));
			iVec3[1] = iVec3[0];
			iRec13[1] = iRec13[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float ftbl0mydspSIG0[65536];
static float mydsp_faustpower2_f(float value) {
	return value * value;
}
static float mydsp_faustpower4_f(float value) {
	return value * value * value * value;
}

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fButton0;
	float fVec0_perm[4];
	float fRec6_perm[4];
	int iVec1_perm[4];
	int iRec7_perm[4];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	float fConst3;
	FAUSTFLOAT fHslider2;
	float fRec8_perm[4];
	int iRec10_perm[4];
	FAUSTFLOAT fEntry0;
	float fVec2_perm[4];
	int iYec0_perm[4];
	int iRec11_perm[4];
	float fConst4;
	float fRec12_perm[4];
	float fYec1[8192];
	int fYec1_idx;
	int fYec1_idx_save;
	int iConst5;
	int iConst6;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fHslider3;
	float fConst7;
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT fEntry1;
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fRec9_perm[4];
	float fRec15_perm[4];
	float fYec2_perm[4];
	float fYec3[4096];
	int fYec3_idx;
	int fYec3_idx_save;
	float fConst8;
	float fConst9;
	float fRec14_perm[4];
	float fRec16_perm[4];
	int iRec19_perm[4];
	float fYec4_perm[4];
	float fRec18_perm[4];
	float fConst11;
	float fConst16;
	float fConst17;
	float fConst18;
	float fRec22_perm[4];
	float fConst21;
	float fConst22;
	float fConst23;
	float fConst26;
	float fConst27;
	float fRec21_perm[4];
	float fConst30;
	float fConst31;
	float fConst32;
	float fConst35;
	float fConst36;
	float fRec20_perm[4];
	FAUSTFLOAT fHslider8;
	float fRec23_perm[4];
	FAUSTFLOAT fCheckbox3;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fCheckbox4;
	FAUSTFLOAT fCheckbox5;
	float fConst37;
	FAUSTFLOAT fCheckbox6;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fCheckbox7;
	FAUSTFLOAT fHslider11;
	float fConst38;
	float fConst39;
	float fConst40;
	FAUSTFLOAT fHslider12;
	float fRec24_perm[4];
	float fRec26_perm[4];
	float fYec5_perm[4];
	float fYec6[4096];
	int fYec6_idx;
	int fYec6_idx_save;
	float fRec25_perm[4];
	float fRec27_perm[4];
	int iConst41;
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	float fRec29_perm[4];
	float fRec31_perm[4];
	float fYec7_perm[4];
	float fYec8[4096];
	int fYec8_idx;
	int fYec8_idx_save;
	float fRec30_perm[4];
	float fRec32_perm[4];
	FAUSTFLOAT fCheckbox8;
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fCheckbox9;
	FAUSTFLOAT fCheckbox10;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fCheckbox11;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fCheckbox12;
	FAUSTFLOAT fCheckbox13;
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	FAUSTFLOAT fCheckbox14;
	FAUSTFLOAT fHslider23;
	FAUSTFLOAT fHslider24;
	FAUSTFLOAT fCheckbox15;
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fHslider26;
	float fRec1_perm[4];
	float fRec2_perm[4];
	float fRec3_perm[4];
	float fRec4_perm[4];
	FAUSTFLOAT fHslider27;
	FAUSTFLOAT fHslider28;
	FAUSTFLOAT fHslider29;
	float fRec34_perm[4];
	float fRec0_perm[4];
	FAUSTFLOAT fCheckbox16;
	FAUSTFLOAT fHslider30;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("aanl.lib/name", "Faust Antialiased Nonlinearities");
		m->declare("aanl.lib/version", "0.3");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.8");
		m->declare("compile_options", "-lang cpp -es 1 -mcd 16 -single -ftz 0 -vec -lv 0 -vs 8 -g");
		m->declare("envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.2");
		m->declare("filename", "Faug.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/spectral_tilt:author", "Julius O. Smith III");
		m->declare("filters.lib/spectral_tilt:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/spectral_tilt:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "Faug");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.4");
		m->declare("oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators.lib/lf_sawpos:licence", "STK-4.3");
		m->declare("oscillators.lib/lf_triangle:author", "Bart Brouns");
		m->declare("oscillators.lib/lf_triangle:licence", "STK-4.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/saw1:author", "Bart Brouns");
		m->declare("oscillators.lib/saw1:licence", "STK-4.3");
		m->declare("oscillators.lib/version", "0.3");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.3");
		m->declare("vaeffects.lib/moogLadder:author", "Dario Sanfilippo");
		m->declare("vaeffects.lib/moogLadder:license", "MIT-style STK-4.3 license");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/version", "0.2");
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
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 0.001f * fConst0;
		fConst4 = 0.05f / fConst0;
		iConst5 = int(0.01f * fConst0);
		iConst6 = 3 * iConst5;
		fConst7 = 1.0f / fConst0;
		fConst8 = 0.5f * fConst0;
		fConst9 = 0.25f * fConst0;
		float fConst10 = 1.0f / std::tan(0.5f / fConst0);
		fConst11 = 125.663704f - fConst10;
		float fConst12 = std::tan(62.831852f / fConst0);
		float fConst13 = std::sqrt(0.0175f * fConst0);
		float fConst14 = std::tan(62.831852f * (std::sqrt(std::sqrt(fConst13)) / fConst0));
		float fConst15 = 125.663704f * (fConst14 / fConst12);
		fConst16 = fConst15 - fConst10;
		fConst17 = fConst10 + fConst15;
		fConst18 = 1.0f / (fConst10 + 125.663704f);
		float fConst19 = std::tan(62.831852f * (std::pow(fConst13, 1.25f) / fConst0));
		float fConst20 = 125.663704f * (fConst19 / fConst12);
		fConst21 = fConst20 - fConst10;
		fConst22 = fConst10 + fConst20;
		fConst23 = fConst12 / fConst14;
		float fConst24 = std::tan(62.831852f * (fConst13 / fConst0));
		float fConst25 = 125.663704f * (fConst24 / fConst12);
		fConst26 = fConst25 - fConst10;
		fConst27 = 1.0f / (fConst10 + fConst25);
		float fConst28 = std::tan(62.831852f * (std::pow(fConst13, 2.25f) / fConst0));
		float fConst29 = 125.663704f * (fConst28 / fConst12);
		fConst30 = fConst29 - fConst10;
		fConst31 = fConst10 + fConst29;
		fConst32 = fConst24 / fConst19;
		float fConst33 = std::tan(62.831852f * (mydsp_faustpower2_f(fConst13) / fConst0));
		float fConst34 = 125.663704f * (fConst33 / fConst12);
		fConst35 = fConst34 - fConst10;
		fConst36 = 1.0f / (fConst10 + fConst34);
		fConst37 = fConst33 / fConst28;
		fConst38 = 4.0f / fConst0;
		fConst39 = 0.7f * fConst0;
		fConst40 = 0.85f * fConst0;
		iConst41 = 2 * iConst5;
	}
	
	virtual void instanceResetUserInterface() {
		fButton0 = FAUSTFLOAT(0.0f);
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(4.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(0.8f);
		fEntry0 = FAUSTFLOAT(4.4e+02f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.01f);
		fCheckbox2 = FAUSTFLOAT(0.0f);
		fEntry1 = FAUSTFLOAT(4.4e+02f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(0.0f);
		fHslider7 = FAUSTFLOAT(2.0f);
		fHslider8 = FAUSTFLOAT(1e+01f);
		fCheckbox3 = FAUSTFLOAT(0.0f);
		fHslider9 = FAUSTFLOAT(2.0f);
		fCheckbox4 = FAUSTFLOAT(0.0f);
		fCheckbox5 = FAUSTFLOAT(0.0f);
		fCheckbox6 = FAUSTFLOAT(0.0f);
		fHslider10 = FAUSTFLOAT(0.0f);
		fCheckbox7 = FAUSTFLOAT(0.0f);
		fHslider11 = FAUSTFLOAT(1.0f);
		fHslider12 = FAUSTFLOAT(0.0f);
		fHslider13 = FAUSTFLOAT(0.0f);
		fHslider14 = FAUSTFLOAT(2.0f);
		fCheckbox8 = FAUSTFLOAT(0.0f);
		fHslider15 = FAUSTFLOAT(0.0f);
		fCheckbox9 = FAUSTFLOAT(0.0f);
		fCheckbox10 = FAUSTFLOAT(0.0f);
		fHslider16 = FAUSTFLOAT(0.5f);
		fHslider17 = FAUSTFLOAT(0.0f);
		fHslider18 = FAUSTFLOAT(1.0f);
		fHslider19 = FAUSTFLOAT(0.0f);
		fCheckbox11 = FAUSTFLOAT(0.0f);
		fHslider20 = FAUSTFLOAT(0.0f);
		fCheckbox12 = FAUSTFLOAT(0.0f);
		fCheckbox13 = FAUSTFLOAT(0.0f);
		fHslider21 = FAUSTFLOAT(1.0f);
		fHslider22 = FAUSTFLOAT(1.0f);
		fCheckbox14 = FAUSTFLOAT(0.0f);
		fHslider23 = FAUSTFLOAT(1.0f);
		fHslider24 = FAUSTFLOAT(1.0f);
		fCheckbox15 = FAUSTFLOAT(0.0f);
		fHslider25 = FAUSTFLOAT(1.0f);
		fHslider26 = FAUSTFLOAT(1.0f);
		fHslider27 = FAUSTFLOAT(4.0f);
		fHslider28 = FAUSTFLOAT(1.0f);
		fHslider29 = FAUSTFLOAT(0.8f);
		fCheckbox16 = FAUSTFLOAT(0.0f);
		fHslider30 = FAUSTFLOAT(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 4; l0 = l0 + 1) {
			fVec0_perm[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 4; l1 = l1 + 1) {
			fRec6_perm[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 4; l2 = l2 + 1) {
			iVec1_perm[l2] = 0;
		}
		for (int l3 = 0; l3 < 4; l3 = l3 + 1) {
			iRec7_perm[l3] = 0;
		}
		for (int l4 = 0; l4 < 4; l4 = l4 + 1) {
			fRec8_perm[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 4; l5 = l5 + 1) {
			iRec10_perm[l5] = 0;
		}
		for (int l6 = 0; l6 < 4; l6 = l6 + 1) {
			fVec2_perm[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 4; l7 = l7 + 1) {
			iYec0_perm[l7] = 0;
		}
		for (int l8 = 0; l8 < 4; l8 = l8 + 1) {
			iRec11_perm[l8] = 0;
		}
		for (int l9 = 0; l9 < 4; l9 = l9 + 1) {
			fRec12_perm[l9] = 0.0f;
		}
		for (int l12 = 0; l12 < 8192; l12 = l12 + 1) {
			fYec1[l12] = 0.0f;
		}
		fYec1_idx = 0;
		fYec1_idx_save = 0;
		for (int l13 = 0; l13 < 4; l13 = l13 + 1) {
			fRec9_perm[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 4; l14 = l14 + 1) {
			fRec15_perm[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 4; l15 = l15 + 1) {
			fYec2_perm[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 4096; l16 = l16 + 1) {
			fYec3[l16] = 0.0f;
		}
		fYec3_idx = 0;
		fYec3_idx_save = 0;
		for (int l17 = 0; l17 < 4; l17 = l17 + 1) {
			fRec14_perm[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 4; l18 = l18 + 1) {
			fRec16_perm[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 4; l19 = l19 + 1) {
			iRec19_perm[l19] = 0;
		}
		for (int l20 = 0; l20 < 4; l20 = l20 + 1) {
			fYec4_perm[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 4; l21 = l21 + 1) {
			fRec18_perm[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 4; l22 = l22 + 1) {
			fRec22_perm[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 4; l23 = l23 + 1) {
			fRec21_perm[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 4; l24 = l24 + 1) {
			fRec20_perm[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 4; l25 = l25 + 1) {
			fRec23_perm[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 4; l26 = l26 + 1) {
			fRec24_perm[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 4; l27 = l27 + 1) {
			fRec26_perm[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 4; l28 = l28 + 1) {
			fYec5_perm[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 4096; l29 = l29 + 1) {
			fYec6[l29] = 0.0f;
		}
		fYec6_idx = 0;
		fYec6_idx_save = 0;
		for (int l30 = 0; l30 < 4; l30 = l30 + 1) {
			fRec25_perm[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 4; l31 = l31 + 1) {
			fRec27_perm[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 4; l32 = l32 + 1) {
			fRec29_perm[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 4; l33 = l33 + 1) {
			fRec31_perm[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 4; l34 = l34 + 1) {
			fYec7_perm[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 4096; l35 = l35 + 1) {
			fYec8[l35] = 0.0f;
		}
		fYec8_idx = 0;
		fYec8_idx_save = 0;
		for (int l36 = 0; l36 < 4; l36 = l36 + 1) {
			fRec30_perm[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 4; l37 = l37 + 1) {
			fRec32_perm[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 4; l38 = l38 + 1) {
			fRec1_perm[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 4; l39 = l39 + 1) {
			fRec2_perm[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 4; l40 = l40 + 1) {
			fRec3_perm[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 4; l41 = l41 + 1) {
			fRec4_perm[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 4; l42 = l42 + 1) {
			fRec34_perm[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 4; l43 = l43 + 1) {
			fRec0_perm[l43] = 0.0f;
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
		ui_interface->declare(&fHslider4, "03", "");
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->addHorizontalSlider("pitchBend", &fHslider4, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2.5f), FAUSTFLOAT(2.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "04", "");
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->addHorizontalSlider("glide", &fHslider3, FAUSTFLOAT(0.01f), FAUSTFLOAT(0.001f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fCheckbox2, "05", "");
		ui_interface->addCheckButton("glideOn", &fCheckbox2);
		ui_interface->declare(&fCheckbox15, "06", "");
		ui_interface->addCheckButton("oscOnePower", &fCheckbox15);
		ui_interface->declare(&fCheckbox14, "07", "");
		ui_interface->addCheckButton("oscTwoPower", &fCheckbox14);
		ui_interface->declare(&fCheckbox13, "08", "");
		ui_interface->addCheckButton("oscThreePower", &fCheckbox13);
		ui_interface->declare(&fHslider25, "09", "");
		ui_interface->declare(&fHslider25, "style", "knob");
		ui_interface->addHorizontalSlider("oscOneGain", &fHslider25, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider23, "10", "");
		ui_interface->declare(&fHslider23, "style", "knob");
		ui_interface->addHorizontalSlider("oscTwoGain", &fHslider23, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider21, "11", "");
		ui_interface->declare(&fHslider21, "style", "knob");
		ui_interface->addHorizontalSlider("oscThreeGain", &fHslider21, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox3, "12", "");
		ui_interface->addCheckButton("oscModOn", &fCheckbox3);
		ui_interface->declare(&fCheckbox1, "13", "");
		ui_interface->addCheckButton("oscThreeKeyTrack", &fCheckbox1);
		ui_interface->declare(&fHslider24, "14", "");
		ui_interface->declare(&fHslider24, "style", "knob");
		ui_interface->addHorizontalSlider("waveOne", &fHslider24, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider22, "15", "");
		ui_interface->declare(&fHslider22, "style", "knob");
		ui_interface->addHorizontalSlider("waveTwo", &fHslider22, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider11, "16", "");
		ui_interface->declare(&fHslider11, "style", "knob");
		ui_interface->addHorizontalSlider("waveThree", &fHslider11, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider9, "17", "");
		ui_interface->declare(&fHslider9, "style", "knob");
		ui_interface->addHorizontalSlider("rangeOne", &fHslider9, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider14, "18", "");
		ui_interface->declare(&fHslider14, "style", "knob");
		ui_interface->addHorizontalSlider("rangeTwo", &fHslider14, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider7, "19", "");
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->addHorizontalSlider("rangeThree", &fHslider7, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider6, "20", "");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->addHorizontalSlider("globalDetune", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2.5f), FAUSTFLOAT(2.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider13, "21", "");
		ui_interface->declare(&fHslider13, "style", "knob");
		ui_interface->addHorizontalSlider("detuneTwo", &fHslider13, FAUSTFLOAT(0.0f), FAUSTFLOAT(-7.5f), FAUSTFLOAT(7.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider5, "22", "");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("detuneThree", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(-7.5f), FAUSTFLOAT(7.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox0, "23", "");
		ui_interface->addCheckButton("decayOn", &fCheckbox0);
		ui_interface->declare(&fHslider28, "24", "");
		ui_interface->declare(&fHslider28, "style", "knob");
		ui_interface->addHorizontalSlider("attack", &fHslider28, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider27, "25", "");
		ui_interface->declare(&fHslider27, "style", "knob");
		ui_interface->addHorizontalSlider("decay", &fHslider27, FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(2.4e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider29, "26", "");
		ui_interface->declare(&fHslider29, "style", "knob");
		ui_interface->addHorizontalSlider("sustain", &fHslider29, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider16, "27", "");
		ui_interface->declare(&fHslider16, "style", "knob");
		ui_interface->addHorizontalSlider("cutoff", &fHslider16, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.00045351475f), FAUSTFLOAT(0.90702945f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fCheckbox10, "28", "");
		ui_interface->addCheckButton("keyTrackOne", &fCheckbox10);
		ui_interface->declare(&fCheckbox9, "29", "");
		ui_interface->addCheckButton("keyTrackTwo", &fCheckbox9);
		ui_interface->declare(&fHslider15, "30", "");
		ui_interface->declare(&fHslider15, "style", "radio{'+':0;'-':1}");
		ui_interface->addHorizontalSlider("contour_direction", &fHslider15, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider17, "31", "");
		ui_interface->declare(&fHslider17, "style", "knob");
		ui_interface->addHorizontalSlider("contourAmount", &fHslider17, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider1, "32", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("fAttack", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(7e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "33", "");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("fDecay", &fHslider0, FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(3e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "34", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("fSustain", &fHslider2, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox8, "35", "");
		ui_interface->addCheckButton("filterModOn", &fCheckbox8);
		ui_interface->declare(&fHslider18, "36", "");
		ui_interface->declare(&fHslider18, "style", "knob");
		ui_interface->addHorizontalSlider("emphasis", &fHslider18, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.707f), FAUSTFLOAT(25.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fCheckbox5, "37", "");
		ui_interface->addCheckButton("noiseType", &fCheckbox5);
		ui_interface->declare(&fCheckbox12, "38", "");
		ui_interface->addCheckButton("noiseOn", &fCheckbox12);
		ui_interface->declare(&fHslider20, "39", "");
		ui_interface->declare(&fHslider20, "style", "knob");
		ui_interface->addHorizontalSlider("noiseGain", &fHslider20, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox7, "40", "");
		ui_interface->addCheckButton("oscThree_filterEg", &fCheckbox7);
		ui_interface->declare(&fHslider8, "41", "");
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("lfoRate", &fHslider8, FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.5f), FAUSTFLOAT(2e+02f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox6, "42", "");
		ui_interface->addCheckButton("lfoShape", &fCheckbox6);
		ui_interface->declare(&fCheckbox4, "43", "");
		ui_interface->addCheckButton("noise_lfo", &fCheckbox4);
		ui_interface->declare(&fHslider10, "44", "");
		ui_interface->declare(&fHslider10, "style", "knob");
		ui_interface->addHorizontalSlider("modMix", &fHslider10, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider12, "45", "");
		ui_interface->declare(&fHslider12, "style", "knob");
		ui_interface->addHorizontalSlider("modAmount", &fHslider12, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider26, "46", "");
		ui_interface->declare(&fHslider26, "style", "knob");
		ui_interface->addHorizontalSlider("load", &fHslider26, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider19, "style", "knob");
		ui_interface->addHorizontalSlider("feedbackGain", &fHslider19, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addCheckButton("feedbackOn", &fCheckbox11);
		ui_interface->declare(&fVbargraph0, "style", "numerical");
		ui_interface->addVerticalBargraph("finalFreq", &fVbargraph0, FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f));
		ui_interface->declare(&fHslider30, "style", "knob");
		ui_interface->addHorizontalSlider("masterVolume", &fHslider30, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addCheckButton("on", &fCheckbox16);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0_ptr = outputs[0];
		FAUSTFLOAT* output1_ptr = outputs[1];
		float fSlow0 = float(fButton0);
		float fVec0_tmp[12];
		float* fVec0 = &fVec0_tmp[4];
		float fRec6_tmp[12];
		float* fRec6 = &fRec6_tmp[4];
		int iVec1_tmp[12];
		int* iVec1 = &iVec1_tmp[4];
		int iSlow1 = fSlow0 == 0.0f;
		int iRec7_tmp[12];
		int* iRec7 = &iRec7_tmp[4];
		int iSlow2 = int(float(fCheckbox0));
		float fSlow3 = float(fHslider0);
		float fSlow4 = std::max<float>(1.0f, fConst0 * ((iSlow2) ? 0.001f * fSlow3 : 0.01f));
		float fZec0[8];
		float fSlow5 = std::max<float>(1.0f, fConst3 * float(fHslider1));
		float fSlow6 = 1.0f / fSlow5;
		float fSlow7 = float(fHslider2);
		float fSlow8 = (1.0f - fSlow7) / std::max<float>(1.0f, fConst3 * fSlow3);
		float fZec1[8];
		float fRec8_tmp[12];
		float* fRec8 = &fRec8_tmp[4];
		int iRec10_tmp[12];
		int* iRec10 = &iRec10_tmp[4];
		float fSlow9 = float(fEntry0);
		float fVec2_tmp[12];
		float* fVec2 = &fVec2_tmp[4];
		int iYec0_tmp[12];
		int* iYec0 = &iYec0_tmp[4];
		int iZec2[8];
		int iRec11_tmp[12];
		int* iRec11 = &iRec11_tmp[4];
		float fRec12_tmp[12];
		float* fRec12 = &fRec12_tmp[4];
		float fZec3[8];
		int iSlow10 = int(float(fCheckbox1));
		float fSlow11 = fConst7 / float(fHslider3);
		float fZec4[8];
		float fSlow12 = ((int(float(fCheckbox2))) ? float(fEntry1) : fSlow9);
		float fZec5[8];
		float fZec6[8];
		float fZec7[8];
		float fZec8[8];
		float fSlow13 = std::pow(2.0f, 0.083333336f * float(fHslider4));
		float fSlow14 = float(fHslider6);
		float fSlow15 = float(fHslider7);
		float fSlow16 = std::pow(2.0f, fSlow15 + -4.0f) * std::pow(2.0f, 0.083333336f * (fSlow14 + float(fHslider5))) * fSlow13;
		float fSlow17 = fConst7 * fSlow16;
		float fZec9[8];
		float fRec9_tmp[12];
		float* fRec9 = &fRec9_tmp[4];
		float fZec10[8];
		float fZec11[8];
		float fZec12[8];
		float fZec13[8];
		float fRec15_tmp[12];
		float* fRec15 = &fRec15_tmp[4];
		float fYec2_tmp[12];
		float* fYec2 = &fYec2_tmp[4];
		float fZec14[8];
		float fZec15[8];
		int iZec16[8];
		float fZec17[8];
		float fZec18[8];
		float fRec14_tmp[12];
		float* fRec14 = &fRec14_tmp[4];
		float fZec19[8];
		float fZec20[8];
		float fZec21[8];
		int iZec22[8];
		float fRec16_tmp[12];
		float* fRec16 = &fRec16_tmp[4];
		float fRec17[8];
		int iRec19_tmp[12];
		int* iRec19 = &iRec19_tmp[4];
		float fYec4_tmp[12];
		float* fYec4 = &fYec4_tmp[4];
		float fZec23[8];
		float fRec18_tmp[12];
		float* fRec18 = &fRec18_tmp[4];
		float fRec22_tmp[12];
		float* fRec22 = &fRec22_tmp[4];
		float fRec21_tmp[12];
		float* fRec21 = &fRec21_tmp[4];
		float fRec20_tmp[12];
		float* fRec20 = &fRec20_tmp[4];
		float fSlow18 = fConst7 * float(fHslider8);
		float fRec23_tmp[12];
		float* fRec23 = &fRec23_tmp[4];
		int iSlow19 = int(float(fCheckbox3));
		float fZec24[8];
		float fSlow20 = float(fHslider9);
		float fSlow21 = fSlow13 * std::pow(2.0f, fSlow20 + -4.0f) * std::pow(2.0f, 0.083333336f * fSlow14);
		int iSlow22 = int(float(fCheckbox4));
		int iSlow23 = int(float(fCheckbox5));
		float fZec25[8];
		int iSlow24 = int(float(fCheckbox6));
		float fSlow25 = float(fHslider10);
		int iSlow26 = int(float(fCheckbox7));
		float fSlow27 = float(fHslider11);
		int iSlow28 = fSlow27 >= 3.0f;
		int iSlow29 = fSlow27 >= 2.0f;
		int iSlow30 = fSlow27 >= 1.0f;
		int iSlow31 = int(fSlow15);
		float fZec26[8];
		float fSlow32 = fConst38 * fSlow16;
		float fZec27[8];
		int iSlow33 = fSlow27 >= 5.0f;
		int iSlow34 = fSlow27 >= 4.0f;
		float fZec28[8];
		int iZec29[8];
		float fZec30[8];
		float fZec31[8];
		int iZec32[8];
		float fZec33[8];
		float fZec34[8];
		float fZec35[8];
		float fSlow35 = 1.0f - fSlow25;
		float fSlow36 = float(fHslider12);
		float fZec36[8];
		float fZec37[8];
		float fZec38[8];
		float fRec24_tmp[12];
		float* fRec24 = &fRec24_tmp[4];
		float fZec39[8];
		float fZec40[8];
		float fZec41[8];
		float fRec26_tmp[12];
		float* fRec26 = &fRec26_tmp[4];
		float fYec5_tmp[12];
		float* fYec5 = &fYec5_tmp[4];
		float fZec42[8];
		int iZec43[8];
		float fZec44[8];
		float fZec45[8];
		float fRec25_tmp[12];
		float* fRec25 = &fRec25_tmp[4];
		float fZec46[8];
		float fZec47[8];
		float fZec48[8];
		int iZec49[8];
		float fRec27_tmp[12];
		float* fRec27 = &fRec27_tmp[4];
		float fRec28[8];
		float fZec50[8];
		float fSlow37 = float(fHslider14);
		float fSlow38 = fSlow13 * std::pow(2.0f, fSlow37 + -4.0f) * std::pow(2.0f, 0.083333336f * (fSlow14 + float(fHslider13)));
		float fZec51[8];
		float fZec52[8];
		float fRec29_tmp[12];
		float* fRec29 = &fRec29_tmp[4];
		float fZec53[8];
		float fZec54[8];
		float fZec55[8];
		float fRec31_tmp[12];
		float* fRec31 = &fRec31_tmp[4];
		float fYec7_tmp[12];
		float* fYec7 = &fYec7_tmp[4];
		float fZec56[8];
		int iZec57[8];
		float fZec58[8];
		float fZec59[8];
		float fRec30_tmp[12];
		float* fRec30 = &fRec30_tmp[4];
		float fZec60[8];
		float fZec61[8];
		float fZec62[8];
		int iZec63[8];
		float fRec32_tmp[12];
		float* fRec32 = &fRec32_tmp[4];
		float fRec33[8];
		int iSlow39 = int(float(fCheckbox8));
		int iSlow40 = int(float(fHslider15));
		float fSlow41 = 2.205e+04f * float(fHslider16) + 0.33333334f * (fSlow9 + -130.81f) * (float(fCheckbox10) + 2.0f * float(fCheckbox9));
		float fSlow42 = fSlow41 * ((iSlow40) ? 0.0625f : 16.0f);
		float fSlow43 = fSlow42 - fSlow41;
		float fSlow44 = float(fHslider17);
		float fSlow45 = fSlow41 - fSlow42;
		float fZec64[8];
		float fZec65[8];
		float fZec66[8];
		float fSlow46 = 0.16465649f * (float(fHslider18) + -0.707f);
		float fSlow47 = float(fHslider19);
		float fSlow48 = float(fCheckbox11);
		float fSlow49 = fSlow48 * fSlow47;
		float fSlow50 = float(fCheckbox12) * float(fHslider20);
		float fSlow51 = float(fHslider21) * float(fCheckbox13);
		float fSlow52 = float(fHslider22);
		int iSlow53 = fSlow52 >= 3.0f;
		int iSlow54 = fSlow52 >= 2.0f;
		int iSlow55 = fSlow52 >= 1.0f;
		int iSlow56 = int(fSlow37);
		float fZec67[8];
		float fZec68[8];
		float fZec69[8];
		int iSlow57 = fSlow52 >= 5.0f;
		int iSlow58 = fSlow52 >= 4.0f;
		float fZec70[8];
		int iZec71[8];
		float fZec72[8];
		float fZec73[8];
		int iZec74[8];
		float fZec75[8];
		float fSlow59 = float(fHslider23) * float(fCheckbox14);
		float fSlow60 = float(fHslider24);
		int iSlow61 = fSlow60 >= 3.0f;
		int iSlow62 = fSlow60 >= 2.0f;
		int iSlow63 = fSlow60 >= 1.0f;
		int iSlow64 = int(fSlow20);
		float fZec76[8];
		float fZec77[8];
		float fZec78[8];
		int iSlow65 = fSlow60 >= 5.0f;
		int iSlow66 = fSlow60 >= 4.0f;
		float fZec79[8];
		int iZec80[8];
		float fZec81[8];
		float fZec82[8];
		int iZec83[8];
		float fZec84[8];
		float fSlow67 = float(fHslider25) * float(fCheckbox15);
		float fSlow68 = 1.0f / std::max<float>(1.0f, 0.4f * (fSlow51 + fSlow67 + fSlow59));
		float fSlow69 = float(fHslider26);
		float fZec85[8];
		float fRec1_tmp[12];
		float* fRec1 = &fRec1_tmp[4];
		float fZec86[8];
		float fRec2_tmp[12];
		float* fRec2 = &fRec2_tmp[4];
		float fZec87[8];
		float fRec3_tmp[12];
		float* fRec3 = &fRec3_tmp[4];
		float fZec88[8];
		float fRec4_tmp[12];
		float* fRec4 = &fRec4_tmp[4];
		float fRec5[8];
		float fSlow70 = float(fHslider27);
		float fSlow71 = std::max<float>(1.0f, fConst0 * ((iSlow2) ? 0.001f * fSlow70 : 0.01f));
		float fSlow72 = std::max<float>(1.0f, fConst3 * float(fHslider28));
		float fSlow73 = 1.0f / fSlow72;
		float fSlow74 = float(fHslider29);
		float fSlow75 = (1.0f - fSlow74) / std::max<float>(1.0f, fConst3 * fSlow70);
		float fZec89[8];
		float fRec34_tmp[12];
		float* fRec34 = &fRec34_tmp[4];
		float fRec0_tmp[12];
		float* fRec0 = &fRec0_tmp[4];
		int iSlow76 = int(fSlow48);
		float fSlow77 = std::pow(2.0f, fSlow47);
		float fSlow78 = 1.0f - fSlow47;
		float fSlow79 = ((int(float(fCheckbox16))) ? 0.0f : 1.0f);
		float fSlow80 = float(fHslider30);
		float fZec90[8];
		int vindex = 0;
		/* Main loop */
		for (vindex = 0; vindex <= (count - 8); vindex = vindex + 8) {
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			FAUSTFLOAT* output1 = &output1_ptr[vindex];
			int vsize = 8;
			/* Vectorizable loop 0 */
			/* Pre code */
			for (int j4 = 0; j4 < 4; j4 = j4 + 1) {
				iVec1_tmp[j4] = iVec1_perm[j4];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iVec1[i] = 1;
			}
			/* Post code */
			for (int j5 = 0; j5 < 4; j5 = j5 + 1) {
				iVec1_perm[j5] = iVec1_tmp[vsize + j5];
			}
			/* Vectorizable loop 1 */
			/* Pre code */
			for (int j12 = 0; j12 < 4; j12 = j12 + 1) {
				fVec2_tmp[j12] = fVec2_perm[j12];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVec2[i] = fSlow9;
			}
			/* Post code */
			for (int j13 = 0; j13 < 4; j13 = j13 + 1) {
				fVec2_perm[j13] = fVec2_tmp[vsize + j13];
			}
			/* Vectorizable loop 2 */
			/* Pre code */
			for (int j14 = 0; j14 < 4; j14 = j14 + 1) {
				iYec0_tmp[j14] = iYec0_perm[j14];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iYec0[i] = fSlow9 != fVec2[i - 1];
			}
			/* Post code */
			for (int j15 = 0; j15 < 4; j15 = j15 + 1) {
				iYec0_perm[j15] = iYec0_tmp[vsize + j15];
			}
			/* Recursive loop 3 */
			/* Pre code */
			for (int j10 = 0; j10 < 4; j10 = j10 + 1) {
				iRec10_tmp[j10] = iRec10_perm[j10];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec10[i] = iRec10[i - 1] + 1;
			}
			/* Post code */
			for (int j11 = 0; j11 < 4; j11 = j11 + 1) {
				iRec10_perm[j11] = iRec10_tmp[vsize + j11];
			}
			/* Vectorizable loop 4 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec2[i] = (iYec0[i - 1] <= 0) & (iYec0[i] > 0);
			}
			/* Recursive loop 5 */
			/* Pre code */
			for (int j16 = 0; j16 < 4; j16 = j16 + 1) {
				iRec11_tmp[j16] = iRec11_perm[j16];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec11[i] = iRec11[i - 1] * (1 - iZec2[i]) + (iRec10[i] + -1) * iZec2[i];
			}
			/* Post code */
			for (int j17 = 0; j17 < 4; j17 = j17 + 1) {
				iRec11_perm[j17] = iRec11_tmp[vsize + j17];
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec4[i] = std::max<float>(std::exp(fSlow11 * float(-1 * (iRec10[i] + (-1 - iRec11[i])))), 0.01f);
			}
			/* Recursive loop 7 */
			/* Pre code */
			for (int j18 = 0; j18 < 4; j18 = j18 + 1) {
				fRec12_tmp[j18] = fRec12_perm[j18];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec12[i] = fConst4 + (fRec12[i - 1] - std::floor(fConst4 + fRec12[i - 1]));
			}
			/* Post code */
			for (int j19 = 0; j19 < 4; j19 = j19 + 1) {
				fRec12_perm[j19] = fRec12_tmp[vsize + j19];
			}
			/* Vectorizable loop 8 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec5[i] = fSlow9 * (1.0f - fZec4[i]) + fSlow12 * fZec4[i];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVbargraph0 = FAUSTFLOAT(fZec5[i]);
				fZec6[i] = fZec5[i];
			}
			/* Vectorizable loop 9 */
			/* Pre code */
			fYec1_idx = (fYec1_idx + fYec1_idx_save) & 8191;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec1[(i + fYec1_idx) & 8191] = std::pow(2.0f, 0.01f * ftbl0mydspSIG0[int(65536.0f * fRec12[i])]);
			}
			/* Post code */
			fYec1_idx_save = vsize;
			/* Vectorizable loop 10 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec7[i] = ((iSlow10) ? 130.81f : fZec6[i]);
			}
			/* Vectorizable loop 11 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec3[i] = fYec1[(i + fYec1_idx - iConst6) & 8191];
				fZec8[i] = fZec7[i] * fZec3[i];
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec10[i] = fSlow16 * fZec8[i];
			}
			/* Vectorizable loop 13 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec11[i] = std::max<float>(fZec10[i], 23.44895f);
			}
			/* Vectorizable loop 14 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec12[i] = std::max<float>(2e+01f, std::fabs(fZec11[i]));
			}
			/* Vectorizable loop 15 */
			/* Pre code */
			for (int j0 = 0; j0 < 4; j0 = j0 + 1) {
				fVec0_tmp[j0] = fVec0_perm[j0];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVec0[i] = fSlow0;
			}
			/* Post code */
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				fVec0_perm[j1] = fVec0_tmp[vsize + j1];
			}
			/* Recursive loop 16 */
			/* Pre code */
			for (int j22 = 0; j22 < 4; j22 = j22 + 1) {
				fRec15_tmp[j22] = fRec15_perm[j22];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec13[i] = fRec15[i - 1] + fConst7 * fZec12[i];
				fRec15[i] = fZec13[i] - std::floor(fZec13[i]);
			}
			/* Post code */
			for (int j23 = 0; j23 < 4; j23 = j23 + 1) {
				fRec15_perm[j23] = fRec15_tmp[vsize + j23];
			}
			/* Recursive loop 17 */
			/* Pre code */
			for (int j6 = 0; j6 < 4; j6 = j6 + 1) {
				iRec7_tmp[j6] = iRec7_perm[j6];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec7[i] = iSlow1 * (iRec7[i - 1] + 1);
			}
			/* Post code */
			for (int j7 = 0; j7 < 4; j7 = j7 + 1) {
				iRec7_perm[j7] = iRec7_tmp[vsize + j7];
			}
			/* Vectorizable loop 18 */
			/* Pre code */
			for (int j24 = 0; j24 < 4; j24 = j24 + 1) {
				fYec2_tmp[j24] = fYec2_perm[j24];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec2[i] = mydsp_faustpower2_f(2.0f * fRec15[i] + -1.0f);
			}
			/* Post code */
			for (int j25 = 0; j25 < 4; j25 = j25 + 1) {
				fYec2_perm[j25] = fYec2_tmp[vsize + j25];
			}
			/* Vectorizable loop 19 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec14[i] = float(iVec1[i - 1]);
			}
			/* Vectorizable loop 20 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec15[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fZec11[i]));
			}
			/* Recursive loop 21 */
			/* Pre code */
			for (int j30 = 0; j30 < 4; j30 = j30 + 1) {
				iRec19_tmp[j30] = iRec19_perm[j30];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec19[i] = 1103515245 * iRec19[i - 1] + 12345;
			}
			/* Post code */
			for (int j31 = 0; j31 < 4; j31 = j31 + 1) {
				iRec19_perm[j31] = iRec19_tmp[vsize + j31];
			}
			/* Recursive loop 22 */
			/* Pre code */
			for (int j2 = 0; j2 < 4; j2 = j2 + 1) {
				fRec6_tmp[j2] = fRec6_perm[j2];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec6[i] = fSlow0 + fRec6[i - 1] * float(fVec0[i - 1] >= fSlow0);
			}
			/* Post code */
			for (int j3 = 0; j3 < 4; j3 = j3 + 1) {
				fRec6_perm[j3] = fRec6_tmp[vsize + j3];
			}
			/* Vectorizable loop 23 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec0[i] = float(iRec7[i]);
			}
			/* Recursive loop 24 */
			/* Pre code */
			for (int j20 = 0; j20 < 4; j20 = j20 + 1) {
				fRec9_tmp[j20] = fRec9_perm[j20];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec9[i] = fRec9[i - 1] + fSlow17 * fZec8[i];
				fRec9[i] = fZec9[i] - std::floor(fZec9[i]);
			}
			/* Post code */
			for (int j21 = 0; j21 < 4; j21 = j21 + 1) {
				fRec9_perm[j21] = fRec9_tmp[vsize + j21];
			}
			/* Vectorizable loop 25 */
			/* Pre code */
			fYec3_idx = (fYec3_idx + fYec3_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec3[(i + fYec3_idx) & 4095] = fZec14[i] * (fYec2[i] - fYec2[i - 1]) / fZec12[i];
			}
			/* Post code */
			fYec3_idx_save = vsize;
			/* Vectorizable loop 26 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec16[i] = int(fZec15[i]);
			}
			/* Vectorizable loop 27 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec17[i] = std::floor(fZec15[i]);
			}
			/* Vectorizable loop 28 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec19[i] = std::max<float>(1.1920929e-07f, std::fabs(fZec10[i]));
			}
			/* Vectorizable loop 29 */
			/* Pre code */
			for (int j32 = 0; j32 < 4; j32 = j32 + 1) {
				fYec4_tmp[j32] = fYec4_perm[j32];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec4[i] = float(iRec19[i]);
			}
			/* Post code */
			for (int j33 = 0; j33 < 4; j33 = j33 + 1) {
				fYec4_perm[j33] = fYec4_tmp[vsize + j33];
			}
			/* Vectorizable loop 30 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec1[i] = std::max<float>(0.0f, std::min<float>(fSlow6 * fRec6[i], std::max<float>(fSlow8 * (fSlow5 - fRec6[i]) + 1.0f, fSlow7)) * (1.0f - fZec0[i] / fSlow4));
			}
			/* Vectorizable loop 31 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec18[i] = fConst9 * (fYec3[(i + fYec3_idx) & 4095] - fYec3[(i + fYec3_idx - iZec16[i]) & 4095] * (fZec17[i] + (1.0f - fZec15[i])) - (fZec15[i] - fZec17[i]) * fYec3[(i + fYec3_idx - (iZec16[i] + 1)) & 4095]);
			}
			/* Recursive loop 32 */
			/* Pre code */
			for (int j28 = 0; j28 < 4; j28 = j28 + 1) {
				fRec16_tmp[j28] = fRec16_perm[j28];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec20[i] = fRec16[i - 1] + fConst7 * fZec19[i];
				fZec21[i] = fZec20[i] + -1.0f;
				iZec22[i] = fZec21[i] < 0.0f;
				fRec16[i] = ((iZec22[i]) ? fZec20[i] : fZec21[i]);
				fRec17[i] = ((iZec22[i]) ? fZec20[i] : fZec20[i] + fZec21[i] * (1.0f - fConst0 / fZec19[i]));
			}
			/* Post code */
			for (int j29 = 0; j29 < 4; j29 = j29 + 1) {
				fRec16_perm[j29] = fRec16_tmp[vsize + j29];
			}
			/* Vectorizable loop 33 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec23[i] = 4.656613e-10f * fYec4[i];
			}
			/* Recursive loop 34 */
			/* Pre code */
			for (int j36 = 0; j36 < 4; j36 = j36 + 1) {
				fRec22_tmp[j36] = fRec22_perm[j36];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec22[i] = fConst18 * (4.656613e-10f * (fConst17 * fYec4[i] + fConst16 * fYec4[i - 1]) - fConst11 * fRec22[i - 1]);
			}
			/* Post code */
			for (int j37 = 0; j37 < 4; j37 = j37 + 1) {
				fRec22_perm[j37] = fRec22_tmp[vsize + j37];
			}
			/* Vectorizable loop 35 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec26[i] = 2.0f * fRec9[i] + -1.0f;
			}
			/* Vectorizable loop 36 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec28[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst39 / fZec11[i]));
			}
			/* Vectorizable loop 37 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec31[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst40 / fZec11[i]));
			}
			/* Recursive loop 38 */
			/* Pre code */
			for (int j8 = 0; j8 < 4; j8 = j8 + 1) {
				fRec8_tmp[j8] = fRec8_perm[j8];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec8[i] = fConst1 * fZec1[i] + fConst2 * fRec8[i - 1];
			}
			/* Post code */
			for (int j9 = 0; j9 < 4; j9 = j9 + 1) {
				fRec8_perm[j9] = fRec8_tmp[vsize + j9];
			}
			/* Recursive loop 39 */
			/* Pre code */
			for (int j26 = 0; j26 < 4; j26 = j26 + 1) {
				fRec14_tmp[j26] = fRec14_perm[j26];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec14[i] = 0.999f * fRec14[i - 1] + fZec18[i];
			}
			/* Post code */
			for (int j27 = 0; j27 < 4; j27 = j27 + 1) {
				fRec14_perm[j27] = fRec14_tmp[vsize + j27];
			}
			/* Recursive loop 40 */
			/* Pre code */
			for (int j34 = 0; j34 < 4; j34 = j34 + 1) {
				fRec18_tmp[j34] = fRec18_perm[j34];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec18[i] = 0.5221894f * fRec18[i - 3] + fZec23[i] + 2.494956f * fRec18[i - 1] - 2.0172658f * fRec18[i - 2];
			}
			/* Post code */
			for (int j35 = 0; j35 < 4; j35 = j35 + 1) {
				fRec18_perm[j35] = fRec18_tmp[vsize + j35];
			}
			/* Recursive loop 41 */
			/* Pre code */
			for (int j38 = 0; j38 < 4; j38 = j38 + 1) {
				fRec21_tmp[j38] = fRec21_perm[j38];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec21[i] = 0.0f - fConst27 * (fConst26 * fRec21[i - 1] - fConst23 * (fConst22 * fRec22[i] + fConst21 * fRec22[i - 1]));
			}
			/* Post code */
			for (int j39 = 0; j39 < 4; j39 = j39 + 1) {
				fRec21_perm[j39] = fRec21_tmp[vsize + j39];
			}
			/* Vectorizable loop 42 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec27[i] = ((iSlow31) ? 2.0f * fRec17[i] + -1.0f : fZec26[i]);
			}
			/* Vectorizable loop 43 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec29[i] = int(fZec28[i]);
			}
			/* Vectorizable loop 44 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec30[i] = std::floor(fZec28[i]);
			}
			/* Vectorizable loop 45 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec32[i] = int(fZec31[i]);
			}
			/* Vectorizable loop 46 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec33[i] = std::floor(fZec31[i]);
			}
			/* Recursive loop 47 */
			/* Pre code */
			for (int j40 = 0; j40 < 4; j40 = j40 + 1) {
				fRec20_tmp[j40] = fRec20_perm[j40];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec20[i] = 0.0f - fConst36 * (fConst35 * fRec20[i - 1] - fConst32 * (fConst31 * fRec21[i] + fConst30 * fRec21[i - 1]));
			}
			/* Post code */
			for (int j41 = 0; j41 < 4; j41 = j41 + 1) {
				fRec20_perm[j41] = fRec20_tmp[vsize + j41];
			}
			/* Recursive loop 48 */
			/* Pre code */
			for (int j42 = 0; j42 < 4; j42 = j42 + 1) {
				fRec23_tmp[j42] = fRec23_perm[j42];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec23[i] = fSlow18 + (fRec23[i - 1] - std::floor(fSlow18 + fRec23[i - 1]));
			}
			/* Post code */
			for (int j43 = 0; j43 < 4; j43 = j43 + 1) {
				fRec23_perm[j43] = fRec23_tmp[vsize + j43];
			}
			/* Vectorizable loop 49 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec25[i] = 0.049922034f * fRec18[i] + 0.0506127f * fRec18[i - 2] - (0.095993534f * fRec18[i - 1] + 0.004408786f * fRec18[i - 3]);
			}
			/* Vectorizable loop 50 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec34[i] = ((iSlow28) ? ((iSlow33) ? ((iSlow31) ? fConst9 * (fYec3[(i + fYec3_idx) & 4095] - fYec3[(i + fYec3_idx - iZec32[i]) & 4095] * (fZec33[i] + (1.0f - fZec31[i])) - (fZec31[i] - fZec33[i]) * fYec3[(i + fYec3_idx - (iZec32[i] + 1)) & 4095]) : 2.0f * float(fRec9[i] <= 0.85f) + -1.0f) : ((iSlow34) ? ((iSlow31) ? fConst9 * (fYec3[(i + fYec3_idx) & 4095] - fYec3[(i + fYec3_idx - iZec29[i]) & 4095] * (fZec30[i] + (1.0f - fZec28[i])) - (fZec28[i] - fZec30[i]) * fYec3[(i + fYec3_idx - (iZec29[i] + 1)) & 4095]) : 2.0f * float(fRec9[i] <= 0.7f) + -1.0f) : ((iSlow31) ? fZec18[i] : 2.0f * float(fRec9[i] <= 0.5f) + -1.0f))) : ((iSlow29) ? fZec27[i] : ((iSlow30) ? 0.0f - fZec27[i] : ((iSlow31) ? fSlow32 * fRec14[i] * fZec7[i] * fZec3[i] : 2.0f * (1.0f - std::fabs(fZec26[i])) + -1.0f))));
			}
			/* Vectorizable loop 51 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec35[i] = ((iSlow2) ? fRec8[i] : fZec1[i]);
			}
			/* Vectorizable loop 52 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec24[i] = fZec6[i] * fYec1[(i + fYec1_idx - iConst5) & 8191];
			}
			/* Vectorizable loop 53 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec36[i] = std::pow(2.0f, fSlow36 * (fSlow35 * ((iSlow26) ? fZec35[i] : fZec34[i]) + fSlow25 * ((iSlow22) ? ((iSlow24) ? 2.0f * float(fRec23[i] <= 0.5f) + -1.0f : 2.0f * (1.0f - std::fabs(2.0f * fRec23[i] + -1.0f)) + -1.0f) : ((iSlow23) ? fConst37 * fRec20[i] : fZec25[i]))));
			}
			/* Vectorizable loop 54 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec50[i] = fZec6[i] * fYec1[(i + fYec1_idx - iConst41) & 8191];
			}
			/* Vectorizable loop 55 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec37[i] = ((iSlow19) ? fSlow21 * fZec24[i] * fZec36[i] : fSlow21 * fZec24[i]);
			}
			/* Vectorizable loop 56 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec51[i] = ((iSlow19) ? fSlow38 * fZec50[i] * fZec36[i] : fSlow38 * fZec50[i]);
			}
			/* Vectorizable loop 57 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec39[i] = std::max<float>(fZec37[i], 23.44895f);
			}
			/* Vectorizable loop 58 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec53[i] = std::max<float>(fZec51[i], 23.44895f);
			}
			/* Vectorizable loop 59 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec40[i] = std::max<float>(2e+01f, std::fabs(fZec39[i]));
			}
			/* Vectorizable loop 60 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec54[i] = std::max<float>(2e+01f, std::fabs(fZec53[i]));
			}
			/* Recursive loop 61 */
			/* Pre code */
			for (int j46 = 0; j46 < 4; j46 = j46 + 1) {
				fRec26_tmp[j46] = fRec26_perm[j46];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec41[i] = fRec26[i - 1] + fConst7 * fZec40[i];
				fRec26[i] = fZec41[i] - std::floor(fZec41[i]);
			}
			/* Post code */
			for (int j47 = 0; j47 < 4; j47 = j47 + 1) {
				fRec26_perm[j47] = fRec26_tmp[vsize + j47];
			}
			/* Recursive loop 62 */
			/* Pre code */
			for (int j56 = 0; j56 < 4; j56 = j56 + 1) {
				fRec31_tmp[j56] = fRec31_perm[j56];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec55[i] = fRec31[i - 1] + fConst7 * fZec54[i];
				fRec31[i] = fZec55[i] - std::floor(fZec55[i]);
			}
			/* Post code */
			for (int j57 = 0; j57 < 4; j57 = j57 + 1) {
				fRec31_perm[j57] = fRec31_tmp[vsize + j57];
			}
			/* Vectorizable loop 63 */
			/* Pre code */
			for (int j48 = 0; j48 < 4; j48 = j48 + 1) {
				fYec5_tmp[j48] = fYec5_perm[j48];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec5[i] = mydsp_faustpower2_f(2.0f * fRec26[i] + -1.0f);
			}
			/* Post code */
			for (int j49 = 0; j49 < 4; j49 = j49 + 1) {
				fYec5_perm[j49] = fYec5_tmp[vsize + j49];
			}
			/* Vectorizable loop 64 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec42[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fZec39[i]));
			}
			/* Vectorizable loop 65 */
			/* Pre code */
			for (int j58 = 0; j58 < 4; j58 = j58 + 1) {
				fYec7_tmp[j58] = fYec7_perm[j58];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec7[i] = mydsp_faustpower2_f(2.0f * fRec31[i] + -1.0f);
			}
			/* Post code */
			for (int j59 = 0; j59 < 4; j59 = j59 + 1) {
				fYec7_perm[j59] = fYec7_tmp[vsize + j59];
			}
			/* Vectorizable loop 66 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec56[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fZec53[i]));
			}
			/* Vectorizable loop 67 */
			/* Pre code */
			fYec6_idx = (fYec6_idx + fYec6_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec6[(i + fYec6_idx) & 4095] = fZec14[i] * (fYec5[i] - fYec5[i - 1]) / fZec40[i];
			}
			/* Post code */
			fYec6_idx_save = vsize;
			/* Vectorizable loop 68 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec43[i] = int(fZec42[i]);
			}
			/* Vectorizable loop 69 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec44[i] = std::floor(fZec42[i]);
			}
			/* Vectorizable loop 70 */
			/* Pre code */
			fYec8_idx = (fYec8_idx + fYec8_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec8[(i + fYec8_idx) & 4095] = fZec14[i] * (fYec7[i] - fYec7[i - 1]) / fZec54[i];
			}
			/* Post code */
			fYec8_idx_save = vsize;
			/* Vectorizable loop 71 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec57[i] = int(fZec56[i]);
			}
			/* Vectorizable loop 72 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec58[i] = std::floor(fZec56[i]);
			}
			/* Recursive loop 73 */
			/* Pre code */
			for (int j44 = 0; j44 < 4; j44 = j44 + 1) {
				fRec24_tmp[j44] = fRec24_perm[j44];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec38[i] = fRec24[i - 1] + fConst7 * fZec37[i];
				fRec24[i] = fZec38[i] - std::floor(fZec38[i]);
			}
			/* Post code */
			for (int j45 = 0; j45 < 4; j45 = j45 + 1) {
				fRec24_perm[j45] = fRec24_tmp[vsize + j45];
			}
			/* Vectorizable loop 74 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec45[i] = fConst9 * (fYec6[(i + fYec6_idx) & 4095] - fYec6[(i + fYec6_idx - iZec43[i]) & 4095] * (fZec44[i] + (1.0f - fZec42[i])) - (fZec42[i] - fZec44[i]) * fYec6[(i + fYec6_idx - (iZec43[i] + 1)) & 4095]);
			}
			/* Vectorizable loop 75 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec46[i] = std::max<float>(1.1920929e-07f, std::fabs(fZec37[i]));
			}
			/* Recursive loop 76 */
			/* Pre code */
			for (int j54 = 0; j54 < 4; j54 = j54 + 1) {
				fRec29_tmp[j54] = fRec29_perm[j54];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec52[i] = fRec29[i - 1] + fConst7 * fZec51[i];
				fRec29[i] = fZec52[i] - std::floor(fZec52[i]);
			}
			/* Post code */
			for (int j55 = 0; j55 < 4; j55 = j55 + 1) {
				fRec29_perm[j55] = fRec29_tmp[vsize + j55];
			}
			/* Vectorizable loop 77 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec59[i] = fConst9 * (fYec8[(i + fYec8_idx) & 4095] - fYec8[(i + fYec8_idx - iZec57[i]) & 4095] * (fZec58[i] + (1.0f - fZec56[i])) - (fZec56[i] - fZec58[i]) * fYec8[(i + fYec8_idx - (iZec57[i] + 1)) & 4095]);
			}
			/* Vectorizable loop 78 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec60[i] = std::max<float>(1.1920929e-07f, std::fabs(fZec51[i]));
			}
			/* Vectorizable loop 79 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec64[i] = ((iSlow40) ? fSlow41 - fSlow44 * fZec35[i] * fSlow45 : fSlow41 + fSlow44 * fZec35[i] * fSlow43);
			}
			/* Recursive loop 80 */
			/* Pre code */
			for (int j50 = 0; j50 < 4; j50 = j50 + 1) {
				fRec25_tmp[j50] = fRec25_perm[j50];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec25[i] = 0.999f * fRec25[i - 1] + fZec45[i];
			}
			/* Post code */
			for (int j51 = 0; j51 < 4; j51 = j51 + 1) {
				fRec25_perm[j51] = fRec25_tmp[vsize + j51];
			}
			/* Recursive loop 81 */
			/* Pre code */
			for (int j52 = 0; j52 < 4; j52 = j52 + 1) {
				fRec27_tmp[j52] = fRec27_perm[j52];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec47[i] = fRec27[i - 1] + fConst7 * fZec46[i];
				fZec48[i] = fZec47[i] + -1.0f;
				iZec49[i] = fZec48[i] < 0.0f;
				fRec27[i] = ((iZec49[i]) ? fZec47[i] : fZec48[i]);
				fRec28[i] = ((iZec49[i]) ? fZec47[i] : fZec47[i] + fZec48[i] * (1.0f - fConst0 / fZec46[i]));
			}
			/* Post code */
			for (int j53 = 0; j53 < 4; j53 = j53 + 1) {
				fRec27_perm[j53] = fRec27_tmp[vsize + j53];
			}
			/* Recursive loop 82 */
			/* Pre code */
			for (int j60 = 0; j60 < 4; j60 = j60 + 1) {
				fRec30_tmp[j60] = fRec30_perm[j60];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec30[i] = 0.999f * fRec30[i - 1] + fZec59[i];
			}
			/* Post code */
			for (int j61 = 0; j61 < 4; j61 = j61 + 1) {
				fRec30_perm[j61] = fRec30_tmp[vsize + j61];
			}
			/* Recursive loop 83 */
			/* Pre code */
			for (int j62 = 0; j62 < 4; j62 = j62 + 1) {
				fRec32_tmp[j62] = fRec32_perm[j62];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec61[i] = fRec32[i - 1] + fConst7 * fZec60[i];
				fZec62[i] = fZec61[i] + -1.0f;
				iZec63[i] = fZec62[i] < 0.0f;
				fRec32[i] = ((iZec63[i]) ? fZec61[i] : fZec62[i]);
				fRec33[i] = ((iZec63[i]) ? fZec61[i] : fZec61[i] + fZec62[i] * (1.0f - fConst0 / fZec60[i]));
			}
			/* Post code */
			for (int j63 = 0; j63 < 4; j63 = j63 + 1) {
				fRec32_perm[j63] = fRec32_tmp[vsize + j63];
			}
			/* Vectorizable loop 84 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec65[i] = std::tan(1.5707964f * std::min<float>(std::max<float>(4.5351473e-05f * ((iSlow39) ? fZec64[i] * fZec36[i] : fZec64[i]), 0.00045351475f), 0.90702945f));
			}
			/* Vectorizable loop 85 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec67[i] = 2.0f * fRec29[i] + -1.0f;
			}
			/* Vectorizable loop 86 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec70[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst39 / fZec53[i]));
			}
			/* Vectorizable loop 87 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec73[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst40 / fZec53[i]));
			}
			/* Vectorizable loop 88 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec76[i] = 2.0f * fRec24[i] + -1.0f;
			}
			/* Vectorizable loop 89 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec79[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst39 / fZec39[i]));
			}
			/* Vectorizable loop 90 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec82[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst40 / fZec39[i]));
			}
			/* Vectorizable loop 91 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec89[i] = std::max<float>(0.0f, std::min<float>(fSlow73 * fRec6[i], std::max<float>(fSlow75 * (fSlow72 - fRec6[i]) + 1.0f, fSlow74)) * (1.0f - fZec0[i] / fSlow71));
			}
			/* Vectorizable loop 92 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec66[i] = fZec65[i] + 1.0f;
			}
			/* Vectorizable loop 93 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec68[i] = ((iSlow56) ? fConst38 * fRec30[i] * fZec51[i] : 2.0f * (1.0f - std::fabs(fZec67[i])) + -1.0f);
			}
			/* Vectorizable loop 94 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec69[i] = ((iSlow56) ? 2.0f * fRec33[i] + -1.0f : fZec67[i]);
			}
			/* Vectorizable loop 95 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec71[i] = int(fZec70[i]);
			}
			/* Vectorizable loop 96 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec72[i] = std::floor(fZec70[i]);
			}
			/* Vectorizable loop 97 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec74[i] = int(fZec73[i]);
			}
			/* Vectorizable loop 98 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec75[i] = std::floor(fZec73[i]);
			}
			/* Vectorizable loop 99 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec77[i] = ((iSlow64) ? fConst38 * fRec25[i] * fZec37[i] : 2.0f * (1.0f - std::fabs(fZec76[i])) + -1.0f);
			}
			/* Vectorizable loop 100 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec78[i] = ((iSlow64) ? 2.0f * fRec28[i] + -1.0f : fZec76[i]);
			}
			/* Vectorizable loop 101 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec80[i] = int(fZec79[i]);
			}
			/* Vectorizable loop 102 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec81[i] = std::floor(fZec79[i]);
			}
			/* Vectorizable loop 103 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec83[i] = int(fZec82[i]);
			}
			/* Vectorizable loop 104 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec84[i] = std::floor(fZec82[i]);
			}
			/* Recursive loop 105 */
			/* Pre code */
			for (int j72 = 0; j72 < 4; j72 = j72 + 1) {
				fRec34_tmp[j72] = fRec34_perm[j72];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec34[i] = fConst1 * fZec89[i] + fConst2 * fRec34[i - 1];
			}
			/* Post code */
			for (int j73 = 0; j73 < 4; j73 = j73 + 1) {
				fRec34_perm[j73] = fRec34_tmp[vsize + j73];
			}
			/* Recursive loop 106 */
			/* Pre code */
			for (int j64 = 0; j64 < 4; j64 = j64 + 1) {
				fRec1_tmp[j64] = fRec1_perm[j64];
			}
			for (int j66 = 0; j66 < 4; j66 = j66 + 1) {
				fRec2_tmp[j66] = fRec2_perm[j66];
			}
			for (int j68 = 0; j68 < 4; j68 = j68 + 1) {
				fRec3_tmp[j68] = fRec3_perm[j68];
			}
			for (int j70 = 0; j70 < 4; j70 = j70 + 1) {
				fRec4_tmp[j70] = fRec4_perm[j70];
			}
			for (int j74 = 0; j74 < 4; j74 = j74 + 1) {
				fRec0_tmp[j74] = fRec0_perm[j74];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec85[i] = fZec65[i] * ((fSlow69 * (fSlow68 * (fSlow67 * ((iSlow61) ? ((iSlow65) ? ((iSlow64) ? fConst9 * (fYec6[(i + fYec6_idx) & 4095] - fYec6[(i + fYec6_idx - iZec83[i]) & 4095] * (fZec84[i] + (1.0f - fZec82[i])) - (fZec82[i] - fZec84[i]) * fYec6[(i + fYec6_idx - (iZec83[i] + 1)) & 4095]) : 2.0f * float(fRec24[i] <= 0.85f) + -1.0f) : ((iSlow66) ? ((iSlow64) ? fConst9 * (fYec6[(i + fYec6_idx) & 4095] - fYec6[(i + fYec6_idx - iZec80[i]) & 4095] * (fZec81[i] + (1.0f - fZec79[i])) - (fZec79[i] - fZec81[i]) * fYec6[(i + fYec6_idx - (iZec80[i] + 1)) & 4095]) : 2.0f * float(fRec24[i] <= 0.7f) + -1.0f) : ((iSlow64) ? fZec45[i] : 2.0f * float(fRec24[i] <= 0.5f) + -1.0f))) : ((iSlow62) ? fZec78[i] : ((iSlow63) ? 0.5f * (fZec77[i] + fZec78[i]) : fZec77[i]))) + fSlow59 * ((iSlow53) ? ((iSlow57) ? ((iSlow56) ? fConst9 * (fYec8[(i + fYec8_idx) & 4095] - fYec8[(i + fYec8_idx - iZec74[i]) & 4095] * (fZec75[i] + (1.0f - fZec73[i])) - (fZec73[i] - fZec75[i]) * fYec8[(i + fYec8_idx - (iZec74[i] + 1)) & 4095]) : 2.0f * float(fRec29[i] <= 0.85f) + -1.0f) : ((iSlow58) ? ((iSlow56) ? fConst9 * (fYec8[(i + fYec8_idx) & 4095] - fYec8[(i + fYec8_idx - iZec71[i]) & 4095] * (fZec72[i] + (1.0f - fZec70[i])) - (fZec70[i] - fZec72[i]) * fYec8[(i + fYec8_idx - (iZec71[i] + 1)) & 4095]) : 2.0f * float(fRec29[i] <= 0.7f) + -1.0f) : ((iSlow56) ? fZec59[i] : 2.0f * float(fRec29[i] <= 0.5f) + -1.0f))) : ((iSlow54) ? fZec69[i] : ((iSlow55) ? 0.5f * (fZec68[i] + fZec69[i]) : fZec68[i]))) + fSlow51 * fZec34[i]) + fSlow50 * ((iSlow23) ? fZec25[i] : fZec23[i])) + fSlow49 * fRec0[i - 1] - fSlow46 * (1.0f - fZec65[i] / fZec66[i]) * (fRec4[i - 1] + fZec65[i] * (fRec3[i - 1] + fZec65[i] * (fRec2[i - 1] + fZec65[i] * fRec1[i - 1] / fZec66[i]) / fZec66[i]) / fZec66[i])) / (fSlow46 * (mydsp_faustpower4_f(fZec65[i]) / mydsp_faustpower4_f(fZec66[i])) + 1.0f) - fRec1[i - 1]) / fZec66[i];
				fRec1[i] = fRec1[i - 1] + 2.0f * fZec85[i];
				fZec86[i] = fZec65[i] * (fRec1[i - 1] + fZec85[i] - fRec2[i - 1]) / fZec66[i];
				fRec2[i] = fRec2[i - 1] + 2.0f * fZec86[i];
				fZec87[i] = fZec65[i] * (fRec2[i - 1] + fZec86[i] - fRec3[i - 1]) / fZec66[i];
				fRec3[i] = fRec3[i - 1] + 2.0f * fZec87[i];
				fZec88[i] = fZec65[i] * (fRec3[i - 1] + fZec87[i] - fRec4[i - 1]) / fZec66[i];
				fRec4[i] = fRec4[i - 1] + 2.0f * fZec88[i];
				fRec5[i] = fRec4[i - 1] + fZec88[i];
				fRec0[i] = fRec5[i] * ((iSlow2) ? fRec34[i] : fZec89[i]);
			}
			/* Post code */
			for (int j65 = 0; j65 < 4; j65 = j65 + 1) {
				fRec1_perm[j65] = fRec1_tmp[vsize + j65];
			}
			for (int j67 = 0; j67 < 4; j67 = j67 + 1) {
				fRec2_perm[j67] = fRec2_tmp[vsize + j67];
			}
			for (int j69 = 0; j69 < 4; j69 = j69 + 1) {
				fRec3_perm[j69] = fRec3_tmp[vsize + j69];
			}
			for (int j71 = 0; j71 < 4; j71 = j71 + 1) {
				fRec4_perm[j71] = fRec4_tmp[vsize + j71];
			}
			for (int j75 = 0; j75 < 4; j75 = j75 + 1) {
				fRec0_perm[j75] = fRec0_tmp[vsize + j75];
			}
			/* Vectorizable loop 107 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec90[i] = fSlow80 * fSlow79 * atanhf(std::max<float>(-0.9999999f, std::min<float>(0.9999999f, ((iSlow76) ? fSlow78 * fRec0[i] : fRec0[i]) + ((iSlow76) ? fSlow77 * fRec0[i] : 0.0f))));
			}
			/* Vectorizable loop 108 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(fZec90[i]);
			}
			/* Vectorizable loop 109 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				output1[i] = FAUSTFLOAT(fZec90[i]);
			}
		}
		/* Remaining frames */
		if ((vindex < count)) {
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			FAUSTFLOAT* output1 = &output1_ptr[vindex];
			int vsize = count - vindex;
			/* Vectorizable loop 0 */
			/* Pre code */
			for (int j4 = 0; j4 < 4; j4 = j4 + 1) {
				iVec1_tmp[j4] = iVec1_perm[j4];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iVec1[i] = 1;
			}
			/* Post code */
			for (int j5 = 0; j5 < 4; j5 = j5 + 1) {
				iVec1_perm[j5] = iVec1_tmp[vsize + j5];
			}
			/* Vectorizable loop 1 */
			/* Pre code */
			for (int j12 = 0; j12 < 4; j12 = j12 + 1) {
				fVec2_tmp[j12] = fVec2_perm[j12];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVec2[i] = fSlow9;
			}
			/* Post code */
			for (int j13 = 0; j13 < 4; j13 = j13 + 1) {
				fVec2_perm[j13] = fVec2_tmp[vsize + j13];
			}
			/* Vectorizable loop 2 */
			/* Pre code */
			for (int j14 = 0; j14 < 4; j14 = j14 + 1) {
				iYec0_tmp[j14] = iYec0_perm[j14];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iYec0[i] = fSlow9 != fVec2[i - 1];
			}
			/* Post code */
			for (int j15 = 0; j15 < 4; j15 = j15 + 1) {
				iYec0_perm[j15] = iYec0_tmp[vsize + j15];
			}
			/* Recursive loop 3 */
			/* Pre code */
			for (int j10 = 0; j10 < 4; j10 = j10 + 1) {
				iRec10_tmp[j10] = iRec10_perm[j10];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec10[i] = iRec10[i - 1] + 1;
			}
			/* Post code */
			for (int j11 = 0; j11 < 4; j11 = j11 + 1) {
				iRec10_perm[j11] = iRec10_tmp[vsize + j11];
			}
			/* Vectorizable loop 4 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec2[i] = (iYec0[i - 1] <= 0) & (iYec0[i] > 0);
			}
			/* Recursive loop 5 */
			/* Pre code */
			for (int j16 = 0; j16 < 4; j16 = j16 + 1) {
				iRec11_tmp[j16] = iRec11_perm[j16];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec11[i] = iRec11[i - 1] * (1 - iZec2[i]) + (iRec10[i] + -1) * iZec2[i];
			}
			/* Post code */
			for (int j17 = 0; j17 < 4; j17 = j17 + 1) {
				iRec11_perm[j17] = iRec11_tmp[vsize + j17];
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec4[i] = std::max<float>(std::exp(fSlow11 * float(-1 * (iRec10[i] + (-1 - iRec11[i])))), 0.01f);
			}
			/* Recursive loop 7 */
			/* Pre code */
			for (int j18 = 0; j18 < 4; j18 = j18 + 1) {
				fRec12_tmp[j18] = fRec12_perm[j18];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec12[i] = fConst4 + (fRec12[i - 1] - std::floor(fConst4 + fRec12[i - 1]));
			}
			/* Post code */
			for (int j19 = 0; j19 < 4; j19 = j19 + 1) {
				fRec12_perm[j19] = fRec12_tmp[vsize + j19];
			}
			/* Vectorizable loop 8 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec5[i] = fSlow9 * (1.0f - fZec4[i]) + fSlow12 * fZec4[i];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVbargraph0 = FAUSTFLOAT(fZec5[i]);
				fZec6[i] = fZec5[i];
			}
			/* Vectorizable loop 9 */
			/* Pre code */
			fYec1_idx = (fYec1_idx + fYec1_idx_save) & 8191;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec1[(i + fYec1_idx) & 8191] = std::pow(2.0f, 0.01f * ftbl0mydspSIG0[int(65536.0f * fRec12[i])]);
			}
			/* Post code */
			fYec1_idx_save = vsize;
			/* Vectorizable loop 10 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec7[i] = ((iSlow10) ? 130.81f : fZec6[i]);
			}
			/* Vectorizable loop 11 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec3[i] = fYec1[(i + fYec1_idx - iConst6) & 8191];
				fZec8[i] = fZec7[i] * fZec3[i];
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec10[i] = fSlow16 * fZec8[i];
			}
			/* Vectorizable loop 13 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec11[i] = std::max<float>(fZec10[i], 23.44895f);
			}
			/* Vectorizable loop 14 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec12[i] = std::max<float>(2e+01f, std::fabs(fZec11[i]));
			}
			/* Vectorizable loop 15 */
			/* Pre code */
			for (int j0 = 0; j0 < 4; j0 = j0 + 1) {
				fVec0_tmp[j0] = fVec0_perm[j0];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVec0[i] = fSlow0;
			}
			/* Post code */
			for (int j1 = 0; j1 < 4; j1 = j1 + 1) {
				fVec0_perm[j1] = fVec0_tmp[vsize + j1];
			}
			/* Recursive loop 16 */
			/* Pre code */
			for (int j22 = 0; j22 < 4; j22 = j22 + 1) {
				fRec15_tmp[j22] = fRec15_perm[j22];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec13[i] = fRec15[i - 1] + fConst7 * fZec12[i];
				fRec15[i] = fZec13[i] - std::floor(fZec13[i]);
			}
			/* Post code */
			for (int j23 = 0; j23 < 4; j23 = j23 + 1) {
				fRec15_perm[j23] = fRec15_tmp[vsize + j23];
			}
			/* Recursive loop 17 */
			/* Pre code */
			for (int j6 = 0; j6 < 4; j6 = j6 + 1) {
				iRec7_tmp[j6] = iRec7_perm[j6];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec7[i] = iSlow1 * (iRec7[i - 1] + 1);
			}
			/* Post code */
			for (int j7 = 0; j7 < 4; j7 = j7 + 1) {
				iRec7_perm[j7] = iRec7_tmp[vsize + j7];
			}
			/* Vectorizable loop 18 */
			/* Pre code */
			for (int j24 = 0; j24 < 4; j24 = j24 + 1) {
				fYec2_tmp[j24] = fYec2_perm[j24];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec2[i] = mydsp_faustpower2_f(2.0f * fRec15[i] + -1.0f);
			}
			/* Post code */
			for (int j25 = 0; j25 < 4; j25 = j25 + 1) {
				fYec2_perm[j25] = fYec2_tmp[vsize + j25];
			}
			/* Vectorizable loop 19 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec14[i] = float(iVec1[i - 1]);
			}
			/* Vectorizable loop 20 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec15[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fZec11[i]));
			}
			/* Recursive loop 21 */
			/* Pre code */
			for (int j30 = 0; j30 < 4; j30 = j30 + 1) {
				iRec19_tmp[j30] = iRec19_perm[j30];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec19[i] = 1103515245 * iRec19[i - 1] + 12345;
			}
			/* Post code */
			for (int j31 = 0; j31 < 4; j31 = j31 + 1) {
				iRec19_perm[j31] = iRec19_tmp[vsize + j31];
			}
			/* Recursive loop 22 */
			/* Pre code */
			for (int j2 = 0; j2 < 4; j2 = j2 + 1) {
				fRec6_tmp[j2] = fRec6_perm[j2];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec6[i] = fSlow0 + fRec6[i - 1] * float(fVec0[i - 1] >= fSlow0);
			}
			/* Post code */
			for (int j3 = 0; j3 < 4; j3 = j3 + 1) {
				fRec6_perm[j3] = fRec6_tmp[vsize + j3];
			}
			/* Vectorizable loop 23 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec0[i] = float(iRec7[i]);
			}
			/* Recursive loop 24 */
			/* Pre code */
			for (int j20 = 0; j20 < 4; j20 = j20 + 1) {
				fRec9_tmp[j20] = fRec9_perm[j20];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec9[i] = fRec9[i - 1] + fSlow17 * fZec8[i];
				fRec9[i] = fZec9[i] - std::floor(fZec9[i]);
			}
			/* Post code */
			for (int j21 = 0; j21 < 4; j21 = j21 + 1) {
				fRec9_perm[j21] = fRec9_tmp[vsize + j21];
			}
			/* Vectorizable loop 25 */
			/* Pre code */
			fYec3_idx = (fYec3_idx + fYec3_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec3[(i + fYec3_idx) & 4095] = fZec14[i] * (fYec2[i] - fYec2[i - 1]) / fZec12[i];
			}
			/* Post code */
			fYec3_idx_save = vsize;
			/* Vectorizable loop 26 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec16[i] = int(fZec15[i]);
			}
			/* Vectorizable loop 27 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec17[i] = std::floor(fZec15[i]);
			}
			/* Vectorizable loop 28 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec19[i] = std::max<float>(1.1920929e-07f, std::fabs(fZec10[i]));
			}
			/* Vectorizable loop 29 */
			/* Pre code */
			for (int j32 = 0; j32 < 4; j32 = j32 + 1) {
				fYec4_tmp[j32] = fYec4_perm[j32];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec4[i] = float(iRec19[i]);
			}
			/* Post code */
			for (int j33 = 0; j33 < 4; j33 = j33 + 1) {
				fYec4_perm[j33] = fYec4_tmp[vsize + j33];
			}
			/* Vectorizable loop 30 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec1[i] = std::max<float>(0.0f, std::min<float>(fSlow6 * fRec6[i], std::max<float>(fSlow8 * (fSlow5 - fRec6[i]) + 1.0f, fSlow7)) * (1.0f - fZec0[i] / fSlow4));
			}
			/* Vectorizable loop 31 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec18[i] = fConst9 * (fYec3[(i + fYec3_idx) & 4095] - fYec3[(i + fYec3_idx - iZec16[i]) & 4095] * (fZec17[i] + (1.0f - fZec15[i])) - (fZec15[i] - fZec17[i]) * fYec3[(i + fYec3_idx - (iZec16[i] + 1)) & 4095]);
			}
			/* Recursive loop 32 */
			/* Pre code */
			for (int j28 = 0; j28 < 4; j28 = j28 + 1) {
				fRec16_tmp[j28] = fRec16_perm[j28];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec20[i] = fRec16[i - 1] + fConst7 * fZec19[i];
				fZec21[i] = fZec20[i] + -1.0f;
				iZec22[i] = fZec21[i] < 0.0f;
				fRec16[i] = ((iZec22[i]) ? fZec20[i] : fZec21[i]);
				fRec17[i] = ((iZec22[i]) ? fZec20[i] : fZec20[i] + fZec21[i] * (1.0f - fConst0 / fZec19[i]));
			}
			/* Post code */
			for (int j29 = 0; j29 < 4; j29 = j29 + 1) {
				fRec16_perm[j29] = fRec16_tmp[vsize + j29];
			}
			/* Vectorizable loop 33 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec23[i] = 4.656613e-10f * fYec4[i];
			}
			/* Recursive loop 34 */
			/* Pre code */
			for (int j36 = 0; j36 < 4; j36 = j36 + 1) {
				fRec22_tmp[j36] = fRec22_perm[j36];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec22[i] = fConst18 * (4.656613e-10f * (fConst17 * fYec4[i] + fConst16 * fYec4[i - 1]) - fConst11 * fRec22[i - 1]);
			}
			/* Post code */
			for (int j37 = 0; j37 < 4; j37 = j37 + 1) {
				fRec22_perm[j37] = fRec22_tmp[vsize + j37];
			}
			/* Vectorizable loop 35 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec26[i] = 2.0f * fRec9[i] + -1.0f;
			}
			/* Vectorizable loop 36 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec28[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst39 / fZec11[i]));
			}
			/* Vectorizable loop 37 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec31[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst40 / fZec11[i]));
			}
			/* Recursive loop 38 */
			/* Pre code */
			for (int j8 = 0; j8 < 4; j8 = j8 + 1) {
				fRec8_tmp[j8] = fRec8_perm[j8];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec8[i] = fConst1 * fZec1[i] + fConst2 * fRec8[i - 1];
			}
			/* Post code */
			for (int j9 = 0; j9 < 4; j9 = j9 + 1) {
				fRec8_perm[j9] = fRec8_tmp[vsize + j9];
			}
			/* Recursive loop 39 */
			/* Pre code */
			for (int j26 = 0; j26 < 4; j26 = j26 + 1) {
				fRec14_tmp[j26] = fRec14_perm[j26];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec14[i] = 0.999f * fRec14[i - 1] + fZec18[i];
			}
			/* Post code */
			for (int j27 = 0; j27 < 4; j27 = j27 + 1) {
				fRec14_perm[j27] = fRec14_tmp[vsize + j27];
			}
			/* Recursive loop 40 */
			/* Pre code */
			for (int j34 = 0; j34 < 4; j34 = j34 + 1) {
				fRec18_tmp[j34] = fRec18_perm[j34];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec18[i] = 0.5221894f * fRec18[i - 3] + fZec23[i] + 2.494956f * fRec18[i - 1] - 2.0172658f * fRec18[i - 2];
			}
			/* Post code */
			for (int j35 = 0; j35 < 4; j35 = j35 + 1) {
				fRec18_perm[j35] = fRec18_tmp[vsize + j35];
			}
			/* Recursive loop 41 */
			/* Pre code */
			for (int j38 = 0; j38 < 4; j38 = j38 + 1) {
				fRec21_tmp[j38] = fRec21_perm[j38];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec21[i] = 0.0f - fConst27 * (fConst26 * fRec21[i - 1] - fConst23 * (fConst22 * fRec22[i] + fConst21 * fRec22[i - 1]));
			}
			/* Post code */
			for (int j39 = 0; j39 < 4; j39 = j39 + 1) {
				fRec21_perm[j39] = fRec21_tmp[vsize + j39];
			}
			/* Vectorizable loop 42 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec27[i] = ((iSlow31) ? 2.0f * fRec17[i] + -1.0f : fZec26[i]);
			}
			/* Vectorizable loop 43 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec29[i] = int(fZec28[i]);
			}
			/* Vectorizable loop 44 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec30[i] = std::floor(fZec28[i]);
			}
			/* Vectorizable loop 45 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec32[i] = int(fZec31[i]);
			}
			/* Vectorizable loop 46 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec33[i] = std::floor(fZec31[i]);
			}
			/* Recursive loop 47 */
			/* Pre code */
			for (int j40 = 0; j40 < 4; j40 = j40 + 1) {
				fRec20_tmp[j40] = fRec20_perm[j40];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec20[i] = 0.0f - fConst36 * (fConst35 * fRec20[i - 1] - fConst32 * (fConst31 * fRec21[i] + fConst30 * fRec21[i - 1]));
			}
			/* Post code */
			for (int j41 = 0; j41 < 4; j41 = j41 + 1) {
				fRec20_perm[j41] = fRec20_tmp[vsize + j41];
			}
			/* Recursive loop 48 */
			/* Pre code */
			for (int j42 = 0; j42 < 4; j42 = j42 + 1) {
				fRec23_tmp[j42] = fRec23_perm[j42];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec23[i] = fSlow18 + (fRec23[i - 1] - std::floor(fSlow18 + fRec23[i - 1]));
			}
			/* Post code */
			for (int j43 = 0; j43 < 4; j43 = j43 + 1) {
				fRec23_perm[j43] = fRec23_tmp[vsize + j43];
			}
			/* Vectorizable loop 49 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec25[i] = 0.049922034f * fRec18[i] + 0.0506127f * fRec18[i - 2] - (0.095993534f * fRec18[i - 1] + 0.004408786f * fRec18[i - 3]);
			}
			/* Vectorizable loop 50 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec34[i] = ((iSlow28) ? ((iSlow33) ? ((iSlow31) ? fConst9 * (fYec3[(i + fYec3_idx) & 4095] - fYec3[(i + fYec3_idx - iZec32[i]) & 4095] * (fZec33[i] + (1.0f - fZec31[i])) - (fZec31[i] - fZec33[i]) * fYec3[(i + fYec3_idx - (iZec32[i] + 1)) & 4095]) : 2.0f * float(fRec9[i] <= 0.85f) + -1.0f) : ((iSlow34) ? ((iSlow31) ? fConst9 * (fYec3[(i + fYec3_idx) & 4095] - fYec3[(i + fYec3_idx - iZec29[i]) & 4095] * (fZec30[i] + (1.0f - fZec28[i])) - (fZec28[i] - fZec30[i]) * fYec3[(i + fYec3_idx - (iZec29[i] + 1)) & 4095]) : 2.0f * float(fRec9[i] <= 0.7f) + -1.0f) : ((iSlow31) ? fZec18[i] : 2.0f * float(fRec9[i] <= 0.5f) + -1.0f))) : ((iSlow29) ? fZec27[i] : ((iSlow30) ? 0.0f - fZec27[i] : ((iSlow31) ? fSlow32 * fRec14[i] * fZec7[i] * fZec3[i] : 2.0f * (1.0f - std::fabs(fZec26[i])) + -1.0f))));
			}
			/* Vectorizable loop 51 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec35[i] = ((iSlow2) ? fRec8[i] : fZec1[i]);
			}
			/* Vectorizable loop 52 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec24[i] = fZec6[i] * fYec1[(i + fYec1_idx - iConst5) & 8191];
			}
			/* Vectorizable loop 53 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec36[i] = std::pow(2.0f, fSlow36 * (fSlow35 * ((iSlow26) ? fZec35[i] : fZec34[i]) + fSlow25 * ((iSlow22) ? ((iSlow24) ? 2.0f * float(fRec23[i] <= 0.5f) + -1.0f : 2.0f * (1.0f - std::fabs(2.0f * fRec23[i] + -1.0f)) + -1.0f) : ((iSlow23) ? fConst37 * fRec20[i] : fZec25[i]))));
			}
			/* Vectorizable loop 54 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec50[i] = fZec6[i] * fYec1[(i + fYec1_idx - iConst41) & 8191];
			}
			/* Vectorizable loop 55 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec37[i] = ((iSlow19) ? fSlow21 * fZec24[i] * fZec36[i] : fSlow21 * fZec24[i]);
			}
			/* Vectorizable loop 56 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec51[i] = ((iSlow19) ? fSlow38 * fZec50[i] * fZec36[i] : fSlow38 * fZec50[i]);
			}
			/* Vectorizable loop 57 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec39[i] = std::max<float>(fZec37[i], 23.44895f);
			}
			/* Vectorizable loop 58 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec53[i] = std::max<float>(fZec51[i], 23.44895f);
			}
			/* Vectorizable loop 59 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec40[i] = std::max<float>(2e+01f, std::fabs(fZec39[i]));
			}
			/* Vectorizable loop 60 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec54[i] = std::max<float>(2e+01f, std::fabs(fZec53[i]));
			}
			/* Recursive loop 61 */
			/* Pre code */
			for (int j46 = 0; j46 < 4; j46 = j46 + 1) {
				fRec26_tmp[j46] = fRec26_perm[j46];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec41[i] = fRec26[i - 1] + fConst7 * fZec40[i];
				fRec26[i] = fZec41[i] - std::floor(fZec41[i]);
			}
			/* Post code */
			for (int j47 = 0; j47 < 4; j47 = j47 + 1) {
				fRec26_perm[j47] = fRec26_tmp[vsize + j47];
			}
			/* Recursive loop 62 */
			/* Pre code */
			for (int j56 = 0; j56 < 4; j56 = j56 + 1) {
				fRec31_tmp[j56] = fRec31_perm[j56];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec55[i] = fRec31[i - 1] + fConst7 * fZec54[i];
				fRec31[i] = fZec55[i] - std::floor(fZec55[i]);
			}
			/* Post code */
			for (int j57 = 0; j57 < 4; j57 = j57 + 1) {
				fRec31_perm[j57] = fRec31_tmp[vsize + j57];
			}
			/* Vectorizable loop 63 */
			/* Pre code */
			for (int j48 = 0; j48 < 4; j48 = j48 + 1) {
				fYec5_tmp[j48] = fYec5_perm[j48];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec5[i] = mydsp_faustpower2_f(2.0f * fRec26[i] + -1.0f);
			}
			/* Post code */
			for (int j49 = 0; j49 < 4; j49 = j49 + 1) {
				fYec5_perm[j49] = fYec5_tmp[vsize + j49];
			}
			/* Vectorizable loop 64 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec42[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fZec39[i]));
			}
			/* Vectorizable loop 65 */
			/* Pre code */
			for (int j58 = 0; j58 < 4; j58 = j58 + 1) {
				fYec7_tmp[j58] = fYec7_perm[j58];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec7[i] = mydsp_faustpower2_f(2.0f * fRec31[i] + -1.0f);
			}
			/* Post code */
			for (int j59 = 0; j59 < 4; j59 = j59 + 1) {
				fYec7_perm[j59] = fYec7_tmp[vsize + j59];
			}
			/* Vectorizable loop 66 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec56[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fZec53[i]));
			}
			/* Vectorizable loop 67 */
			/* Pre code */
			fYec6_idx = (fYec6_idx + fYec6_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec6[(i + fYec6_idx) & 4095] = fZec14[i] * (fYec5[i] - fYec5[i - 1]) / fZec40[i];
			}
			/* Post code */
			fYec6_idx_save = vsize;
			/* Vectorizable loop 68 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec43[i] = int(fZec42[i]);
			}
			/* Vectorizable loop 69 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec44[i] = std::floor(fZec42[i]);
			}
			/* Vectorizable loop 70 */
			/* Pre code */
			fYec8_idx = (fYec8_idx + fYec8_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec8[(i + fYec8_idx) & 4095] = fZec14[i] * (fYec7[i] - fYec7[i - 1]) / fZec54[i];
			}
			/* Post code */
			fYec8_idx_save = vsize;
			/* Vectorizable loop 71 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec57[i] = int(fZec56[i]);
			}
			/* Vectorizable loop 72 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec58[i] = std::floor(fZec56[i]);
			}
			/* Recursive loop 73 */
			/* Pre code */
			for (int j44 = 0; j44 < 4; j44 = j44 + 1) {
				fRec24_tmp[j44] = fRec24_perm[j44];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec38[i] = fRec24[i - 1] + fConst7 * fZec37[i];
				fRec24[i] = fZec38[i] - std::floor(fZec38[i]);
			}
			/* Post code */
			for (int j45 = 0; j45 < 4; j45 = j45 + 1) {
				fRec24_perm[j45] = fRec24_tmp[vsize + j45];
			}
			/* Vectorizable loop 74 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec45[i] = fConst9 * (fYec6[(i + fYec6_idx) & 4095] - fYec6[(i + fYec6_idx - iZec43[i]) & 4095] * (fZec44[i] + (1.0f - fZec42[i])) - (fZec42[i] - fZec44[i]) * fYec6[(i + fYec6_idx - (iZec43[i] + 1)) & 4095]);
			}
			/* Vectorizable loop 75 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec46[i] = std::max<float>(1.1920929e-07f, std::fabs(fZec37[i]));
			}
			/* Recursive loop 76 */
			/* Pre code */
			for (int j54 = 0; j54 < 4; j54 = j54 + 1) {
				fRec29_tmp[j54] = fRec29_perm[j54];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec52[i] = fRec29[i - 1] + fConst7 * fZec51[i];
				fRec29[i] = fZec52[i] - std::floor(fZec52[i]);
			}
			/* Post code */
			for (int j55 = 0; j55 < 4; j55 = j55 + 1) {
				fRec29_perm[j55] = fRec29_tmp[vsize + j55];
			}
			/* Vectorizable loop 77 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec59[i] = fConst9 * (fYec8[(i + fYec8_idx) & 4095] - fYec8[(i + fYec8_idx - iZec57[i]) & 4095] * (fZec58[i] + (1.0f - fZec56[i])) - (fZec56[i] - fZec58[i]) * fYec8[(i + fYec8_idx - (iZec57[i] + 1)) & 4095]);
			}
			/* Vectorizable loop 78 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec60[i] = std::max<float>(1.1920929e-07f, std::fabs(fZec51[i]));
			}
			/* Vectorizable loop 79 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec64[i] = ((iSlow40) ? fSlow41 - fSlow44 * fZec35[i] * fSlow45 : fSlow41 + fSlow44 * fZec35[i] * fSlow43);
			}
			/* Recursive loop 80 */
			/* Pre code */
			for (int j50 = 0; j50 < 4; j50 = j50 + 1) {
				fRec25_tmp[j50] = fRec25_perm[j50];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec25[i] = 0.999f * fRec25[i - 1] + fZec45[i];
			}
			/* Post code */
			for (int j51 = 0; j51 < 4; j51 = j51 + 1) {
				fRec25_perm[j51] = fRec25_tmp[vsize + j51];
			}
			/* Recursive loop 81 */
			/* Pre code */
			for (int j52 = 0; j52 < 4; j52 = j52 + 1) {
				fRec27_tmp[j52] = fRec27_perm[j52];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec47[i] = fRec27[i - 1] + fConst7 * fZec46[i];
				fZec48[i] = fZec47[i] + -1.0f;
				iZec49[i] = fZec48[i] < 0.0f;
				fRec27[i] = ((iZec49[i]) ? fZec47[i] : fZec48[i]);
				fRec28[i] = ((iZec49[i]) ? fZec47[i] : fZec47[i] + fZec48[i] * (1.0f - fConst0 / fZec46[i]));
			}
			/* Post code */
			for (int j53 = 0; j53 < 4; j53 = j53 + 1) {
				fRec27_perm[j53] = fRec27_tmp[vsize + j53];
			}
			/* Recursive loop 82 */
			/* Pre code */
			for (int j60 = 0; j60 < 4; j60 = j60 + 1) {
				fRec30_tmp[j60] = fRec30_perm[j60];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec30[i] = 0.999f * fRec30[i - 1] + fZec59[i];
			}
			/* Post code */
			for (int j61 = 0; j61 < 4; j61 = j61 + 1) {
				fRec30_perm[j61] = fRec30_tmp[vsize + j61];
			}
			/* Recursive loop 83 */
			/* Pre code */
			for (int j62 = 0; j62 < 4; j62 = j62 + 1) {
				fRec32_tmp[j62] = fRec32_perm[j62];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec61[i] = fRec32[i - 1] + fConst7 * fZec60[i];
				fZec62[i] = fZec61[i] + -1.0f;
				iZec63[i] = fZec62[i] < 0.0f;
				fRec32[i] = ((iZec63[i]) ? fZec61[i] : fZec62[i]);
				fRec33[i] = ((iZec63[i]) ? fZec61[i] : fZec61[i] + fZec62[i] * (1.0f - fConst0 / fZec60[i]));
			}
			/* Post code */
			for (int j63 = 0; j63 < 4; j63 = j63 + 1) {
				fRec32_perm[j63] = fRec32_tmp[vsize + j63];
			}
			/* Vectorizable loop 84 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec65[i] = std::tan(1.5707964f * std::min<float>(std::max<float>(4.5351473e-05f * ((iSlow39) ? fZec64[i] * fZec36[i] : fZec64[i]), 0.00045351475f), 0.90702945f));
			}
			/* Vectorizable loop 85 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec67[i] = 2.0f * fRec29[i] + -1.0f;
			}
			/* Vectorizable loop 86 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec70[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst39 / fZec53[i]));
			}
			/* Vectorizable loop 87 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec73[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst40 / fZec53[i]));
			}
			/* Vectorizable loop 88 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec76[i] = 2.0f * fRec24[i] + -1.0f;
			}
			/* Vectorizable loop 89 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec79[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst39 / fZec39[i]));
			}
			/* Vectorizable loop 90 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec82[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst40 / fZec39[i]));
			}
			/* Vectorizable loop 91 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec89[i] = std::max<float>(0.0f, std::min<float>(fSlow73 * fRec6[i], std::max<float>(fSlow75 * (fSlow72 - fRec6[i]) + 1.0f, fSlow74)) * (1.0f - fZec0[i] / fSlow71));
			}
			/* Vectorizable loop 92 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec66[i] = fZec65[i] + 1.0f;
			}
			/* Vectorizable loop 93 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec68[i] = ((iSlow56) ? fConst38 * fRec30[i] * fZec51[i] : 2.0f * (1.0f - std::fabs(fZec67[i])) + -1.0f);
			}
			/* Vectorizable loop 94 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec69[i] = ((iSlow56) ? 2.0f * fRec33[i] + -1.0f : fZec67[i]);
			}
			/* Vectorizable loop 95 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec71[i] = int(fZec70[i]);
			}
			/* Vectorizable loop 96 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec72[i] = std::floor(fZec70[i]);
			}
			/* Vectorizable loop 97 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec74[i] = int(fZec73[i]);
			}
			/* Vectorizable loop 98 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec75[i] = std::floor(fZec73[i]);
			}
			/* Vectorizable loop 99 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec77[i] = ((iSlow64) ? fConst38 * fRec25[i] * fZec37[i] : 2.0f * (1.0f - std::fabs(fZec76[i])) + -1.0f);
			}
			/* Vectorizable loop 100 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec78[i] = ((iSlow64) ? 2.0f * fRec28[i] + -1.0f : fZec76[i]);
			}
			/* Vectorizable loop 101 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec80[i] = int(fZec79[i]);
			}
			/* Vectorizable loop 102 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec81[i] = std::floor(fZec79[i]);
			}
			/* Vectorizable loop 103 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec83[i] = int(fZec82[i]);
			}
			/* Vectorizable loop 104 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec84[i] = std::floor(fZec82[i]);
			}
			/* Recursive loop 105 */
			/* Pre code */
			for (int j72 = 0; j72 < 4; j72 = j72 + 1) {
				fRec34_tmp[j72] = fRec34_perm[j72];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec34[i] = fConst1 * fZec89[i] + fConst2 * fRec34[i - 1];
			}
			/* Post code */
			for (int j73 = 0; j73 < 4; j73 = j73 + 1) {
				fRec34_perm[j73] = fRec34_tmp[vsize + j73];
			}
			/* Recursive loop 106 */
			/* Pre code */
			for (int j64 = 0; j64 < 4; j64 = j64 + 1) {
				fRec1_tmp[j64] = fRec1_perm[j64];
			}
			for (int j66 = 0; j66 < 4; j66 = j66 + 1) {
				fRec2_tmp[j66] = fRec2_perm[j66];
			}
			for (int j68 = 0; j68 < 4; j68 = j68 + 1) {
				fRec3_tmp[j68] = fRec3_perm[j68];
			}
			for (int j70 = 0; j70 < 4; j70 = j70 + 1) {
				fRec4_tmp[j70] = fRec4_perm[j70];
			}
			for (int j74 = 0; j74 < 4; j74 = j74 + 1) {
				fRec0_tmp[j74] = fRec0_perm[j74];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec85[i] = fZec65[i] * ((fSlow69 * (fSlow68 * (fSlow67 * ((iSlow61) ? ((iSlow65) ? ((iSlow64) ? fConst9 * (fYec6[(i + fYec6_idx) & 4095] - fYec6[(i + fYec6_idx - iZec83[i]) & 4095] * (fZec84[i] + (1.0f - fZec82[i])) - (fZec82[i] - fZec84[i]) * fYec6[(i + fYec6_idx - (iZec83[i] + 1)) & 4095]) : 2.0f * float(fRec24[i] <= 0.85f) + -1.0f) : ((iSlow66) ? ((iSlow64) ? fConst9 * (fYec6[(i + fYec6_idx) & 4095] - fYec6[(i + fYec6_idx - iZec80[i]) & 4095] * (fZec81[i] + (1.0f - fZec79[i])) - (fZec79[i] - fZec81[i]) * fYec6[(i + fYec6_idx - (iZec80[i] + 1)) & 4095]) : 2.0f * float(fRec24[i] <= 0.7f) + -1.0f) : ((iSlow64) ? fZec45[i] : 2.0f * float(fRec24[i] <= 0.5f) + -1.0f))) : ((iSlow62) ? fZec78[i] : ((iSlow63) ? 0.5f * (fZec77[i] + fZec78[i]) : fZec77[i]))) + fSlow59 * ((iSlow53) ? ((iSlow57) ? ((iSlow56) ? fConst9 * (fYec8[(i + fYec8_idx) & 4095] - fYec8[(i + fYec8_idx - iZec74[i]) & 4095] * (fZec75[i] + (1.0f - fZec73[i])) - (fZec73[i] - fZec75[i]) * fYec8[(i + fYec8_idx - (iZec74[i] + 1)) & 4095]) : 2.0f * float(fRec29[i] <= 0.85f) + -1.0f) : ((iSlow58) ? ((iSlow56) ? fConst9 * (fYec8[(i + fYec8_idx) & 4095] - fYec8[(i + fYec8_idx - iZec71[i]) & 4095] * (fZec72[i] + (1.0f - fZec70[i])) - (fZec70[i] - fZec72[i]) * fYec8[(i + fYec8_idx - (iZec71[i] + 1)) & 4095]) : 2.0f * float(fRec29[i] <= 0.7f) + -1.0f) : ((iSlow56) ? fZec59[i] : 2.0f * float(fRec29[i] <= 0.5f) + -1.0f))) : ((iSlow54) ? fZec69[i] : ((iSlow55) ? 0.5f * (fZec68[i] + fZec69[i]) : fZec68[i]))) + fSlow51 * fZec34[i]) + fSlow50 * ((iSlow23) ? fZec25[i] : fZec23[i])) + fSlow49 * fRec0[i - 1] - fSlow46 * (1.0f - fZec65[i] / fZec66[i]) * (fRec4[i - 1] + fZec65[i] * (fRec3[i - 1] + fZec65[i] * (fRec2[i - 1] + fZec65[i] * fRec1[i - 1] / fZec66[i]) / fZec66[i]) / fZec66[i])) / (fSlow46 * (mydsp_faustpower4_f(fZec65[i]) / mydsp_faustpower4_f(fZec66[i])) + 1.0f) - fRec1[i - 1]) / fZec66[i];
				fRec1[i] = fRec1[i - 1] + 2.0f * fZec85[i];
				fZec86[i] = fZec65[i] * (fRec1[i - 1] + fZec85[i] - fRec2[i - 1]) / fZec66[i];
				fRec2[i] = fRec2[i - 1] + 2.0f * fZec86[i];
				fZec87[i] = fZec65[i] * (fRec2[i - 1] + fZec86[i] - fRec3[i - 1]) / fZec66[i];
				fRec3[i] = fRec3[i - 1] + 2.0f * fZec87[i];
				fZec88[i] = fZec65[i] * (fRec3[i - 1] + fZec87[i] - fRec4[i - 1]) / fZec66[i];
				fRec4[i] = fRec4[i - 1] + 2.0f * fZec88[i];
				fRec5[i] = fRec4[i - 1] + fZec88[i];
				fRec0[i] = fRec5[i] * ((iSlow2) ? fRec34[i] : fZec89[i]);
			}
			/* Post code */
			for (int j65 = 0; j65 < 4; j65 = j65 + 1) {
				fRec1_perm[j65] = fRec1_tmp[vsize + j65];
			}
			for (int j67 = 0; j67 < 4; j67 = j67 + 1) {
				fRec2_perm[j67] = fRec2_tmp[vsize + j67];
			}
			for (int j69 = 0; j69 < 4; j69 = j69 + 1) {
				fRec3_perm[j69] = fRec3_tmp[vsize + j69];
			}
			for (int j71 = 0; j71 < 4; j71 = j71 + 1) {
				fRec4_perm[j71] = fRec4_tmp[vsize + j71];
			}
			for (int j75 = 0; j75 < 4; j75 = j75 + 1) {
				fRec0_perm[j75] = fRec0_tmp[vsize + j75];
			}
			/* Vectorizable loop 107 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec90[i] = fSlow80 * fSlow79 * atanhf(std::max<float>(-0.9999999f, std::min<float>(0.9999999f, ((iSlow76) ? fSlow78 * fRec0[i] : fRec0[i]) + ((iSlow76) ? fSlow77 * fRec0[i] : 0.0f))));
			}
			/* Vectorizable loop 108 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(fZec90[i]);
			}
			/* Vectorizable loop 109 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				output1[i] = FAUSTFLOAT(fZec90[i]);
			}
		}
	}

};

#endif
