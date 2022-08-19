declare filename "FaugExp.dsp"; declare name "FaugExp"; declare version "2.44.5";
declare compile_options "-single -scal -I libraries/ -I project/ -lang wasm";
declare library_path0 "/libraries/stdfaust.lib";
declare library_path1 "/libraries/aanl.lib";
declare library_path2 "/libraries/basics.lib";
declare library_path3 "/libraries/maths.lib";
declare library_path4 "/libraries/platform.lib";
declare library_path5 "/libraries/signals.lib";
declare library_path6 "/libraries/oscillators.lib";
declare library_path7 "/libraries/filters.lib";
declare library_path8 "/libraries/noises.lib";
declare library_path9 "/libraries/vaeffects.lib";
declare library_path10 "/libraries/envelopes.lib";
declare aanl_lib_ADAA1_author "Dario Sanfilippo";
declare aanl_lib_ADAA1_copyright "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>";
declare aanl_lib_ADAA1_license "LGPL v3.0 license";
declare aanl_lib_name "Faust Antialiased Nonlinearities";
declare aanl_lib_tanh1_author "Dario Sanfilippo";
declare aanl_lib_tanh1_copyright "Copyright (C) 2021 Dario Sanfilippo     <sanfilippo.dario@gmail.com>";
declare aanl_lib_tanh1_license "LGPL v3.0 license";
declare aanl_lib_version "0.3";
declare basics_lib_name "Faust Basic Element Library";
declare basics_lib_version "0.8";
declare envelopes_lib_adsr_author "Yann Orlarey and Andrey Bundin";
declare envelopes_lib_author "GRAME";
declare envelopes_lib_copyright "GRAME";
declare envelopes_lib_license "LGPL with exception";
declare envelopes_lib_name "Faust Envelope Library";
declare envelopes_lib_version "0.2";
declare filename "FaustDSP";
declare filters_lib_fir_author "Julius O. Smith III";
declare filters_lib_fir_copyright "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>";
declare filters_lib_fir_license "MIT-style STK-4.3 license";
declare filters_lib_iir_author "Julius O. Smith III";
declare filters_lib_iir_copyright "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>";
declare filters_lib_iir_license "MIT-style STK-4.3 license";
declare filters_lib_lowpass0_highpass1 "MIT-style STK-4.3 license";
declare filters_lib_name "Faust Filters Library";
declare filters_lib_pole_author "Julius O. Smith III";
declare filters_lib_pole_copyright "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>";
declare filters_lib_pole_license "MIT-style STK-4.3 license";
declare filters_lib_version "0.3";
declare maths_lib_author "GRAME";
declare maths_lib_copyright "GRAME";
declare maths_lib_license "LGPL with exception";
declare maths_lib_name "Faust Math Library";
declare maths_lib_version "2.5";
declare name "FaustDSP";
declare noises_lib_name "Faust Noise Generator Library";
declare noises_lib_version "0.4";
declare oscillators_lib_lf_sawpos_author "Bart Brouns, revised by Stéphane Letz";
declare oscillators_lib_lf_sawpos_licence "STK-4.3";
declare oscillators_lib_lf_triangle_author "Bart Brouns";
declare oscillators_lib_lf_triangle_licence "STK-4.3";
declare oscillators_lib_name "Faust Oscillator Library";
declare oscillators_lib_saw1_author "Bart Brouns";
declare oscillators_lib_saw1_licence "STK-4.3";
declare oscillators_lib_version "0.3";
declare platform_lib_name "Generic Platform Library";
declare platform_lib_version "0.2";
declare signals_lib_name "Faust Signal Routing Library";
declare signals_lib_version "0.3";
declare vaeffects_lib_moogLadder_author "Dario Sanfilippo";
declare vaeffects_lib_moogLadder_license "MIT-style STK-4.3 license";
declare vaeffects_lib_name "Faust Virtual Analog Filter Effect Library";
declare vaeffects_lib_version "0.2";
ID_0 = hslider("feedbackGain[style:knob]", 0.0f, 0.0f, 1.0f, 0.01f);
ID_1 = _, ID_0;
ID_2 = (ID_1 : *);
ID_3 = checkbox("feedbackOn");
ID_4 = ID_2, ID_3;
ID_5 = (ID_4 : *);
ID_7 = 1, ID_0;
ID_8 = (ID_7 : -);
ID_9 = ID_8, _;
ID_10 = (ID_9 : *);
ID_11 = _, ID_10;
ID_12 = _, _;
ID_13 = ID_3, ID_12;
ID_14 = ID_13 : select2;
ID_15 = ID_14 : \(x625).(((x625,(x625 : mem) : - : abs),(1.0f,(192000.0f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : <=),(((3.4028234660000002e+38f,(x625 : ffunction(float coshf(float),<math.h>,"")) : min : log),(3.4028234660000002e+38f,(x625 : mem : ffunction(float coshf(float),<math.h>,"")) : min : log) : -),(x625,(x625 : mem) : -) : /),(0.5f,(x625,(x625 : mem) : +) : * : ffunction(float tanhf(float),<math.h>,"")) : select2);
ID_16 = (ID_11 : ID_15);
ID_17 = ID_0, ID_3;
ID_18 = (ID_17 : *);
ID_19 = ID_18, _;
ID_20 = ID_19 : *;
ID_21 = + ~ \(x627).((0,(0.10000000000000001f,(x627 : mem : mem : mem) : *) : -),(0.5f,(x627 : mem : mem : mem : mem) : *) : -);
ID_22 = \(x626).((0.10000000000000001f,(x626 : mem) : *),(0.5f,(x626 : mem : mem : mem) : *) : +) : ID_21;
ID_23 = ID_22 : \(x625).(((x625,(x625 : mem) : - : abs),(1.0f,(192000.0f,(1.0f,fconstant(int fSamplingFreq, <math.h>) : max) : min) : /) : <=),(((3.4028234660000002e+38f,(x625 : ffunction(float coshf(float),<math.h>,"")) : min : log),(3.4028234660000002e+38f,(x625 : mem : ffunction(float coshf(float),<math.h>,"")) : min : log) : -),(x625,(x625 : mem) : -) : /),(0.5f,(x625,(x625 : mem) : +) : * : ffunction(float tanhf(float),<math.h>,"")) : select2);
ID_24 = (ID_20 : ID_23);
ID_25 = ID_16, ID_24;
ID_26 = ID_25 : +;
ID_27 = _ <: ID_26;
ID_28 = ID_6 : ID_27;
ID_29 = hgroup("faug", ID_28);
ID_30 = ID_29 <: ID_12;
process = ID_30;