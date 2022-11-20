/*
  ==============================================================================

    Wheel.cpp
    Created: 18 Nov 2022 11:11:42pm
    Author:  tytu1

  ==============================================================================
*/

#include "ModWheel.h"

ModWheel::ModWheel(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int wheelWidth, int wheelHeight)
{
    slider = std::make_unique<juce::Slider>();
    addAndMakeVisible(slider.get());
    slider->setBounds(0, 0, wheelWidth, wheelHeight);
    slider->setSliderStyle(juce::Slider::LinearVertical);
    slider->setTextBoxStyle(juce::Slider::NoTextBox, true, 80, 20);
    attach.reset(new SliderAttachment(vts, juce::String(paramId), *slider.get()));

    modWheelLaf->setWheelImage(BinaryData::wheel_png, BinaryData::wheel_pngSize, wheelWidth, wheelHeight);
    setLaf(modWheelLaf.get());
}

ModWheel::~ModWheel()
{
    slider->setLookAndFeel(nullptr);
}

void ModWheel::setLaf(ModWheelLookAndFeel* laf) {
    slider->setLookAndFeel(laf);
}

std::unique_ptr<ModWheelLookAndFeel>ModWheel::modWheelLaf = std::make_unique<ModWheelLookAndFeel>();