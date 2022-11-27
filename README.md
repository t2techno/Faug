# Faug
A Minimoog Model D emulation with the DSP portion written in Faust. Moog + Faust = Faug

![Alt text](./imageWork/backgroundExample.png?raw=true "Faug UI")

<h2>Controllers Section:</h2>
<ul>
  <li>Tune Knob:  Global detune ranging from [-2.5, 2.5] semi-tones</li>
  <li>Glide Knob : Glide rate/portamento, max time ~6sec</li>
  <li>Modulation Mix Knob: Mixes between modulation sources determined by buttons below</li>
  <li>Osc-3/Filter Eg Button: Determines mod source added by left side of the Modulation Mix knob
    <ul>
        <li>Osc-3: Osc three signal is modulation source</li>
        <li>Filter EG: Filter Envelope Generator is modulation source</li>
    </ul>
  </li>
  <li>Noise/LFO Button: Determines mod source added by Right side of the Modulation Mix knob
    <ul>
        <li>Noise: Noise is modulation source
          <ul>
            <li>White Noise in mixer section means pink noise for noise modulation source</li>
            <li>Pink Noise in mixer section means red noise for noise modulation source</li>
          </ul>
        </li>
        <li>LFO: LFO is modulation source</li>
    </ul>
  </li>
</ul>

<h2>Keyboard Section:</h2>
<ul>
  <li>LFO Rate Knob: Frequency of dedicated modulation Low Frequency Oscillator: [0.5Hz,200Hz]
    <ul>
      <li>ToDo: LFO Shape toggle</li>
    </ul>
  </li>
  <li>Pitch Wheel: Pitch bend for while playing.
    <ul>
      <li>ToDo: Setting to send wheel automatically back to center when released</li>
    </ul>
  </li>
  <li>Mod Wheel: Modulation Amount to modulation targets
    <ul>
      <li>ToDo: Wheel image/slider integration not working yet.</li>
    </ul>
  </li>
  <li>Glide Button: 
    <ul>
      <li>Activates glide/portamento when notes are played with no seperation</li>
    </ul>
  </li>
  <li>Decay Button: 
    <ul>
      <li>Applies an Envelope's decay setting to it's release stage</li>
      <li>Release is ~10ms when turned off</li>
    </ul>
  </li>
</ul>

<h2>Oscillator Bank:</h2>
<ul>
  <li>Oscillator Modulation Button: Turns on modulation source routing to Oscillators 1 and 2<ul>
    <li>Oscillator 3 doesn't get modulated b/c it is a modulation source</li>
  </ul></li>
  <li>Osc-3 Control Button: Connects Oscillator 3's frequency to the keyboard input<ul>
    <li>Uses Keyboard center of C3 - Midi Note 48 - 130.81Hz as input frequency when Oscillator 3 disengaged from keyboard</li>
  </ul></li>
  <li>Range Column:<ul>
    <li>Octave for pitch of respective oscillator</li>
    <li>Units are feet - tradition from organ pipes</li>
    <li>Midi Note 93(A6) at 16' plays 440Hz(A4)</li>
    <li>Lo mode uses aliasing oscillators since the pitch is in a range aliasing shouldn't occur</li>
  </ul></li>
  <li>Frequency column:<ul>
    <li>Detune for Oscillators 2 and 3</li>
    <li>Range of [-7.5,7.5] semi-tones</li>
    <li>Oscillator 1 doesn't get detuned as it serves as a reference for the other two</li>
  </ul></li>
  <li>Waveform column:<ul>
    <li>Triangle: Triangle wave</li><ul>
      <li>Triangle+Saw: Oscillators 1 & 2: A triangle and saw wave added together</li>
      <li>Reverse Saw: Oscillator 3: A saw wave that ramps down instead of ramping up</li>
    </ul>
    <li>Saw: Save Wave, ramps up</li>
    <li>Square: Square Wave</li>
    <li>Rectangle: Rectangle Wave-Pulse train with 0.7 duty cycle </li>
    <li>Narrow Rectangle: Rectangle Wave-Pulse train with 0.85 duty cycle </li>
  </ul></li>
</ul>

<h2>Mixer Section:</h2>
<ul>
  <li>Left Column of knobs: Volume knobs for their respective oscillators<ul>
    <li>Volume Knob for Oscillator 3 has no impact on it's contribution to modulation signal</li>
  </ul></li>
  <li>Center Column of buttons: On/Off buttons for their respective noise sources contribution to the sound signal path<ul>
    <li>On/Off buttons for Oscillator 3 and Noise have no impact on they're contributions to the modulation signal</li>
  </ul></li>
  <li>Right Column: <ul>
    <li>Load Screw/knob: Increases the output of Oscillators and Noise(not feedback) before being fed into the filter<ul>
      <li>ToDo: Include a warm little light that increases in brightness with load</li>
      <li>ToDo: Improve/build upon scaling/saturation algorithms</li>
    </ul></li>
    <li>Feedback Amount: Amount of the signal's output that gets fed back to the input<ul>
      <li>ToDo: Improve and build upon feedback saturation/processing</li>
    </ul></li>
    <li>Noise Volume: Volume knob for noise signal's contribution to sound signal<ul>
      <li>Has no impact on noise's contribution to modulation signal</li>
    </ul></li>
    <li>Noise-Type Button: Determines noise type for sound and modulation signals<ul>
      <li>White Noise for sound signal is Pink Noise for modulation Signal</li>
      <li>Pink Noise for sound signal is Red Noise for modulation Signal</li>
    </ul></li>
  </ul></li>
