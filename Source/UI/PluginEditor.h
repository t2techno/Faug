/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"

class MainComponent;


//==============================================================================
/**
*/
class FaugAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    FaugAudioProcessorEditor (FaugAudioProcessor&, juce::MidiKeyboardState& state, juce::AudioProcessorValueTreeState& vts);
    virtual ~FaugAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FaugAudioProcessor& audioProcessor;
    std::unique_ptr<MainComponent> m_main;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FaugAudioProcessorEditor)
};