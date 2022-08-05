/*
  ==============================================================================

    Knob.cpp
    Created: 3 Aug 2022 8:15:21am
    Author:  tytu1

  ==============================================================================
*/

#include "Knob.h"

const int Knob::SLIDER_SIZE = 65;

Knob::Knob(juce::AudioProcessorValueTreeState& vts, juce::String labelString, juce::String paramId)
{
    slider = std::make_unique<juce::Slider>();
    label = std::make_unique<juce::Label>();
    createSliderAndLabel(labelString);
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

void Knob::createSliderAndLabel(juce::String labelText)
{
    addAndMakeVisible(slider.get());
    slider->setBounds(0, 0, SLIDER_SIZE, SLIDER_SIZE);
    slider->setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    slider->setTextBoxStyle(juce::Slider::NoTextBox, true, 80, 20);

    addAndMakeVisible(label.get());
    label->setFont(juce::Font(15.00f, juce::Font::plain));
    label->setText(labelText, juce::dontSendNotification);
    label->setJustificationType(juce::Justification::centred);
    label->setEditable(false, false, false);
    label->setColour(juce::Label::textColourId, juce::Colour(0xffff8917));
    label->attachToComponent(slider.get(), false);
}