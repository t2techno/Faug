/*
  ==============================================================================

    Knob.cpp
    Created: 3 Aug 2022 8:15:21am
    Author:  tytu1

  ==============================================================================
*/

#include "Knob.h"

Knob::Knob(juce::AudioProcessorValueTreeState& vts, juce::String label, juce::String paramId, int knobSize)
{
    m_sliderSize = knobSize;
    slider = std::make_unique<juce::Slider>();
    addAndMakeVisible(slider.get());
    slider->setBounds(0, 0, m_sliderSize, m_sliderSize);
    slider->setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    slider->setTextBoxStyle(juce::Slider::NoTextBox, true, 80, 20);
    attach.reset(new SliderAttachment(vts, juce::String(paramId), *slider.get()));
}

Knob::~Knob()
{
}

void Knob::paint(juce::Graphics& g)
{
}

void Knob::resized()
{
}

void Knob::setLaf(KnobLookAndFeel* laf) {
    slider->setLookAndFeel(laf);
}

std::unique_ptr<KnobLookAndFeel>KnobOne::knobLaf = std::make_unique<KnobLookAndFeel>();
std::unique_ptr<KnobLookAndFeel>KnobTwo::knobLaf = std::make_unique<KnobLookAndFeel>();
std::unique_ptr<KnobLookAndFeel>KnobThree::knobLaf = std::make_unique<KnobLookAndFeel>();