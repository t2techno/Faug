#pragma once

// Main Component, holds the primary synth UI

#include <JuceHeader.h>

class MainComponent : public juce::Component,
							 juce::Timer
{
public:
	MainComponent(juce::MidiKeyboardState& keyboardState, juce::AudioProcessorValueTreeState& vts);
	virtual ~MainComponent() override;

	 void  timerCallback() override; // timer

	 void paint(juce::Graphics& g) override; //Component
	 void resized() override; //Component

private:
	juce::MidiKeyboardComponent keyboardComponent;
    juce::AudioProcessorValueTreeState& m_vts;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> m_decayAttach;
    //[/UserVariables]

    //==============================================================================
    juce::Slider m_decaySlider;
    juce::Label m_decayLabel;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};