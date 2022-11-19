#pragma once

// Main Component, holds the primary synth UI

#include <JuceHeader.h>
#include "./Knobs/Knob.h"
#include "./Toggles/Toggle.h"
#include "./Wheel/ModWheel.h"

class MainComponent : public juce::Component,
							 juce::Timer
{
public:
	MainComponent(juce::MidiKeyboardState& keyboardState, juce::AudioProcessorValueTreeState& vts, int windowWidth, int windowHeight);
	virtual ~MainComponent() override;

	 void  timerCallback() override; // timer

	 void paint(juce::Graphics& g) override; //Component
	 void resized() override; //Component

	 // Create UI Sections
	 void createController();

	 void createOscBank();

	 void createMixer();

	 void createFilterBank();

	 void createEnvelope();

	 void placeElement(juce::Component& comp, std::string label);

	 void placeVerticalButton(juce::Component& comp, std::string label);

	 // getElementDimensions. single line call, but it would be super verbose to include it everywhere
	 int getElWidth(std::string label);
	 int getElHeight(std::string label);
private:
	int window_width;
	int window_height;
	int toggle_width;
	int toggle_height;
	int knob_size;
	int small_knob_size;

	juce::MidiKeyboardComponent keyboardComponent;
    juce::AudioProcessorValueTreeState& m_vts;
	std::unique_ptr<juce::Drawable> background;


	// CONTROLLERS
	std::unique_ptr<KnobOne> m_globalDetune;
	std::unique_ptr<KnobOne> m_glide;
	std::unique_ptr<KnobOne> m_modMix;
	std::unique_ptr<BrownToggle> m_osc3_filterEG_modSrc;
	std::unique_ptr<BrownToggle> m_noise_lfo_modSrc;


	// KEYBOARDS
	std::unique_ptr<BrownToggle> m_glideOn;
	std::unique_ptr<BrownToggle> m_decayOn;
	std::unique_ptr<TinyKnobOne> m_lfoRate;
	std::unique_ptr<ModWheel> m_pitchBend;
	std::unique_ptr<ModWheel> m_modAmount;


	// In-Between CONTROLLER/OSCILLATOR
	std::unique_ptr<BigOrangeToggle> m_oscModOn;


	// OSCILLATOR BANK
	std::unique_ptr<KnobTwo>     m_oscOneRange;
	std::unique_ptr<KnobTwo>     m_oscOneWaveForm;
	
	std::unique_ptr<KnobTwo>     m_oscTwoRange;
	std::unique_ptr<KnobTwo>     m_oscTwoWaveForm;
	std::unique_ptr<BigKnobOne>  m_oscTwoDetune;

	std::unique_ptr<KnobTwo>        m_oscThreeRange;
	std::unique_ptr<KnobTwo>        m_oscThreeWaveForm;
	std::unique_ptr<BigKnobOne>     m_oscThreeDetune;
	std::unique_ptr<BigOrangeToggle>m_osc3Ctrl;


	// MIXER
	std::unique_ptr<ScrewKnob>  m_load;

	std::unique_ptr<BlueToggle> m_oscOnePowerButton;
	std::unique_ptr<KnobOne>    m_oscOneGain;

	std::unique_ptr<BlueToggle> m_oscTwoPowerButton;
	std::unique_ptr<KnobOne>    m_oscTwoGain;

	std::unique_ptr<BlueToggle> m_oscThreePowerButton;
	std::unique_ptr<KnobOne>    m_oscThreeGain;

	std::unique_ptr<BlueToggle> m_feedbackOn;
	std::unique_ptr<KnobOne>    m_feedbackGain;

	std::unique_ptr<BlueToggle> m_noiseOn;
	std::unique_ptr<KnobOne>    m_noiseGain;
	std::unique_ptr<BlueToggle> m_noiseType;

	// In-Between
	std::unique_ptr<OrangeToggle> m_keyTrackOne;
	std::unique_ptr<OrangeToggle> m_keyTrackTwo;
	std::unique_ptr<OrangeToggle> m_filterModOn;

	// FILTER
	std::unique_ptr<KnobOne> m_filterCutoff;
	std::unique_ptr<KnobOne> m_filterQ;
	std::unique_ptr<KnobOne> m_filterContourAmount;
	//std::unique_ptr<BrownToggle> m_filterDirection;
	std::unique_ptr<KnobOne> m_filterAttack;
	std::unique_ptr<KnobOne> m_filterDecay;
	std::unique_ptr<KnobOne> m_filterSustain;

	// ENVELOPE
	std::unique_ptr<KnobOne> m_attack;
	std::unique_ptr<KnobOne> m_decay;
	std::unique_ptr<KnobOne> m_sustain;

	// POWER
	std::unique_ptr<TinyKnobOne> master_volume;
	std::unique_ptr<BrownToggle> master_on;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};