/*
  ==============================================================================

    Knob.cpp
    Created: 3 Aug 2022 8:15:21am
    Author:  tytu1

  ==============================================================================
*/

#include "Knob.h"

Knob::Knob(juce::AudioProcessorValueTreeState& vts, juce::String paramId, KnobLookAndFeel& laf)
{
    slider = std::make_unique<juce::Slider>();
    addAndMakeVisible(slider.get());
    slider->setBounds(0, 0, laf.knobSize, laf.knobSize);
    slider->setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    slider->setTextBoxStyle(juce::Slider::NoTextBox, true, 80, 20);
    slider->setLookAndFeel(&laf);
    attach.reset(new SliderAttachment(vts, juce::String(paramId), *slider.get()));
}

Knob::~Knob()
{
}