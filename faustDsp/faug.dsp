import("stdfaust.lib");

oscillators = vgroup("[0]osc_bank", (oscOne + oscTwo + oscThree)/scale)
with{
    freq = hslider("[00]freq[style:knob]",440,50,8000,0.01) : si.smoo;
    driftConst = 0.25;

    scale = 1, oscOnePower*oscOneGain*0.8 + oscTwoPower*oscTwoGain*0.8 + oscThreePower*oscThreeGain*0.8 : max;

    oscOnePower   = checkbox("[01]oscOnePower");
    oscTwoPower   = checkbox("[02]oscTwoPower");
    oscThreePower = checkbox("[03]oscThreePower");

    oscOneGain   = hslider("[04]oscOneGain",10.0,0.0,10.0,0.01)/10 : si.smoo;
    oscTwoGain   = hslider("[05]oscTwoGain",10.0,0.0,10.0,0.01)/10 : si.smoo;
    oscThreeGain = hslider("[06]oscThreeGain",10.0,0.0,10.0,0.01)/10 : si.smoo;

    // oscillators
    oscOne = waveOneTwo(freqOne, rangeOne, waveSelectOne)*oscOneGain*oscOnePower;
    oscTwo = waveOneTwo(freqTwo, rangeTwo, waveSelectTwo)*oscTwoGain*oscTwoPower;
    oscThree = waveThree(freqThree, rangeThree, waveSelectThree)*oscThreeGain*oscThreePower;

    // Oscillator wave selectors. 3rd option in waves one and two is a triangle saw
    //                            3rd option in wave three is a reverse saw
    waveSelectOne = hslider("[07]waveOne[style:knob]",1,0,5,1);
    waveSelectTwo = hslider("[08]waveTwo[style:knob]",1,0,5,1);
    waveSelectThree = hslider("[09]waveThree[style:knob]",1,0,5,1);
    waveOneTwo(f,r,ws) = tri(f,r), saw(f,r), triSaw(f,r), square(f,r),
        rectangle(f,r,0.70), rectangle(f,r,0.85) : ba.selectn(6,ws);
    waveThree(f,r,ws) = tri(f,r), saw(f,r), revSaw(f,r), square(f,r), 
        rectangle(f,r,0.70), rectangle(f,r,0.85) : ba.selectn(6,ws);

    freqOne = freq, 2^(rangeOne-4) : * : _, globalDetune : * : _, driftOne : +;
    freqTwo = freq, 2^(rangeTwo-4) : * : _, detuneTwo : * : _, driftTwo : +;
    freqThree = freq, 2^(rangeThree-4) : * : _, detuneThree : * : _, driftThree : +;

    driftOne = os.osc(0.05)*0.15*driftConst : @(ma.SR/2);
    driftTwo = os.osc(0.1)*0.1*driftConst : @(ma.SR/3);
    driftThree = os.osc(0.25)*0.05*driftConst : @(ma.SR/5);

    rangeOne = hslider("[10]rangeOne[style:knob]",2,0,6,1);
    rangeTwo = hslider("[11]rangeTwo[style:knob]",2,0,6,1);
    rangeThree = hslider("[12]rangeThree[style:knob]",2,0,6,1);

    globalDetune = hslider("[13]globalDetune[style:knob]", 0, -2.5, 2.5, 0.01) : ba.semi2ratio : si.smoo; 
    detuneTwo = hslider("[14]detuneTwo[style:knob]", 0, -7.5, 7.5, 0.01) : ba.semi2ratio, globalDetune : + : si.smoo;
    detuneThree = hslider("[15]detuneThree[style:knob]", 0, -7.5, 7.5, 0.01) : ba.semi2ratio, globalDetune : + : si.smoo;

    tri(f,type)    = os.lf_triangle(f), os.triangle(f) : select2(type);
    saw(f,type)    = os.lf_saw(f), os.sawtooth(f) : select2(type);
    revSaw(f,type) = saw(f,type), -1: *;
    triSaw(f,type) = (saw(f,type) + tri(f,type))/2;
    square(f,type) = os.lf_squarewave(f), os.square(f) : select2(type);
    rectangle(f,type,n) = os.lf_pulsetrain(f,n), os.pulsetrain(f,n) : select2(type);
};


envelope = vgroup("[1]envelope",en.adsr(attack,decay,sustain,release,gate))
with{
  attack = hslider("[0]eAttack[style:knob]",50,1,1000,1) : si.smoo*0.001;
  decay = hslider("[1]eDecay[style:knob]",50,1,1000,1) : si.smoo*0.001;
  sustain = hslider("[2]eSustain[style:knob]",0.8,0.01,1,0.01) : si.smoo;
  release = decay/2;
  gain = hslider("[4]gain[style:knob]",1,0,1,0.01) : si.smoo;
  gate = button("[5]gate");
};

filter = hgroup("[2]filter",ve.moogLadder(cutoffFreq, Q))
with{
    cutoffFreq = (hslider("[0]cutoff[style:knob]",440,10,32000,1)/32000)  : si.smoo <: _, (1-_)*filterEnvelope : +;
    Q = hslider("[1]emphasis[style:knob]",1,0.707,25,0.001) : si.smoo;
    //reverse = hslider("[0]contour_direction[style:radio{'+':0;'-':1}]",0,0,1,1) : si.smoo;
    contourAmount = hslider("[2]contourAmount[style:knob]",1,0,1,0.01) : si.smoo;

    filterEnvelope = en.adsr(attack,decay,sustain,decay,gate)*contourAmount;
    attack = hslider("[3]fAttack[style:knob]",50,1,1000,1) : si.smoo*0.01;
    decay = hslider("[4]fDecay[style:knob]",50,1,1000,1) : si.smoo*0.01;
    sustain = hslider("[5]fSustain[style:knob]",0.8,0.01,1,0.01) : si.smoo;
    gain = hslider("[6]gain[style:knob]",1,0,1,0.01) : si.smoo;
    gate = button("[7]gate");
};

generateSound(fdb) = envelope*(oscillators+fdb) : filter;

process = hgroup("faug", (generateSound ~ fdBackSignal) : drive) <: _,_
with {
    fdback = hslider("feedback[style:knob]",0,0,1,0.01) : si.smoo;
    fdBackSignal = _*fdback;
    drive = _ <: drySig, wetSig : +;
    drySig = (1-fdback)*_;
    wetSig = (histeresis : aa.tanh1)*fdback;

    histeresis = firpart : + ~ backPart;
    firpart(x) = 0.1*x' + 0.5*x''';
    backPart(v) = 0  - 0.1*v''' - .5*v'''';
};