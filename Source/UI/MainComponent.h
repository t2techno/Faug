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

	 // Load Images
	 void initializeAssets();

	 // Create UI Sections
	 void createKeyboard();

	 void createController();

	 void createOscBank();

	 void createMixer();

	 void createFilterBank();

	 void createEnvelope();

	 void placeElement(juce::Component& comp, std::string label);

	 void placeVerticalButton(juce::Component& comp, std::string label);

	 // getElementDimensions. single line call, but it would be annoyingly verbose to include it everywhere
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

	// 3 Image assets
	std::unique_ptr<juce::Image> floatKnobImage;
	std::unique_ptr<juce::Image> intKnobImage;
	std::unique_ptr<juce::Image> screwKnobImage;

	// referenced among 5 LookAndFeels of varying size
	std::unique_ptr<KnobLookAndFeel>BigFloatKnobLaf;
	std::unique_ptr<KnobLookAndFeel>TinyFloatKnobLaf;
	std::unique_ptr<KnobLookAndFeel>FloatKnobLaf;
	std::unique_ptr<KnobLookAndFeel>IntKnobLaf;
	std::unique_ptr<KnobLookAndFeel>ScrewKnobLaf;


	// CONTROLLERS
	// 
	std::unique_ptr<FloatKnob> m_globalDetune;
	std::unique_ptr<FloatKnob> m_glide;
	std::unique_ptr<FloatKnob> m_modMix;

	// Brown Toggles
	std::unique_ptr<BrownToggle> m_osc3_filterEG_modSrc;
	std::unique_ptr<BrownToggle> m_noise_lfo_modSrc;


	// KEYBOARD
	//
	std::unique_ptr<TinyFloatKnob> m_lfoRate;

	// White Toggle
	std::unique_ptr<WhiteToggle> m_glideOn;
	std::unique_ptr<WhiteToggle> m_decayOn;

	// Mod Wheels
	std::unique_ptr<ModWheel> m_pitchBend;
	std::unique_ptr<ModWheel> m_modAmount;


	// In-Between CONTROLLER/OSCILLATOR
	std::unique_ptr<BigOrangeToggle> m_oscModOn;


	// OSCILLATOR BANK
	std::unique_ptr<IntKnob>  m_oscOneRange;
	std::unique_ptr<IntKnob>  m_oscOneWaveForm;
	
	std::unique_ptr<IntKnob>  m_oscTwoRange;
	std::unique_ptr<IntKnob>  m_oscTwoWaveForm;
	std::unique_ptr<BigFloatKnob>  m_oscTwoDetune;

	std::unique_ptr<IntKnob> m_oscThreeRange;
	std::unique_ptr<IntKnob> m_oscThreeWaveForm;
	std::unique_ptr<BigFloatKnob> m_oscThreeDetune;
	std::unique_ptr<BigOrangeToggle>m_osc3Ctrl;

	// MIXER
	std::unique_ptr<ScrewFloatKnob>  m_load;

	std::unique_ptr<BlueToggle> m_oscOnePowerButton;
	std::unique_ptr<FloatKnob>    m_oscOneGain;

	std::unique_ptr<BlueToggle> m_oscTwoPowerButton;
	std::unique_ptr<FloatKnob>    m_oscTwoGain;

	std::unique_ptr<BlueToggle> m_oscThreePowerButton;
	std::unique_ptr<FloatKnob>    m_oscThreeGain;

	std::unique_ptr<BlueToggle> m_feedbackOn;
	std::unique_ptr<FloatKnob>    m_feedbackGain;

	std::unique_ptr<BlueToggle> m_noiseOn;
	std::unique_ptr<FloatKnob>    m_noiseGain;
	std::unique_ptr<BlueToggle> m_noiseType;

	// In-Between
	std::unique_ptr<OrangeToggle> m_keyTrackOne;
	std::unique_ptr<OrangeToggle> m_keyTrackTwo;
	std::unique_ptr<OrangeToggle> m_filterModOn;


	// FILTER
	//knob_one
	std::unique_ptr<FloatKnob> m_filterCutoff;
	std::unique_ptr<FloatKnob> m_filterQ;
	std::unique_ptr<FloatKnob> m_filterContourAmount;
	//std::unique_ptr<BrownToggle> m_filterDirection;
	std::unique_ptr<FloatKnob> m_filterAttack;
	std::unique_ptr<FloatKnob> m_filterDecay;
	std::unique_ptr<FloatKnob> m_filterSustain;

	// ENVELOPE
	std::unique_ptr<FloatKnob> m_attack;
	std::unique_ptr<FloatKnob> m_decay;
	std::unique_ptr<FloatKnob> m_sustain;

	// POWER
	//tiny knob one
	std::unique_ptr<TinyFloatKnob> master_volume;
	std::unique_ptr<BrownToggle> master_on;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};