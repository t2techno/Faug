#pragma once

// Main Component, holds the primary synth UI

#include <JuceHeader.h>

typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

class Knob;

class MainComponent : public juce::Component,
							 juce::Timer
{
public:
	MainComponent(juce::MidiKeyboardState& keyboardState, juce::AudioProcessorValueTreeState& vts);
	virtual ~MainComponent() override;

	 void  timerCallback() override; // timer

	 void paint(juce::Graphics& g) override; //Component
	 void resized() override; //Component

	 void createButtonAndLabel(juce::Label* label, std::string labelText, juce::Button* slider,
		 int x, int y, int width, int height);

	 // Create UI Sections
	 void createOscBank();

	 void createFilterBank();

private:

	// Constants
	static const int UPL_X;
	static const int UPL_Y;
	static const int COL_W;
	static const int ROW_H;
	static const int SECT_W;
	static const int COMP_SIZE;

	juce::MidiKeyboardComponent keyboardComponent;
    juce::AudioProcessorValueTreeState& m_vts;
	std::unique_ptr<juce::Drawable> background;

	// OSC PARAMS
	// OSC ONE
	std::unique_ptr<juce::ToggleButton> m_oscOnePowerButton;
	std::unique_ptr<ButtonAttachment>   m_oscOnePowerAttach;

	std::unique_ptr<Knob> m_oscOneGain;
	std::unique_ptr<Knob> m_oscOneRange;
	std::unique_ptr<Knob> m_oscOneWaveForm;

	// OSC TWO
	std::unique_ptr<juce::ToggleButton> m_oscTwoPowerButton;
	std::unique_ptr<ButtonAttachment>   m_oscTwoPowerAttach;

	std::unique_ptr<Knob> m_oscTwoGain;
	std::unique_ptr<Knob> m_oscTwoRange;
	std::unique_ptr<Knob> m_oscTwoWaveForm;
	std::unique_ptr<Knob> m_oscTwoDetune;

	// OSC THREE
	std::unique_ptr<juce::ToggleButton> m_oscThreePowerButton;
	std::unique_ptr<ButtonAttachment>   m_oscThreePowerAttach;

	std::unique_ptr<Knob> m_oscThreeGain;
	std::unique_ptr<Knob> m_oscThreeRange;
	std::unique_ptr<Knob> m_oscThreeWaveForm;
	std::unique_ptr<Knob> m_oscThreeDetune;

	// FILTER
	std::unique_ptr<Knob> m_filterCutoff;
	std::unique_ptr<Knob> m_filterQ;
	std::unique_ptr<Knob> m_filterContourAmount;
	std::unique_ptr<Knob> m_filterAttack;
	std::unique_ptr<Knob> m_filterDecay;
	std::unique_ptr<Knob> m_filterSustain;

	// ENVELOPE
	std::unique_ptr<Knob> m_Decay;

	// GLOBAL
	std::unique_ptr<juce::Slider>       m_globalDetuneSlider;
	std::unique_ptr <juce::Label>       m_globalDetuneLabel;
	//std::unique_ptr<SliderAttachment>   m_globalDetuneAttach;


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};