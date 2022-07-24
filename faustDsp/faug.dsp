import("stdfaust.lib");
tri(drift,type)    = os.lf_triangle(freq+drift), os.triangle(freq+drift) : select2(type);
saw(drift,type)    = os.lf_saw(freq+drift), os.sawtooth(freq+drift) : select2(type);
revSaw(drift,type) = saw(drift,type+drift), -1: *;
triSaw(drift,type) = (saw(drift,type) + tri(drift,type))/2;
square(drift,type) = os.lf_squarewave(freq+drift), os.square(freq+drift) : select2(type);
rectangle(drift,type, n) = os.lf_pulsetrain(freq+drift,n), os.pulsetrain(freq+drift,n) : select2(type);
waveSelector = vslider("wave[style:knob]",1,0,5,1);

range = vslider("[0]range[style:knob]",2,0,6,1);
detune = vslider("[2]detune[style:knob]", 0, -7.5, 7.5, 0.01) : si.smoo;
freq = hslider("[1]freq[style:knob]",440,50,5000,0.01) : si.smoo, 2^(range-4) : * : _, ba.semi2ratio(detune) : *;
gate = button("gate[hidden:1]") : si.smoo;
gain = vslider("gain[style:knob]", 0.5,0,1,0.01) : si.smoo;
waveOneTwo(drift) = tri(drift,range), saw(drift,range), triSaw(drift,range), square(drift,range), rectangle(drift,range,0.70), rectangle(drift,range,0.85) : ba.selectn(6,waveSelector);
waveThree(drift) = tri(drift,range), saw(drift,range), revSaw(drift,range), square(drift,range), rectangle(drift,range,0.70), rectangle(drift,range,0.85) : ba.selectn(6,waveSelector);

driftConst = 0.25;
// noise = no.pink_noise
oscOne   = hgroup("[0]osc-1",waveOneTwo(drift))
with{
    driftRate = vslider("drift_rate[style:knob]",0.05,0,1,0.001) : si.smoo;
    driftAmount = vslider("drift_amount[style:knob]",.125,0,1,0.001) : si.smoo;
    drift = os.osc(driftRate)*driftAmount*driftConst : @(ma.SR/2);
};

oscTwo   = hgroup("[1]osc-2",waveOneTwo(drift))
with{
    driftRate = vslider("drift_rate[style:knob]",0.1,0,1,0.001) : si.smoo;
    driftAmount = vslider("drift_amount[style:knob]",.1,0,1,0.001) : si.smoo;
    drift = os.osc(driftRate)*driftAmount*driftConst : @(ma.SR/3);
};
oscThree = hgroup("[2]osc-3",waveThree(drift))
with{
    driftRate = vslider("drift_rate[style:knob]",0.15,0,1,0.001) : si.smoo;
    driftAmount = vslider("drift_amount[style:knob]",.25,0,1,0.01) : si.smoo;
    drift = os.osc(driftRate)*driftAmount*driftConst : @(ma.SR/5);
};
envelope = vgroup("[1]envelope",en.adsr(attack,decay,sustain,release,gate))
with{
  attack = hslider("[0]attack[style:knob]",50,1,1000,1) : si.smoo*0.001;
  decay = hslider("[1]decay[style:knob]",50,1,1000,1) : si.smoo*0.001;
  sustain = hslider("[2]sustain[style:knob]",0.8,0.01,1,0.01) : si.smoo;
  release = decay/2;
  gain = hslider("[4]gain[style:knob]",1,0,1,0.01) : si.smoo;
  gate = button("[5]gate") : si.smoo;
};

// add oscillators together and scale 
oscillators = vgroup("[0]osc_bank",(oscOne + oscTwo)/2 : (_ + oscThree)/2);

filter = hgroup("[2]filter",ve.moogLadder(cutoffFreq, Q))
with{
    filterParams = vgroup("[0]filter", cutoffFreq, Q);
    cutoffFreq = (vslider("[0]cutoff[style:knob]",440,10,32000,1)/32000) : si.smoo <: _, (1-_)*filterEnvelope : +;
    Q = vslider("[1]emphasis[style:knob]",1,0.707,25,0.001) : si.smoo;
    reverse = hslider("[0]contour_direction[style:radio{'+':0;'-':1}]",0,0,1,1) : si.smoo;
    contourAmount = vslider("[2]amount[style:knob]",10,0,10,0.01) : si.smoo/10;


    filterEnvelope = vgroup("[3]filter_contour",en.adsr(attack,decay,sustain,decay,gate)*contourAmount);
    attack = hslider("[1]attack[style:knob]",50,1,1000,1) : si.smoo*0.01;
    decay = hslider("[2]decay[style:knob]",50,1,1000,1) : si.smoo*0.01;
    sustain = hslider("[3]sustain[style:knob]",0.8,0.01,1,0.01) : si.smoo;
    gain = hslider("[4]gain[style:knob]",1,0,1,0.01) : si.smoo;
    gate = button("[5]gate") : si.smoo;
};

generateSound(fdb) = envelope*(oscillators+fdb) : filter;

process = hgroup("faug", generateSound ~ fdBackSignal ) : drive, gain : * <: _,_
with {
    fdback = vslider("[0]feedback[style:knob]",0,0,1,0.01) : si.smoo;
    fdBackSignal = _*fdback;

    histeresis = firpart : + ~ backPart;
    firpart(x) = 0.1*x' + 0.5*x''';
    backPart(v) = 0  - 0.1*v''' - .5*v'''';

    drive = _ <: drySig, wetSig : +;
    drySig = (1-fdback)*_;
    wetSig = (histeresis : aa.tanh1)*fdback;
};