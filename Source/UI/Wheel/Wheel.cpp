/*
  ==============================================================================

    Wheel.cpp
    Created: 18 Nov 2022 11:11:42pm
    Author:  tytu1

  ==============================================================================
*/

#include "Wheel.h"

Wheel::Wheel(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int wheelWidth, int wheelHeight)
{
    slider = std::make_unique<juce::Slider>();
    addAndMakeVisible(slider.get());
    slider->setBounds(0, 0, wheelWidth, wheelHeight);
    slider->setSliderStyle(juce::Slider::LinearVertical);
    slider->setTextBoxStyle(juce::Slider::NoTextBox, true, 80, 20);
    attach.reset(new SliderAttachment(vts, juce::String(paramId), *slider.get()));
}

Wheel::~Wheel()
{
    slider->setLookAndFeel(nullptr);
}

void Wheel::setLaf(WheelLookAndFeel* laf) {
    slider->setLookAndFeel(laf);
}

std::unique_ptr<WheelLookAndFeel>Wheel::wheelLaf = std::make_unique<WheelLookAndFeel>();