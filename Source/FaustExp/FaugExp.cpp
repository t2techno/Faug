/* ------------------------------------------------------------
name: "FaugExp", "FaustDSP"
version: "2.52.3"
Code generated with Faust 2.52.7 (https://faust.grame.fr)
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
	
	int iVec6[2];
	int iRec23[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			iVec6[l23] = 0;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			iRec23[l24] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec6[0] = 1;
			iRec23[0] = (iVec6[1] + iRec23[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec23[0]));
			iVec6[1] = iVec6[0];
			iRec23[1] = iRec23[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float mydsp_faustpower2_f(float value) {
	return value * value;
}
static float ftbl0mydspSIG0[65536];
static float mydsp_faustpower4_f(float value) {
	return value * value * value * value;
}

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fCheckbox1;
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fConst3;
	float fRec1[2];
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec2[2];
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	float fRec4[2];
	FAUSTFLOAT fHslider2;
	float fRec5[2];
	float fRec6[2];
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fCheckbox3;
	FAUSTFLOAT fCheckbox4;
	FAUSTFLOAT fEntry0;
	float fVec2[2];
	float fVec3[2];
	FAUSTFLOAT fHslider4;
	float fConst4;
	FAUSTFLOAT fHslider5;
	float fRec12[2];
	int iRec13[2];
	FAUSTFLOAT fHslider6;
	float fRec14[2];
	float fRec15[2];
	FAUSTFLOAT fHslider7;
	float fRec16[2];
	FAUSTFLOAT fHslider8;
	float fRec17[2];
	float fVec4[2];
	FAUSTFLOAT fCheckbox5;
	FAUSTFLOAT fCheckbox6;
	int iRec19[2];
	float fVec5[2];
	float fRec18[4];
	float fConst6;
	float fConst11;
	float fConst12;
	float fConst13;
	float fRec22[2];
	float fConst16;
	float fConst17;
	float fConst18;
	float fConst21;
	float fConst22;
	float fRec21[2];
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst30;
	float fConst31;
	float fRec20[2];
	float fConst32;
	FAUSTFLOAT fCheckbox7;
	FAUSTFLOAT fHslider9;
	float fRec25[2];
	float fConst33;
	float fRec24[2];
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fCheckbox8;
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHslider12;
	float fConst34;
	float fRec27[2];
	int IOTA0;
	float fVec7[8192];
	int iConst35;
	int iConst36;
	FAUSTFLOAT fCheckbox9;
	FAUSTFLOAT fEntry1;
	FAUSTFLOAT fHslider13;
	int iVec8[2];
	int iRec29[2];
	int iRec28[2];
	FAUSTFLOAT fCheckbox10;
	FAUSTFLOAT fVbargraph0;
	FAUSTFLOAT fHslider14;
	float fRec30[2];
	FAUSTFLOAT fHslider15;
	FAUSTFLOAT fHslider16;
	float fRec26[2];
	float fRec32[2];
	float fVec9[2];
	float fVec10[4096];
	float fConst37;
	float fRec31[2];
	float fConst38;
	float fRec33[2];
	float fConst39;
	float fConst40;
	int iRec35[2];
	float fRec36[2];
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	float fRec37[2];
	FAUSTFLOAT fHslider19;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fCheckbox11;
	FAUSTFLOAT fHslider21;
	float fRec38[2];
	FAUSTFLOAT fCheckbox12;
	FAUSTFLOAT fHslider22;
	float fRec39[2];
	FAUSTFLOAT fCheckbox13;
	FAUSTFLOAT fHslider23;
	float fRec40[2];
	FAUSTFLOAT fCheckbox14;
	FAUSTFLOAT fHslider24;
	FAUSTFLOAT fHslider25;
	FAUSTFLOAT fCheckbox15;
	int iConst41;
	FAUSTFLOAT fHslider26;
	float fVec11[2];
	int iRec42[2];
	float fRec43[2];
	float fRec41[2];
	float fRec45[2];
	float fVec12[2];
	float fVec13[4096];
	float fRec44[2];
	float fRec46[2];
	FAUSTFLOAT fHslider27;
	FAUSTFLOAT fHslider28;
	float fVec14[2];
	int iRec49[2];
	float fRec50[2];
	float fRec48[2];
	float fRec52[2];
	float fVec15[2];
	float fVec16[4096];
	float fRec51[2];
	float fRec53[2];
	FAUSTFLOAT fHslider29;
	float fRec7[2];
	float fRec8[2];
	float fRec9[2];
	float fRec10[2];
	float fRec0[2];
	float fVec17[4];
	float fRec55[6];
	FAUSTFLOAT fCheckbox16;
	FAUSTFLOAT fHslider30;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("aanl_lib_name", "Faust Antialiased Nonlinearities");
		m->declare("aanl_lib_version", "0.3");
		m->declare("basics_lib_name", "Faust Basic Element Library");
		m->declare("basics_lib_version", "0.8");
		m->declare("compile_options", "-lang cpp -es 1 -mcd 16 -single -ftz 0");
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
		m->declare("filters_lib_lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters_lib_name", "Faust Filters Library");
		m->declare("filters_lib_pole_author", "Julius O. Smith III");
		m->declare("filters_lib_pole_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_pole_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_spectral_tilt_author", "Julius O. Smith III");
		m->declare("filters_lib_spectral_tilt_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_spectral_tilt_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_tf1_author", "Julius O. Smith III");
		m->declare("filters_lib_tf1_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_tf1_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_tf1s_author", "Julius O. Smith III");
		m->declare("filters_lib_tf1s_copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters_lib_tf1s_license", "MIT-style STK-4.3 license");
		m->declare("filters_lib_version", "0.3");
		m->declare("library_path0", "/libraries/stdfaust.lib");
		m->declare("library_path1", "/libraries/aanl.lib");
		m->declare("library_path10", "/libraries/vaeffects.lib");
		m->declare("library_path2", "/libraries/basics.lib");
		m->declare("library_path3", "/libraries/maths.lib");
		m->declare("library_path4", "/libraries/platform.lib");
		m->declare("library_path5", "/libraries/oscillators.lib");
		m->declare("library_path6", "/libraries/signals.lib");
		m->declare("library_path7", "/libraries/filters.lib");
		m->declare("library_path8", "/libraries/envelopes.lib");
		m->declare("library_path9", "/libraries/noises.lib");
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
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 0.0441f / fConst0;
		fConst4 = 0.5f * fConst0;
		float fConst5 = 1.0f / std::tan(0.5f / fConst0);
		fConst6 = 125.663704f - fConst5;
		float fConst7 = std::tan(62.831852f / fConst0);
		float fConst8 = std::sqrt(0.0175f * fConst0);
		float fConst9 = std::tan(62.831852f * (std::sqrt(std::sqrt(fConst8)) / fConst0));
		float fConst10 = 125.663704f * (fConst9 / fConst7);
		fConst11 = fConst10 - fConst5;
		fConst12 = fConst5 + fConst10;
		fConst13 = 1.0f / (fConst5 + 125.663704f);
		float fConst14 = std::tan(62.831852f * (std::pow(fConst8, 1.25f) / fConst0));
		float fConst15 = 125.663704f * (fConst14 / fConst7);
		fConst16 = fConst15 - fConst5;
		fConst17 = fConst5 + fConst15;
		fConst18 = fConst7 / fConst9;
		float fConst19 = std::tan(62.831852f * (fConst8 / fConst0));
		float fConst20 = 125.663704f * (fConst19 / fConst7);
		fConst21 = fConst20 - fConst5;
		fConst22 = 1.0f / (fConst5 + fConst20);
		float fConst23 = std::tan(62.831852f * (std::pow(fConst8, 2.25f) / fConst0));
		float fConst24 = 125.663704f * (fConst23 / fConst7);
		fConst25 = fConst24 - fConst5;
		fConst26 = fConst5 + fConst24;
		fConst27 = fConst19 / fConst14;
		float fConst28 = std::tan(62.831852f * (mydsp_faustpower2_f(fConst8) / fConst0));
		float fConst29 = 125.663704f * (fConst28 / fConst7);
		fConst30 = fConst29 - fConst5;
		fConst31 = 1.0f / (fConst5 + fConst29);
		fConst32 = fConst28 / fConst23;
		fConst33 = 1.0f / fConst0;
		fConst34 = 0.05f / fConst0;
		iConst35 = int(0.01f * fConst0);
		iConst36 = 3 * iConst35;
		fConst37 = 0.25f * fConst0;
		fConst38 = 4.0f / fConst0;
		fConst39 = 0.7f * fConst0;
		fConst40 = 0.85f * fConst0;
		iConst41 = 2 * iConst35;
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(5e+01f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(5e+01f);
		fHslider2 = FAUSTFLOAT(0.8f);
		fCheckbox2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.0f);
		fCheckbox3 = FAUSTFLOAT(0.0f);
		fCheckbox4 = FAUSTFLOAT(0.0f);
		fEntry0 = FAUSTFLOAT(4.4e+02f);
		fHslider4 = FAUSTFLOAT(0.5f);
		fHslider5 = FAUSTFLOAT(5e+01f);
		fHslider6 = FAUSTFLOAT(5e+01f);
		fHslider7 = FAUSTFLOAT(0.8f);
		fHslider8 = FAUSTFLOAT(0.0f);
		fCheckbox5 = FAUSTFLOAT(0.0f);
		fCheckbox6 = FAUSTFLOAT(0.0f);
		fCheckbox7 = FAUSTFLOAT(0.0f);
		fHslider9 = FAUSTFLOAT(1e+01f);
		fHslider10 = FAUSTFLOAT(0.0f);
		fCheckbox8 = FAUSTFLOAT(0.0f);
		fHslider11 = FAUSTFLOAT(1.0f);
		fHslider12 = FAUSTFLOAT(2.0f);
		fCheckbox9 = FAUSTFLOAT(0.0f);
		fEntry1 = FAUSTFLOAT(4.4e+02f);
		fHslider13 = FAUSTFLOAT(0.01f);
		fCheckbox10 = FAUSTFLOAT(0.0f);
		fHslider14 = FAUSTFLOAT(0.0f);
		fHslider15 = FAUSTFLOAT(0.0f);
		fHslider16 = FAUSTFLOAT(0.0f);
		fHslider17 = FAUSTFLOAT(0.0f);
		fHslider18 = FAUSTFLOAT(1.0f);
		fHslider19 = FAUSTFLOAT(0.0f);
		fHslider20 = FAUSTFLOAT(0.0f);
		fCheckbox11 = FAUSTFLOAT(0.0f);
		fHslider21 = FAUSTFLOAT(1.0f);
		fCheckbox12 = FAUSTFLOAT(0.0f);
		fHslider22 = FAUSTFLOAT(1.0f);
		fCheckbox13 = FAUSTFLOAT(0.0f);
		fHslider23 = FAUSTFLOAT(1.0f);
		fCheckbox14 = FAUSTFLOAT(0.0f);
		fHslider24 = FAUSTFLOAT(1.0f);
		fHslider25 = FAUSTFLOAT(2.0f);
		fCheckbox15 = FAUSTFLOAT(0.0f);
		fHslider26 = FAUSTFLOAT(0.0f);
		fHslider27 = FAUSTFLOAT(1.0f);
		fHslider28 = FAUSTFLOAT(2.0f);
		fHslider29 = FAUSTFLOAT(1.0f);
		fCheckbox16 = FAUSTFLOAT(0.0f);
		fHslider30 = FAUSTFLOAT(1.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec2[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec6[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fVec2[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fVec3[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec12[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iRec13[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec14[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec15[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec16[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec17[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fVec4[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			iRec19[l17] = 0;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fVec5[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 4; l19 = l19 + 1) {
			fRec18[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec22[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec21[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec20[l22] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec25[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec24[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec27[l27] = 0.0f;
		}
		IOTA0 = 0;
		for (int l28 = 0; l28 < 8192; l28 = l28 + 1) {
			fVec7[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			iVec8[l29] = 0;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			iRec29[l30] = 0;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			iRec28[l31] = 0;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec30[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec26[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec32[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fVec9[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 4096; l36 = l36 + 1) {
			fVec10[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec31[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec33[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			iRec35[l39] = 0;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec36[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec37[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec38[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec39[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fRec40[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fVec11[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			iRec42[l46] = 0;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fRec43[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fRec41[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec45[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fVec12[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 4096; l51 = l51 + 1) {
			fVec13[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec44[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			fRec46[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			fVec14[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			iRec49[l55] = 0;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec50[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec48[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			fRec52[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			fVec15[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 4096; l60 = l60 + 1) {
			fVec16[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			fRec51[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			fRec53[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2; l63 = l63 + 1) {
			fRec7[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 2; l64 = l64 + 1) {
			fRec8[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 2; l65 = l65 + 1) {
			fRec9[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = l66 + 1) {
			fRec10[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 2; l67 = l67 + 1) {
			fRec0[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 4; l68 = l68 + 1) {
			fVec17[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 6; l69 = l69 + 1) {
			fRec55[l69] = 0.0f;
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
		ui_interface->declare(&fHslider14, "03", "");
		ui_interface->declare(&fHslider14, "style", "knob");
		ui_interface->addHorizontalSlider("pitchBend", &fHslider14, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2.5f), FAUSTFLOAT(2.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider13, "04", "");
		ui_interface->declare(&fHslider13, "style", "knob");
		ui_interface->addHorizontalSlider("glide", &fHslider13, FAUSTFLOAT(0.01f), FAUSTFLOAT(0.001f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fCheckbox10, "05", "");
		ui_interface->addCheckButton("glideOn", &fCheckbox10);
		ui_interface->declare(&fCheckbox13, "06", "");
		ui_interface->addCheckButton("oscOnePower", &fCheckbox13);
		ui_interface->declare(&fCheckbox12, "07", "");
		ui_interface->addCheckButton("oscTwoPower", &fCheckbox12);
		ui_interface->declare(&fCheckbox14, "08", "");
		ui_interface->addCheckButton("oscThreePower", &fCheckbox14);
		ui_interface->declare(&fHslider22, "09", "");
		ui_interface->declare(&fHslider22, "style", "knob");
		ui_interface->addHorizontalSlider("oscOneGain", &fHslider22, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider21, "10", "");
		ui_interface->declare(&fHslider21, "style", "knob");
		ui_interface->addHorizontalSlider("oscTwoGain", &fHslider21, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider23, "11", "");
		ui_interface->declare(&fHslider23, "style", "knob");
		ui_interface->addHorizontalSlider("oscThreeGain", &fHslider23, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox15, "12", "");
		ui_interface->addCheckButton("oscModOn", &fCheckbox15);
		ui_interface->declare(&fCheckbox9, "13", "");
		ui_interface->addCheckButton("oscThreeKeyTrack", &fCheckbox9);
		ui_interface->declare(&fHslider27, "14", "");
		ui_interface->declare(&fHslider27, "style", "knob");
		ui_interface->addHorizontalSlider("waveOne", &fHslider27, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider24, "15", "");
		ui_interface->declare(&fHslider24, "style", "knob");
		ui_interface->addHorizontalSlider("waveTwo", &fHslider24, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider11, "16", "");
		ui_interface->declare(&fHslider11, "style", "knob");
		ui_interface->addHorizontalSlider("waveThree", &fHslider11, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider28, "17", "");
		ui_interface->declare(&fHslider28, "style", "knob");
		ui_interface->addHorizontalSlider("rangeOne", &fHslider28, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider25, "18", "");
		ui_interface->declare(&fHslider25, "style", "knob");
		ui_interface->addHorizontalSlider("rangeTwo", &fHslider25, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider12, "19", "");
		ui_interface->declare(&fHslider12, "style", "knob");
		ui_interface->addHorizontalSlider("rangeThree", &fHslider12, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider16, "20", "");
		ui_interface->declare(&fHslider16, "style", "knob");
		ui_interface->addHorizontalSlider("globalDetune", &fHslider16, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2.5f), FAUSTFLOAT(2.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider26, "21", "");
		ui_interface->declare(&fHslider26, "style", "knob");
		ui_interface->addHorizontalSlider("detuneTwo", &fHslider26, FAUSTFLOAT(0.0f), FAUSTFLOAT(-7.5f), FAUSTFLOAT(7.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider15, "22", "");
		ui_interface->declare(&fHslider15, "style", "knob");
		ui_interface->addHorizontalSlider("detuneThree", &fHslider15, FAUSTFLOAT(0.0f), FAUSTFLOAT(-7.5f), FAUSTFLOAT(7.5f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox1, "23", "");
		ui_interface->addCheckButton("decayOn", &fCheckbox1);
		ui_interface->declare(&fHslider1, "24", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("attack", &fHslider1, FAUSTFLOAT(5e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider0, "25", "");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("decay", &fHslider0, FAUSTFLOAT(5e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(2.4e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "26", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("sustain", &fHslider2, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider4, "27", "");
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->addHorizontalSlider("cutoff", &fHslider4, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fCheckbox4, "28", "");
		ui_interface->addCheckButton("keyTrackOne", &fCheckbox4);
		ui_interface->declare(&fCheckbox3, "29", "");
		ui_interface->addCheckButton("keyTrackTwo", &fCheckbox3);
		ui_interface->declare(&fHslider3, "30", "");
		ui_interface->declare(&fHslider3, "style", "radio{'+':0;'-':1}");
		ui_interface->addHorizontalSlider("contour_direction", &fHslider3, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider8, "31", "");
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("contourAmount", &fHslider8, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider6, "32", "");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->addHorizontalSlider("fAttack", &fHslider6, FAUSTFLOAT(5e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(7e+03f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider5, "33", "");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("fDecay", &fHslider5, FAUSTFLOAT(5e+01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(3e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider7, "34", "");
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->addHorizontalSlider("fSustain", &fHslider7, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox2, "35", "");
		ui_interface->addCheckButton("filterModOn", &fCheckbox2);
		ui_interface->declare(&fHslider18, "36", "");
		ui_interface->declare(&fHslider18, "style", "knob");
		ui_interface->addHorizontalSlider("emphasis", &fHslider18, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.707f), FAUSTFLOAT(25.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fCheckbox6, "37", "");
		ui_interface->addCheckButton("noiseType", &fCheckbox6);
		ui_interface->declare(&fCheckbox11, "38", "");
		ui_interface->addCheckButton("noiseOn", &fCheckbox11);
		ui_interface->declare(&fHslider20, "39", "");
		ui_interface->declare(&fHslider20, "style", "knob");
		ui_interface->addHorizontalSlider("noiseGain", &fHslider20, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox8, "40", "");
		ui_interface->addCheckButton("oscThree_filterEg", &fCheckbox8);
		ui_interface->declare(&fHslider9, "41", "");
		ui_interface->declare(&fHslider9, "style", "knob");
		ui_interface->addHorizontalSlider("lfoRate", &fHslider9, FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.5f), FAUSTFLOAT(2e+02f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fCheckbox7, "42", "");
		ui_interface->addCheckButton("lfoShape", &fCheckbox7);
		ui_interface->declare(&fCheckbox5, "43", "");
		ui_interface->addCheckButton("noise_lfo", &fCheckbox5);
		ui_interface->declare(&fHslider10, "44", "");
		ui_interface->declare(&fHslider10, "style", "knob");
		ui_interface->addHorizontalSlider("modMix", &fHslider10, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider17, "45", "");
		ui_interface->declare(&fHslider17, "style", "knob");
		ui_interface->addHorizontalSlider("modAmount", &fHslider17, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider29, "46", "");
		ui_interface->declare(&fHslider29, "style", "knob");
		ui_interface->addHorizontalSlider("load", &fHslider29, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider19, "style", "knob");
		ui_interface->addHorizontalSlider("feedbackGain", &fHslider19, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addCheckButton("feedbackOn", &fCheckbox0);
		ui_interface->declare(&fVbargraph0, "style", "numerical");
		ui_interface->addVerticalBargraph("finalFreq", &fVbargraph0, FAUSTFLOAT(0.0f), FAUSTFLOAT(2e+04f));
		ui_interface->declare(&fHslider30, "style", "knob");
		ui_interface->addHorizontalSlider("masterVolume", &fHslider30, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addCheckButton("on", &fCheckbox16);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fCheckbox0);
		int iSlow1 = int(fSlow0);
		int iSlow2 = int(float(fCheckbox1));
		float fSlow3 = fConst3 * float(fHslider0);
		float fSlow4 = float(fButton0);
		int iSlow5 = fSlow4 == 0.0f;
		float fSlow6 = fConst3 * float(fHslider1);
		float fSlow7 = fConst1 * float(fHslider2);
		int iSlow8 = int(float(fCheckbox2));
		int iSlow9 = int(float(fHslider3));
		float fSlow10 = float(fEntry0);
		float fSlow11 = (fSlow10 + -130.81f) * (float(fCheckbox4) + 2.0f * float(fCheckbox3));
		float fSlow12 = 0.33333334f * fSlow11;
		float fSlow13 = float(fHslider4);
		float fThen2 = std::min<float>(16.0f * fSlow13, fConst4);
		float fElse2 = 0.0625f * fSlow13;
		float fSlow14 = ((iSlow9) ? fElse2 : fThen2);
		float fSlow15 = fSlow14 - fSlow12;
		float fSlow16 = fConst1 * float(fHslider5);
		int iSlow17 = fSlow12 == 0.0f;
		float fSlow18 = fConst1 * float(fHslider6);
		float fSlow19 = fConst1 * float(fHslider7);
		float fSlow20 = fConst1 * float(fHslider8);
		float fSlow21 = fSlow12 - fSlow14;
		float fSlow22 = fConst0 * fSlow13;
		int iSlow23 = int(float(fCheckbox5));
		int iSlow24 = int(float(fCheckbox6));
		int iSlow25 = int(float(fCheckbox7));
		float fSlow26 = fConst1 * float(fHslider9);
		float fSlow27 = float(fHslider10);
		int iSlow28 = int(float(fCheckbox8));
		float fSlow29 = float(fHslider11);
		int iSlow30 = fSlow29 >= 3.0f;
		int iSlow31 = fSlow29 >= 2.0f;
		int iSlow32 = fSlow29 >= 1.0f;
		float fSlow33 = float(fHslider12);
		int iSlow34 = int(fSlow33);
		int iSlow35 = int(float(fCheckbox9));
		float fSlow36 = float(fEntry1);
		float fSlow37 = float(fHslider13);
		float fElse8 = 0.5555556f * fSlow37;
		float fSlow38 = ((fSlow10 > fSlow36) ? fElse8 : fSlow37);
		float fSlow39 = ((int(float(fCheckbox10))) ? fSlow36 : fSlow10);
		float fSlow40 = fConst1 * std::pow(2.0f, 0.083333336f * float(fHslider14));
		float fSlow41 = float(fHslider16);
		float fSlow42 = std::pow(2.0f, fSlow33 + -4.0f) * std::pow(2.0f, 0.083333336f * (fSlow41 + float(fHslider15)));
		float fSlow43 = fConst33 * fSlow42;
		float fSlow44 = fConst38 * fSlow42;
		int iSlow45 = fSlow29 >= 5.0f;
		int iSlow46 = fSlow29 >= 4.0f;
		float fSlow47 = 1.0f - fSlow27;
		float fSlow48 = float(fHslider17);
		float fSlow49 = fConst1 * float(fHslider18);
		float fSlow50 = float(fHslider19);
		float fSlow51 = fSlow0 * fSlow50;
		float fSlow52 = float(fCheckbox11) * float(fHslider20);
		float fSlow53 = fConst1 * float(fHslider21);
		float fSlow54 = float(fCheckbox12);
		float fSlow55 = fConst1 * float(fHslider22);
		float fSlow56 = float(fCheckbox13);
		float fSlow57 = fConst1 * float(fHslider23);
		float fSlow58 = float(fCheckbox14);
		float fSlow59 = float(fHslider24);
		int iSlow60 = fSlow59 >= 3.0f;
		int iSlow61 = fSlow59 >= 2.0f;
		int iSlow62 = fSlow59 >= 1.0f;
		float fSlow63 = float(fHslider25);
		int iSlow64 = int(fSlow63);
		int iSlow65 = int(float(fCheckbox15));
		float fSlow66 = std::pow(2.0f, fSlow63 + -4.0f) * std::pow(2.0f, 0.083333336f * (fSlow41 + float(fHslider26)));
		int iSlow67 = fSlow59 >= 5.0f;
		int iSlow68 = fSlow59 >= 4.0f;
		float fSlow69 = float(fHslider27);
		int iSlow70 = fSlow69 >= 3.0f;
		int iSlow71 = fSlow69 >= 2.0f;
		int iSlow72 = fSlow69 >= 1.0f;
		float fSlow73 = float(fHslider28);
		int iSlow74 = int(fSlow73);
		float fSlow75 = std::pow(2.0f, fSlow73 + -4.0f) * std::pow(2.0f, 0.083333336f * fSlow41);
		int iSlow76 = fSlow69 >= 5.0f;
		int iSlow77 = fSlow69 >= 4.0f;
		float fSlow78 = float(fHslider29);
		float fSlow79 = 1.0f - fSlow50;
		float fSlow80 = ((int(float(fCheckbox16))) ? 0.0f : 1.0f);
		float fSlow81 = float(fHslider30);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fRec1[0] = fSlow3 + fConst2 * fRec1[1];
			fVec1[0] = fSlow4;
			iRec2[0] = iSlow5 * (iRec2[1] + 1);
			fRec3[0] = fSlow6 + fConst2 * fRec3[1];
			float fTemp0 = std::max<float>(1.0f, fConst0 * fRec3[0]);
			fRec4[0] = fSlow4 + fRec4[1] * float(fVec1[1] >= fSlow4);
			fRec5[0] = fSlow7 + fConst2 * fRec5[1];
			float fTemp1 = std::max<float>(0.0f, std::min<float>(fRec4[0] / fTemp0, std::max<float>((1.0f - fRec5[0]) * (fTemp0 - fRec4[0]) / std::max<float>(1.0f, fConst0 * fRec1[0]) + 1.0f, fRec5[0])) * (1.0f - float(iRec2[0]) / std::max<float>(1.0f, fConst0 * ((iSlow2) ? fRec1[0] : 0.01f))));
			fRec6[0] = fConst1 * fTemp1 + fConst2 * fRec6[1];
			fVec2[0] = fSlow10;
			fVec3[0] = fSlow11;
			fRec12[0] = fSlow16 + fConst2 * fRec12[1];
			float fTemp2 = std::max<float>(1.0f, fConst0 * ((iSlow2) ? fRec12[0] : 1e+01f));
			iRec13[0] = iSlow17 * (iRec13[1] + 1);
			fRec14[0] = fSlow18 + fConst2 * fRec14[1];
			float fTemp3 = std::max<float>(1.0f, fConst0 * fRec14[0]);
			fRec15[0] = fSlow12 + fRec15[1] * float((0.33333334f * fVec3[1]) >= fSlow12);
			float fTemp4 = std::max<float>(1.0f, fConst0 * fRec12[0]);
			fRec16[0] = fSlow19 + fConst2 * fRec16[1];
			float fTemp5 = 1.0f - fRec16[0];
			fRec17[0] = fSlow20 + fConst2 * fRec17[1];
			float fTemp6 = fRec17[0] * std::max<float>(0.0f, std::min<float>(fRec15[0] / fTemp3, std::max<float>(fTemp5 * (fTemp3 - fRec15[0]) / fTemp4 + 1.0f, fRec16[0])) * (1.0f - float(iRec13[0]) / fTemp2));
			float fThen4 = fSlow12 + fTemp6 * fSlow15;
			float fElse4 = fSlow12 - fTemp6 * fSlow21;
			float fTemp7 = ((iSlow9) ? fElse4 : fThen4);
			float fTemp8 = fSlow22 + fTemp7;
			fVec4[0] = fTemp8;
			iRec19[0] = 1103515245 * iRec19[1] + 12345;
			float fTemp9 = float(iRec19[0]);
			fVec5[0] = fTemp9;
			float fTemp10 = 4.656613e-10f * fTemp9;
			fRec18[0] = 0.5221894f * fRec18[3] + fTemp10 + 2.494956f * fRec18[1] - 2.0172658f * fRec18[2];
			float fTemp11 = 0.049922034f * fRec18[0] + 0.0506127f * fRec18[2] - (0.095993534f * fRec18[1] + 0.004408786f * fRec18[3]);
			fRec22[0] = fConst13 * (4.656613e-10f * (fConst12 * fTemp9 + fConst11 * fVec5[1]) - fConst6 * fRec22[1]);
			fRec21[0] = 0.0f - fConst22 * (fConst21 * fRec21[1] - fConst18 * (fConst17 * fRec22[0] + fConst16 * fRec22[1]));
			fRec20[0] = 0.0f - fConst31 * (fConst30 * fRec20[1] - fConst27 * (fConst26 * fRec21[0] + fConst25 * fRec21[1]));
			float fElse5 = fConst32 * fRec20[0];
			fRec25[0] = fSlow26 + fConst2 * fRec25[1];
			float fTemp12 = fRec24[1] + fConst33 * fRec25[0];
			fRec24[0] = fTemp12 - std::floor(fTemp12);
			float fThen6 = ftbl0mydspSIG0[int(65536.0f * fRec24[0])];
			float fElse6 = 2.0f * float(fRec24[0] <= 0.5f) + -1.0f;
			float fThen7 = ((iSlow24) ? fElse5 : fTemp11);
			float fElse7 = ((iSlow25) ? fElse6 : fThen6);
			float fTemp13 = fSlow27 * ((iSlow23) ? fElse7 : fThen7);
			fRec27[0] = fConst34 + (fRec27[1] - std::floor(fConst34 + fRec27[1]));
			float fTemp14 = std::pow(2.0f, 0.01f * ftbl0mydspSIG0[int(65536.0f * fRec27[0])]);
			fVec7[IOTA0 & 8191] = fTemp14;
			float fTemp15 = fVec7[(IOTA0 - iConst36) & 8191];
			int iTemp16 = fSlow10 != fVec2[1];
			iVec8[0] = iTemp16;
			int iTemp17 = (iVec8[1] <= 0) & (iTemp16 > 0);
			iRec29[0] = iRec29[1] + 1;
			iRec28[0] = iRec28[1] * (1 - iTemp17) + (iRec29[0] + -1) * iTemp17;
			float fTemp18 = std::max<float>(std::exp(fConst33 * (float(-1 * (iRec29[0] + (-1 - iRec28[0]))) / fSlow38)), 0.01f);
			float fTemp19 = fSlow10 * (1.0f - fTemp18) + fSlow39 * fTemp18;
			fVbargraph0 = FAUSTFLOAT(fTemp19);
			float fTemp20 = fTemp19;
			float fTemp21 = ((iSlow35) ? 130.81f : fTemp20);
			fRec30[0] = fSlow40 + fConst2 * fRec30[1];
			float fTemp22 = fRec30[0] * fTemp21 * fTemp15;
			float fTemp23 = fRec26[1] + fSlow43 * fTemp22;
			fRec26[0] = fTemp23 - std::floor(fTemp23);
			float fTemp24 = 2.0f * fRec26[0] + -1.0f;
			float fTemp25 = fSlow42 * fTemp22;
			float fTemp26 = std::max<float>(fTemp25, 23.44895f);
			float fTemp27 = std::max<float>(2e+01f, std::fabs(fTemp26));
			float fTemp28 = fRec32[1] + fConst33 * fTemp27;
			fRec32[0] = fTemp28 - std::floor(fTemp28);
			float fTemp29 = mydsp_faustpower2_f(2.0f * fRec32[0] + -1.0f);
			fVec9[0] = fTemp29;
			float fTemp30 = float(iVec0[1]);
			float fTemp31 = fTemp30 * (fTemp29 - fVec9[1]) / fTemp27;
			fVec10[IOTA0 & 4095] = fTemp31;
			float fTemp32 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst4 / fTemp26));
			int iTemp33 = int(fTemp32);
			float fTemp34 = std::floor(fTemp32);
			float fTemp35 = fConst37 * (fTemp31 - fVec10[(IOTA0 - iTemp33) & 4095] * (fTemp34 + (1.0f - fTemp32)) - (fTemp32 - fTemp34) * fVec10[(IOTA0 - (iTemp33 + 1)) & 4095]);
			fRec31[0] = 0.999f * fRec31[1] + fTemp35;
			float fThen11 = 2.0f * (1.0f - std::fabs(fTemp24)) + -1.0f;
			float fElse11 = fSlow44 * fRec30[0] * fRec31[0] * fTemp21 * fTemp15;
			float fTemp36 = std::max<float>(1.1920929e-07f, std::fabs(fTemp25));
			float fTemp37 = fRec33[1] + fConst33 * fTemp36;
			float fTemp38 = fTemp37 + -1.0f;
			int iTemp39 = fTemp38 < 0.0f;
			fRec33[0] = ((iTemp39) ? fTemp37 : fTemp38);
			float fThen13 = fTemp37 + fTemp38 * (1.0f - fConst0 / fTemp36);
			float fRec34 = ((iTemp39) ? fTemp37 : fThen13);
			float fElse14 = 2.0f * fRec34 + -1.0f;
			float fTemp40 = ((iSlow34) ? fElse14 : fTemp24);
			float fThen15 = ((iSlow34) ? fElse11 : fThen11);
			float fThen16 = ((iSlow32) ? fTemp40 : fThen15);
			float fElse16 = 0.0f - fTemp40;
			float fThen17 = 2.0f * float(fRec26[0] <= 0.5f) + -1.0f;
			float fTemp41 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst39 / fTemp26));
			int iTemp42 = int(fTemp41);
			float fTemp43 = std::floor(fTemp41);
			float fThen18 = 2.0f * float(fRec26[0] <= 0.7f) + -1.0f;
			float fElse18 = fConst37 * (fTemp31 - fVec10[(IOTA0 - iTemp42) & 4095] * (fTemp43 + (1.0f - fTemp41)) - (fTemp41 - fTemp43) * fVec10[(IOTA0 - (iTemp42 + 1)) & 4095]);
			float fThen19 = ((iSlow34) ? fTemp35 : fThen17);
			float fElse19 = ((iSlow34) ? fElse18 : fThen18);
			float fTemp44 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst40 / fTemp26));
			int iTemp45 = int(fTemp44);
			float fTemp46 = std::floor(fTemp44);
			float fThen20 = 2.0f * float(fRec26[0] <= 0.85f) + -1.0f;
			float fElse20 = fConst37 * (fTemp31 - fVec10[(IOTA0 - iTemp45) & 4095] * (fTemp46 + (1.0f - fTemp44)) - (fTemp44 - fTemp46) * fVec10[(IOTA0 - (iTemp45 + 1)) & 4095]);
			float fThen21 = ((iSlow46) ? fElse19 : fThen19);
			float fElse21 = ((iSlow34) ? fElse20 : fThen20);
			float fThen22 = ((iSlow31) ? fElse16 : fThen16);
			float fElse22 = ((iSlow45) ? fElse21 : fThen21);
			float fTemp47 = ((iSlow30) ? fElse22 : fThen22);
			iRec35[0] = (iRec35[1] + 1) * (fTemp8 == 0.0f);
			fRec36[0] = fSlow22 + fTemp7 + fRec36[1] * float(fVec4[1] >= fTemp8);
			float fElse23 = std::max<float>(0.0f, std::min<float>(fRec36[0] / fTemp3, std::max<float>(fTemp5 * (fTemp3 - fRec36[0]) / fTemp4 + 1.0f, fRec16[0])) * (1.0f - float(iRec35[0]) / fTemp2));
			float fElse24 = fTemp8 * std::pow(2.0f, fSlow48 * (fSlow47 * ((iSlow28) ? fElse23 : fTemp47) + fTemp13));
			float fTemp48 = std::tan(1.5707964f * std::min<float>(std::max<float>(fConst33 * ((iSlow8) ? fElse24 : fTemp8), 0.0f), 1.0f));
			float fTemp49 = fTemp48 + 1.0f;
			fRec37[0] = fSlow49 + fConst2 * fRec37[1];
			float fTemp50 = fRec37[0] + -0.707f;
			fRec38[0] = fSlow53 + fConst2 * fRec38[1];
			fRec39[0] = fSlow55 + fConst2 * fRec39[1];
			fRec40[0] = fSlow57 + fConst2 * fRec40[1];
			float fTemp51 = fRec30[0] * fTemp20;
			float fTemp52 = fTemp51 * fVec7[(IOTA0 - iConst41) & 8191];
			float fTemp53 = fSlow66 * fTemp52;
			fVec11[0] = fTemp53;
			iRec42[0] = (iRec42[1] + 1) * (fTemp53 == 0.0f);
			fRec43[0] = fTemp53 + fRec43[1] * float(fVec11[1] >= fTemp53);
			float fElse26 = std::max<float>(0.0f, std::min<float>(fRec43[0] / fTemp3, std::max<float>(fTemp5 * (fTemp3 - fRec43[0]) / fTemp4 + 1.0f, fRec16[0])) * (1.0f - float(iRec42[0]) / fTemp2));
			float fElse27 = fSlow66 * fTemp52 * std::pow(2.0f, fSlow48 * (fTemp13 + fSlow47 * ((iSlow28) ? fElse26 : fTemp47)));
			float fTemp54 = ((iSlow65) ? fElse27 : fTemp53);
			float fTemp55 = fRec41[1] + fConst33 * fTemp54;
			fRec41[0] = fTemp55 - std::floor(fTemp55);
			float fTemp56 = 2.0f * fRec41[0] + -1.0f;
			float fTemp57 = std::max<float>(fTemp54, 23.44895f);
			float fTemp58 = std::max<float>(2e+01f, std::fabs(fTemp57));
			float fTemp59 = fRec45[1] + fConst33 * fTemp58;
			fRec45[0] = fTemp59 - std::floor(fTemp59);
			float fTemp60 = mydsp_faustpower2_f(2.0f * fRec45[0] + -1.0f);
			fVec12[0] = fTemp60;
			float fTemp61 = fTemp30 * (fTemp60 - fVec12[1]) / fTemp58;
			fVec13[IOTA0 & 4095] = fTemp61;
			float fTemp62 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst4 / fTemp57));
			int iTemp63 = int(fTemp62);
			float fTemp64 = std::floor(fTemp62);
			float fTemp65 = fConst37 * (fTemp61 - fVec13[(IOTA0 - iTemp63) & 4095] * (fTemp64 + (1.0f - fTemp62)) - (fTemp62 - fTemp64) * fVec13[(IOTA0 - (iTemp63 + 1)) & 4095]);
			fRec44[0] = 0.999f * fRec44[1] + fTemp65;
			float fThen28 = 2.0f * (1.0f - std::fabs(fTemp56)) + -1.0f;
			float fElse28 = fConst38 * fRec44[0] * fTemp54;
			float fTemp66 = ((iSlow64) ? fElse28 : fThen28);
			float fTemp67 = std::max<float>(1.1920929e-07f, std::fabs(fTemp54));
			float fTemp68 = fRec46[1] + fConst33 * fTemp67;
			float fTemp69 = fTemp68 + -1.0f;
			int iTemp70 = fTemp69 < 0.0f;
			fRec46[0] = ((iTemp70) ? fTemp68 : fTemp69);
			float fThen30 = fTemp68 + fTemp69 * (1.0f - fConst0 / fTemp67);
			float fRec47 = ((iTemp70) ? fTemp68 : fThen30);
			float fElse31 = 2.0f * fRec47 + -1.0f;
			float fTemp71 = ((iSlow64) ? fElse31 : fTemp56);
			float fThen33 = ((iSlow62) ? fTemp71 : fTemp66);
			float fElse33 = 0.5f * (fTemp66 + fTemp71);
			float fThen34 = 2.0f * float(fRec41[0] <= 0.5f) + -1.0f;
			float fTemp72 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst39 / fTemp57));
			int iTemp73 = int(fTemp72);
			float fTemp74 = std::floor(fTemp72);
			float fThen35 = 2.0f * float(fRec41[0] <= 0.7f) + -1.0f;
			float fElse35 = fConst37 * (fTemp61 - fVec13[(IOTA0 - iTemp73) & 4095] * (fTemp74 + (1.0f - fTemp72)) - (fTemp72 - fTemp74) * fVec13[(IOTA0 - (iTemp73 + 1)) & 4095]);
			float fThen36 = ((iSlow64) ? fTemp65 : fThen34);
			float fElse36 = ((iSlow64) ? fElse35 : fThen35);
			float fTemp75 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst40 / fTemp57));
			int iTemp76 = int(fTemp75);
			float fTemp77 = std::floor(fTemp75);
			float fThen37 = 2.0f * float(fRec41[0] <= 0.85f) + -1.0f;
			float fElse37 = fConst37 * (fTemp61 - fVec13[(IOTA0 - iTemp76) & 4095] * (fTemp77 + (1.0f - fTemp75)) - (fTemp75 - fTemp77) * fVec13[(IOTA0 - (iTemp76 + 1)) & 4095]);
			float fThen38 = ((iSlow68) ? fElse36 : fThen36);
			float fElse38 = ((iSlow64) ? fElse37 : fThen37);
			float fThen39 = ((iSlow61) ? fElse33 : fThen33);
			float fElse39 = ((iSlow67) ? fElse38 : fThen38);
			float fTemp78 = fTemp51 * fVec7[(IOTA0 - iConst35) & 8191];
			float fTemp79 = fSlow75 * fTemp78;
			fVec14[0] = fTemp79;
			iRec49[0] = (iRec49[1] + 1) * (fTemp79 == 0.0f);
			fRec50[0] = fTemp79 + fRec50[1] * float(fVec14[1] >= fTemp79);
			float fElse40 = std::max<float>(0.0f, std::min<float>(fRec50[0] / fTemp3, std::max<float>(fTemp5 * (fTemp3 - fRec50[0]) / fTemp4 + 1.0f, fRec16[0])) * (1.0f - float(iRec49[0]) / fTemp2));
			float fElse41 = fSlow75 * fTemp78 * std::pow(2.0f, fSlow48 * (fTemp13 + fSlow47 * ((iSlow28) ? fElse40 : fTemp47)));
			float fTemp80 = ((iSlow65) ? fElse41 : fTemp79);
			float fTemp81 = fRec48[1] + fConst33 * fTemp80;
			fRec48[0] = fTemp81 - std::floor(fTemp81);
			float fTemp82 = 2.0f * fRec48[0] + -1.0f;
			float fTemp83 = std::max<float>(fTemp80, 23.44895f);
			float fTemp84 = std::max<float>(2e+01f, std::fabs(fTemp83));
			float fTemp85 = fRec52[1] + fConst33 * fTemp84;
			fRec52[0] = fTemp85 - std::floor(fTemp85);
			float fTemp86 = mydsp_faustpower2_f(2.0f * fRec52[0] + -1.0f);
			fVec15[0] = fTemp86;
			float fTemp87 = fTemp30 * (fTemp86 - fVec15[1]) / fTemp84;
			fVec16[IOTA0 & 4095] = fTemp87;
			float fTemp88 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst4 / fTemp83));
			int iTemp89 = int(fTemp88);
			float fTemp90 = std::floor(fTemp88);
			float fTemp91 = fConst37 * (fTemp87 - fVec16[(IOTA0 - iTemp89) & 4095] * (fTemp90 + (1.0f - fTemp88)) - (fTemp88 - fTemp90) * fVec16[(IOTA0 - (iTemp89 + 1)) & 4095]);
			fRec51[0] = 0.999f * fRec51[1] + fTemp91;
			float fThen42 = 2.0f * (1.0f - std::fabs(fTemp82)) + -1.0f;
			float fElse42 = fConst38 * fRec51[0] * fTemp80;
			float fTemp92 = ((iSlow74) ? fElse42 : fThen42);
			float fTemp93 = std::max<float>(1.1920929e-07f, std::fabs(fTemp80));
			float fTemp94 = fRec53[1] + fConst33 * fTemp93;
			float fTemp95 = fTemp94 + -1.0f;
			int iTemp96 = fTemp95 < 0.0f;
			fRec53[0] = ((iTemp96) ? fTemp94 : fTemp95);
			float fThen44 = fTemp94 + fTemp95 * (1.0f - fConst0 / fTemp93);
			float fRec54 = ((iTemp96) ? fTemp94 : fThen44);
			float fElse45 = 2.0f * fRec54 + -1.0f;
			float fTemp97 = ((iSlow74) ? fElse45 : fTemp82);
			float fThen47 = ((iSlow72) ? fTemp97 : fTemp92);
			float fElse47 = 0.5f * (fTemp92 + fTemp97);
			float fThen48 = 2.0f * float(fRec48[0] <= 0.5f) + -1.0f;
			float fTemp98 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst39 / fTemp83));
			int iTemp99 = int(fTemp98);
			float fTemp100 = std::floor(fTemp98);
			float fThen49 = 2.0f * float(fRec48[0] <= 0.7f) + -1.0f;
			float fElse49 = fConst37 * (fTemp87 - fVec16[(IOTA0 - iTemp99) & 4095] * (fTemp100 + (1.0f - fTemp98)) - (fTemp98 - fTemp100) * fVec16[(IOTA0 - (iTemp99 + 1)) & 4095]);
			float fThen50 = ((iSlow74) ? fTemp91 : fThen48);
			float fElse50 = ((iSlow74) ? fElse49 : fThen49);
			float fTemp101 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst40 / fTemp83));
			int iTemp102 = int(fTemp101);
			float fTemp103 = std::floor(fTemp101);
			float fThen51 = 2.0f * float(fRec48[0] <= 0.85f) + -1.0f;
			float fElse51 = fConst37 * (fTemp87 - fVec16[(IOTA0 - iTemp102) & 4095] * (fTemp103 + (1.0f - fTemp101)) - (fTemp101 - fTemp103) * fVec16[(IOTA0 - (iTemp102 + 1)) & 4095]);
			float fThen52 = ((iSlow77) ? fElse50 : fThen50);
			float fElse52 = ((iSlow74) ? fElse51 : fThen51);
			float fThen53 = ((iSlow71) ? fElse47 : fThen47);
			float fElse53 = ((iSlow76) ? fElse52 : fThen52);
			float fTemp104 = fTemp48 * ((fSlow78 * ((fSlow56 * fRec39[0] * ((iSlow70) ? fElse53 : fThen53) + fSlow54 * fRec38[0] * ((iSlow60) ? fElse39 : fThen39) + fSlow58 * fRec40[0] * fTemp47) / std::max<float>(1.0f, 0.4f * (fSlow58 * fRec40[0] + fSlow56 * fRec39[0] + fSlow54 * fRec38[0])) + fSlow52 * ((iSlow24) ? fTemp11 : fTemp10)) + fSlow51 * fRec0[1] - 0.16465649f * fTemp50 * (1.0f - fTemp48 / fTemp49) * (fRec10[1] + fTemp48 * (fRec9[1] + fTemp48 * (fRec8[1] + fTemp48 * fRec7[1] / fTemp49) / fTemp49) / fTemp49)) / (0.16465649f * (mydsp_faustpower4_f(fTemp48) * fTemp50 / mydsp_faustpower4_f(fTemp49)) + 1.0f) - fRec7[1]) / fTemp49;
			fRec7[0] = fRec7[1] + 2.0f * fTemp104;
			float fTemp105 = fTemp48 * (fRec7[1] + fTemp104 - fRec8[1]) / fTemp49;
			fRec8[0] = fRec8[1] + 2.0f * fTemp105;
			float fTemp106 = fTemp48 * (fRec8[1] + fTemp105 - fRec9[1]) / fTemp49;
			fRec9[0] = fRec9[1] + 2.0f * fTemp106;
			float fTemp107 = fTemp48 * (fRec9[1] + fTemp106 - fRec10[1]) / fTemp49;
			fRec10[0] = fRec10[1] + 2.0f * fTemp107;
			float fRec11 = fRec10[1] + fTemp107;
			fRec0[0] = fRec11 * ((iSlow2) ? fRec6[0] : fTemp1);
			float fElse54 = fSlow79 * fRec0[0];
			float fTemp108 = fSlow50 * fRec0[0];
			fVec17[0] = fTemp108;
			fRec55[0] = 0.0f - (0.1f * (fRec55[4] - fVec17[1]) + 0.5f * (fRec55[5] - fVec17[3]));
			float fTemp109 = fSlow81 * fSlow80 * atanhf(std::max<float>(-0.9999999f, std::min<float>(0.9999999f, fRec55[0] + ((iSlow1) ? fElse54 : fRec0[0]))));
			output0[i0] = FAUSTFLOAT(fTemp109);
			output1[i0] = FAUSTFLOAT(fTemp109);
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			fVec1[1] = fVec1[0];
			iRec2[1] = iRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fVec2[1] = fVec2[0];
			fVec3[1] = fVec3[0];
			fRec12[1] = fRec12[0];
			iRec13[1] = iRec13[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fVec4[1] = fVec4[0];
			iRec19[1] = iRec19[0];
			fVec5[1] = fVec5[0];
			for (int j0 = 3; j0 > 0; j0 = j0 - 1) {
				fRec18[j0] = fRec18[j0 - 1];
			}
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec27[1] = fRec27[0];
			IOTA0 = IOTA0 + 1;
			iVec8[1] = iVec8[0];
			iRec29[1] = iRec29[0];
			iRec28[1] = iRec28[0];
			fRec30[1] = fRec30[0];
			fRec26[1] = fRec26[0];
			fRec32[1] = fRec32[0];
			fVec9[1] = fVec9[0];
			fRec31[1] = fRec31[0];
			fRec33[1] = fRec33[0];
			iRec35[1] = iRec35[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			fRec40[1] = fRec40[0];
			fVec11[1] = fVec11[0];
			iRec42[1] = iRec42[0];
			fRec43[1] = fRec43[0];
			fRec41[1] = fRec41[0];
			fRec45[1] = fRec45[0];
			fVec12[1] = fVec12[0];
			fRec44[1] = fRec44[0];
			fRec46[1] = fRec46[0];
			fVec14[1] = fVec14[0];
			iRec49[1] = iRec49[0];
			fRec50[1] = fRec50[0];
			fRec48[1] = fRec48[0];
			fRec52[1] = fRec52[0];
			fVec15[1] = fVec15[0];
			fRec51[1] = fRec51[0];
			fRec53[1] = fRec53[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec0[1] = fRec0[0];
			for (int j1 = 3; j1 > 0; j1 = j1 - 1) {
				fVec17[j1] = fVec17[j1 - 1];
			}
			for (int j2 = 5; j2 > 0; j2 = j2 - 1) {
				fRec55[j2] = fRec55[j2 - 1];
			}
		}
	}

};

#endif
