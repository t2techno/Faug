/*
  ==============================================================================

    Toggle.cpp
    Created: 10 Aug 2022 9:48:06pm
    Author:  tytu1

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Toggle.h"


Toggle::Toggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, ToggleLookAndFeel& laf)
{
    toggle = std::make_unique<juce::ToggleButton>();
    toggle->setBounds(0, 0, laf.toggleWidth, laf.toggleHeight);
    toggle->setLookAndFeel(&laf);
    addAndMakeVisible(toggle.get());
    attach.reset(new ButtonAttachment(vts, paramId, *toggle.get()));
}

Toggle::~Toggle(){}