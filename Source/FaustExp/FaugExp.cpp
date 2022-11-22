/* ------------------------------------------------------------
name: "Faug"
Code generated with Faust 2.53.2 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -mcd 16 -single -ftz 0 -vec -lv 1 -vs 8 -g
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
	int iRec14[2];
	
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
			iRec14[l11] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec3[0] = 1;
			iRec14[0] = (iVec3[1] + iRec14[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec14[0]));
			iVec3[1] = iVec3[0];
			iRec14[1] = iRec14[0];
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
	
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fEntry0;
	float fVec0_perm[4];
	float fVec1_perm[4];
	float fRec7_perm[4];
	int iVec2_perm[4];
	int iRec8_perm[4];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec9_perm[4];
	int iRec11_perm[4];
	int iYec0_perm[4];
	int iRec12_perm[4];
	float fConst3;
	float fRec13_perm[4];
	float fYec1[8192];
	int fYec1_idx;
	int fYec1_idx_save;
	int iConst4;
	int iConst5;
	FAUSTFLOAT fCheckbox3;
	FAUSTFLOAT fHslider3;
	float fConst6;
	FAUSTFLOAT fCheckbox4;
	FAUSTFLOAT fEntry1;
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fRec10_perm[4];
	float fRec16_perm[4];
	float fYec2_perm[4];
	float fYec3[4096];
	int fYec3_idx;
	int fYec3_idx_save;
	float fConst7;
	float fConst8;
	float fRec15_perm[4];
	float fRec17_perm[4];
	FAUSTFLOAT fHslider8;
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	float fYec4_perm[4];
	float fRec19_perm[4];
	int iRec20_perm[4];
	float fRec21_perm[4];
	int iRec23_perm[4];
	float fYec5_perm[4];
	float fRec22_perm[4];
	float fConst10;
	float fConst15;
	float fConst16;
	float fConst17;
	float fRec26_perm[4];
	float fConst20;
	float fConst21;
	float fConst22;
	float fConst25;
	float fConst26;
	float fRec25_perm[4];
	float fConst29;
	float fConst30;
	float fConst31;
	float fConst34;
	float fConst35;
	float fRec24_perm[4];
	FAUSTFLOAT fHslider11;
	float fRec27_perm[4];
	FAUSTFLOAT fHslider12;
	float fYec6_perm[4];
	float fRec29_perm[4];
	int iRec30_perm[4];
	float fRec31_perm[4];
	FAUSTFLOAT fCheckbox5;
	FAUSTFLOAT fCheckbox6;
	FAUSTFLOAT fHslider13;
	float fConst36;
	float fConst37;
	float fConst38;
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fCheckbox7;
	FAUSTFLOAT fCheckbox8;
	float fConst39;
	FAUSTFLOAT fCheckbox9;
	FAUSTFLOAT fHslider15;
	float fRec28_perm[4];
	float fRec33_perm[4];
	float fYec7_perm[4];
	float fYec8[4096];
	int fYec8_idx;
	int fYec8_idx_save;
	float fRec32_perm[4];
	float fRec34_perm[4];
	int iConst40;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	float fYec9_perm[4];
	float fRec37_perm[4];
	int iRec38_perm[4];
	float fRec39_perm[4];
	float fRec36_perm[4];
	float fRec41_perm[4];
	float fYec10_perm[4];
	float fYec11[4096];
	int fYec11_idx;
	int fYec11_idx_save;
	float fRec40_perm[4];
	float fRec42_perm[4];
	FAUSTFLOAT fCheckbox10;
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
	float fRec2_perm[4];
	float fRec3_perm[4];
	float fRec4_perm[4];
	float fRec5_perm[4];
	FAUSTFLOAT fButton0;
	float fVec4_perm[4];
	float fRec44_perm[4];
	int iRec45_perm[4];
	FAUSTFLOAT fHslider27;
	FAUSTFLOAT fHslider28;
	float fConst41;
	FAUSTFLOAT fHslider29;
	float fRec46_perm[4];
	float fRec1_perm[4];
	float fYec12_perm[4];
	float fRec0_perm[8];
	FAUSTFLOAT fCheckbox16;
	FAUSTFLOAT fHslider30;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("aanl.lib/name", "Faust Antialiased Nonlinearities");
		m->declare("aanl.lib/version", "0.3");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.8");
		m->declare("compile_options", "-lang cpp -es 1 -mcd 16 -single -ftz 0 -vec -lv 1 -vs 8 -g");
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
		fConst3 = 0.05f / fConst0;
		iConst4 = int(0.01f * fConst0);
		iConst5 = 3 * iConst4;
		fConst6 = 1.0f / fConst0;
		fConst7 = 0.5f * fConst0;
		fConst8 = 0.25f * fConst0;
		float fConst9 = 1.0f / std::tan(0.5f / fConst0);
		fConst10 = 125.663704f - fConst9;
		float fConst11 = std::tan(62.831852f / fConst0);
		float fConst12 = std::sqrt(0.0175f * fConst0);
		float fConst13 = std::tan(62.831852f * (std::sqrt(std::sqrt(fConst12)) / fConst0));
		float fConst14 = 125.663704f * (fConst13 / fConst11);
		fConst15 = fConst14 - fConst9;
		fConst16 = fConst9 + fConst14;
		fConst17 = 1.0f / (fConst9 + 125.663704f);
		float fConst18 = std::tan(62.831852f * (std::pow(fConst12, 1.25f) / fConst0));
		float fConst19 = 125.663704f * (fConst18 / fConst11);
		fConst20 = fConst19 - fConst9;
		fConst21 = fConst9 + fConst19;
		fConst22 = fConst11 / fConst13;
		float fConst23 = std::tan(62.831852f * (fConst12 / fConst0));
		float fConst24 = 125.663704f * (fConst23 / fConst11);
		fConst25 = fConst24 - fConst9;
		fConst26 = 1.0f / (fConst9 + fConst24);
		float fConst27 = std::tan(62.831852f * (std::pow(fConst12, 2.25f) / fConst0));
		float fConst28 = 125.663704f * (fConst27 / fConst11);
		fConst29 = fConst28 - fConst9;
		fConst30 = fConst9 + fConst28;
		fConst31 = fConst23 / fConst18;
		float fConst32 = std::tan(62.831852f * (mydsp_faustpower2_f(fConst12) / fConst0));
		float fConst33 = 125.663704f * (fConst32 / fConst11);
		fConst34 = fConst33 - fConst9;
		fConst35 = 1.0f / (fConst9 + fConst33);
		fConst36 = 4.0f / fConst0;
		fConst37 = 0.7f * fConst0;
		fConst38 = 0.85f * fConst0;
		fConst39 = fConst32 / fConst27;
		iConst40 = 2 * iConst4;
		fConst41 = 0.001f * fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fEntry0 = FAUSTFLOAT(4.4e+02f);
		fCheckbox2 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(4.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(0.8f);
		fCheckbox3 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.01f);
		fCheckbox4 = FAUSTFLOAT(0.0f);
		fEntry1 = FAUSTFLOAT(4.4e+02f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(0.0f);
		fHslider7 = FAUSTFLOAT(2.0f);
		fHslider8 = FAUSTFLOAT(0.0f);
		fHslider9 = FAUSTFLOAT(0.5f);
		fHslider10 = FAUSTFLOAT(0.0f);
		fHslider11 = FAUSTFLOAT(1e+01f);
		fHslider12 = FAUSTFLOAT(2.0f);
		fCheckbox5 = FAUSTFLOAT(0.0f);
		fCheckbox6 = FAUSTFLOAT(0.0f);
		fHslider13 = FAUSTFLOAT(1.0f);
		fHslider14 = FAUSTFLOAT(0.0f);
		fCheckbox7 = FAUSTFLOAT(0.0f);
		fCheckbox8 = FAUSTFLOAT(0.0f);
		fCheckbox9 = FAUSTFLOAT(0.0f);
		fHslider15 = FAUSTFLOAT(0.0f);
		fHslider16 = FAUSTFLOAT(0.0f);
		fHslider17 = FAUSTFLOAT(2.0f);
		fCheckbox10 = FAUSTFLOAT(0.0f);
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
		fButton0 = FAUSTFLOAT(0.0f);
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
			fVec1_perm[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 4; l2 = l2 + 1) {
			fRec7_perm[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 4; l3 = l3 + 1) {
			iVec2_perm[l3] = 0;
		}
		for (int l4 = 0; l4 < 4; l4 = l4 + 1) {
			iRec8_perm[l4] = 0;
		}
		for (int l5 = 0; l5 < 4; l5 = l5 + 1) {
			fRec9_perm[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 4; l6 = l6 + 1) {
			iRec11_perm[l6] = 0;
		}
		for (int l7 = 0; l7 < 4; l7 = l7 + 1) {
			iYec0_perm[l7] = 0;
		}
		for (int l8 = 0; l8 < 4; l8 = l8 + 1) {
			iRec12_perm[l8] = 0;
		}
		for (int l9 = 0; l9 < 4; l9 = l9 + 1) {
			fRec13_perm[l9] = 0.0f;
		}
		for (int l12 = 0; l12 < 8192; l12 = l12 + 1) {
			fYec1[l12] = 0.0f;
		}
		fYec1_idx = 0;
		fYec1_idx_save = 0;
		for (int l13 = 0; l13 < 4; l13 = l13 + 1) {
			fRec10_perm[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 4; l14 = l14 + 1) {
			fRec16_perm[l14] = 0.0f;
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
			fRec15_perm[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 4; l18 = l18 + 1) {
			fRec17_perm[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 4; l19 = l19 + 1) {
			fYec4_perm[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 4; l20 = l20 + 1) {
			fRec19_perm[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 4; l21 = l21 + 1) {
			iRec20_perm[l21] = 0;
		}
		for (int l22 = 0; l22 < 4; l22 = l22 + 1) {
			fRec21_perm[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 4; l23 = l23 + 1) {
			iRec23_perm[l23] = 0;
		}
		for (int l24 = 0; l24 < 4; l24 = l24 + 1) {
			fYec5_perm[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 4; l25 = l25 + 1) {
			fRec22_perm[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 4; l26 = l26 + 1) {
			fRec26_perm[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 4; l27 = l27 + 1) {
			fRec25_perm[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 4; l28 = l28 + 1) {
			fRec24_perm[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 4; l29 = l29 + 1) {
			fRec27_perm[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 4; l30 = l30 + 1) {
			fYec6_perm[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 4; l31 = l31 + 1) {
			fRec29_perm[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 4; l32 = l32 + 1) {
			iRec30_perm[l32] = 0;
		}
		for (int l33 = 0; l33 < 4; l33 = l33 + 1) {
			fRec31_perm[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 4; l34 = l34 + 1) {
			fRec28_perm[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 4; l35 = l35 + 1) {
			fRec33_perm[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 4; l36 = l36 + 1) {
			fYec7_perm[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 4096; l37 = l37 + 1) {
			fYec8[l37] = 0.0f;
		}
		fYec8_idx = 0;
		fYec8_idx_save = 0;
		for (int l38 = 0; l38 < 4; l38 = l38 + 1) {
			fRec32_perm[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 4; l39 = l39 + 1) {
			fRec34_perm[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 4; l40 = l40 + 1) {
			fYec9_perm[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 4; l41 = l41 + 1) {
			fRec37_perm[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 4; l42 = l42 + 1) {
			iRec38_perm[l42] = 0;
		}
		for (int l43 = 0; l43 < 4; l43 = l43 + 1) {
			fRec39_perm[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 4; l44 = l44 + 1) {
			fRec36_perm[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 4; l45 = l45 + 1) {
			fRec41_perm[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 4; l46 = l46 + 1) {
			fYec10_perm[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 4096; l47 = l47 + 1) {
			fYec11[l47] = 0.0f;
		}
		fYec11_idx = 0;
		fYec11_idx_save = 0;
		for (int l48 = 0; l48 < 4; l48 = l48 + 1) {
			fRec40_perm[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 4; l49 = l49 + 1) {
			fRec42_perm[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 4; l50 = l50 + 1) {
			fRec2_perm[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 4; l51 = l51 + 1) {
			fRec3_perm[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 4; l52 = l52 + 1) {
			fRec4_perm[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 4; l53 = l53 + 1) {
			fRec5_perm[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 4; l54 = l54 + 1) {
			fVec4_perm[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 4; l55 = l55 + 1) {
			fRec44_perm[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 4; l56 = l56 + 1) {
			iRec45_perm[l56] = 0;
		}
		for (int l57 = 0; l57 < 4; l57 = l57 + 1) {
			fRec46_perm[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 4; l58 = l58 + 1) {
			fRec1_perm[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 4; l59 = l59 + 1) {
			fYec12_perm[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 8; l60 = l60 + 1) {
			fRec0_perm[l60] = 0.0f;
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
		ui_interface->declare(&fCheckbox4, "05", "");
		ui_interface->addCheckButton("glideOn", &fCheckbox4);
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
		ui_interface->declare(&fCheckbox5, "12", "");
		ui_interface->addCheckButton("oscModOn", &fCheckbox5);
		ui_interface->declare(&fCheckbox3, "13", "");
		ui_interface->addCheckButton("oscThreeKeyTrack", &fCheckbox3);
		ui_interface->declare(&fHslider24, "14", "");
		ui_interface->declare(&fHslider24, "style", "knob");
		ui_interface->addHorizontalSlider("waveOne", &fHslider24, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider22, "15", "");
		ui_interface->declare(&fHslider22, "style", "knob");
		ui_interface->addHorizontalSlider("waveTwo", &fHslider22, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider13, "16", "");
		ui_interface->declare(&fHslider13, "style", "knob");
		ui_interface->addHorizontalSlider("waveThree", &fHslider13, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider12, "17", "");
		ui_interface->declare(&fHslider12, "style", "knob");
		ui_interface->addHorizontalSlider("rangeOne", &fHslider12, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider17, "18", "");
		ui_interface->declare(&fHslider17, "style", "knob");
		ui_interface->addHorizontalSlider("rangeTwo", &fHslider17, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider7, "19", "");
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->addHorizontalSlider("rangeThree", &fHslider7, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider6, "20", "");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->addHorizontalSlider("globalDetune", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2.5f), FAUSTFLOAT(2.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider16, "21", "");
		ui_interface->declare(&fHslider16, "style", "knob");
		ui_interface->addHorizontalSlider("detuneTwo", &fHslider16, FAUSTFLOAT(0.0f), FAUSTFLOAT(-7.5f), FAUSTFLOAT(7.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider5, "22", "");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("detuneThree", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(-7.5f), FAUSTFLOAT(7.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox2, "23", "");
		ui_interface->addCheckButton("decayOn", &fCheckbox2);
		ui_interface->declare(&fHslider28, "24", "");
		ui_interface->declare(&fHslider28, "style", "knob");
		ui_interface->addHorizontalSlider("attack", &fHslider28, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider27, "25", "");
		ui_interface->declare(&fHslider27, "style", "knob");
		ui_interface->addHorizontalSlider("decay", &fHslider27, FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(2.4e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider29, "26", "");
		ui_interface->declare(&fHslider29, "style", "knob");
		ui_interface->addHorizontalSlider("sustain", &fHslider29, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider9, "27", "");
		ui_interface->declare(&fHslider9, "style", "knob");
		ui_interface->addHorizontalSlider("cutoff", &fHslider9, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.00045351475f), FAUSTFLOAT(0.90702945f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fCheckbox1, "28", "");
		ui_interface->addCheckButton("keyTrackOne", &fCheckbox1);
		ui_interface->declare(&fCheckbox0, "29", "");
		ui_interface->addCheckButton("keyTrackTwo", &fCheckbox0);
		ui_interface->declare(&fHslider8, "30", "");
		ui_interface->declare(&fHslider8, "style", "radio{'+':0;'-':1}");
		ui_interface->addHorizontalSlider("contour_direction", &fHslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider10, "31", "");
		ui_interface->declare(&fHslider10, "style", "knob");
		ui_interface->addHorizontalSlider("contourAmount", &fHslider10, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider1, "32", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("fAttack", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(7e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "33", "");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("fDecay", &fHslider0, FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(3e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "34", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("fSustain", &fHslider2, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox10, "35", "");
		ui_interface->addCheckButton("filterModOn", &fCheckbox10);
		ui_interface->declare(&fHslider18, "36", "");
		ui_interface->declare(&fHslider18, "style", "knob");
		ui_interface->addHorizontalSlider("emphasis", &fHslider18, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.707f), FAUSTFLOAT(25.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fCheckbox8, "37", "");
		ui_interface->addCheckButton("noiseType", &fCheckbox8);
		ui_interface->declare(&fCheckbox12, "38", "");
		ui_interface->addCheckButton("noiseOn", &fCheckbox12);
		ui_interface->declare(&fHslider20, "39", "");
		ui_interface->declare(&fHslider20, "style", "knob");
		ui_interface->addHorizontalSlider("noiseGain", &fHslider20, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox6, "40", "");
		ui_interface->addCheckButton("oscThree_filterEg", &fCheckbox6);
		ui_interface->declare(&fHslider11, "41", "");
		ui_interface->declare(&fHslider11, "style", "knob");
		ui_interface->addHorizontalSlider("lfoRate", &fHslider11, FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.5f), FAUSTFLOAT(2e+02f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox9, "42", "");
		ui_interface->addCheckButton("lfoShape", &fCheckbox9);
		ui_interface->declare(&fCheckbox7, "43", "");
		ui_interface->addCheckButton("noise_lfo", &fCheckbox7);
		ui_interface->declare(&fHslider14, "44", "");
		ui_interface->declare(&fHslider14, "style", "knob");
		ui_interface->addHorizontalSlider("modMix", &fHslider14, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider15, "45", "");
		ui_interface->declare(&fHslider15, "style", "knob");
		ui_interface->addHorizontalSlider("modAmount", &fHslider15, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
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
		float fSlow0 = float(fEntry0);
		float fVec0_tmp[12];
		float* fVec0 = &fVec0_tmp[4];
		float fSlow1 = (fSlow0 + -130.81f) * (float(fCheckbox1) + 2.0f * float(fCheckbox0));
		float fVec1_tmp[12];
		float* fVec1 = &fVec1_tmp[4];
		float fSlow2 = 0.33333334f * fSlow1;
		float fRec7_tmp[12];
		float* fRec7 = &fRec7_tmp[4];
		int iVec2_tmp[12];
		int* iVec2 = &iVec2_tmp[4];
		int iSlow3 = fSlow2 == 0.0f;
		int iRec8_tmp[12];
		int* iRec8 = &iRec8_tmp[4];
		int iSlow4 = int(float(fCheckbox2));
		float fSlow5 = float(fHslider0);
		float fSlow6 = std::max<float>(1.0f, fConst0 * ((iSlow4) ? fSlow5 : 1e+01f));
		float fSlow7 = std::max<float>(1.0f, fConst0 * float(fHslider1));
		float fSlow8 = 1.0f / fSlow7;
		float fSlow9 = float(fHslider2);
		float fSlow10 = (1.0f - fSlow9) / std::max<float>(1.0f, fConst0 * fSlow5);
		float fZec0[8];
		float fRec9_tmp[12];
		float* fRec9 = &fRec9_tmp[4];
		int iRec11_tmp[12];
		int* iRec11 = &iRec11_tmp[4];
		int iYec0_tmp[12];
		int* iYec0 = &iYec0_tmp[4];
		int iZec1[8];
		int iRec12_tmp[12];
		int* iRec12 = &iRec12_tmp[4];
		float fRec13_tmp[12];
		float* fRec13 = &fRec13_tmp[4];
		float fZec2[8];
		int iSlow11 = int(float(fCheckbox3));
		float fSlow12 = fConst6 / float(fHslider3);
		float fZec3[8];
		float fSlow13 = ((int(float(fCheckbox4))) ? float(fEntry1) : fSlow0);
		float fZec4[8];
		float fZec5[8];
		float fZec6[8];
		float fZec7[8];
		float fSlow14 = std::pow(2.0f, 0.083333336f * float(fHslider4));
		float fSlow15 = float(fHslider6);
		float fSlow16 = float(fHslider7);
		float fSlow17 = std::pow(2.0f, fSlow16 + -4.0f) * std::pow(2.0f, 0.083333336f * (fSlow15 + float(fHslider5))) * fSlow14;
		float fSlow18 = fConst6 * fSlow17;
		float fZec8[8];
		float fRec10_tmp[12];
		float* fRec10 = &fRec10_tmp[4];
		float fZec9[8];
		float fZec10[8];
		float fZec11[8];
		float fZec12[8];
		float fRec16_tmp[12];
		float* fRec16 = &fRec16_tmp[4];
		float fYec2_tmp[12];
		float* fYec2 = &fYec2_tmp[4];
		float fZec13[8];
		float fZec14[8];
		int iZec15[8];
		float fZec16[8];
		float fZec17[8];
		float fRec15_tmp[12];
		float* fRec15 = &fRec15_tmp[4];
		float fZec18[8];
		float fZec19[8];
		float fZec20[8];
		int iZec21[8];
		float fRec17_tmp[12];
		float* fRec17 = &fRec17_tmp[4];
		float fRec18[8];
		int iSlow19 = int(float(fHslider8));
		float fSlow20 = float(fHslider9);
		float fSlow21 = ((iSlow19) ? 0.0625f * fSlow20 : std::min<float>(16.0f * fSlow20, 0.90702945f));
		float fSlow22 = fSlow21 - fSlow2;
		float fZec22[8];
		float fSlow23 = float(fHslider10);
		float fSlow24 = fSlow2 - fSlow21;
		float fZec23[8];
		float fSlow25 = fConst0 * fSlow20;
		float fYec4_tmp[12];
		float* fYec4 = &fYec4_tmp[4];
		float fRec19_tmp[12];
		float* fRec19 = &fRec19_tmp[4];
		int iRec20_tmp[12];
		int* iRec20 = &iRec20_tmp[4];
		float fZec24[8];
		float fRec21_tmp[12];
		float* fRec21 = &fRec21_tmp[4];
		int iRec23_tmp[12];
		int* iRec23 = &iRec23_tmp[4];
		float fYec5_tmp[12];
		float* fYec5 = &fYec5_tmp[4];
		float fZec25[8];
		float fRec22_tmp[12];
		float* fRec22 = &fRec22_tmp[4];
		float fRec26_tmp[12];
		float* fRec26 = &fRec26_tmp[4];
		float fRec25_tmp[12];
		float* fRec25 = &fRec25_tmp[4];
		float fRec24_tmp[12];
		float* fRec24 = &fRec24_tmp[4];
		float fSlow26 = fConst6 * float(fHslider11);
		float fRec27_tmp[12];
		float* fRec27 = &fRec27_tmp[4];
		float fZec26[8];
		float fSlow27 = float(fHslider12);
		float fSlow28 = fSlow14 * std::pow(2.0f, fSlow27 + -4.0f) * std::pow(2.0f, 0.083333336f * fSlow15);
		float fYec6_tmp[12];
		float* fYec6 = &fYec6_tmp[4];
		float fRec29_tmp[12];
		float* fRec29 = &fRec29_tmp[4];
		int iRec30_tmp[12];
		int* iRec30 = &iRec30_tmp[4];
		float fZec27[8];
		float fRec31_tmp[12];
		float* fRec31 = &fRec31_tmp[4];
		int iSlow29 = int(float(fCheckbox5));
		int iSlow30 = int(float(fCheckbox6));
		float fSlow31 = float(fHslider13);
		int iSlow32 = fSlow31 >= 3.0f;
		int iSlow33 = fSlow31 >= 2.0f;
		int iSlow34 = fSlow31 >= 1.0f;
		int iSlow35 = int(fSlow16);
		float fZec28[8];
		float fSlow36 = fConst36 * fSlow17;
		float fZec29[8];
		int iSlow37 = fSlow31 >= 5.0f;
		int iSlow38 = fSlow31 >= 4.0f;
		float fZec30[8];
		int iZec31[8];
		float fZec32[8];
		float fZec33[8];
		int iZec34[8];
		float fZec35[8];
		float fZec36[8];
		float fSlow39 = float(fHslider14);
		float fSlow40 = 1.0f - fSlow39;
		int iSlow41 = int(float(fCheckbox7));
		int iSlow42 = int(float(fCheckbox8));
		float fZec37[8];
		int iSlow43 = int(float(fCheckbox9));
		float fZec38[8];
		float fSlow44 = float(fHslider15);
		float fZec39[8];
		float fZec40[8];
		float fRec28_tmp[12];
		float* fRec28 = &fRec28_tmp[4];
		float fZec41[8];
		float fZec42[8];
		float fZec43[8];
		float fRec33_tmp[12];
		float* fRec33 = &fRec33_tmp[4];
		float fYec7_tmp[12];
		float* fYec7 = &fYec7_tmp[4];
		float fZec44[8];
		int iZec45[8];
		float fZec46[8];
		float fZec47[8];
		float fRec32_tmp[12];
		float* fRec32 = &fRec32_tmp[4];
		float fZec48[8];
		float fZec49[8];
		float fZec50[8];
		int iZec51[8];
		float fRec34_tmp[12];
		float* fRec34 = &fRec34_tmp[4];
		float fRec35[8];
		float fZec52[8];
		float fSlow45 = float(fHslider17);
		float fSlow46 = fSlow14 * std::pow(2.0f, fSlow45 + -4.0f) * std::pow(2.0f, 0.083333336f * (fSlow15 + float(fHslider16)));
		float fYec9_tmp[12];
		float* fYec9 = &fYec9_tmp[4];
		float fRec37_tmp[12];
		float* fRec37 = &fRec37_tmp[4];
		int iRec38_tmp[12];
		int* iRec38 = &iRec38_tmp[4];
		float fZec53[8];
		float fRec39_tmp[12];
		float* fRec39 = &fRec39_tmp[4];
		float fZec54[8];
		float fZec55[8];
		float fRec36_tmp[12];
		float* fRec36 = &fRec36_tmp[4];
		float fZec56[8];
		float fZec57[8];
		float fZec58[8];
		float fRec41_tmp[12];
		float* fRec41 = &fRec41_tmp[4];
		float fYec10_tmp[12];
		float* fYec10 = &fYec10_tmp[4];
		float fZec59[8];
		int iZec60[8];
		float fZec61[8];
		float fZec62[8];
		float fRec40_tmp[12];
		float* fRec40 = &fRec40_tmp[4];
		float fZec63[8];
		float fZec64[8];
		float fZec65[8];
		int iZec66[8];
		float fRec42_tmp[12];
		float* fRec42 = &fRec42_tmp[4];
		float fRec43[8];
		int iSlow47 = int(float(fCheckbox10));
		float fZec67[8];
		float fZec68[8];
		float fSlow48 = 0.16465649f * (float(fHslider18) + -0.707f);
		float fSlow49 = float(fHslider19);
		float fSlow50 = float(fCheckbox11);
		float fSlow51 = fSlow50 * fSlow49;
		float fSlow52 = float(fCheckbox12) * float(fHslider20);
		float fSlow53 = float(fHslider21) * float(fCheckbox13);
		float fSlow54 = float(fHslider22);
		int iSlow55 = fSlow54 >= 3.0f;
		int iSlow56 = fSlow54 >= 2.0f;
		int iSlow57 = fSlow54 >= 1.0f;
		int iSlow58 = int(fSlow45);
		float fZec69[8];
		float fZec70[8];
		float fZec71[8];
		int iSlow59 = fSlow54 >= 5.0f;
		int iSlow60 = fSlow54 >= 4.0f;
		float fZec72[8];
		int iZec73[8];
		float fZec74[8];
		float fZec75[8];
		int iZec76[8];
		float fZec77[8];
		float fSlow61 = float(fHslider23) * float(fCheckbox14);
		float fSlow62 = float(fHslider24);
		int iSlow63 = fSlow62 >= 3.0f;
		int iSlow64 = fSlow62 >= 2.0f;
		int iSlow65 = fSlow62 >= 1.0f;
		int iSlow66 = int(fSlow27);
		float fZec78[8];
		float fZec79[8];
		float fZec80[8];
		int iSlow67 = fSlow62 >= 5.0f;
		int iSlow68 = fSlow62 >= 4.0f;
		float fZec81[8];
		int iZec82[8];
		float fZec83[8];
		float fZec84[8];
		int iZec85[8];
		float fZec86[8];
		float fSlow69 = float(fHslider25) * float(fCheckbox15);
		float fSlow70 = 1.0f / std::max<float>(1.0f, 0.4f * (fSlow53 + fSlow69 + fSlow61));
		float fSlow71 = float(fHslider26);
		float fZec87[8];
		float fRec2_tmp[12];
		float* fRec2 = &fRec2_tmp[4];
		float fZec88[8];
		float fRec3_tmp[12];
		float* fRec3 = &fRec3_tmp[4];
		float fZec89[8];
		float fRec4_tmp[12];
		float* fRec4 = &fRec4_tmp[4];
		float fZec90[8];
		float fRec5_tmp[12];
		float* fRec5 = &fRec5_tmp[4];
		float fRec6[8];
		float fSlow72 = float(fButton0);
		float fVec4_tmp[12];
		float* fVec4 = &fVec4_tmp[4];
		float fRec44_tmp[12];
		float* fRec44 = &fRec44_tmp[4];
		int iSlow73 = fSlow72 == 0.0f;
		int iRec45_tmp[12];
		int* iRec45 = &iRec45_tmp[4];
		float fSlow74 = float(fHslider27);
		float fSlow75 = std::max<float>(1.0f, fConst0 * ((iSlow4) ? 0.001f * fSlow74 : 0.01f));
		float fSlow76 = std::max<float>(1.0f, fConst41 * float(fHslider28));
		float fSlow77 = 1.0f / fSlow76;
		float fSlow78 = float(fHslider29);
		float fSlow79 = (1.0f - fSlow78) / std::max<float>(1.0f, fConst41 * fSlow74);
		float fZec91[8];
		float fRec46_tmp[12];
		float* fRec46 = &fRec46_tmp[4];
		float fRec1_tmp[12];
		float* fRec1 = &fRec1_tmp[4];
		float fYec12_tmp[12];
		float* fYec12 = &fYec12_tmp[4];
		float fRec0_tmp[16];
		float* fRec0 = &fRec0_tmp[8];
		int iSlow80 = int(fSlow50);
		float fSlow81 = 1.0f - fSlow49;
		float fSlow82 = ((int(float(fCheckbox16))) ? 0.0f : 1.0f);
		float fSlow83 = float(fHslider30);
		float fZec92[8];
		for (int vindex = 0; vindex < count; vindex = vindex + 8) {
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			FAUSTFLOAT* output1 = &output1_ptr[vindex];
			int vsize = std::min<int>(8, count - vindex);
			/* Vectorizable loop 0 */
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
			/* Vectorizable loop 1 */
			/* Pre code */
			for (int j6 = 0; j6 < 4; j6 = j6 + 1) {
				iVec2_tmp[j6] = iVec2_perm[j6];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iVec2[i] = 1;
			}
			/* Post code */
			for (int j7 = 0; j7 < 4; j7 = j7 + 1) {
				iVec2_perm[j7] = iVec2_tmp[vsize + j7];
			}
			/* Vectorizable loop 2 */
			/* Pre code */
			for (int j14 = 0; j14 < 4; j14 = j14 + 1) {
				iYec0_tmp[j14] = iYec0_perm[j14];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iYec0[i] = fSlow0 != fVec0[i - 1];
			}
			/* Post code */
			for (int j15 = 0; j15 < 4; j15 = j15 + 1) {
				iYec0_perm[j15] = iYec0_tmp[vsize + j15];
			}
			/* Recursive loop 3 */
			/* Pre code */
			for (int j12 = 0; j12 < 4; j12 = j12 + 1) {
				iRec11_tmp[j12] = iRec11_perm[j12];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec11[i] = iRec11[i - 1] + 1;
			}
			/* Post code */
			for (int j13 = 0; j13 < 4; j13 = j13 + 1) {
				iRec11_perm[j13] = iRec11_tmp[vsize + j13];
			}
			/* Vectorizable loop 4 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec1[i] = (iYec0[i - 1] <= 0) & (iYec0[i] > 0);
			}
			/* Recursive loop 5 */
			/* Pre code */
			for (int j16 = 0; j16 < 4; j16 = j16 + 1) {
				iRec12_tmp[j16] = iRec12_perm[j16];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec12[i] = iRec12[i - 1] * (1 - iZec1[i]) + (iRec11[i] + -1) * iZec1[i];
			}
			/* Post code */
			for (int j17 = 0; j17 < 4; j17 = j17 + 1) {
				iRec12_perm[j17] = iRec12_tmp[vsize + j17];
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec3[i] = std::max<float>(std::exp(fSlow12 * float(-1 * (iRec11[i] + (-1 - iRec12[i])))), 0.01f);
			}
			/* Recursive loop 7 */
			/* Pre code */
			for (int j18 = 0; j18 < 4; j18 = j18 + 1) {
				fRec13_tmp[j18] = fRec13_perm[j18];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec13[i] = fConst3 + (fRec13[i - 1] - std::floor(fConst3 + fRec13[i - 1]));
			}
			/* Post code */
			for (int j19 = 0; j19 < 4; j19 = j19 + 1) {
				fRec13_perm[j19] = fRec13_tmp[vsize + j19];
			}
			/* Vectorizable loop 8 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec4[i] = fSlow0 * (1.0f - fZec3[i]) + fSlow13 * fZec3[i];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVbargraph0 = FAUSTFLOAT(fZec4[i]);
				fZec5[i] = fZec4[i];
			}
			/* Vectorizable loop 9 */
			/* Pre code */
			fYec1_idx = (fYec1_idx + fYec1_idx_save) & 8191;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec1[(i + fYec1_idx) & 8191] = std::pow(2.0f, 0.01f * ftbl0mydspSIG0[int(65536.0f * fRec13[i])]);
			}
			/* Post code */
			fYec1_idx_save = vsize;
			/* Vectorizable loop 10 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec6[i] = ((iSlow11) ? 130.81f : fZec5[i]);
			}
			/* Vectorizable loop 11 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec2[i] = fYec1[(i + fYec1_idx - iConst5) & 8191];
				fZec7[i] = fZec6[i] * fZec2[i];
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec9[i] = fSlow17 * fZec7[i];
			}
			/* Vectorizable loop 13 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec10[i] = std::max<float>(fZec9[i], 23.44895f);
			}
			/* Vectorizable loop 14 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec11[i] = std::max<float>(2e+01f, std::fabs(fZec10[i]));
			}
			/* Recursive loop 15 */
			/* Pre code */
			for (int j22 = 0; j22 < 4; j22 = j22 + 1) {
				fRec16_tmp[j22] = fRec16_perm[j22];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec12[i] = fRec16[i - 1] + fConst6 * fZec11[i];
				fRec16[i] = fZec12[i] - std::floor(fZec12[i]);
			}
			/* Post code */
			for (int j23 = 0; j23 < 4; j23 = j23 + 1) {
				fRec16_perm[j23] = fRec16_tmp[vsize + j23];
			}
			/* Recursive loop 16 */
			/* Pre code */
			for (int j38 = 0; j38 < 4; j38 = j38 + 1) {
				iRec23_tmp[j38] = iRec23_perm[j38];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec23[i] = 1103515245 * iRec23[i - 1] + 12345;
			}
			/* Post code */
			for (int j39 = 0; j39 < 4; j39 = j39 + 1) {
				iRec23_perm[j39] = iRec23_tmp[vsize + j39];
			}
			/* Vectorizable loop 17 */
			/* Pre code */
			for (int j24 = 0; j24 < 4; j24 = j24 + 1) {
				fYec2_tmp[j24] = fYec2_perm[j24];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec2[i] = mydsp_faustpower2_f(2.0f * fRec16[i] + -1.0f);
			}
			/* Post code */
			for (int j25 = 0; j25 < 4; j25 = j25 + 1) {
				fYec2_perm[j25] = fYec2_tmp[vsize + j25];
			}
			/* Vectorizable loop 18 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec13[i] = float(iVec2[i - 1]);
			}
			/* Vectorizable loop 19 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec14[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst7 / fZec10[i]));
			}
			/* Vectorizable loop 20 */
			/* Pre code */
			for (int j40 = 0; j40 < 4; j40 = j40 + 1) {
				fYec5_tmp[j40] = fYec5_perm[j40];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec5[i] = float(iRec23[i]);
			}
			/* Post code */
			for (int j41 = 0; j41 < 4; j41 = j41 + 1) {
				fYec5_perm[j41] = fYec5_tmp[vsize + j41];
			}
			/* Vectorizable loop 21 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec26[i] = fZec5[i] * fYec1[(i + fYec1_idx - iConst4) & 8191];
			}
			/* Vectorizable loop 22 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec52[i] = fZec5[i] * fYec1[(i + fYec1_idx - iConst40) & 8191];
			}
			/* Recursive loop 23 */
			/* Pre code */
			for (int j20 = 0; j20 < 4; j20 = j20 + 1) {
				fRec10_tmp[j20] = fRec10_perm[j20];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec8[i] = fRec10[i - 1] + fSlow18 * fZec7[i];
				fRec10[i] = fZec8[i] - std::floor(fZec8[i]);
			}
			/* Post code */
			for (int j21 = 0; j21 < 4; j21 = j21 + 1) {
				fRec10_perm[j21] = fRec10_tmp[vsize + j21];
			}
			/* Vectorizable loop 24 */
			/* Pre code */
			fYec3_idx = (fYec3_idx + fYec3_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec3[(i + fYec3_idx) & 4095] = fZec13[i] * (fYec2[i] - fYec2[i - 1]) / fZec11[i];
			}
			/* Post code */
			fYec3_idx_save = vsize;
			/* Vectorizable loop 25 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec15[i] = int(fZec14[i]);
			}
			/* Vectorizable loop 26 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec16[i] = std::floor(fZec14[i]);
			}
			/* Vectorizable loop 27 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec18[i] = std::max<float>(1.1920929e-07f, std::fabs(fZec9[i]));
			}
			/* Vectorizable loop 28 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec25[i] = 4.656613e-10f * fYec5[i];
			}
			/* Recursive loop 29 */
			/* Pre code */
			for (int j44 = 0; j44 < 4; j44 = j44 + 1) {
				fRec26_tmp[j44] = fRec26_perm[j44];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec26[i] = fConst17 * (4.656613e-10f * (fConst16 * fYec5[i] + fConst15 * fYec5[i - 1]) - fConst10 * fRec26[i - 1]);
			}
			/* Post code */
			for (int j45 = 0; j45 < 4; j45 = j45 + 1) {
				fRec26_perm[j45] = fRec26_tmp[vsize + j45];
			}
			/* Vectorizable loop 30 */
			/* Pre code */
			for (int j52 = 0; j52 < 4; j52 = j52 + 1) {
				fYec6_tmp[j52] = fYec6_perm[j52];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec6[i] = fSlow28 * fZec26[i];
			}
			/* Post code */
			for (int j53 = 0; j53 < 4; j53 = j53 + 1) {
				fYec6_perm[j53] = fYec6_tmp[vsize + j53];
			}
			/* Vectorizable loop 31 */
			/* Pre code */
			for (int j70 = 0; j70 < 4; j70 = j70 + 1) {
				fYec9_tmp[j70] = fYec9_perm[j70];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec9[i] = fSlow46 * fZec52[i];
			}
			/* Post code */
			for (int j71 = 0; j71 < 4; j71 = j71 + 1) {
				fYec9_perm[j71] = fYec9_tmp[vsize + j71];
			}
			/* Vectorizable loop 32 */
			/* Pre code */
			for (int j2 = 0; j2 < 4; j2 = j2 + 1) {
				fVec1_tmp[j2] = fVec1_perm[j2];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVec1[i] = fSlow1;
			}
			/* Post code */
			for (int j3 = 0; j3 < 4; j3 = j3 + 1) {
				fVec1_perm[j3] = fVec1_tmp[vsize + j3];
			}
			/* Vectorizable loop 33 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec17[i] = fConst8 * (fYec3[(i + fYec3_idx) & 4095] - fYec3[(i + fYec3_idx - iZec15[i]) & 4095] * (fZec16[i] + (1.0f - fZec14[i])) - (fZec14[i] - fZec16[i]) * fYec3[(i + fYec3_idx - (iZec15[i] + 1)) & 4095]);
			}
			/* Recursive loop 34 */
			/* Pre code */
			for (int j28 = 0; j28 < 4; j28 = j28 + 1) {
				fRec17_tmp[j28] = fRec17_perm[j28];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec19[i] = fRec17[i - 1] + fConst6 * fZec18[i];
				fZec20[i] = fZec19[i] + -1.0f;
				iZec21[i] = fZec20[i] < 0.0f;
				fRec17[i] = ((iZec21[i]) ? fZec19[i] : fZec20[i]);
				fRec18[i] = ((iZec21[i]) ? fZec19[i] : fZec19[i] + fZec20[i] * (1.0f - fConst0 / fZec18[i]));
			}
			/* Post code */
			for (int j29 = 0; j29 < 4; j29 = j29 + 1) {
				fRec17_perm[j29] = fRec17_tmp[vsize + j29];
			}
			/* Recursive loop 35 */
			/* Pre code */
			for (int j42 = 0; j42 < 4; j42 = j42 + 1) {
				fRec22_tmp[j42] = fRec22_perm[j42];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec22[i] = 0.5221894f * fRec22[i - 3] + fZec25[i] + 2.494956f * fRec22[i - 1] - 2.0172658f * fRec22[i - 2];
			}
			/* Post code */
			for (int j43 = 0; j43 < 4; j43 = j43 + 1) {
				fRec22_perm[j43] = fRec22_tmp[vsize + j43];
			}
			/* Recursive loop 36 */
			/* Pre code */
			for (int j46 = 0; j46 < 4; j46 = j46 + 1) {
				fRec25_tmp[j46] = fRec25_perm[j46];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec25[i] = 0.0f - fConst26 * (fConst25 * fRec25[i - 1] - fConst22 * (fConst21 * fRec26[i] + fConst20 * fRec26[i - 1]));
			}
			/* Post code */
			for (int j47 = 0; j47 < 4; j47 = j47 + 1) {
				fRec25_perm[j47] = fRec25_tmp[vsize + j47];
			}
			/* Recursive loop 37 */
			/* Pre code */
			for (int j54 = 0; j54 < 4; j54 = j54 + 1) {
				fRec29_tmp[j54] = fRec29_perm[j54];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec29[i] = fYec6[i] + fRec29[i - 1] * float(fYec6[i - 1] >= fYec6[i]);
			}
			/* Post code */
			for (int j55 = 0; j55 < 4; j55 = j55 + 1) {
				fRec29_perm[j55] = fRec29_tmp[vsize + j55];
			}
			/* Recursive loop 38 */
			/* Pre code */
			for (int j56 = 0; j56 < 4; j56 = j56 + 1) {
				iRec30_tmp[j56] = iRec30_perm[j56];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec30[i] = (iRec30[i - 1] + 1) * (fYec6[i] == 0.0f);
			}
			/* Post code */
			for (int j57 = 0; j57 < 4; j57 = j57 + 1) {
				iRec30_perm[j57] = iRec30_tmp[vsize + j57];
			}
			/* Vectorizable loop 39 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec28[i] = 2.0f * fRec10[i] + -1.0f;
			}
			/* Vectorizable loop 40 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec30[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst37 / fZec10[i]));
			}
			/* Vectorizable loop 41 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec33[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst38 / fZec10[i]));
			}
			/* Recursive loop 42 */
			/* Pre code */
			for (int j72 = 0; j72 < 4; j72 = j72 + 1) {
				fRec37_tmp[j72] = fRec37_perm[j72];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec37[i] = fYec9[i] + fRec37[i - 1] * float(fYec9[i - 1] >= fYec9[i]);
			}
			/* Post code */
			for (int j73 = 0; j73 < 4; j73 = j73 + 1) {
				fRec37_perm[j73] = fRec37_tmp[vsize + j73];
			}
			/* Recursive loop 43 */
			/* Pre code */
			for (int j74 = 0; j74 < 4; j74 = j74 + 1) {
				iRec38_tmp[j74] = iRec38_perm[j74];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec38[i] = (iRec38[i - 1] + 1) * (fYec9[i] == 0.0f);
			}
			/* Post code */
			for (int j75 = 0; j75 < 4; j75 = j75 + 1) {
				iRec38_perm[j75] = iRec38_tmp[vsize + j75];
			}
			/* Recursive loop 44 */
			/* Pre code */
			for (int j4 = 0; j4 < 4; j4 = j4 + 1) {
				fRec7_tmp[j4] = fRec7_perm[j4];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec7[i] = fSlow2 + fRec7[i - 1] * float((0.33333334f * fVec1[i - 1]) >= fSlow2);
			}
			/* Post code */
			for (int j5 = 0; j5 < 4; j5 = j5 + 1) {
				fRec7_perm[j5] = fRec7_tmp[vsize + j5];
			}
			/* Recursive loop 45 */
			/* Pre code */
			for (int j8 = 0; j8 < 4; j8 = j8 + 1) {
				iRec8_tmp[j8] = iRec8_perm[j8];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec8[i] = iSlow3 * (iRec8[i - 1] + 1);
			}
			/* Post code */
			for (int j9 = 0; j9 < 4; j9 = j9 + 1) {
				iRec8_perm[j9] = iRec8_tmp[vsize + j9];
			}
			/* Recursive loop 46 */
			/* Pre code */
			for (int j26 = 0; j26 < 4; j26 = j26 + 1) {
				fRec15_tmp[j26] = fRec15_perm[j26];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec15[i] = 0.999f * fRec15[i - 1] + fZec17[i];
			}
			/* Post code */
			for (int j27 = 0; j27 < 4; j27 = j27 + 1) {
				fRec15_perm[j27] = fRec15_tmp[vsize + j27];
			}
			/* Recursive loop 47 */
			/* Pre code */
			for (int j48 = 0; j48 < 4; j48 = j48 + 1) {
				fRec24_tmp[j48] = fRec24_perm[j48];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec24[i] = 0.0f - fConst35 * (fConst34 * fRec24[i - 1] - fConst31 * (fConst30 * fRec25[i] + fConst29 * fRec25[i - 1]));
			}
			/* Post code */
			for (int j49 = 0; j49 < 4; j49 = j49 + 1) {
				fRec24_perm[j49] = fRec24_tmp[vsize + j49];
			}
			/* Recursive loop 48 */
			/* Pre code */
			for (int j50 = 0; j50 < 4; j50 = j50 + 1) {
				fRec27_tmp[j50] = fRec27_perm[j50];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec27[i] = fSlow26 + (fRec27[i - 1] - std::floor(fSlow26 + fRec27[i - 1]));
			}
			/* Post code */
			for (int j51 = 0; j51 < 4; j51 = j51 + 1) {
				fRec27_perm[j51] = fRec27_tmp[vsize + j51];
			}
			/* Vectorizable loop 49 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec27[i] = std::max<float>(0.0f, std::min<float>(fSlow8 * fRec29[i], std::max<float>(fSlow10 * (fSlow7 - fRec29[i]) + 1.0f, fSlow9)) * (1.0f - float(iRec30[i]) / fSlow6));
			}
			/* Vectorizable loop 50 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec29[i] = ((iSlow35) ? 2.0f * fRec18[i] + -1.0f : fZec28[i]);
			}
			/* Vectorizable loop 51 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec31[i] = int(fZec30[i]);
			}
			/* Vectorizable loop 52 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec32[i] = std::floor(fZec30[i]);
			}
			/* Vectorizable loop 53 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec34[i] = int(fZec33[i]);
			}
			/* Vectorizable loop 54 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec35[i] = std::floor(fZec33[i]);
			}
			/* Vectorizable loop 55 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec37[i] = 0.049922034f * fRec22[i] + 0.0506127f * fRec22[i - 2] - (0.095993534f * fRec22[i - 1] + 0.004408786f * fRec22[i - 3]);
			}
			/* Vectorizable loop 56 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec53[i] = std::max<float>(0.0f, std::min<float>(fSlow8 * fRec37[i], std::max<float>(fSlow10 * (fSlow7 - fRec37[i]) + 1.0f, fSlow9)) * (1.0f - float(iRec38[i]) / fSlow6));
			}
			/* Vectorizable loop 57 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec0[i] = std::max<float>(0.0f, std::min<float>(fSlow8 * fRec7[i], std::max<float>(fSlow10 * (fSlow7 - fRec7[i]) + 1.0f, fSlow9)) * (1.0f - float(iRec8[i]) / fSlow6));
			}
			/* Recursive loop 58 */
			/* Pre code */
			for (int j58 = 0; j58 < 4; j58 = j58 + 1) {
				fRec31_tmp[j58] = fRec31_perm[j58];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec31[i] = fConst1 * fZec27[i] + fConst2 * fRec31[i - 1];
			}
			/* Post code */
			for (int j59 = 0; j59 < 4; j59 = j59 + 1) {
				fRec31_perm[j59] = fRec31_tmp[vsize + j59];
			}
			/* Vectorizable loop 59 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec36[i] = ((iSlow32) ? ((iSlow37) ? ((iSlow35) ? fConst8 * (fYec3[(i + fYec3_idx) & 4095] - fYec3[(i + fYec3_idx - iZec34[i]) & 4095] * (fZec35[i] + (1.0f - fZec33[i])) - (fZec33[i] - fZec35[i]) * fYec3[(i + fYec3_idx - (iZec34[i] + 1)) & 4095]) : 2.0f * float(fRec10[i] <= 0.85f) + -1.0f) : ((iSlow38) ? ((iSlow35) ? fConst8 * (fYec3[(i + fYec3_idx) & 4095] - fYec3[(i + fYec3_idx - iZec31[i]) & 4095] * (fZec32[i] + (1.0f - fZec30[i])) - (fZec30[i] - fZec32[i]) * fYec3[(i + fYec3_idx - (iZec31[i] + 1)) & 4095]) : 2.0f * float(fRec10[i] <= 0.7f) + -1.0f) : ((iSlow35) ? fZec17[i] : 2.0f * float(fRec10[i] <= 0.5f) + -1.0f))) : ((iSlow33) ? fZec29[i] : ((iSlow34) ? 0.0f - fZec29[i] : ((iSlow35) ? fSlow36 * fRec15[i] * fZec6[i] * fZec2[i] : 2.0f * (1.0f - std::fabs(fZec28[i])) + -1.0f))));
			}
			/* Vectorizable loop 60 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec38[i] = fSlow39 * ((iSlow41) ? ((iSlow43) ? 2.0f * float(fRec27[i] <= 0.5f) + -1.0f : 2.0f * (1.0f - std::fabs(2.0f * fRec27[i] + -1.0f)) + -1.0f) : ((iSlow42) ? fConst39 * fRec24[i] : fZec37[i]));
			}
			/* Recursive loop 61 */
			/* Pre code */
			for (int j76 = 0; j76 < 4; j76 = j76 + 1) {
				fRec39_tmp[j76] = fRec39_perm[j76];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec39[i] = fConst1 * fZec53[i] + fConst2 * fRec39[i - 1];
			}
			/* Post code */
			for (int j77 = 0; j77 < 4; j77 = j77 + 1) {
				fRec39_perm[j77] = fRec39_tmp[vsize + j77];
			}
			/* Recursive loop 62 */
			/* Pre code */
			for (int j10 = 0; j10 < 4; j10 = j10 + 1) {
				fRec9_tmp[j10] = fRec9_perm[j10];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec9[i] = fConst1 * fZec0[i] + fConst2 * fRec9[i - 1];
			}
			/* Post code */
			for (int j11 = 0; j11 < 4; j11 = j11 + 1) {
				fRec9_perm[j11] = fRec9_tmp[vsize + j11];
			}
			/* Vectorizable loop 63 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec39[i] = ((iSlow29) ? fSlow28 * fZec26[i] * std::pow(2.0f, fSlow44 * (fZec38[i] + fSlow40 * ((iSlow30) ? ((iSlow4) ? fRec31[i] : fZec27[i]) : fZec36[i]))) : fYec6[i]);
			}
			/* Vectorizable loop 64 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec54[i] = ((iSlow29) ? fSlow46 * fZec52[i] * std::pow(2.0f, fSlow44 * (fZec38[i] + fSlow40 * ((iSlow30) ? ((iSlow4) ? fRec39[i] : fZec53[i]) : fZec36[i]))) : fYec9[i]);
			}
			/* Vectorizable loop 65 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec22[i] = ((iSlow4) ? fRec9[i] : fZec0[i]);
			}
			/* Vectorizable loop 66 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec41[i] = std::max<float>(fZec39[i], 23.44895f);
			}
			/* Vectorizable loop 67 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec56[i] = std::max<float>(fZec54[i], 23.44895f);
			}
			/* Vectorizable loop 68 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec23[i] = ((iSlow19) ? fSlow2 - fSlow23 * fZec22[i] * fSlow24 : fSlow2 + fSlow23 * fZec22[i] * fSlow22);
			}
			/* Vectorizable loop 69 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec42[i] = std::max<float>(2e+01f, std::fabs(fZec41[i]));
			}
			/* Vectorizable loop 70 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec57[i] = std::max<float>(2e+01f, std::fabs(fZec56[i]));
			}
			/* Vectorizable loop 71 */
			/* Pre code */
			for (int j30 = 0; j30 < 4; j30 = j30 + 1) {
				fYec4_tmp[j30] = fYec4_perm[j30];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec4[i] = fSlow25 + fZec23[i];
			}
			/* Post code */
			for (int j31 = 0; j31 < 4; j31 = j31 + 1) {
				fYec4_perm[j31] = fYec4_tmp[vsize + j31];
			}
			/* Recursive loop 72 */
			/* Pre code */
			for (int j62 = 0; j62 < 4; j62 = j62 + 1) {
				fRec33_tmp[j62] = fRec33_perm[j62];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec43[i] = fRec33[i - 1] + fConst6 * fZec42[i];
				fRec33[i] = fZec43[i] - std::floor(fZec43[i]);
			}
			/* Post code */
			for (int j63 = 0; j63 < 4; j63 = j63 + 1) {
				fRec33_perm[j63] = fRec33_tmp[vsize + j63];
			}
			/* Recursive loop 73 */
			/* Pre code */
			for (int j80 = 0; j80 < 4; j80 = j80 + 1) {
				fRec41_tmp[j80] = fRec41_perm[j80];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec58[i] = fRec41[i - 1] + fConst6 * fZec57[i];
				fRec41[i] = fZec58[i] - std::floor(fZec58[i]);
			}
			/* Post code */
			for (int j81 = 0; j81 < 4; j81 = j81 + 1) {
				fRec41_perm[j81] = fRec41_tmp[vsize + j81];
			}
			/* Recursive loop 74 */
			/* Pre code */
			for (int j32 = 0; j32 < 4; j32 = j32 + 1) {
				fRec19_tmp[j32] = fRec19_perm[j32];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec19[i] = fSlow25 + fZec23[i] + fRec19[i - 1] * float(fYec4[i - 1] >= fYec4[i]);
			}
			/* Post code */
			for (int j33 = 0; j33 < 4; j33 = j33 + 1) {
				fRec19_perm[j33] = fRec19_tmp[vsize + j33];
			}
			/* Recursive loop 75 */
			/* Pre code */
			for (int j34 = 0; j34 < 4; j34 = j34 + 1) {
				iRec20_tmp[j34] = iRec20_perm[j34];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec20[i] = (iRec20[i - 1] + 1) * (fYec4[i] == 0.0f);
			}
			/* Post code */
			for (int j35 = 0; j35 < 4; j35 = j35 + 1) {
				iRec20_perm[j35] = iRec20_tmp[vsize + j35];
			}
			/* Vectorizable loop 76 */
			/* Pre code */
			for (int j64 = 0; j64 < 4; j64 = j64 + 1) {
				fYec7_tmp[j64] = fYec7_perm[j64];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec7[i] = mydsp_faustpower2_f(2.0f * fRec33[i] + -1.0f);
			}
			/* Post code */
			for (int j65 = 0; j65 < 4; j65 = j65 + 1) {
				fYec7_perm[j65] = fYec7_tmp[vsize + j65];
			}
			/* Vectorizable loop 77 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec44[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst7 / fZec41[i]));
			}
			/* Vectorizable loop 78 */
			/* Pre code */
			for (int j82 = 0; j82 < 4; j82 = j82 + 1) {
				fYec10_tmp[j82] = fYec10_perm[j82];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec10[i] = mydsp_faustpower2_f(2.0f * fRec41[i] + -1.0f);
			}
			/* Post code */
			for (int j83 = 0; j83 < 4; j83 = j83 + 1) {
				fYec10_perm[j83] = fYec10_tmp[vsize + j83];
			}
			/* Vectorizable loop 79 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec59[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst7 / fZec56[i]));
			}
			/* Vectorizable loop 80 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec24[i] = std::max<float>(0.0f, std::min<float>(fSlow8 * fRec19[i], std::max<float>(fSlow10 * (fSlow7 - fRec19[i]) + 1.0f, fSlow9)) * (1.0f - float(iRec20[i]) / fSlow6));
			}
			/* Vectorizable loop 81 */
			/* Pre code */
			fYec8_idx = (fYec8_idx + fYec8_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec8[(i + fYec8_idx) & 4095] = fZec13[i] * (fYec7[i] - fYec7[i - 1]) / fZec42[i];
			}
			/* Post code */
			fYec8_idx_save = vsize;
			/* Vectorizable loop 82 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec45[i] = int(fZec44[i]);
			}
			/* Vectorizable loop 83 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec46[i] = std::floor(fZec44[i]);
			}
			/* Vectorizable loop 84 */
			/* Pre code */
			fYec11_idx = (fYec11_idx + fYec11_idx_save) & 4095;
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec11[(i + fYec11_idx) & 4095] = fZec13[i] * (fYec10[i] - fYec10[i - 1]) / fZec57[i];
			}
			/* Post code */
			fYec11_idx_save = vsize;
			/* Vectorizable loop 85 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec60[i] = int(fZec59[i]);
			}
			/* Vectorizable loop 86 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec61[i] = std::floor(fZec59[i]);
			}
			/* Vectorizable loop 87 */
			/* Pre code */
			for (int j96 = 0; j96 < 4; j96 = j96 + 1) {
				fVec4_tmp[j96] = fVec4_perm[j96];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fVec4[i] = fSlow72;
			}
			/* Post code */
			for (int j97 = 0; j97 < 4; j97 = j97 + 1) {
				fVec4_perm[j97] = fVec4_tmp[vsize + j97];
			}
			/* Recursive loop 88 */
			/* Pre code */
			for (int j36 = 0; j36 < 4; j36 = j36 + 1) {
				fRec21_tmp[j36] = fRec21_perm[j36];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec21[i] = fConst1 * fZec24[i] + fConst2 * fRec21[i - 1];
			}
			/* Post code */
			for (int j37 = 0; j37 < 4; j37 = j37 + 1) {
				fRec21_perm[j37] = fRec21_tmp[vsize + j37];
			}
			/* Recursive loop 89 */
			/* Pre code */
			for (int j60 = 0; j60 < 4; j60 = j60 + 1) {
				fRec28_tmp[j60] = fRec28_perm[j60];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec40[i] = fRec28[i - 1] + fConst6 * fZec39[i];
				fRec28[i] = fZec40[i] - std::floor(fZec40[i]);
			}
			/* Post code */
			for (int j61 = 0; j61 < 4; j61 = j61 + 1) {
				fRec28_perm[j61] = fRec28_tmp[vsize + j61];
			}
			/* Vectorizable loop 90 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec47[i] = fConst8 * (fYec8[(i + fYec8_idx) & 4095] - fYec8[(i + fYec8_idx - iZec45[i]) & 4095] * (fZec46[i] + (1.0f - fZec44[i])) - (fZec44[i] - fZec46[i]) * fYec8[(i + fYec8_idx - (iZec45[i] + 1)) & 4095]);
			}
			/* Vectorizable loop 91 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec48[i] = std::max<float>(1.1920929e-07f, std::fabs(fZec39[i]));
			}
			/* Recursive loop 92 */
			/* Pre code */
			for (int j78 = 0; j78 < 4; j78 = j78 + 1) {
				fRec36_tmp[j78] = fRec36_perm[j78];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec55[i] = fRec36[i - 1] + fConst6 * fZec54[i];
				fRec36[i] = fZec55[i] - std::floor(fZec55[i]);
			}
			/* Post code */
			for (int j79 = 0; j79 < 4; j79 = j79 + 1) {
				fRec36_perm[j79] = fRec36_tmp[vsize + j79];
			}
			/* Vectorizable loop 93 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec62[i] = fConst8 * (fYec11[(i + fYec11_idx) & 4095] - fYec11[(i + fYec11_idx - iZec60[i]) & 4095] * (fZec61[i] + (1.0f - fZec59[i])) - (fZec59[i] - fZec61[i]) * fYec11[(i + fYec11_idx - (iZec60[i] + 1)) & 4095]);
			}
			/* Vectorizable loop 94 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec63[i] = std::max<float>(1.1920929e-07f, std::fabs(fZec54[i]));
			}
			/* Recursive loop 95 */
			/* Pre code */
			for (int j98 = 0; j98 < 4; j98 = j98 + 1) {
				fRec44_tmp[j98] = fRec44_perm[j98];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec44[i] = fSlow72 + fRec44[i - 1] * float(fVec4[i - 1] >= fSlow72);
			}
			/* Post code */
			for (int j99 = 0; j99 < 4; j99 = j99 + 1) {
				fRec44_perm[j99] = fRec44_tmp[vsize + j99];
			}
			/* Recursive loop 96 */
			/* Pre code */
			for (int j100 = 0; j100 < 4; j100 = j100 + 1) {
				iRec45_tmp[j100] = iRec45_perm[j100];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iRec45[i] = iSlow73 * (iRec45[i - 1] + 1);
			}
			/* Post code */
			for (int j101 = 0; j101 < 4; j101 = j101 + 1) {
				iRec45_perm[j101] = iRec45_tmp[vsize + j101];
			}
			/* Recursive loop 97 */
			/* Pre code */
			for (int j66 = 0; j66 < 4; j66 = j66 + 1) {
				fRec32_tmp[j66] = fRec32_perm[j66];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec32[i] = 0.999f * fRec32[i - 1] + fZec47[i];
			}
			/* Post code */
			for (int j67 = 0; j67 < 4; j67 = j67 + 1) {
				fRec32_perm[j67] = fRec32_tmp[vsize + j67];
			}
			/* Recursive loop 98 */
			/* Pre code */
			for (int j68 = 0; j68 < 4; j68 = j68 + 1) {
				fRec34_tmp[j68] = fRec34_perm[j68];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec49[i] = fRec34[i - 1] + fConst6 * fZec48[i];
				fZec50[i] = fZec49[i] + -1.0f;
				iZec51[i] = fZec50[i] < 0.0f;
				fRec34[i] = ((iZec51[i]) ? fZec49[i] : fZec50[i]);
				fRec35[i] = ((iZec51[i]) ? fZec49[i] : fZec49[i] + fZec50[i] * (1.0f - fConst0 / fZec48[i]));
			}
			/* Post code */
			for (int j69 = 0; j69 < 4; j69 = j69 + 1) {
				fRec34_perm[j69] = fRec34_tmp[vsize + j69];
			}
			/* Recursive loop 99 */
			/* Pre code */
			for (int j84 = 0; j84 < 4; j84 = j84 + 1) {
				fRec40_tmp[j84] = fRec40_perm[j84];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec40[i] = 0.999f * fRec40[i - 1] + fZec62[i];
			}
			/* Post code */
			for (int j85 = 0; j85 < 4; j85 = j85 + 1) {
				fRec40_perm[j85] = fRec40_tmp[vsize + j85];
			}
			/* Recursive loop 100 */
			/* Pre code */
			for (int j86 = 0; j86 < 4; j86 = j86 + 1) {
				fRec42_tmp[j86] = fRec42_perm[j86];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec64[i] = fRec42[i - 1] + fConst6 * fZec63[i];
				fZec65[i] = fZec64[i] + -1.0f;
				iZec66[i] = fZec65[i] < 0.0f;
				fRec42[i] = ((iZec66[i]) ? fZec64[i] : fZec65[i]);
				fRec43[i] = ((iZec66[i]) ? fZec64[i] : fZec64[i] + fZec65[i] * (1.0f - fConst0 / fZec63[i]));
			}
			/* Post code */
			for (int j87 = 0; j87 < 4; j87 = j87 + 1) {
				fRec42_perm[j87] = fRec42_tmp[vsize + j87];
			}
			/* Vectorizable loop 101 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec67[i] = std::tan(1.5707964f * std::min<float>(std::max<float>(fConst6 * ((iSlow47) ? fYec4[i] * std::pow(2.0f, fSlow44 * (fSlow40 * ((iSlow30) ? ((iSlow4) ? fRec21[i] : fZec24[i]) : fZec36[i]) + fZec38[i])) : fYec4[i]), 0.0f), 1.0f));
			}
			/* Vectorizable loop 102 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec69[i] = 2.0f * fRec36[i] + -1.0f;
			}
			/* Vectorizable loop 103 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec72[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst37 / fZec56[i]));
			}
			/* Vectorizable loop 104 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec75[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst38 / fZec56[i]));
			}
			/* Vectorizable loop 105 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec78[i] = 2.0f * fRec28[i] + -1.0f;
			}
			/* Vectorizable loop 106 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec81[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst37 / fZec41[i]));
			}
			/* Vectorizable loop 107 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec84[i] = std::max<float>(0.0f, std::min<float>(2047.0f, fConst38 / fZec41[i]));
			}
			/* Vectorizable loop 108 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec91[i] = std::max<float>(0.0f, std::min<float>(fSlow77 * fRec44[i], std::max<float>(fSlow79 * (fSlow76 - fRec44[i]) + 1.0f, fSlow78)) * (1.0f - float(iRec45[i]) / fSlow75));
			}
			/* Vectorizable loop 109 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec68[i] = fZec67[i] + 1.0f;
			}
			/* Vectorizable loop 110 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec70[i] = ((iSlow58) ? fConst36 * fRec40[i] * fZec54[i] : 2.0f * (1.0f - std::fabs(fZec69[i])) + -1.0f);
			}
			/* Vectorizable loop 111 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec71[i] = ((iSlow58) ? 2.0f * fRec43[i] + -1.0f : fZec69[i]);
			}
			/* Vectorizable loop 112 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec73[i] = int(fZec72[i]);
			}
			/* Vectorizable loop 113 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec74[i] = std::floor(fZec72[i]);
			}
			/* Vectorizable loop 114 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec76[i] = int(fZec75[i]);
			}
			/* Vectorizable loop 115 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec77[i] = std::floor(fZec75[i]);
			}
			/* Vectorizable loop 116 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec79[i] = ((iSlow66) ? fConst36 * fRec32[i] * fZec39[i] : 2.0f * (1.0f - std::fabs(fZec78[i])) + -1.0f);
			}
			/* Vectorizable loop 117 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec80[i] = ((iSlow66) ? 2.0f * fRec35[i] + -1.0f : fZec78[i]);
			}
			/* Vectorizable loop 118 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec82[i] = int(fZec81[i]);
			}
			/* Vectorizable loop 119 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec83[i] = std::floor(fZec81[i]);
			}
			/* Vectorizable loop 120 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				iZec85[i] = int(fZec84[i]);
			}
			/* Vectorizable loop 121 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec86[i] = std::floor(fZec84[i]);
			}
			/* Recursive loop 122 */
			/* Pre code */
			for (int j102 = 0; j102 < 4; j102 = j102 + 1) {
				fRec46_tmp[j102] = fRec46_perm[j102];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec46[i] = fConst1 * fZec91[i] + fConst2 * fRec46[i - 1];
			}
			/* Post code */
			for (int j103 = 0; j103 < 4; j103 = j103 + 1) {
				fRec46_perm[j103] = fRec46_tmp[vsize + j103];
			}
			/* Recursive loop 123 */
			/* Pre code */
			for (int j88 = 0; j88 < 4; j88 = j88 + 1) {
				fRec2_tmp[j88] = fRec2_perm[j88];
			}
			for (int j90 = 0; j90 < 4; j90 = j90 + 1) {
				fRec3_tmp[j90] = fRec3_perm[j90];
			}
			for (int j92 = 0; j92 < 4; j92 = j92 + 1) {
				fRec4_tmp[j92] = fRec4_perm[j92];
			}
			for (int j94 = 0; j94 < 4; j94 = j94 + 1) {
				fRec5_tmp[j94] = fRec5_perm[j94];
			}
			for (int j104 = 0; j104 < 4; j104 = j104 + 1) {
				fRec1_tmp[j104] = fRec1_perm[j104];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec87[i] = fZec67[i] * ((fSlow71 * (fSlow70 * (fSlow69 * ((iSlow63) ? ((iSlow67) ? ((iSlow66) ? fConst8 * (fYec8[(i + fYec8_idx) & 4095] - fYec8[(i + fYec8_idx - iZec85[i]) & 4095] * (fZec86[i] + (1.0f - fZec84[i])) - (fZec84[i] - fZec86[i]) * fYec8[(i + fYec8_idx - (iZec85[i] + 1)) & 4095]) : 2.0f * float(fRec28[i] <= 0.85f) + -1.0f) : ((iSlow68) ? ((iSlow66) ? fConst8 * (fYec8[(i + fYec8_idx) & 4095] - fYec8[(i + fYec8_idx - iZec82[i]) & 4095] * (fZec83[i] + (1.0f - fZec81[i])) - (fZec81[i] - fZec83[i]) * fYec8[(i + fYec8_idx - (iZec82[i] + 1)) & 4095]) : 2.0f * float(fRec28[i] <= 0.7f) + -1.0f) : ((iSlow66) ? fZec47[i] : 2.0f * float(fRec28[i] <= 0.5f) + -1.0f))) : ((iSlow64) ? fZec80[i] : ((iSlow65) ? 0.5f * (fZec79[i] + fZec80[i]) : fZec79[i]))) + fSlow61 * ((iSlow55) ? ((iSlow59) ? ((iSlow58) ? fConst8 * (fYec11[(i + fYec11_idx) & 4095] - fYec11[(i + fYec11_idx - iZec76[i]) & 4095] * (fZec77[i] + (1.0f - fZec75[i])) - (fZec75[i] - fZec77[i]) * fYec11[(i + fYec11_idx - (iZec76[i] + 1)) & 4095]) : 2.0f * float(fRec36[i] <= 0.85f) + -1.0f) : ((iSlow60) ? ((iSlow58) ? fConst8 * (fYec11[(i + fYec11_idx) & 4095] - fYec11[(i + fYec11_idx - iZec73[i]) & 4095] * (fZec74[i] + (1.0f - fZec72[i])) - (fZec72[i] - fZec74[i]) * fYec11[(i + fYec11_idx - (iZec73[i] + 1)) & 4095]) : 2.0f * float(fRec36[i] <= 0.7f) + -1.0f) : ((iSlow58) ? fZec62[i] : 2.0f * float(fRec36[i] <= 0.5f) + -1.0f))) : ((iSlow56) ? fZec71[i] : ((iSlow57) ? 0.5f * (fZec70[i] + fZec71[i]) : fZec70[i]))) + fSlow53 * fZec36[i]) + fSlow52 * ((iSlow42) ? fZec37[i] : fZec25[i])) + fSlow51 * fRec1[i - 1] - fSlow48 * (1.0f - fZec67[i] / fZec68[i]) * (fRec5[i - 1] + fZec67[i] * (fRec4[i - 1] + fZec67[i] * (fRec3[i - 1] + fZec67[i] * fRec2[i - 1] / fZec68[i]) / fZec68[i]) / fZec68[i])) / (fSlow48 * (mydsp_faustpower4_f(fZec67[i]) / mydsp_faustpower4_f(fZec68[i])) + 1.0f) - fRec2[i - 1]) / fZec68[i];
				fRec2[i] = fRec2[i - 1] + 2.0f * fZec87[i];
				fZec88[i] = fZec67[i] * (fRec2[i - 1] + fZec87[i] - fRec3[i - 1]) / fZec68[i];
				fRec3[i] = fRec3[i - 1] + 2.0f * fZec88[i];
				fZec89[i] = fZec67[i] * (fRec3[i - 1] + fZec88[i] - fRec4[i - 1]) / fZec68[i];
				fRec4[i] = fRec4[i - 1] + 2.0f * fZec89[i];
				fZec90[i] = fZec67[i] * (fRec4[i - 1] + fZec89[i] - fRec5[i - 1]) / fZec68[i];
				fRec5[i] = fRec5[i - 1] + 2.0f * fZec90[i];
				fRec6[i] = fRec5[i - 1] + fZec90[i];
				fRec1[i] = fRec6[i] * ((iSlow4) ? fRec46[i] : fZec91[i]);
			}
			/* Post code */
			for (int j89 = 0; j89 < 4; j89 = j89 + 1) {
				fRec2_perm[j89] = fRec2_tmp[vsize + j89];
			}
			for (int j91 = 0; j91 < 4; j91 = j91 + 1) {
				fRec3_perm[j91] = fRec3_tmp[vsize + j91];
			}
			for (int j93 = 0; j93 < 4; j93 = j93 + 1) {
				fRec4_perm[j93] = fRec4_tmp[vsize + j93];
			}
			for (int j95 = 0; j95 < 4; j95 = j95 + 1) {
				fRec5_perm[j95] = fRec5_tmp[vsize + j95];
			}
			for (int j105 = 0; j105 < 4; j105 = j105 + 1) {
				fRec1_perm[j105] = fRec1_tmp[vsize + j105];
			}
			/* Vectorizable loop 124 */
			/* Pre code */
			for (int j106 = 0; j106 < 4; j106 = j106 + 1) {
				fYec12_tmp[j106] = fYec12_perm[j106];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fYec12[i] = fSlow49 * fRec1[i];
			}
			/* Post code */
			for (int j107 = 0; j107 < 4; j107 = j107 + 1) {
				fYec12_perm[j107] = fYec12_tmp[vsize + j107];
			}
			/* Recursive loop 125 */
			/* Pre code */
			for (int j108 = 0; j108 < 8; j108 = j108 + 1) {
				fRec0_tmp[j108] = fRec0_perm[j108];
			}
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fRec0[i] = 0.0f - (0.1f * (fRec0[i - 4] - fYec12[i - 1]) + 0.5f * (fRec0[i - 5] - fYec12[i - 3]));
			}
			/* Post code */
			for (int j109 = 0; j109 < 8; j109 = j109 + 1) {
				fRec0_perm[j109] = fRec0_tmp[vsize + j109];
			}
			/* Vectorizable loop 126 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				fZec92[i] = fSlow83 * fSlow82 * atanhf(std::max<float>(-0.9999999f, std::min<float>(0.9999999f, fRec0[i] + ((iSlow80) ? fSlow81 * fRec1[i] : fRec1[i]))));
			}
			/* Vectorizable loop 127 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				output0[i] = FAUSTFLOAT(fZec92[i]);
			}
			/* Vectorizable loop 128 */
			/* Compute code */
			for (int i = 0; i < vsize; i = i + 1) {
				output1[i] = FAUSTFLOAT(fZec92[i]);
			}
		}
	}

};

#endif
