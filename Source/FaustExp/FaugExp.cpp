/* ------------------------------------------------------------
name: "FaugExp", "FaustDSP"
version: "2.44.5"
Code generated with Faust 2.40.12 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#include "FaustIncludes.h"

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

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
	int iRec26[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			iVec6[l24] = 0;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			iRec26[l25] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec6[0] = 1;
			iRec26[0] = (iVec6[1] + iRec26[1]) % 65536;
			table[i1] = std::sin(9.58738019e-05f * float(iRec26[0]));
			iVec6[1] = iVec6[0];
			iRec26[1] = iRec26[0];
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
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	float fConst2;
	float fRec7[2];
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fRec8[2];
	float fConst3;
	FAUSTFLOAT fHslider2;
	float fRec9[2];
	FAUSTFLOAT fHslider3;
	float fRec10[2];
	FAUSTFLOAT fHslider4;
	float fRec11[2];
	int iRec12[2];
	float fRec6[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fHslider6;
	float fRec13[2];
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	float fConst4;
	FAUSTFLOAT fHslider9;
	float fRec15[2];
	FAUSTFLOAT fEntry0;
	FAUSTFLOAT fHslider10;
	int iRec16[2];
	FAUSTFLOAT fEntry1;
	float fVec2[2];
	int iVec3[2];
	int iRec17[2];
	FAUSTFLOAT fHslider11;
	float fRec18[2];
	FAUSTFLOAT fVbargraph0;
	float fRec14[2];
	float fConst5;
	float fConst6;
	float fRec20[2];
	float fVec4[2];
	int IOTA0;
	float fVec5[4096];
	float fConst7;
	float fRec19[2];
	float fRec21[2];
	float fConst8;
	float fConst9;
	FAUSTFLOAT fCheckbox2;
	FAUSTFLOAT fHslider12;
	float fRec23[2];
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fHslider15;
	float fRec25[2];
	float fConst10;
	float fRec27[2];
	float fConst11;
	float fRec28[2];
	float fVec7[131072];
	int iConst12;
	float fVec8[65536];
	int iConst13;
	float fRec24[2];
	float fRec30[2];
	float fVec9[2];
	float fVec10[4096];
	float fRec29[2];
	float fRec31[2];
	FAUSTFLOAT fCheckbox3;
	FAUSTFLOAT fHslider16;
	float fRec33[2];
	FAUSTFLOAT fHslider17;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	float fRec35[2];
	float fConst14;
	float fRec36[2];
	float fVec11[65536];
	int iConst15;
	float fRec34[2];
	float fRec38[2];
	float fVec12[2];
	float fVec13[4096];
	float fRec37[2];
	float fRec39[2];
	FAUSTFLOAT fCheckbox4;
	FAUSTFLOAT fHslider20;
	FAUSTFLOAT fCheckbox5;
	int iRec41[2];
	float fRec42[4];
	FAUSTFLOAT fHslider21;
	FAUSTFLOAT fHslider22;
	float fRec43[2];
	float fRec1[2];
	float fRec2[2];
	float fRec3[2];
	float fRec4[2];
	float fConst16;
	FAUSTFLOAT fHslider23;
	float fRec44[2];
	FAUSTFLOAT fHslider24;
	float fRec45[2];
	FAUSTFLOAT fHslider25;
	float fRec46[2];
	float fRec0[2];
	float fVec14[2];
	float fVec15[4];
	float fRec47[6];
	
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
		m->declare("filters_lib_lowpass0_highpass1", "MIT-style STK-4.3 license");
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
		m->declare("version", "2.44.5");
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
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 44.0999985f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 0.441000015f / fConst0;
		fConst4 = 1.0f / fConst0;
		fConst5 = 4.0f / fConst0;
		fConst6 = 0.25f * fConst0;
		fConst7 = 0.5f * fConst0;
		fConst8 = 0.699999988f * fConst0;
		fConst9 = 0.850000024f * fConst0;
		fConst10 = 0.100000001f / fConst0;
		fConst11 = 0.0500000007f / fConst0;
		iConst12 = int(fConst7);
		iConst13 = int(0.333333343f * fConst0);
		fConst14 = 0.25f / fConst0;
		iConst15 = int(0.200000003f * fConst0);
		fConst16 = 0.0441000015f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fCheckbox0 = FAUSTFLOAT(0.0f);
		fHslider0 = FAUSTFLOAT(440.0f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(50.0f);
		fHslider3 = FAUSTFLOAT(0.80000000000000004f);
		fHslider4 = FAUSTFLOAT(50.0f);
		fHslider5 = FAUSTFLOAT(1.0f);
		fCheckbox1 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(1.0f);
		fHslider7 = FAUSTFLOAT(1.0f);
		fHslider8 = FAUSTFLOAT(2.0f);
		fHslider9 = FAUSTFLOAT(0.0f);
		fEntry0 = FAUSTFLOAT(440.0f);
		fHslider10 = FAUSTFLOAT(0.01f);
		fEntry1 = FAUSTFLOAT(440.0f);
		fHslider11 = FAUSTFLOAT(0.0f);
		fCheckbox2 = FAUSTFLOAT(0.0f);
		fHslider12 = FAUSTFLOAT(1.0f);
		fHslider13 = FAUSTFLOAT(1.0f);
		fHslider14 = FAUSTFLOAT(2.0f);
		fHslider15 = FAUSTFLOAT(0.0f);
		fCheckbox3 = FAUSTFLOAT(0.0f);
		fHslider16 = FAUSTFLOAT(1.0f);
		fHslider17 = FAUSTFLOAT(1.0f);
		fHslider18 = FAUSTFLOAT(2.0f);
		fHslider19 = FAUSTFLOAT(0.0f);
		fCheckbox4 = FAUSTFLOAT(0.0f);
		fHslider20 = FAUSTFLOAT(0.0f);
		fCheckbox5 = FAUSTFLOAT(0.0f);
		fHslider21 = FAUSTFLOAT(0.0f);
		fHslider22 = FAUSTFLOAT(1.0f);
		fHslider23 = FAUSTFLOAT(50.0f);
		fHslider24 = FAUSTFLOAT(0.80000000000000004f);
		fHslider25 = FAUSTFLOAT(50.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec7[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec8[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec9[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec10[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec11[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			iRec12[l7] = 0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec13[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec15[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iRec16[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fVec2[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			iVec3[l13] = 0;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			iRec17[l14] = 0;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec18[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec14[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec20[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fVec4[l18] = 0.0f;
		}
		IOTA0 = 0;
		for (int l19 = 0; l19 < 4096; l19 = l19 + 1) {
			fVec5[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec19[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec21[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec23[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec25[l23] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec27[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec28[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 131072; l28 = l28 + 1) {
			fVec7[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 65536; l29 = l29 + 1) {
			fVec8[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec24[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec30[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fVec9[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 4096; l33 = l33 + 1) {
			fVec10[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec29[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec31[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec33[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec35[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec36[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 65536; l39 = l39 + 1) {
			fVec11[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec34[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec38[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fVec12[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 4096; l43 = l43 + 1) {
			fVec13[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fRec37[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fRec39[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			iRec41[l46] = 0;
		}
		for (int l47 = 0; l47 < 4; l47 = l47 + 1) {
			fRec42[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fRec43[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec1[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fRec2[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = l51 + 1) {
			fRec3[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec4[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			fRec44[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			fRec45[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			fRec46[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec0[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fVec14[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 4; l58 = l58 + 1) {
			fVec15[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 6; l59 = l59 + 1) {
			fRec47[l59] = 0.0f;
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
		ui_interface->declare(&fEntry1, "01", "");
		ui_interface->declare(&fEntry1, "unit", "Hz");
		ui_interface->addNumEntry("freq", &fEntry1, FAUSTFLOAT(440.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(20000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fEntry0, "02", "");
		ui_interface->declare(&fEntry0, "unit", "Hz");
		ui_interface->addNumEntry("prevFreq", &fEntry0, FAUSTFLOAT(440.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(20000.0f), FAUSTFLOAT(0.100000001f));
		ui_interface->declare(&fHslider10, "03", "");
		ui_interface->declare(&fHslider10, "style", "knob");
		ui_interface->addHorizontalSlider("glide", &fHslider10, FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(0.00100000005f), FAUSTFLOAT(9.25f), FAUSTFLOAT(0.00100000005f));
		ui_interface->declare(&fHslider11, "04", "");
		ui_interface->declare(&fHslider11, "style", "knob");
		ui_interface->addHorizontalSlider("pitchBend", &fHslider11, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2.5f), FAUSTFLOAT(2.5f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fCheckbox1, "05", "");
		ui_interface->addCheckButton("oscOnePower", &fCheckbox1);
		ui_interface->declare(&fCheckbox2, "06", "");
		ui_interface->addCheckButton("oscTwoPower", &fCheckbox2);
		ui_interface->declare(&fCheckbox3, "07", "");
		ui_interface->addCheckButton("oscThreePower", &fCheckbox3);
		ui_interface->declare(&fHslider6, "08", "");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->addHorizontalSlider("oscOneGain", &fHslider6, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider12, "09", "");
		ui_interface->declare(&fHslider12, "style", "knob");
		ui_interface->addHorizontalSlider("oscTwoGain", &fHslider12, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider16, "10", "");
		ui_interface->declare(&fHslider16, "style", "knob");
		ui_interface->addHorizontalSlider("oscThreeGain", &fHslider16, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider7, "11", "");
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->addHorizontalSlider("waveOne", &fHslider7, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider13, "12", "");
		ui_interface->declare(&fHslider13, "style", "knob");
		ui_interface->addHorizontalSlider("waveTwo", &fHslider13, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider17, "13", "");
		ui_interface->declare(&fHslider17, "style", "knob");
		ui_interface->addHorizontalSlider("waveThree", &fHslider17, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider8, "14", "");
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("rangeOne", &fHslider8, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider14, "15", "");
		ui_interface->declare(&fHslider14, "style", "knob");
		ui_interface->addHorizontalSlider("rangeTwo", &fHslider14, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider18, "16", "");
		ui_interface->declare(&fHslider18, "style", "knob");
		ui_interface->addHorizontalSlider("rangeThree", &fHslider18, FAUSTFLOAT(2.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider9, "17", "");
		ui_interface->declare(&fHslider9, "style", "knob");
		ui_interface->addHorizontalSlider("globalDetune", &fHslider9, FAUSTFLOAT(0.0f), FAUSTFLOAT(-2.5f), FAUSTFLOAT(2.5f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider15, "18", "");
		ui_interface->declare(&fHslider15, "style", "knob");
		ui_interface->addHorizontalSlider("detuneTwo", &fHslider15, FAUSTFLOAT(0.0f), FAUSTFLOAT(-7.5f), FAUSTFLOAT(7.5f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider19, "19", "");
		ui_interface->declare(&fHslider19, "style", "knob");
		ui_interface->addHorizontalSlider("detuneThree", &fHslider19, FAUSTFLOAT(0.0f), FAUSTFLOAT(-7.5f), FAUSTFLOAT(7.5f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider23, "20", "");
		ui_interface->declare(&fHslider23, "style", "knob");
		ui_interface->addHorizontalSlider("attack", &fHslider23, FAUSTFLOAT(50.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(10000.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider25, "21", "");
		ui_interface->declare(&fHslider25, "style", "knob");
		ui_interface->addHorizontalSlider("decay", &fHslider25, FAUSTFLOAT(50.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(24000.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider24, "22", "");
		ui_interface->declare(&fHslider24, "style", "knob");
		ui_interface->addHorizontalSlider("sustain", &fHslider24, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider0, "24", "");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("cutoff", &fHslider0, FAUSTFLOAT(440.0f), FAUSTFLOAT(10.0f), FAUSTFLOAT(32000.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider22, "25", "");
		ui_interface->declare(&fHslider22, "style", "knob");
		ui_interface->addHorizontalSlider("emphasis", &fHslider22, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.707000017f), FAUSTFLOAT(25.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->declare(&fHslider1, "26", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("contourAmount", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider2, "27", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("fAttack", &fHslider2, FAUSTFLOAT(50.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(7000.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider4, "28", "");
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->addHorizontalSlider("fDecay", &fHslider4, FAUSTFLOAT(50.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(30000.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider3, "29", "");
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->addHorizontalSlider("fSustain", &fHslider3, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.00999999978f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fCheckbox5, "30", "");
		ui_interface->addCheckButton("noiseType", &fCheckbox5);
		ui_interface->declare(&fCheckbox4, "31", "");
		ui_interface->addCheckButton("noiseOn", &fCheckbox4);
		ui_interface->declare(&fHslider20, "32", "");
		ui_interface->declare(&fHslider20, "style", "knob");
		ui_interface->addHorizontalSlider("noiseGain", &fHslider20, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider5, "33", "");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("load", &fHslider5, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(3.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->declare(&fHslider21, "style", "knob");
		ui_interface->addHorizontalSlider("feedbackGain", &fHslider21, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00999999978f));
		ui_interface->addCheckButton("feedbackOn", &fCheckbox0);
		ui_interface->declare(&fVbargraph0, "style", "numerical");
		ui_interface->addVerticalBargraph("finalFreq", &fVbargraph0, FAUSTFLOAT(0.0f), FAUSTFLOAT(20000.0f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fCheckbox0);
		int iSlow1 = int(fSlow0);
		float fSlow2 = 3.12500015e-05f * float(fHslider0);
		float fSlow3 = 1.0f - fSlow2;
		float fSlow4 = fConst1 * float(fHslider1);
		float fSlow5 = float(fButton0);
		float fSlow6 = fConst3 * float(fHslider2);
		float fSlow7 = fConst1 * float(fHslider3);
		float fSlow8 = fConst3 * float(fHslider4);
		int iSlow9 = fSlow5 == 0.0f;
		float fSlow10 = float(fHslider5);
		float fSlow11 = float(fCheckbox1);
		float fSlow12 = fConst1 * float(fHslider6);
		float fSlow13 = float(fHslider7);
		int iSlow14 = fSlow13 >= 3.0f;
		int iSlow15 = fSlow13 >= 2.0f;
		int iSlow16 = fSlow13 >= 1.0f;
		float fSlow17 = float(fHslider8);
		int iSlow18 = int(fSlow17);
		float fSlow19 = std::pow(2.0f, fSlow17 + -4.0f);
		float fSlow20 = fConst4 * fSlow19;
		float fSlow21 = fConst1 * std::pow(2.0f, 0.0833333358f * float(fHslider9));
		float fSlow22 = float(fEntry0);
		float fSlow23 = fConst4 / float(fHslider10);
		float fSlow24 = float(fEntry1);
		float fSlow25 = fConst1 * std::pow(2.0f, 0.0833333358f * float(fHslider11));
		float fSlow26 = fConst5 * fSlow19;
		int iSlow27 = fSlow13 >= 5.0f;
		int iSlow28 = fSlow13 >= 4.0f;
		float fSlow29 = float(fCheckbox2);
		float fSlow30 = fConst1 * float(fHslider12);
		float fSlow31 = float(fHslider13);
		int iSlow32 = fSlow31 >= 3.0f;
		int iSlow33 = fSlow31 >= 2.0f;
		int iSlow34 = fSlow31 >= 1.0f;
		float fSlow35 = float(fHslider14);
		int iSlow36 = int(fSlow35);
		float fSlow37 = std::pow(2.0f, fSlow35 + -4.0f);
		float fSlow38 = std::pow(2.0f, 0.0833333358f * float(fHslider15));
		int iSlow39 = fSlow31 >= 5.0f;
		int iSlow40 = fSlow31 >= 4.0f;
		float fSlow41 = float(fCheckbox3);
		float fSlow42 = fConst1 * float(fHslider16);
		float fSlow43 = float(fHslider17);
		int iSlow44 = fSlow43 >= 3.0f;
		int iSlow45 = fSlow43 >= 2.0f;
		int iSlow46 = fSlow43 >= 1.0f;
		float fSlow47 = float(fHslider18);
		int iSlow48 = int(fSlow47);
		float fSlow49 = std::pow(2.0f, fSlow47 + -4.0f);
		float fSlow50 = std::pow(2.0f, 0.0833333358f * float(fHslider19));
		int iSlow51 = fSlow43 >= 5.0f;
		int iSlow52 = fSlow43 >= 4.0f;
		float fSlow53 = float(fCheckbox4) * float(fHslider20);
		int iSlow54 = int(float(fCheckbox5));
		float fSlow55 = float(fHslider21);
		float fSlow56 = fSlow0 * fSlow55;
		float fSlow57 = fConst1 * float(fHslider22);
		float fSlow58 = fConst16 * float(fHslider23);
		float fSlow59 = fConst1 * float(fHslider24);
		float fSlow60 = fConst16 * float(fHslider25);
		float fSlow61 = 1.0f - fSlow55;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fRec7[0] = fSlow4 + fConst2 * fRec7[1];
			fVec1[0] = fSlow5;
			fRec8[0] = fSlow5 + fRec8[1] * float(fVec1[1] >= fSlow5);
			fRec9[0] = fSlow6 + fConst2 * fRec9[1];
			float fTemp0 = std::max<float>(1.0f, fConst0 * fRec9[0]);
			fRec10[0] = fSlow7 + fConst2 * fRec10[1];
			fRec11[0] = fSlow8 + fConst2 * fRec11[1];
			float fTemp1 = std::max<float>(1.0f, fConst0 * fRec11[0]);
			iRec12[0] = iSlow9 * (iRec12[1] + 1);
			float fTemp2 = float(iRec12[0]);
			fRec6[0] = fConst1 * (fSlow2 + fSlow3 * fRec7[0] * std::max<float>(0.0f, std::min<float>(fRec8[0] / fTemp0, std::max<float>(((1.0f - fRec10[0]) * (fTemp0 - fRec8[0])) / fTemp1 + 1.0f, fRec10[0])) * (1.0f - fTemp2 / fTemp1))) + fConst2 * fRec6[1];
			float fTemp3 = std::tan(1.57079637f * fRec6[0]);
			fRec13[0] = fSlow12 + fConst2 * fRec13[1];
			fRec15[0] = fSlow21 + fConst2 * fRec15[1];
			iRec16[0] = iRec16[1] + 1;
			fVec2[0] = fSlow24;
			int iTemp4 = fSlow24 != fVec2[1];
			iVec3[0] = iTemp4;
			int iTemp5 = (iVec3[1] <= 0) & (iTemp4 > 0);
			iRec17[0] = iRec17[1] * (1 - iTemp5) + (iRec16[0] + -1) * iTemp5;
			float fTemp6 = std::exp(-1.0f * fSlow23 * float(iRec16[0] + -1 - iRec17[0]));
			fRec18[0] = fSlow25 + fConst2 * fRec18[1];
			float fTemp7 = fSlow22 * fTemp6 + fRec18[0] + fSlow24 * (1.0f - fTemp6);
			fVbargraph0 = FAUSTFLOAT(fTemp7);
			float fTemp8 = fTemp7;
			float fTemp9 = fRec15[0] * fTemp8;
			float fTemp10 = fRec14[1] + fSlow20 * fTemp9;
			fRec14[0] = fTemp10 - std::floor(fTemp10);
			float fTemp11 = 2.0f * fRec14[0] + -1.0f;
			float fTemp12 = float(iVec0[1]);
			float fTemp13 = fSlow19 * fTemp9;
			float fTemp14 = std::max<float>(fTemp13, 23.4489498f);
			float fTemp15 = std::max<float>(20.0f, std::fabs(fTemp14));
			float fTemp16 = fRec20[1] + fConst4 * fTemp15;
			fRec20[0] = fTemp16 - std::floor(fTemp16);
			float fTemp17 = mydsp_faustpower2_f(2.0f * fRec20[0] + -1.0f);
			fVec4[0] = fTemp17;
			float fTemp18 = (fTemp12 * (fTemp17 - fVec4[1])) / fTemp15;
			fVec5[IOTA0 & 4095] = fTemp18;
			float fTemp19 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst7 / fTemp14));
			int iTemp20 = int(fTemp19);
			float fTemp21 = std::floor(fTemp19);
			float fTemp22 = fConst6 * (fTemp18 - fVec5[(IOTA0 - iTemp20) & 4095] * (fTemp21 + 1.0f - fTemp19) - (fTemp19 - fTemp21) * fVec5[(IOTA0 - (iTemp20 + 1)) & 4095]);
			fRec19[0] = 0.999000013f * fRec19[1] + fTemp22;
			float fThen0 = 2.0f * (1.0f - std::fabs(fTemp11)) + -1.0f;
			float fElse0 = fSlow26 * fRec15[0] * fRec19[0] * fTemp8;
			float fTemp23 = ((iSlow18) ? fElse0 : fThen0);
			float fTemp24 = std::max<float>(1.1920929e-07f, std::fabs(fTemp13));
			float fTemp25 = fRec21[1] + fConst4 * fTemp24;
			float fTemp26 = fTemp25 + -1.0f;
			int iTemp27 = fTemp26 < 0.0f;
			fRec21[0] = ((iTemp27) ? fTemp25 : fTemp26);
			float fThen2 = fTemp25 + fTemp26 * (1.0f - fConst0 / fTemp24);
			float fRec22 = ((iTemp27) ? fTemp25 : fThen2);
			float fElse3 = 2.0f * fRec22 + -1.0f;
			float fTemp28 = ((iSlow18) ? fElse3 : fTemp11);
			float fThen5 = ((iSlow16) ? fTemp28 : fTemp23);
			float fElse5 = 0.5f * (fTemp23 + fTemp28);
			float fThen6 = 2.0f * float(fRec14[0] <= 0.5f) + -1.0f;
			float fTemp29 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fTemp14));
			int iTemp30 = int(fTemp29);
			float fTemp31 = std::floor(fTemp29);
			float fThen7 = 2.0f * float(fRec14[0] <= 0.699999988f) + -1.0f;
			float fElse7 = fConst6 * (fTemp18 - fVec5[(IOTA0 - iTemp30) & 4095] * (fTemp31 + 1.0f - fTemp29) - (fTemp29 - fTemp31) * fVec5[(IOTA0 - (iTemp30 + 1)) & 4095]);
			float fThen8 = ((iSlow18) ? fTemp22 : fThen6);
			float fElse8 = ((iSlow18) ? fElse7 : fThen7);
			float fTemp32 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst9 / fTemp14));
			int iTemp33 = int(fTemp32);
			float fTemp34 = std::floor(fTemp32);
			float fThen9 = 2.0f * float(fRec14[0] <= 0.850000024f) + -1.0f;
			float fElse9 = fConst6 * (fTemp18 - fVec5[(IOTA0 - iTemp33) & 4095] * (fTemp34 + 1.0f - fTemp32) - (fTemp32 - fTemp34) * fVec5[(IOTA0 - (iTemp33 + 1)) & 4095]);
			float fThen10 = ((iSlow28) ? fElse8 : fThen8);
			float fElse10 = ((iSlow18) ? fElse9 : fThen9);
			float fThen11 = ((iSlow15) ? fElse5 : fThen5);
			float fElse11 = ((iSlow27) ? fElse10 : fThen10);
			fRec23[0] = fSlow30 + fConst2 * fRec23[1];
			fRec25[0] = fConst1 * (fSlow38 + fRec15[0]) + fConst2 * fRec25[1];
			fRec27[0] = fConst10 + fRec27[1] - std::floor(fConst10 + fRec27[1]);
			fRec28[0] = fConst11 + fRec28[1] - std::floor(fConst11 + fRec28[1]);
			fVec7[IOTA0 & 131071] = ftbl0mydspSIG0[int(65536.0f * fRec28[0])];
			float fTemp35 = 0.100000001f * fVec7[(IOTA0 - iConst12) & 131071];
			fVec8[IOTA0 & 65535] = 0.0500000007f * ftbl0mydspSIG0[int(65536.0f * fRec27[0])] + fTemp35;
			float fTemp36 = fSlow37 * fRec25[0] * fTemp8 + fVec8[(IOTA0 - iConst13) & 65535];
			float fTemp37 = fRec24[1] + fConst4 * fTemp36;
			fRec24[0] = fTemp37 - std::floor(fTemp37);
			float fTemp38 = 2.0f * fRec24[0] + -1.0f;
			float fTemp39 = std::max<float>(fTemp36, 23.4489498f);
			float fTemp40 = std::max<float>(20.0f, std::fabs(fTemp39));
			float fTemp41 = fRec30[1] + fConst4 * fTemp40;
			fRec30[0] = fTemp41 - std::floor(fTemp41);
			float fTemp42 = mydsp_faustpower2_f(2.0f * fRec30[0] + -1.0f);
			fVec9[0] = fTemp42;
			float fTemp43 = (fTemp12 * (fTemp42 - fVec9[1])) / fTemp40;
			fVec10[IOTA0 & 4095] = fTemp43;
			float fTemp44 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst7 / fTemp39));
			int iTemp45 = int(fTemp44);
			float fTemp46 = std::floor(fTemp44);
			float fTemp47 = fConst6 * (fTemp43 - fVec10[(IOTA0 - iTemp45) & 4095] * (fTemp46 + 1.0f - fTemp44) - (fTemp44 - fTemp46) * fVec10[(IOTA0 - (iTemp45 + 1)) & 4095]);
			fRec29[0] = 0.999000013f * fRec29[1] + fTemp47;
			float fThen12 = 2.0f * (1.0f - std::fabs(fTemp38)) + -1.0f;
			float fElse12 = fConst5 * fRec29[0] * fTemp36;
			float fTemp48 = ((iSlow36) ? fElse12 : fThen12);
			float fTemp49 = std::max<float>(1.1920929e-07f, std::fabs(fTemp36));
			float fTemp50 = fRec31[1] + fConst4 * fTemp49;
			float fTemp51 = fTemp50 + -1.0f;
			int iTemp52 = fTemp51 < 0.0f;
			fRec31[0] = ((iTemp52) ? fTemp50 : fTemp51);
			float fThen14 = fTemp50 + fTemp51 * (1.0f - fConst0 / fTemp49);
			float fRec32 = ((iTemp52) ? fTemp50 : fThen14);
			float fElse15 = 2.0f * fRec32 + -1.0f;
			float fTemp53 = ((iSlow36) ? fElse15 : fTemp38);
			float fThen17 = ((iSlow34) ? fTemp53 : fTemp48);
			float fElse17 = 0.5f * (fTemp48 + fTemp53);
			float fThen18 = 2.0f * float(fRec24[0] <= 0.5f) + -1.0f;
			float fTemp54 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fTemp39));
			int iTemp55 = int(fTemp54);
			float fTemp56 = std::floor(fTemp54);
			float fThen19 = 2.0f * float(fRec24[0] <= 0.699999988f) + -1.0f;
			float fElse19 = fConst6 * (fTemp43 - fVec10[(IOTA0 - iTemp55) & 4095] * (fTemp56 + 1.0f - fTemp54) - (fTemp54 - fTemp56) * fVec10[(IOTA0 - (iTemp55 + 1)) & 4095]);
			float fThen20 = ((iSlow36) ? fTemp47 : fThen18);
			float fElse20 = ((iSlow36) ? fElse19 : fThen19);
			float fTemp57 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst9 / fTemp39));
			int iTemp58 = int(fTemp57);
			float fTemp59 = std::floor(fTemp57);
			float fThen21 = 2.0f * float(fRec24[0] <= 0.850000024f) + -1.0f;
			float fElse21 = fConst6 * (fTemp43 - fVec10[(IOTA0 - iTemp58) & 4095] * (fTemp59 + 1.0f - fTemp57) - (fTemp57 - fTemp59) * fVec10[(IOTA0 - (iTemp58 + 1)) & 4095]);
			float fThen22 = ((iSlow40) ? fElse20 : fThen20);
			float fElse22 = ((iSlow36) ? fElse21 : fThen21);
			float fThen23 = ((iSlow33) ? fElse17 : fThen17);
			float fElse23 = ((iSlow39) ? fElse22 : fThen22);
			fRec33[0] = fSlow42 + fConst2 * fRec33[1];
			fRec35[0] = fConst1 * (fSlow50 + fRec15[0]) + fConst2 * fRec35[1];
			fRec36[0] = fConst14 + fRec36[1] - std::floor(fConst14 + fRec36[1]);
			fVec11[IOTA0 & 65535] = fTemp35 + 0.0250000004f * ftbl0mydspSIG0[int(65536.0f * fRec36[0])];
			float fTemp60 = fSlow49 * fRec35[0] * fTemp8 + fVec11[(IOTA0 - iConst15) & 65535];
			float fTemp61 = fRec34[1] + fConst4 * fTemp60;
			fRec34[0] = fTemp61 - std::floor(fTemp61);
			float fTemp62 = 2.0f * fRec34[0] + -1.0f;
			float fTemp63 = std::max<float>(fTemp60, 23.4489498f);
			float fTemp64 = std::max<float>(20.0f, std::fabs(fTemp63));
			float fTemp65 = fRec38[1] + fConst4 * fTemp64;
			fRec38[0] = fTemp65 - std::floor(fTemp65);
			float fTemp66 = mydsp_faustpower2_f(2.0f * fRec38[0] + -1.0f);
			fVec12[0] = fTemp66;
			float fTemp67 = (fTemp12 * (fTemp66 - fVec12[1])) / fTemp64;
			fVec13[IOTA0 & 4095] = fTemp67;
			float fTemp68 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst7 / fTemp63));
			int iTemp69 = int(fTemp68);
			float fTemp70 = std::floor(fTemp68);
			float fTemp71 = fConst6 * (fTemp67 - fVec13[(IOTA0 - iTemp69) & 4095] * (fTemp70 + 1.0f - fTemp68) - (fTemp68 - fTemp70) * fVec13[(IOTA0 - (iTemp69 + 1)) & 4095]);
			fRec37[0] = 0.999000013f * fRec37[1] + fTemp71;
			float fThen24 = 2.0f * (1.0f - std::fabs(fTemp62)) + -1.0f;
			float fElse24 = fConst5 * fRec37[0] * fTemp60;
			float fTemp72 = std::max<float>(1.1920929e-07f, std::fabs(fTemp60));
			float fTemp73 = fRec39[1] + fConst4 * fTemp72;
			float fTemp74 = fTemp73 + -1.0f;
			int iTemp75 = fTemp74 < 0.0f;
			fRec39[0] = ((iTemp75) ? fTemp73 : fTemp74);
			float fThen26 = fTemp73 + fTemp74 * (1.0f - fConst0 / fTemp72);
			float fRec40 = ((iTemp75) ? fTemp73 : fThen26);
			float fElse27 = 2.0f * fRec40 + -1.0f;
			float fTemp76 = ((iSlow48) ? fElse27 : fTemp62);
			float fThen28 = ((iSlow48) ? fElse24 : fThen24);
			float fThen29 = ((iSlow46) ? fTemp76 : fThen28);
			float fElse29 = 0.0f - fTemp76;
			float fThen30 = 2.0f * float(fRec34[0] <= 0.5f) + -1.0f;
			float fTemp77 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fTemp63));
			int iTemp78 = int(fTemp77);
			float fTemp79 = std::floor(fTemp77);
			float fThen31 = 2.0f * float(fRec34[0] <= 0.699999988f) + -1.0f;
			float fElse31 = fConst6 * (fTemp67 - fVec13[(IOTA0 - iTemp78) & 4095] * (fTemp79 + 1.0f - fTemp77) - (fTemp77 - fTemp79) * fVec13[(IOTA0 - (iTemp78 + 1)) & 4095]);
			float fThen32 = ((iSlow48) ? fTemp71 : fThen30);
			float fElse32 = ((iSlow48) ? fElse31 : fThen31);
			float fTemp80 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst9 / fTemp63));
			int iTemp81 = int(fTemp80);
			float fTemp82 = std::floor(fTemp80);
			float fThen33 = 2.0f * float(fRec34[0] <= 0.850000024f) + -1.0f;
			float fElse33 = fConst6 * (fTemp67 - fVec13[(IOTA0 - iTemp81) & 4095] * (fTemp82 + 1.0f - fTemp80) - (fTemp80 - fTemp82) * fVec13[(IOTA0 - (iTemp81 + 1)) & 4095]);
			float fThen34 = ((iSlow52) ? fElse32 : fThen32);
			float fElse34 = ((iSlow48) ? fElse33 : fThen33);
			float fThen35 = ((iSlow45) ? fElse29 : fThen29);
			float fElse35 = ((iSlow51) ? fElse34 : fThen34);
			iRec41[0] = 1103515245 * iRec41[1] + 12345;
			float fTemp83 = 4.65661287e-10f * float(iRec41[0]);
			fRec42[0] = (0.522189379f * fRec42[3] + fTemp83 + 2.49495602f * fRec42[1]) - 2.0172658f * fRec42[2];
			float fElse36 = (0.0499220341f * fRec42[0] + 0.0506126992f * fRec42[2]) - (0.0959935337f * fRec42[1] + 0.00440878607f * fRec42[3]);
			fRec43[0] = fSlow57 + fConst2 * fRec43[1];
			float fTemp84 = fRec43[0] + -0.707000017f;
			float fTemp85 = fTemp3 + 1.0f;
			float fTemp86 = (fTemp3 * (((fSlow10 * ((fSlow11 * fRec13[0] * ((iSlow14) ? fElse11 : fThen11) + fSlow29 * fRec23[0] * ((iSlow32) ? fElse23 : fThen23) + fSlow41 * fRec33[0] * ((iSlow44) ? fElse35 : fThen35)) / std::max<float>(1.0f, 0.800000012f * (fSlow41 * fRec33[0] + fSlow11 * fRec13[0] + fSlow29 * fRec23[0])) + fSlow53 * ((iSlow54) ? fElse36 : fTemp83)) + fSlow56 * fRec0[1]) - 0.16465649f * fTemp84 * (1.0f - fTemp3 / fTemp85) * (fRec4[1] + (fTemp3 * (fRec3[1] + (fTemp3 * (fRec2[1] + (fTemp3 * fRec1[1]) / fTemp85)) / fTemp85)) / fTemp85)) / (0.16465649f * (mydsp_faustpower4_f(fTemp3) * fTemp84) / mydsp_faustpower4_f(fTemp85) + 1.0f) - fRec1[1])) / fTemp85;
			fRec1[0] = fRec1[1] + 2.0f * fTemp86;
			float fTemp87 = (fTemp3 * ((fRec1[1] + fTemp86) - fRec2[1])) / fTemp85;
			fRec2[0] = fRec2[1] + 2.0f * fTemp87;
			float fTemp88 = (fTemp3 * ((fRec2[1] + fTemp87) - fRec3[1])) / fTemp85;
			fRec3[0] = fRec3[1] + 2.0f * fTemp88;
			float fTemp89 = (fTemp3 * ((fRec3[1] + fTemp88) - fRec4[1])) / fTemp85;
			fRec4[0] = fRec4[1] + 2.0f * fTemp89;
			float fRec5 = fRec4[1] + fTemp89;
			fRec44[0] = fSlow58 + fConst2 * fRec44[1];
			float fTemp90 = std::max<float>(1.0f, fConst0 * fRec44[0]);
			fRec45[0] = fSlow59 + fConst2 * fRec45[1];
			fRec46[0] = fSlow60 + fConst2 * fRec46[1];
			fRec0[0] = fRec5 * std::max<float>(0.0f, std::min<float>(fRec8[0] / fTemp90, std::max<float>(((1.0f - fRec45[0]) * (fTemp90 - fRec8[0])) / std::max<float>(1.0f, fConst0 * fRec46[0]) + 1.0f, fRec45[0])) * (1.0f - fTemp2 / std::max<float>(1.0f, fConst7 * fRec46[0])));
			float fElse37 = fSlow61 * fRec0[0];
			float fTemp91 = ((iSlow1) ? fElse37 : fRec0[0]);
			fVec14[0] = fTemp91;
			float fTemp92 = fTemp91 - fVec14[1];
			float fThen38 = (std::log(std::min<float>(3.40282347e+38f, float(coshf(float(fTemp91))))) - std::log(std::min<float>(3.40282347e+38f, float(coshf(float(fVec14[1])))))) / fTemp92;
			float fElse38 = float(tanhf(float(0.5f * (fTemp91 + fVec14[1]))));
			float fTemp93 = fSlow56 * fRec0[0];
			fVec15[0] = fTemp93;
			fRec47[0] = 0.0f - (0.100000001f * (fRec47[4] - fVec15[1]) + 0.5f * (fRec47[5] - fVec15[3]));
			float fTemp94 = fRec47[0] - fRec47[1];
			float fThen39 = (std::log(std::min<float>(3.40282347e+38f, float(coshf(float(fRec47[0]))))) - std::log(std::min<float>(3.40282347e+38f, float(coshf(float(fRec47[1])))))) / fTemp94;
			float fElse39 = float(tanhf(float(0.5f * (fRec47[0] + fRec47[1]))));
			float fTemp95 = ((std::fabs(fTemp92) <= fConst4) ? fElse38 : fThen38) + ((std::fabs(fTemp94) <= fConst4) ? fElse39 : fThen39);
			output0[i0] = FAUSTFLOAT(fTemp95);
			output1[i0] = FAUSTFLOAT(fTemp95);
			iVec0[1] = iVec0[0];
			fRec7[1] = fRec7[0];
			fVec1[1] = fVec1[0];
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			iRec12[1] = iRec12[0];
			fRec6[1] = fRec6[0];
			fRec13[1] = fRec13[0];
			fRec15[1] = fRec15[0];
			iRec16[1] = iRec16[0];
			fVec2[1] = fVec2[0];
			iVec3[1] = iVec3[0];
			iRec17[1] = iRec17[0];
			fRec18[1] = fRec18[0];
			fRec14[1] = fRec14[0];
			fRec20[1] = fRec20[0];
			fVec4[1] = fVec4[0];
			IOTA0 = IOTA0 + 1;
			fRec19[1] = fRec19[0];
			fRec21[1] = fRec21[0];
			fRec23[1] = fRec23[0];
			fRec25[1] = fRec25[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec24[1] = fRec24[0];
			fRec30[1] = fRec30[0];
			fVec9[1] = fVec9[0];
			fRec29[1] = fRec29[0];
			fRec31[1] = fRec31[0];
			fRec33[1] = fRec33[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec38[1] = fRec38[0];
			fVec12[1] = fVec12[0];
			fRec37[1] = fRec37[0];
			fRec39[1] = fRec39[0];
			iRec41[1] = iRec41[0];
			for (int j0 = 3; j0 > 0; j0 = j0 - 1) {
				fRec42[j0] = fRec42[j0 - 1];
			}
			fRec43[1] = fRec43[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec44[1] = fRec44[0];
			fRec45[1] = fRec45[0];
			fRec46[1] = fRec46[0];
			fRec0[1] = fRec0[0];
			fVec14[1] = fVec14[0];
			for (int j1 = 3; j1 > 0; j1 = j1 - 1) {
				fVec15[j1] = fVec15[j1 - 1];
			}
			for (int j2 = 5; j2 > 0; j2 = j2 - 1) {
				fRec47[j2] = fRec47[j2 - 1];
			}
		}
	}

};

#endif
