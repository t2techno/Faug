/* ------------------------------------------------------------
name: "FaugExp", "FaustDSP"
version: "2.44.5"
Code generated with Faust 2.40.12 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

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
#include "FaustIncludes.h"

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
			table[i1] = std::sin(9.58738019e-05f * float(iRec26[0]));
			iVec4[1] = iVec4[0];
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
	int iRec17[2];
	FAUSTFLOAT fHslider11;
	float fRec18[2];
	FAUSTFLOAT fEntry1;
	float fRec14[2];
	float fConst5;
	float fConst6;
	float fRec20[2];
	float fVec2[2];
	int IOTA0;
	float fVec3[4096];
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
	float fVec5[131072];
	int iConst12;
	float fVec6[65536];
	int iConst13;
	float fRec24[2];
	float fRec30[2];
	float fVec7[2];
	float fVec8[4096];
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
	float fVec9[65536];
	int iConst15;
	float fRec34[2];
	float fRec38[2];
	float fVec10[2];
	float fVec11[4096];
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
	float fVec12[2];
	float fVec13[4];
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
		fHslider11 = FAUSTFLOAT(0.0f);
		fEntry1 = FAUSTFLOAT(440.0f);
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
			iRec17[l12] = 0;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec18[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec14[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec20[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fVec2[l16] = 0.0f;
		}
		IOTA0 = 0;
		for (int l17 = 0; l17 < 4096; l17 = l17 + 1) {
			fVec3[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec19[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec21[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec23[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec25[l21] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec27[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec28[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 131072; l26 = l26 + 1) {
			fVec5[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 65536; l27 = l27 + 1) {
			fVec6[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec24[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fRec30[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fVec7[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 4096; l31 = l31 + 1) {
			fVec8[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec29[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec31[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec33[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec35[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec36[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 65536; l37 = l37 + 1) {
			fVec9[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec34[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			fRec38[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fVec10[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 4096; l41 = l41 + 1) {
			fVec11[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec37[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec39[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			iRec41[l44] = 0;
		}
		for (int l45 = 0; l45 < 4; l45 = l45 + 1) {
			fRec42[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			fRec43[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fRec1[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fRec2[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec3[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fRec4[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 2; l51 = l51 + 1) {
			fRec44[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec45[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			fRec46[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			fRec0[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			fVec12[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 4; l56 = l56 + 1) {
			fVec13[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 6; l57 = l57 + 1) {
			fRec47[l57] = 0.0f;
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
		ui_interface->addNumEntry("freq", &fEntry1, FAUSTFLOAT(440.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(20000.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fEntry0, "02", "");
		ui_interface->declare(&fEntry0, "unit", "Hz");
		ui_interface->addNumEntry("prevFreq", &fEntry0, FAUSTFLOAT(440.0f), FAUSTFLOAT(20.0f), FAUSTFLOAT(20000.0f), FAUSTFLOAT(1.0f));
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
		int iSlow24 = fSlow5 > 0.0f;
		float fSlow25 = fConst1 * std::pow(2.0f, 0.0833333358f * float(fHslider11));
		float fSlow26 = float(fEntry1);
		float fSlow27 = fConst5 * fSlow19;
		int iSlow28 = fSlow13 >= 5.0f;
		int iSlow29 = fSlow13 >= 4.0f;
		float fSlow30 = float(fCheckbox2);
		float fSlow31 = fConst1 * float(fHslider12);
		float fSlow32 = float(fHslider13);
		int iSlow33 = fSlow32 >= 3.0f;
		int iSlow34 = fSlow32 >= 2.0f;
		int iSlow35 = fSlow32 >= 1.0f;
		float fSlow36 = float(fHslider14);
		int iSlow37 = int(fSlow36);
		float fSlow38 = std::pow(2.0f, fSlow36 + -4.0f);
		float fSlow39 = std::pow(2.0f, 0.0833333358f * float(fHslider15));
		int iSlow40 = fSlow32 >= 5.0f;
		int iSlow41 = fSlow32 >= 4.0f;
		float fSlow42 = float(fCheckbox3);
		float fSlow43 = fConst1 * float(fHslider16);
		float fSlow44 = float(fHslider17);
		int iSlow45 = fSlow44 >= 3.0f;
		int iSlow46 = fSlow44 >= 2.0f;
		int iSlow47 = fSlow44 >= 1.0f;
		float fSlow48 = float(fHslider18);
		int iSlow49 = int(fSlow48);
		float fSlow50 = std::pow(2.0f, fSlow48 + -4.0f);
		float fSlow51 = std::pow(2.0f, 0.0833333358f * float(fHslider19));
		int iSlow52 = fSlow44 >= 5.0f;
		int iSlow53 = fSlow44 >= 4.0f;
		float fSlow54 = float(fCheckbox4) * float(fHslider20);
		int iSlow55 = int(float(fCheckbox5));
		float fSlow56 = float(fHslider21);
		float fSlow57 = fSlow0 * fSlow56;
		float fSlow58 = fConst1 * float(fHslider22);
		float fSlow59 = fConst16 * float(fHslider23);
		float fSlow60 = fConst1 * float(fHslider24);
		float fSlow61 = fConst16 * float(fHslider25);
		float fSlow62 = 1.0f - fSlow56;
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
			int iTemp4 = (fVec1[1] <= 0.0f) & iSlow24;
			iRec17[0] = iRec17[1] * (1 - iTemp4) + (iRec16[0] + -1) * iTemp4;
			float fTemp5 = std::exp(-1.0f * fSlow23 * float(iRec16[0] + -1 - iRec17[0]));
			fRec18[0] = fSlow25 + fConst2 * fRec18[1];
			float fTemp6 = fSlow22 * fTemp5 + fRec18[0] + fSlow26 * (1.0f - fTemp5);
			float fTemp7 = fRec15[0] * fTemp6;
			float fTemp8 = fRec14[1] + fSlow20 * fTemp7;
			fRec14[0] = fTemp8 - std::floor(fTemp8);
			float fTemp9 = 2.0f * fRec14[0] + -1.0f;
			float fTemp10 = float(iVec0[1]);
			float fTemp11 = fSlow19 * fTemp7;
			float fTemp12 = std::max<float>(fTemp11, 23.4489498f);
			float fTemp13 = std::max<float>(20.0f, std::fabs(fTemp12));
			float fTemp14 = fRec20[1] + fConst4 * fTemp13;
			fRec20[0] = fTemp14 - std::floor(fTemp14);
			float fTemp15 = mydsp_faustpower2_f(2.0f * fRec20[0] + -1.0f);
			fVec2[0] = fTemp15;
			float fTemp16 = (fTemp10 * (fTemp15 - fVec2[1])) / fTemp13;
			fVec3[IOTA0 & 4095] = fTemp16;
			float fTemp17 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst7 / fTemp12));
			int iTemp18 = int(fTemp17);
			float fTemp19 = std::floor(fTemp17);
			float fTemp20 = fConst6 * (fTemp16 - fVec3[(IOTA0 - iTemp18) & 4095] * (fTemp19 + 1.0f - fTemp17) - (fTemp17 - fTemp19) * fVec3[(IOTA0 - (iTemp18 + 1)) & 4095]);
			fRec19[0] = 0.999000013f * fRec19[1] + fTemp20;
			float fThen0 = 2.0f * (1.0f - std::fabs(fTemp9)) + -1.0f;
			float fElse0 = fSlow27 * fRec15[0] * fRec19[0] * fTemp6;
			float fTemp21 = ((iSlow18) ? fElse0 : fThen0);
			float fTemp22 = std::max<float>(1.1920929e-07f, std::fabs(fTemp11));
			float fTemp23 = fRec21[1] + fConst4 * fTemp22;
			float fTemp24 = fTemp23 + -1.0f;
			int iTemp25 = fTemp24 < 0.0f;
			fRec21[0] = ((iTemp25) ? fTemp23 : fTemp24);
			float fThen2 = fTemp23 + fTemp24 * (1.0f - fConst0 / fTemp22);
			float fRec22 = ((iTemp25) ? fTemp23 : fThen2);
			float fElse3 = 2.0f * fRec22 + -1.0f;
			float fTemp26 = ((iSlow18) ? fElse3 : fTemp9);
			float fThen5 = ((iSlow16) ? fTemp26 : fTemp21);
			float fElse5 = 0.5f * (fTemp21 + fTemp26);
			float fThen6 = 2.0f * float(fRec14[0] <= 0.5f) + -1.0f;
			float fTemp27 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fTemp12));
			int iTemp28 = int(fTemp27);
			float fTemp29 = std::floor(fTemp27);
			float fThen7 = 2.0f * float(fRec14[0] <= 0.699999988f) + -1.0f;
			float fElse7 = fConst6 * (fTemp16 - fVec3[(IOTA0 - iTemp28) & 4095] * (fTemp29 + 1.0f - fTemp27) - (fTemp27 - fTemp29) * fVec3[(IOTA0 - (iTemp28 + 1)) & 4095]);
			float fThen8 = ((iSlow18) ? fTemp20 : fThen6);
			float fElse8 = ((iSlow18) ? fElse7 : fThen7);
			float fTemp30 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst9 / fTemp12));
			int iTemp31 = int(fTemp30);
			float fTemp32 = std::floor(fTemp30);
			float fThen9 = 2.0f * float(fRec14[0] <= 0.850000024f) + -1.0f;
			float fElse9 = fConst6 * (fTemp16 - fVec3[(IOTA0 - iTemp31) & 4095] * (fTemp32 + 1.0f - fTemp30) - (fTemp30 - fTemp32) * fVec3[(IOTA0 - (iTemp31 + 1)) & 4095]);
			float fThen10 = ((iSlow29) ? fElse8 : fThen8);
			float fElse10 = ((iSlow18) ? fElse9 : fThen9);
			float fThen11 = ((iSlow15) ? fElse5 : fThen5);
			float fElse11 = ((iSlow28) ? fElse10 : fThen10);
			fRec23[0] = fSlow31 + fConst2 * fRec23[1];
			fRec25[0] = fConst1 * (fSlow39 + fRec15[0]) + fConst2 * fRec25[1];
			fRec27[0] = fConst10 + fRec27[1] - std::floor(fConst10 + fRec27[1]);
			fRec28[0] = fConst11 + fRec28[1] - std::floor(fConst11 + fRec28[1]);
			fVec5[IOTA0 & 131071] = ftbl0mydspSIG0[int(65536.0f * fRec28[0])];
			float fTemp33 = 0.100000001f * fVec5[(IOTA0 - iConst12) & 131071];
			fVec6[IOTA0 & 65535] = 0.0500000007f * ftbl0mydspSIG0[int(65536.0f * fRec27[0])] + fTemp33;
			float fTemp34 = fSlow38 * fRec25[0] * fTemp6 + fVec6[(IOTA0 - iConst13) & 65535];
			float fTemp35 = fRec24[1] + fConst4 * fTemp34;
			fRec24[0] = fTemp35 - std::floor(fTemp35);
			float fTemp36 = 2.0f * fRec24[0] + -1.0f;
			float fTemp37 = std::max<float>(fTemp34, 23.4489498f);
			float fTemp38 = std::max<float>(20.0f, std::fabs(fTemp37));
			float fTemp39 = fRec30[1] + fConst4 * fTemp38;
			fRec30[0] = fTemp39 - std::floor(fTemp39);
			float fTemp40 = mydsp_faustpower2_f(2.0f * fRec30[0] + -1.0f);
			fVec7[0] = fTemp40;
			float fTemp41 = (fTemp10 * (fTemp40 - fVec7[1])) / fTemp38;
			fVec8[IOTA0 & 4095] = fTemp41;
			float fTemp42 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst7 / fTemp37));
			int iTemp43 = int(fTemp42);
			float fTemp44 = std::floor(fTemp42);
			float fTemp45 = fConst6 * (fTemp41 - fVec8[(IOTA0 - iTemp43) & 4095] * (fTemp44 + 1.0f - fTemp42) - (fTemp42 - fTemp44) * fVec8[(IOTA0 - (iTemp43 + 1)) & 4095]);
			fRec29[0] = 0.999000013f * fRec29[1] + fTemp45;
			float fThen12 = 2.0f * (1.0f - std::fabs(fTemp36)) + -1.0f;
			float fElse12 = fConst5 * fRec29[0] * fTemp34;
			float fTemp46 = ((iSlow37) ? fElse12 : fThen12);
			float fTemp47 = std::max<float>(1.1920929e-07f, std::fabs(fTemp34));
			float fTemp48 = fRec31[1] + fConst4 * fTemp47;
			float fTemp49 = fTemp48 + -1.0f;
			int iTemp50 = fTemp49 < 0.0f;
			fRec31[0] = ((iTemp50) ? fTemp48 : fTemp49);
			float fThen14 = fTemp48 + fTemp49 * (1.0f - fConst0 / fTemp47);
			float fRec32 = ((iTemp50) ? fTemp48 : fThen14);
			float fElse15 = 2.0f * fRec32 + -1.0f;
			float fTemp51 = ((iSlow37) ? fElse15 : fTemp36);
			float fThen17 = ((iSlow35) ? fTemp51 : fTemp46);
			float fElse17 = 0.5f * (fTemp46 + fTemp51);
			float fThen18 = 2.0f * float(fRec24[0] <= 0.5f) + -1.0f;
			float fTemp52 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fTemp37));
			int iTemp53 = int(fTemp52);
			float fTemp54 = std::floor(fTemp52);
			float fThen19 = 2.0f * float(fRec24[0] <= 0.699999988f) + -1.0f;
			float fElse19 = fConst6 * (fTemp41 - fVec8[(IOTA0 - iTemp53) & 4095] * (fTemp54 + 1.0f - fTemp52) - (fTemp52 - fTemp54) * fVec8[(IOTA0 - (iTemp53 + 1)) & 4095]);
			float fThen20 = ((iSlow37) ? fTemp45 : fThen18);
			float fElse20 = ((iSlow37) ? fElse19 : fThen19);
			float fTemp55 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst9 / fTemp37));
			int iTemp56 = int(fTemp55);
			float fTemp57 = std::floor(fTemp55);
			float fThen21 = 2.0f * float(fRec24[0] <= 0.850000024f) + -1.0f;
			float fElse21 = fConst6 * (fTemp41 - fVec8[(IOTA0 - iTemp56) & 4095] * (fTemp57 + 1.0f - fTemp55) - (fTemp55 - fTemp57) * fVec8[(IOTA0 - (iTemp56 + 1)) & 4095]);
			float fThen22 = ((iSlow41) ? fElse20 : fThen20);
			float fElse22 = ((iSlow37) ? fElse21 : fThen21);
			float fThen23 = ((iSlow34) ? fElse17 : fThen17);
			float fElse23 = ((iSlow40) ? fElse22 : fThen22);
			fRec33[0] = fSlow43 + fConst2 * fRec33[1];
			fRec35[0] = fConst1 * (fSlow51 + fRec15[0]) + fConst2 * fRec35[1];
			fRec36[0] = fConst14 + fRec36[1] - std::floor(fConst14 + fRec36[1]);
			fVec9[IOTA0 & 65535] = fTemp33 + 0.0250000004f * ftbl0mydspSIG0[int(65536.0f * fRec36[0])];
			float fTemp58 = fSlow50 * fRec35[0] * fTemp6 + fVec9[(IOTA0 - iConst15) & 65535];
			float fTemp59 = fRec34[1] + fConst4 * fTemp58;
			fRec34[0] = fTemp59 - std::floor(fTemp59);
			float fTemp60 = 2.0f * fRec34[0] + -1.0f;
			float fTemp61 = std::max<float>(fTemp58, 23.4489498f);
			float fTemp62 = std::max<float>(20.0f, std::fabs(fTemp61));
			float fTemp63 = fRec38[1] + fConst4 * fTemp62;
			fRec38[0] = fTemp63 - std::floor(fTemp63);
			float fTemp64 = mydsp_faustpower2_f(2.0f * fRec38[0] + -1.0f);
			fVec10[0] = fTemp64;
			float fTemp65 = (fTemp10 * (fTemp64 - fVec10[1])) / fTemp62;
			fVec11[IOTA0 & 4095] = fTemp65;
			float fTemp66 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst7 / fTemp61));
			int iTemp67 = int(fTemp66);
			float fTemp68 = std::floor(fTemp66);
			float fTemp69 = fConst6 * (fTemp65 - fVec11[(IOTA0 - iTemp67) & 4095] * (fTemp68 + 1.0f - fTemp66) - (fTemp66 - fTemp68) * fVec11[(IOTA0 - (iTemp67 + 1)) & 4095]);
			fRec37[0] = 0.999000013f * fRec37[1] + fTemp69;
			float fThen24 = 2.0f * (1.0f - std::fabs(fTemp60)) + -1.0f;
			float fElse24 = fConst5 * fRec37[0] * fTemp58;
			float fTemp70 = std::max<float>(1.1920929e-07f, std::fabs(fTemp58));
			float fTemp71 = fRec39[1] + fConst4 * fTemp70;
			float fTemp72 = fTemp71 + -1.0f;
			int iTemp73 = fTemp72 < 0.0f;
			fRec39[0] = ((iTemp73) ? fTemp71 : fTemp72);
			float fThen26 = fTemp71 + fTemp72 * (1.0f - fConst0 / fTemp70);
			float fRec40 = ((iTemp73) ? fTemp71 : fThen26);
			float fElse27 = 2.0f * fRec40 + -1.0f;
			float fTemp74 = ((iSlow49) ? fElse27 : fTemp60);
			float fThen28 = ((iSlow49) ? fElse24 : fThen24);
			float fThen29 = ((iSlow47) ? fTemp74 : fThen28);
			float fElse29 = 0.0f - fTemp74;
			float fThen30 = 2.0f * float(fRec34[0] <= 0.5f) + -1.0f;
			float fTemp75 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst8 / fTemp61));
			int iTemp76 = int(fTemp75);
			float fTemp77 = std::floor(fTemp75);
			float fThen31 = 2.0f * float(fRec34[0] <= 0.699999988f) + -1.0f;
			float fElse31 = fConst6 * (fTemp65 - fVec11[(IOTA0 - iTemp76) & 4095] * (fTemp77 + 1.0f - fTemp75) - (fTemp75 - fTemp77) * fVec11[(IOTA0 - (iTemp76 + 1)) & 4095]);
			float fThen32 = ((iSlow49) ? fTemp69 : fThen30);
			float fElse32 = ((iSlow49) ? fElse31 : fThen31);
			float fTemp78 = std::max<float>(0.0f, std::min<float>(2047.0f, fConst9 / fTemp61));
			int iTemp79 = int(fTemp78);
			float fTemp80 = std::floor(fTemp78);
			float fThen33 = 2.0f * float(fRec34[0] <= 0.850000024f) + -1.0f;
			float fElse33 = fConst6 * (fTemp65 - fVec11[(IOTA0 - iTemp79) & 4095] * (fTemp80 + 1.0f - fTemp78) - (fTemp78 - fTemp80) * fVec11[(IOTA0 - (iTemp79 + 1)) & 4095]);
			float fThen34 = ((iSlow53) ? fElse32 : fThen32);
			float fElse34 = ((iSlow49) ? fElse33 : fThen33);
			float fThen35 = ((iSlow46) ? fElse29 : fThen29);
			float fElse35 = ((iSlow52) ? fElse34 : fThen34);
			iRec41[0] = 1103515245 * iRec41[1] + 12345;
			float fTemp81 = 4.65661287e-10f * float(iRec41[0]);
			fRec42[0] = (0.522189379f * fRec42[3] + fTemp81 + 2.49495602f * fRec42[1]) - 2.0172658f * fRec42[2];
			float fElse36 = (0.0499220341f * fRec42[0] + 0.0506126992f * fRec42[2]) - (0.0959935337f * fRec42[1] + 0.00440878607f * fRec42[3]);
			fRec43[0] = fSlow58 + fConst2 * fRec43[1];
			float fTemp82 = fRec43[0] + -0.707000017f;
			float fTemp83 = fTemp3 + 1.0f;
			float fTemp84 = (fTemp3 * (((fSlow10 * ((fSlow11 * fRec13[0] * ((iSlow14) ? fElse11 : fThen11) + fSlow30 * fRec23[0] * ((iSlow33) ? fElse23 : fThen23) + fSlow42 * fRec33[0] * ((iSlow45) ? fElse35 : fThen35)) / std::max<float>(1.0f, 0.800000012f * (fSlow42 * fRec33[0] + fSlow11 * fRec13[0] + fSlow30 * fRec23[0])) + fSlow54 * ((iSlow55) ? fElse36 : fTemp81)) + fSlow57 * fRec0[1]) - 0.16465649f * fTemp82 * (1.0f - fTemp3 / fTemp83) * (fRec4[1] + (fTemp3 * (fRec3[1] + (fTemp3 * (fRec2[1] + (fTemp3 * fRec1[1]) / fTemp83)) / fTemp83)) / fTemp83)) / (0.16465649f * (mydsp_faustpower4_f(fTemp3) * fTemp82) / mydsp_faustpower4_f(fTemp83) + 1.0f) - fRec1[1])) / fTemp83;
			fRec1[0] = fRec1[1] + 2.0f * fTemp84;
			float fTemp85 = (fTemp3 * ((fRec1[1] + fTemp84) - fRec2[1])) / fTemp83;
			fRec2[0] = fRec2[1] + 2.0f * fTemp85;
			float fTemp86 = (fTemp3 * ((fRec2[1] + fTemp85) - fRec3[1])) / fTemp83;
			fRec3[0] = fRec3[1] + 2.0f * fTemp86;
			float fTemp87 = (fTemp3 * ((fRec3[1] + fTemp86) - fRec4[1])) / fTemp83;
			fRec4[0] = fRec4[1] + 2.0f * fTemp87;
			float fRec5 = fRec4[1] + fTemp87;
			fRec44[0] = fSlow59 + fConst2 * fRec44[1];
			float fTemp88 = std::max<float>(1.0f, fConst0 * fRec44[0]);
			fRec45[0] = fSlow60 + fConst2 * fRec45[1];
			fRec46[0] = fSlow61 + fConst2 * fRec46[1];
			fRec0[0] = fRec5 * std::max<float>(0.0f, std::min<float>(fRec8[0] / fTemp88, std::max<float>(((1.0f - fRec45[0]) * (fTemp88 - fRec8[0])) / std::max<float>(1.0f, fConst0 * fRec46[0]) + 1.0f, fRec45[0])) * (1.0f - fTemp2 / std::max<float>(1.0f, fConst7 * fRec46[0])));
			float fElse37 = fSlow62 * fRec0[0];
			float fTemp89 = ((iSlow1) ? fElse37 : fRec0[0]);
			fVec12[0] = fTemp89;
			float fTemp90 = fTemp89 - fVec12[1];
			float fThen38 = (std::log(std::min<float>(3.40282347e+38f, float(coshf(float(fTemp89))))) - std::log(std::min<float>(3.40282347e+38f, float(coshf(float(fVec12[1])))))) / fTemp90;
			float fElse38 = float(tanhf(float(0.5f * (fTemp89 + fVec12[1]))));
			float fTemp91 = fSlow57 * fRec0[0];
			fVec13[0] = fTemp91;
			fRec47[0] = 0.0f - (0.100000001f * (fRec47[4] - fVec13[1]) + 0.5f * (fRec47[5] - fVec13[3]));
			float fTemp92 = fRec47[0] - fRec47[1];
			float fThen39 = (std::log(std::min<float>(3.40282347e+38f, float(coshf(float(fRec47[0]))))) - std::log(std::min<float>(3.40282347e+38f, float(coshf(float(fRec47[1])))))) / fTemp92;
			float fElse39 = float(tanhf(float(0.5f * (fRec47[0] + fRec47[1]))));
			float fTemp93 = ((std::fabs(fTemp90) <= fConst4) ? fElse38 : fThen38) + ((std::fabs(fTemp92) <= fConst4) ? fElse39 : fThen39);
			output0[i0] = FAUSTFLOAT(fTemp93);
			output1[i0] = FAUSTFLOAT(fTemp93);
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
			iRec17[1] = iRec17[0];
			fRec18[1] = fRec18[0];
			fRec14[1] = fRec14[0];
			fRec20[1] = fRec20[0];
			fVec2[1] = fVec2[0];
			IOTA0 = IOTA0 + 1;
			fRec19[1] = fRec19[0];
			fRec21[1] = fRec21[0];
			fRec23[1] = fRec23[0];
			fRec25[1] = fRec25[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec24[1] = fRec24[0];
			fRec30[1] = fRec30[0];
			fVec7[1] = fVec7[0];
			fRec29[1] = fRec29[0];
			fRec31[1] = fRec31[0];
			fRec33[1] = fRec33[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec38[1] = fRec38[0];
			fVec10[1] = fVec10[0];
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
			fVec12[1] = fVec12[0];
			for (int j1 = 3; j1 > 0; j1 = j1 - 1) {
				fVec13[j1] = fVec13[j1 - 1];
			}
			for (int j2 = 5; j2 > 0; j2 = j2 - 1) {
				fRec47[j2] = fRec47[j2 - 1];
			}
		}
	}

};

#endif
