import("stdfaust.lib");

display(name, mini, maxi) = _ <: attach(_,vbargraph("[9999]%name[style:numerical]",mini,maxi));
limit_range(mini,maxi) = _, mini : max : _, maxi : min;
gain = hslider("gain[style:knob]",1.0,0.0,1.0,0.01);

// todo variable keytracking per oscillator

generateSound(fdb) = output(fdb) : filter : _*envelope
with{
    gate = button("[00]gate");

    frequencyIn = nentry("[01]freq[unit:Hz]",     440, 20, 20000, 0.01)*pitchbend;
    prevfreq    = nentry("[02]prevFreq[unit:Hz]", 440, 20, 20000, 0.01);

    pitchbend  = hslider("[03]pitchBend[style:knob]", 0, -2.5, 2.5, 0.01) : ba.semi2ratio : si.smoo;
    glide      = hslider("[04]glide[style:knob]", 0.01, 0.001, 3.0, 0.001);
    start_time = ba.latch(frequencyIn != frequencyIn', ba.time);
    dt         = ba.time - start_time;
    epsilon    = 0.01;
    expo(tau)  = exp((0-dt)/(tau*ma.SR)), epsilon : max;

    blend(rate, f, pf) = f*(1 - expo(rate)) + pf*expo(rate);
    glideOn = checkbox("[05]glideOn");

    // mini-moogs generally had longer glide times down vs up 
    // upglide is about half of downglide
    freq = blend(ba.if(frequencyIn > prevfreq, glide/1.8, glide), 
                       frequencyIn, 
                       ba.if(glideOn, prevfreq, frequencyIn)) 
                       <: attach(_,vbargraph("finalFreq[style:numerical]",0,20000));

// Oscillators
    scale = 1, oscOnePower*oscOneGain*0.8 + oscTwoPower*oscTwoGain*0.8 + oscThreePower*oscThreeGain*0.8 : max;

    oscOnePower   = checkbox("[06]oscOnePower");
    oscTwoPower   = checkbox("[07]oscTwoPower");
    oscThreePower = checkbox("[08]oscThreePower");

    oscOneGain   = hslider("[09]oscOneGain[style:knob]",1.0,0.0,1.0,0.01)   : si.smoo;
    oscTwoGain   = hslider("[10]oscTwoGain[style:knob]",1.0,0.0,1.0,0.01)   : si.smoo;
    oscThreeGain = hslider("[11]oscThreeGain[style:knob]",1.0,0.0,1.0,0.01) : si.smoo;

    oscModOn = checkbox("[12]oscModOn");

    // oscillators
    oscOne         = waveOneTwo(freqOne,   rangeOne,   waveSelectOne)*oscOneGain*oscOnePower;
    oscThreeSignal = waveThree (freqThree, rangeThree, waveSelectThree);
    oscTwoSignal   = waveOneTwo(freqTwo,   rangeTwo,   waveSelectTwo);

    oscTwo   = oscTwoSignal  *oscTwoGain  *oscTwoPower;
    oscThree = oscThreeSignal*oscThreeGain*oscThreePower;

    oscillators = (oscOne + oscTwo + oscThree)/scale;

    freqOne   = freq, 2^(rangeOne-4)   : * : _*globalDetune*driftOne : modulateOsc;
    freqTwo   = freq, 2^(rangeTwo-4)   : * : _*detuneTwo   *driftTwo : modulateOsc;

    oscThreeKeyTrack    = checkbox("[13]oscThreeKeyTrack");
    oscThreeManualFreq  = hslider("[14]oscThreeIsoFreq",200,440,20,0.01) : si.smoo;
    freqThreePre = freq, oscThreeDeTrack : select2(oscThreeKeyTrack); 
    freqThree    = freqThreePre : _, 2^(rangeThree-4)   : * : _*detuneThree *driftThree;

    modulateOsc = _ <: _, _*(2^(modulation)) : select2(oscModOn);
    // Oscillator wave selectors. 3rd option in waves one and two is a triangle saw
    //                            3rd option in wave three is a reverse saw
    waveSelectOne   = hslider("[13]waveOne[style:knob]"  ,1,0,5,1);
    waveSelectTwo   = hslider("[14]waveTwo[style:knob]"  ,1,0,5,1);
    waveSelectThree = hslider("[15]waveThree[style:knob]",1,0,5,1);
    waveOneTwo(f,r,ws) = tri(f,r), saw(f,r), triSaw(f,r), square(f,r),
        rectangle(f,r,0.70), rectangle(f,r,0.85) : ba.selectn(6,ws);
    waveThree(f,r,ws) = tri(f,r), saw(f,r), revSaw(f,r), square(f,r), 
        rectangle(f,r,0.70), rectangle(f,r,0.85) : ba.selectn(6,ws);

    driftOne   = os.osc(0.05)*0.01 : 2^_ : @(ma.SR/100);
    driftTwo   = driftOne@(100);
    driftThree = driftTwo@(100);

    rangeOne   = hslider("[16]rangeOne[style:knob]",2,0,5,1);
    rangeTwo   = hslider("[17]rangeTwo[style:knob]",2,0,5,1);
    rangeThree = hslider("[18]rangeThree[style:knob]",2,0,5,1);

    globalDetune = hslider("[19]globalDetune[style:knob]", 0, -2.5, 2.5, 0.01) : ba.semi2ratio : si.smoo; 
    detuneTwo    = hslider("[20]detuneTwo[style:knob]", 0, -7.5, 7.5, 0.01)    : ba.semi2ratio,  globalDetune : + : si.smoo;
    detuneThree  = hslider("[21]detuneThree[style:knob]", 0, -7.5, 7.5, 0.01)  : ba.semi2ratio,  globalDetune : + : si.smoo;

    tri(f,type)    = os.lf_triangle(f),   os.triangle(f) : select2(type);
    saw(f,type)    = os.lf_saw(f),        os.sawtooth(f) : select2(type);
    square(f,type) = os.lf_squarewave(f), os.square(f)   : select2(type);

    rectangle(f,type,n) = os.lf_pulsetrain(f,n), os.pulsetrain(f,n) : select2(type);
    revSaw(f,type)      = saw(f,type), -1: *;
    triSaw(f,type)      = (saw(f,type) + tri(f,type))/2;


// Envelope Section
    envelope    = en.adsr(attack,decay,sustain,release,gate) <: _, si.smoo : select2(decayButton);
    decayButton = checkbox("[22]decayOn");
    attack      = hslider("[23]attack[style:knob]",50,1,10000,1)*0.001 : si.smoo;
    decay       = hslider("[24]decay[style:knob]",50,1,24000,1)*0.001  : si.smoo;
    sustain     = hslider("[25]sustain[style:knob]",0.8,0.01,1,0.01)   : si.smoo;
    release     = 10*0.001, decay : select2(decayButton);

// Filter Section
    // filter response is 32k, cutoff range max ma.SR
    filterMax = ma.SR/2;
    cutoffIn = hslider("[26]cutoff[style:knob]",0.5,0.0,1.0,0.001);

// key tracking stuff
    // Midi note 48, 130.81hz, C2 is default 1V in model D
    // Will use as center for keyTrackingDiff
    keyTrackCenter = 130.81;

    keyTrackDiff = frequencyIn-keyTrackCenter;

    //oneThird, twoThird
    keyTrackOne = checkbox("[27]keyTrackOne")*keyTrackDiff;
    keyTrackTwo = checkbox("[28]keyTrackTwo")*2.0*keyTrackDiff;
    keyTrackSum = (keyTrackOne + keyTrackTwo)/3.0;

// filter contour
    reverseContour = hslider("[29]contour_direction[style:radio{'+':0;'-':1}]",0,0,1,1);
    contourAmount = hslider("[30]contourAmount[style:knob]",0.0,0.0,1.0,0.001) : si.smoo;
    fAttack = hslider("[31]fAttack[style:knob]",50,1,7000,1) : si.smoo;
    fDecay = hslider("[32]fDecay[style:knob]",50,1,30000,1) : si.smoo;
    fSustain = hslider("[33]fSustain[style:knob]",0.8,0.01,1.0,0.01) : si.smoo;
    fRelease = 10, fDecay : select2(decayButton);
    
   // 4 octave change max
    contourPeak = (cutoffIn*16), filterMax : min, 
                  (cutoffIn/16) :  select2(reverseContour);

    filterUp   = _ + filterContour*(contourPeak-_)*contourAmount;
    filterDown = _ - filterContour*(_-contourPeak)*contourAmount;
    filterContour = en.adsr(fAttack, fDecay, fSustain, fRelease);

    // set signal up/down a percentage of 4 octaves from the set cutoff-frequency(plus keyTrack)
    cutOffCombine = keyTrackSum <: filterUp, filterDown: select2(reverseContour) : 
        _ + (cutoffIn*ma.SR) : modulateFilter : _/ma.SR : limit_range(0.0,1.0);

    filterModOn = checkbox("[38]filterModOn");
    modulateFilter = _ <: _, _*(2^(modulation)) : select2(filterModOn);

    emphasis = hslider("[34]emphasis[style:knob]",1,0.707,25.0,0.001) : si.smoo;
    filter = ve.moogLadder(cutOffCombine, emphasis);

// Noise
    noiseSelect = checkbox("[35]noiseType");
    noiseOn = checkbox("[36]noiseOn");
    noiseGain = hslider("[37]noiseGain[style:knob]", 0.0, 0.0, 1.0, 0.01);
    noise = no.noise, no.pink_noise : select2(noiseSelect)*noiseGain*noiseOn;

// Modulation
    oscThree_filterEg = checkbox("[39]oscThree_filterEg");
    modLeft = oscThreeSignal, filterContour : select2(oscThree_filterEg);
    
    lfoRate = hslider("[40]lfoRate[style:knob]",10.0,0.5,200.0,0.01) : si.smoo;
    lfo = os.osc(lfoRate), os.lf_squarewave(lfoRate) : select2(checkbox("[41]lfoShape"));

    lowBandLimit = 20;
    bw3 = 0.7 * ma.SR/2.0 - lowBandLimit;
    redNoise = no.noise : fi.spectral_tilt(3,lowBandLimit,bw3,-0.25);
    modNoise = no.pink_noise, redNoise : select2(noiseSelect);

    modRight  = modNoise, lfo : select2(checkbox("[42]noise_lfo"));
    modMix = hslider("[43]modMix[style:knob]",0.0,0.0,1.0,0.01) : si.smoo;
    modAmount = hslider("[43]modAmount[style:knob]",0.0,0.0,1.0,0.01) : si.smoo;
    modulation = (1-modMix)*modLeft + (modMix)*modRight : _*modAmount;

    load = hslider("[44]load[style:knob]",1.0,1.0,3.0,0.01);
    output(fdb) = ((oscillators+noise)*load)+fdb;
};

process = hgroup("faug", (generateSound ~ fdBackSignal*fdbackOn) : drive : _*on*masterVolume) <: _,_
with {
    // Inverting power button so it defaults to on
    powerButton = checkbox("on");
    on = 1.0,0.0 : select2(powerButton);
    masterVolume = hslider("masterVolume[style:knob]",1.0,0.0,1.0,0.01);

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