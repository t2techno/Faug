#pragma once

// Main Component, holds the primary synth UI

#include <JuceHeader.h>

typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;

const int SLIDE_SIZE = 65;

class MainComponent : public juce::Component,
							 juce::Timer
{
public:
	MainComponent(juce::MidiKeyboardState& keyboardState, juce::AudioProcessorValueTreeState& vts);
	virtual ~MainComponent() override;

	 void  timerCallback() override; // timer

	 void paint(juce::Graphics& g) override; //Component
	 void resized() override; //Component

	 void createSliderAndLabel(juce::Label* label, std::string labelText, juce::Slider* slider,
		 int x, int y, int width, int height);
	 void createButtonAndLabel(juce::Label* label, std::string labelText, juce::Button* slider,
		 int x, int y, int width, int height);

private:
	juce::MidiKeyboardComponent keyboardComponent;
    juce::AudioProcessorValueTreeState& m_vts;

    
	std::unique_ptr<juce::Drawable> background;

	// OSC PARAMS
	// 
	// OSC ONE
	std::unique_ptr<juce::ToggleButton> m_oscOnePowerButton;
	std::unique_ptr<ButtonAttachment>   m_oscOnePowerAttach;

	std::unique_ptr<juce::Slider>       m_oscOneGainSlider;
	std::unique_ptr<juce::Label>        m_oscOneGainLabel;
	std::unique_ptr<SliderAttachment>   m_oscOneGainAttach;

	// OSC TWO
	std::unique_ptr<juce::ToggleButton> m_oscTwoPowerButton;
	std::unique_ptr<ButtonAttachment>   m_oscTwoPowerAttach;

	std::unique_ptr<juce::Slider>       m_oscTwoGainSlider;
	std::unique_ptr<juce::Label>        m_oscTwoGainLabel;
	std::unique_ptr<SliderAttachment>   m_oscTwoGainAttach;

	// OSC THREE

	std::unique_ptr<juce::ToggleButton> m_oscThreePowerButton;
	std::unique_ptr<ButtonAttachment>   m_oscThreePowerAttach;

	std::unique_ptr<juce::Slider>       m_oscThreeGainSlider;
	std::unique_ptr<juce::Label>        m_oscThreeGainLabel;
	std::unique_ptr<SliderAttachment>   m_oscThreeGainAttach;

	// ENVELOPE
    std::unique_ptr<juce::Slider>       m_decaySlider;
	std::unique_ptr<juce::Label>        m_decayLabel;
	std::unique_ptr<SliderAttachment>   m_decayAttach;

	// GLOBAL
	std::unique_ptr<juce::Slider>       m_globalDetuneSlider;
	std::unique_ptr <juce::Label>       m_globalDetuneLabel;
	std::unique_ptr<SliderAttachment>   m_globalDetuneAttach;


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};