</ul>

<h2>Filter Section:</h2>
<h3>Faust Libraries-vaeffects emulation of traditional moog 4th order ladder filter</h3>
<ul>
  <li>Filter Modulation Button: Turns on modulation of filter cutoff by modulation sources</li>
  <li>Keyboard Control:<ul>
    <li>Keyboard Control 1: Turns on 1/3 of key tracking for filter cutoff</li>
    <li>Keyboard Control 2: Turns on 2/3 of key tracking for filter cutoff</li>
    <li>Turning on both gives full keyboard tracking eg. Filter cutoff will move 1:1 with change in played pitch</li>  
  </ul></li>
  <li>Cutoff Frequency Knob: Determines base cutoff of filter: range [10Hz,20kHz]</li>
  <li>Emphasis Knob: Controls the amount of filter signal fed back into filter, resulting in a resonance peak at cutoff<ul>
    <li>Self-Oscillation occurs at max value</li>
    <li>ToDo: Add scaling to reduce emphasis as cutoff freq goes down so bass notes still have bass frequencies</li>
  </ul></li>
  <li>Contour Amount Knob: Adjusts the amount that the Filter's envelope generator impacts the filter cutoff<ul>
    <li>Max Range of 4 octaves</li>
    <li>ToDo: Add filter direction toggle</li>
  </ul></li>
  <li>Attack Time Knob: The amount of time it takes for the filter cutoff to go from the base frequency to max or min cutoff frequency.<ul>
    <li>Value Range: [1ms, 7s]</li>
    <li>Peak change amount is determined by Contour Amount knob.</li>
  </ul></li>
  <li>Sustain Level Knob: The percent of difference between filter cutoff and contour peak for the cutoff frequency to stay at after Decay Phase<ul>
    <li>Value Range: [0%, 100%]</li>
    <li>0%: After the Attack phase, the filter cutoff will decay to the base cutoff frequency set by the knob</li>
    <li>50%: If contour is set to max(4 octaves), the filter cutoff will decay to 2 octaves above base cutoff frequency determined by knob</li>
    <li>100%: After the Attack phase, the filter cutoff will not decay at all and will sustain at peak value until note is released</li>
  </ul></li>
  <li>Decay Time Knob: The amount of time it takes for the filter cutoff to go from the max or min cutoff frequency to Sustain level<ul>
    <li>Value Range: [4ms, 30s]</li>
    <li>Begins immediately after Attack phase ends</li>
  </ul></li>
  <li>Release for filter envelope is either 10ms, or Decay Time value if Decay Button in keyboard section is on</li>
  <li>ToDo: Add different cutoff slopes/filter implementations</li>
</ul>

<h2>Loudness Contour:</h2>
<ul>
  <li>Attack Time Knob: The amount of time it takes for the volume to reach it's peak.<ul>
    <li>Value Range: [1ms, 10s]</li>
    <li>Peak determined by the Volume Knob in Power Section.</li>
  </ul></li>
  <li>Sustain Level Knob: Volume level held after decay<ul>
    <li>Value Range: [0%, 100%]</li>
    <li>0%: Volume will decay to nothing</li>
    <li>100%: No volume decay after attack until note released</li>
  </ul></li>
  <li>Decay Time Knob: The amount of time it takes for the filter cutoff to go from the max or min cutoff frequency to Sustain level<ul>
    <li>Value Range: [4ms, 24s]</li>
    <li>Begins immediately after Attack phase ends</li>
  </ul></li>
  <li>Release for envelope is either 10ms, or Decay Time value if Decay Button in keyboard section is on</li>
</ul>

<h2>Power Section:</h2>
<ul>
  <li>Volume Knob: Scales overall output</li>
  <li>Power Button: Turns output on/off <ul>
    <li>ToDo: Add a warm up process</li>
  </ul></li>
</ul>
<h3>Other ToDos:</h3>
<ul>
  <li></li>
  <li>Filter Direction button</li>
  <li>Oversampling</li>
  <li>Alternate UI view when no keyboard is needed</li>
  <li>Contour generator builds on itself when decay button is on</li>
  <li>Replace various implementations with exponential versions</li>
</ul>
