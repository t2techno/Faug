/*
  ==============================================================================

    Toggle.cpp
    Created: 10 Aug 2022 9:48:06pm
    Author:  tytu1

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Toggle.h"

typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;

Toggle::Toggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, const int toggleSize)
{
    toggle = std::make_unique<juce::ToggleButton>();
    toggle->setBounds(0, 0, toggleSize, toggleSize);
    addAndMakeVisible(toggle.get());
    attach.reset(new ButtonAttachment(vts, paramId, *toggle.get()));
}

Toggle::~Toggle()
{
}

void Toggle::setLaf(ToggleLookAndFeel* laf)
{
    toggle->setLookAndFeel(laf);
}

std::unique_ptr<ToggleLookAndFeel> OrangeToggle::toggleLaf = std::make_unique<ToggleLookAndFeel>();
std::unique_ptr<ToggleLookAndFeel> BlueToggle::toggleLaf = std::make_unique<ToggleLookAndFeel>();
std::unique_ptr<ToggleLookAndFeel> BrownToggle::toggleLaf = std::make_unique<ToggleLookAndFeel>();