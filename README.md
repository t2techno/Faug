# Faug
A Minimoog Model D emulation with the DSP portion written in Faust. Moog + Faust = Faug

![Alt text](./imageWork/backgroundExample.png?raw=true "Full Faug")

<h2>Controllers Section:</h2>
<ul>
  <li>Tune:  Global detune ranging from [-2.5, 2.5] semi-tones</li>
  <li>Glide: Glide rate/portamento, max time ~6sec</li>
  <li>Modulation Mix: Knob to mix between modulation sources determined by buttons below</li>
  <li>Osc-3/Filter Eg:Button to determine mod source added by left side of the Modulation Mix knob
    <ul>
        <li>Osc-3: Osc three signal is modulation source</li>
        <li>Filter EG: Filter Envelope Generator is modulation source</li>
    </ul>
  </li>
  <li>Noise/LFO:Button to determine mod source added by Right side of the Modulation Mix knob
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
      <li>ToDo: Wheel should automatically go back to center when released</li>
      <li>ToDo: Wheel image/slider integration not working yet.</li>
    </ul>
  </li>
  <li>Mod Wheel: Modulation Amount to modulation targets
    <ul>
      <li>ToDo: Wheel image/slider integration not working yet.=</li>
    </ul>
  </li>
  <li>Glide button: 
    <ul>
      <li>Activates glide/portamento when notes are played with no seperation</li>
    </ul>
  </li>
  <li>Decay button: 
    <ul>
      <li>Applies an Envelope's decay setting to it's release stage</li>
      <li>Release is ~10ms when turned off</li>
    </ul>
  </li>
</ul>

<h2>Oscillator Bank:</h2>
<ul>
  <li>Oscillator Modulation: Turns on modulation source routing to Oscillators 1 and 2
    <ul><li>Oscillator 3 doesn't get modulated b/c it is a modulation source</li></ul>
  </li>
  <li>Osc-3 Control button: Connects Oscillator 3's frequency to the keyboard input
  <ul><li>Uses Keyboard center of C3 - Midi Note 48 - 130.81Hz as input frequency when Oscillator 3 disengaged from keyboard</li></ul>
  </li>
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
    <li>Triangle: Triangle wave</li>
    <ul><li>Triangle+Saw: Oscillators 1 & 2: A triangle and saw wave added together</li>
    <li>Reverse Saw: Oscillator 3: A saw wave that ramps down instead of ramping up</li></ul>
    <li>Saw: Save Wave, ramps up</li>
    <li>Square: Square Wave</li>
    <li>Rectangle: Rectangle Wave-Pulse train with 0.7 duty cycle </li>
    <li>Narrow Rectangle: Rectangle Wave-Pulse train with 0.85 duty cycle </li>
  </ul></li>
</ul>
To Be Continue...
<h3>Other ToDos:</h3>
<ul>
  <li>Filter Direction button</li>
  <li>Oversampling</li>
  <li>Alternate UI view when no keyboard is needed</li>
  <li>Envelope generator builds on itself when decay button is on</li>
</ul>
