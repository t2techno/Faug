import("stdfaust.lib");

// current/voltage constants
is1 = 1e-15;
is2 = 1e-15;
vt1 = 26e-3;
vt2 = 26e-3;

// derivative of current over resistor
gr = 1.0 / 2200.0;

// Newton–Raphson loop
nr_loop(v1, v2_guess1, v2_guess2) = (gr*v1 + id1eq - id2eq) / (gr + gd1)
with {
    vd1 = 0.0-v2_guess1;
    ed1 = exp(vd1/vt1);
    id1 = is1*ed1-is1;
    gd1 = is1*ed1/vt1;
    id1eq = id1 - gd1*vd1;

    vd2 = v2_guess2-0.0;
    ed2 = exp(vd2/vt2);
    id2 = is2*ed2-is2;
    gd2 = is2*ed2/vt2;
    id2eq = id2 - gd2*vd2;
};

diode_clipper = nr_loop(_, 0.0, 0.0);

process = experiment <: _,_ with {
    sound = os.sawtooth(440)*hslider("gain[style:knob]", 1.0, 0.0, 2.0, 0.01);
    mix   = hslider("mix[style:knob]",0.0, 0.0, 1.0, 0.01);
    experiment = sound <: _*(1-mix) + diode_clipper(_)*mix;
};