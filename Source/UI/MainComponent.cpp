// Main Component, holds the primary synth UI
// Todo: Move MidiKeyboardComponent to it's own class to be added/removed

#include "MainComponent.h"

MainComponent::MainComponent(juce::MidiKeyboardState& keyboardState) : 
    keyboardComponent(keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)

{
    setOpaque(true);
    addAndMakeVisible(keyboardComponent);

    setSize(600, 160);

    // wait .4 seconds, then grab keyboard focus to use as potential midi-input
    startTimer(400);
}

MainComponent::~MainComponent()
{}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void MainComponent::resized()
{
    auto area = getLocalBounds();
    keyboardComponent.setBounds(area.removeFromTop(80).reduced(8));
}

void MainComponent::timerCallback()
{
    keyboardComponent.grabKeyboardFocus();
    stopTimer();
}