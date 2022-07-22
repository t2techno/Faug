#pragma once

// Main Component, holds the primary synth UI
// Todo: Move MidiKeyboardComponent to it's own class to be added/removed

#include <JuceHeader.h>

class MainComponent : public juce::Component,
							 juce::Timer
{
public:
	MainComponent(juce::MidiKeyboardState& keyboardState);
	virtual ~MainComponent();

	 void  timerCallback() override; // timer

	 void paint(juce::Graphics& g) override; //Component
	 void resized() override; //Component

private:
	juce::MidiKeyboardComponent keyboardComponent;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};