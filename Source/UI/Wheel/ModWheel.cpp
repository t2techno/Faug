/*
  ==============================================================================

    Wheel.cpp
    Created: 18 Nov 2022 11:11:42pm
    Author:  tytu1

  ==============================================================================
*/

#include "ModWheel.h"

ModWheel::ModWheel(juce::AudioProcessorValueTreeState& vts, juce::String paramId, ModWheelLookAndFeel& laf)
{
    slider = std::make_unique<juce::Slider>();
    addAndMakeVisible(slider.get());
    slider->setBounds(0, 0, laf.wheelWidth, laf.wheelHeight);
    slider->setSliderStyle(juce::Slider::LinearVertical);
    slider->setTextBoxStyle(juce::Slider::NoTextBox, true, 80, 20);
    attach.reset(new SliderAttachment(vts, juce::String(paramId), *slider.get()));
    slider->setLookAndFeel(&laf);
}

ModWheel::~ModWheel()
{
}