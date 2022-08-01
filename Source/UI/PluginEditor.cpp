/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "../PluginProcessor.h"
#include "../ParamsList.h"
#include "PluginEditor.h"
#include "MainComponent.h"

//==============================================================================
FaugAudioProcessorEditor::FaugAudioProcessorEditor (FaugAudioProcessor& p, juce::MidiKeyboardState& state, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    m_main = std::make_unique<MainComponent>(state, vts);

    addAndMakeVisible(*m_main.get());
    setSize (WIDTH, HEIGHT);
}

FaugAudioProcessorEditor::~FaugAudioProcessorEditor()
{
}

//==============================================================================
void FaugAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Faug", getLocalBounds(), juce::Justification::centred, 1);
}

void FaugAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}