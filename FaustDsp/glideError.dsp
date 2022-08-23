import("stdfaust.lib");

// ASSERT : please report this message and the failing DSP file to Faust developers 
//(file: wasm_code_container.hh, line: 60, version: 2.44.5, options: -lang wasm-eb -cn 6c8d401ba69332e9d6e1db0cb080c0ea460e0c5330d8225da3afa78018e22821 -es 1 -mcd 16 -single -ftz 0 )

glide_synth = output
with
{
    glideRate = hslider("[0]glideRate[style:knob]",50,1,9250,1) * 0.001;
    playedFreq = hslider("[1]freq[style:knob]",880.0,1.0,20000.0,0.01) <: attach(_, vbargraph("playedFreq[style:numerical]",0,20000));
    //counter(trig) = upfront(trig) : + ~ _;
    counter(trig) = upfront(trig) <: attach(_, vbargraph("writeIndex[style:numerical]",0,10));
    upfront(x) = x > x';
    w_idx =  counter(gate) <: attach(_, vbargraph("writeIndex[style:numerical]",0,10));
    //r_idx = w_idx+1%2 <: attach(_, vbargraph("readIndex[style:numerical]",0,1));
    gain   = hslider("[2]gain[style:knob]",1.0,0.0,1.0,0.01);
    gate   = button("[3]gate");
    output = gain*gate*(os.osc(playedFreq + w_idx) + os.osc(playedFreq));
};

process = glide_synth;