/*
  ==============================================================================

    Toggle.cpp
    Created: 10 Aug 2022 9:48:06pm
    Author:  tytu1

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Toggle.h"


Toggle::Toggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int toggleWidth, int toggleHeight)
{
    toggle = std::make_unique<juce::ToggleButton>();
    toggle->setBounds(0, 0, toggleWidth, toggleHeight);
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

std::unique_ptr<ToggleLookAndFeel> BigOrangeToggle::toggleLaf = std::make_unique<ToggleLookAndFeel>();
std::unique_ptr<ToggleLookAndFeel> OrangeToggle::toggleLaf    = std::make_unique<ToggleLookAndFeel>();
std::unique_ptr<ToggleLookAndFeel> BlueToggle::toggleLaf      = std::make_unique<ToggleLookAndFeel>();
std::unique_ptr<ToggleLookAndFeel> BrownToggle::toggleLaf     = std::make_unique<ToggleLookAndFeel>();
std::unique_ptr<ToggleLookAndFeel> WhiteToggle::toggleLaf     = std::make_unique<ToggleLookAndFeel>();