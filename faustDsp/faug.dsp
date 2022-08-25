import("stdfaust.lib");

// add AlphaScale tuning mode
// many modulations things to add yet
// tuning variance on a per note basis
// tuning variance on a per note press basis

generateSound(fdb) = output(fdb) : filter*envelope
with{
// Base playing frequency and gate
    gain = hslider("gain",1.0,0.0,1.0,0.01);
    gate = button("[00]gate");
    frequencyIn = nentry("[01]freq[unit:Hz]", 440, 20, 20000, 0.01);
    prevfreq = nentry("[02]prevFreq[unit:Hz]", 440, 20, 20000, 0.01);

    //upglide is about half of downglide
    glide = hslider("[03]glide[style:knob]", 0.01, 0.001, 3.0, 0.001);
    pitchbend = hslider("[04]pitchBend[style:knob]", 0, -2.5, 2.5, 0.01) : ba.semi2ratio : si.smoo;
    start_time = ba.latch(frequencyIn != frequencyIn', ba.time);
    dt = ba.time - start_time;
    epsilon = 0.01;
    expo(tau) = exp((0-dt)/(tau*ma.SR)), epsilon : max;

    blend(rate, f, pf) = f*(1 - expo(rate)) + pf*expo(rate)+pitchbend;

    // mini-moogs generally had longer glide times down vs up 
    freq = blend(ba.if(frequencyIn > prevfreq, glide/1.8, glide), frequencyIn, prevfreq) <: attach(_,vbargraph("finalFreq[style:numerical]",0,20000));

// Oscillators
    scale = 1, oscOnePower*oscOneGain*0.8 + oscTwoPower*oscTwoGain*0.8 + oscThreePower*oscThreeGain*0.8 : max;
    
    oscOnePower   = checkbox("[05]oscOnePower");
    oscTwoPower   = checkbox("[06]oscTwoPower");
    oscThreePower = checkbox("[07]oscThreePower");

    oscOneGain   = hslider("[08]oscOneGain[style:knob]",1.0,0.0,1.0,0.01) : si.smoo;
    oscTwoGain   = hslider("[09]oscTwoGain[style:knob]",1.0,0.0,1.0,0.01) : si.smoo;
    oscThreeGain = hslider("[10]oscThreeGain[style:knob]",1.0,0.0,1.0,0.01) : si.smoo;

    // oscillators
    oscOne = waveOneTwo(freqOne+oscTwo*0.001, rangeOne, waveSelectOne)*oscOneGain*oscOnePower;
    oscTwo = waveOneTwo(freqTwo, rangeTwo, waveSelectTwo)*oscTwoGain*oscTwoPower;
    oscThree = waveThree(freqThree, rangeThree, waveSelectThree)*oscThreeGain*oscThreePower;
    oscillators = (oscOne + oscTwo + oscThree)/scale;

    freqOne = freq, 2^(rangeOne-4) : * : _, globalDetune : *;
    freqTwo = freq, 2^(rangeTwo-4) : * : _, detuneTwo : * : _, driftTwo : +;
    freqThree = freq, 2^(rangeThree-4) : * : _, detuneThree : * : _, driftThree : +;

    // Oscillator wave selectors. 3rd option in waves one and two is a triangle saw
    //                            3rd option in wave three is a reverse saw
    waveSelectOne = hslider("[11]waveOne[style:knob]",1,0,5,1);
    waveSelectTwo = hslider("[12]waveTwo[style:knob]",1,0,5,1);
    waveSelectThree = hslider("[13]waveThree[style:knob]",1,0,5,1);
    waveOneTwo(f,r,ws) = tri(f,r), saw(f,r), triSaw(f,r), square(f,r),
        rectangle(f,r,0.70), rectangle(f,r,0.85) : ba.selectn(6,ws);
    waveThree(f,r,ws) = tri(f,r), saw(f,r), revSaw(f,r), square(f,r), 
        rectangle(f,r,0.70), rectangle(f,r,0.85) : ba.selectn(6,ws);

    driftOne = os.osc(0.05)*0.01 : @(ma.SR/2);
    driftTwo = os.osc(0.1)*0.005 + driftOne : @(ma.SR/3);
    driftThree = os.osc(0.25)*0.0025 + driftTwo: @(ma.SR/5);

    rangeOne = hslider("[14]rangeOne[style:knob]",2,0,5,1);
    rangeTwo = hslider("[15]rangeTwo[style:knob]",2,0,5,1);
    rangeThree = hslider("[16]rangeThree[style:knob]",2,0,5,1);

    globalDetune = hslider("[17]globalDetune[style:knob]", 0, -2.5, 2.5, 0.01) : ba.semi2ratio : si.smoo; 
    detuneTwo = hslider("[18]detuneTwo[style:knob]", 0, -7.5, 7.5, 0.01) : ba.semi2ratio, globalDetune : + : si.smoo;
    detuneThree = hslider("[19]detuneThree[style:knob]", 0, -7.5, 7.5, 0.01) : ba.semi2ratio, globalDetune : + : si.smoo;

    tri(f,type)    = os.lf_triangle(f), os.triangle(f) : select2(type);
    saw(f,type)    = os.lf_saw(f), os.sawtooth(f) : select2(type);
    revSaw(f,type) = saw(f,type), -1: *;
    triSaw(f,type) = (saw(f,type) + tri(f,type))/2;
    square(f,type) = os.lf_squarewave(f), os.square(f) : select2(type);
    rectangle(f,type,n) = os.lf_pulsetrain(f,n), os.pulsetrain(f,n) : select2(type);

// Envelope
    envelope = en.adsr(attack,decay,sustain,release,gate);
    attack = hslider("[20]attack[style:knob]",50,1,10000,1)*0.001 : si.smoo;
    decay = hslider("[21]decay[style:knob]",50,1,24000,1)*0.001 : si.smoo;
    sustain = hslider("[22]sustain[style:knob]",0.8,0.01,1,0.01) : si.smoo;
    release = decay/2;

// Filter

    filter = ve.moogLadder(cutoffFreq, Q);
    cutoffFreq = (hslider("[24]cutoff[style:knob]",440,10,32000,1)/32000) <: _, (1-_)*filterEnvelope : + : si.smoo;
    Q = hslider("[25]emphasis[style:knob]",1,0.707,25,0.001) : si.smoo;
    //reverse = hslider("[0]contour_direction[style:radio{'+':0;'-':1}]",0,0,1,1) : si.smoo;
    contourAmount = hslider("[26]contourAmount[style:knob]",1,0,1,0.01) : si.smoo;

    filterEnvelope = en.adsr(fAttack,fDecay,fSustain,fDecay,gate)*contourAmount;
    fAttack = hslider("[27]fAttack[style:knob]",50,1,7000,1)*0.01 : si.smoo;
    fDecay = hslider("[28]fDecay[style:knob]",50,1,30000,1)*0.01 : si.smoo;
    fSustain = hslider("[29]fSustain[style:knob]",0.8,0.01,1,0.01) : si.smoo;

// Noise
    noiseSelect = checkbox("[30]noiseType");
    noiseOn = checkbox("[31]noiseOn");
    noiseGain = hslider("[32]noiseGain[style:knob]", 0.0, 0.0, 1.0, 0.01);
    noise = no.noise, no.pink_noise : select2(noiseSelect)*noiseGain*noiseOn;

    output(fdb) = ((oscillators+noise)*load)+fdb;
    load = hslider("[33]load[style:knob]",1.0,1.0,3.0,0.01);
};

process = hgroup("faug", (generateSound ~ fdBackSignal*fdbackOn) : drive) <: _,_
with {
    fdback = hslider("feedbackGain[style:knob]",0,0,1,0.01);
    fdbackOn = checkbox("feedbackOn");
    fdBackSignal = _*fdback;
    drive = _ <: drySig, wetSig : +;
    drySig = _, (1-fdback)*_ : select2(fdbackOn) : aa.tanh1;
    wetSig = fdback*fdbackOn*_ : histeresis : aa.tanh1;

    histeresis = firpart : + ~ backPart;
    firpart(x) = 0.1*x' + 0.5*x''';
    backPart(v) = 0  - 0.1*v''' - .5*v'''';
};