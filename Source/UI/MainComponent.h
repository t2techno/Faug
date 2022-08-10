#pragma once

// Main Component, holds the primary synth UI

#include <JuceHeader.h>
#include "./Knobs/Knob.h"

typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

class MainComponent : public juce::Component,
							 juce::Timer
{
public:
	MainComponent(juce::MidiKeyboardState& keyboardState, juce::AudioProcessorValueTreeState& vts, juce::Rectangle<int> screen);
	virtual ~MainComponent() override;

	 void  timerCallback() override; // timer

	 void paint(juce::Graphics& g) override; //Component
	 void resized() override; //Component

	 // Create UI Sections
	 void createOscBank(int upl_x, int upl_y, int col_w, int row_h);

	 void createMixer(int upl_x, int upl_y, int col_w, int row_h);

	 void createFilterBank(int upl_x, int upl_y, int col_w, int row_h);

	 void createEnvelope(int upl_x, int upl_y, int col_w);
private:
	int screenWidth;
	int screenHeight;
	int knob_size;
	int small_knob_size;

	juce::MidiKeyboardComponent keyboardComponent;
    juce::AudioProcessorValueTreeState& m_vts;
	std::unique_ptr<juce::Drawable> background;

	// OSC PARAMS
	// OSC ONE
	std::unique_ptr<juce::ToggleButton> m_oscOnePowerButton;
	std::unique_ptr<ButtonAttachment>   m_oscOnePowerAttach;

	std::unique_ptr<KnobThree> m_oscOneGain;
	std::unique_ptr<KnobTwo> m_oscOneRange;
	std::unique_ptr<KnobTwo> m_oscOneWaveForm;

	// OSC TWO
	std::unique_ptr<juce::ToggleButton> m_oscTwoPowerButton;
	std::unique_ptr<ButtonAttachment>   m_oscTwoPowerAttach;

	std::unique_ptr<KnobThree> m_oscTwoGain;
	std::unique_ptr<KnobTwo> m_oscTwoRange;
	std::unique_ptr<KnobTwo> m_oscTwoWaveForm;
	std::unique_ptr<KnobOne> m_oscTwoDetune;

	// OSC THREE
	std::unique_ptr<juce::ToggleButton> m_oscThreePowerButton;
	std::unique_ptr<ButtonAttachment>   m_oscThreePowerAttach;

	std::unique_ptr<KnobThree> m_oscThreeGain;
	std::unique_ptr<KnobTwo> m_oscThreeRange;
	std::unique_ptr<KnobTwo> m_oscThreeWaveForm;
	std::unique_ptr<KnobOne> m_oscThreeDetune;

	// FILTER
	std::unique_ptr<KnobThree> m_filterCutoff;
	std::unique_ptr<KnobThree> m_filterQ;
	std::unique_ptr<KnobThree> m_filterContourAmount;
	std::unique_ptr<KnobThree> m_filterAttack;
	std::unique_ptr<KnobThree> m_filterDecay;
	std::unique_ptr<KnobThree> m_filterSustain;

	// ENVELOPE
	std::unique_ptr<KnobThree> m_attack;
	std::unique_ptr<KnobThree> m_decay;
	std::unique_ptr<KnobThree> m_sustain;

	// GLOBAL
	std::unique_ptr<juce::Slider>       m_globalDetuneSlider;
	std::unique_ptr <juce::Label>       m_globalDetuneLabel;
	//std::unique_ptr<SliderAttachment>   m_globalDetuneAttach;


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};