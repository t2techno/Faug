/*
  ==============================================================================

    Knob.h
    Created: 3 Aug 2022 8:15:21am
    Author:  tytu1

    Holds a juce::Slider, juce::SliderAttachment, and (optional) juce::Label
  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

class Knob : public juce::Component
{
public:
    Knob(juce::AudioProcessorValueTreeState& vts, juce::String label, juce::String paramId, int sliderSize);
    virtual ~Knob() override;
    void paint(juce::Graphics& g) override; //Component
    void resized() override; //Component

private:
    void createSliderAndLabel(juce::String labelText);

    int m_sliderSize;
    std::unique_ptr<juce::Slider>     slider;
    std::unique_ptr<juce::Label>      label;
    std::unique_ptr<SliderAttachment> attach;
};