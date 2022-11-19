/*
  ==============================================================================

    Wheel.h
    Created: 18 Nov 2022 11:11:42pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "WheelLookAndFeel.h"

typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

class Wheel : public juce::Component
{
public:
    Wheel(juce::AudioProcessorValueTreeState& vts, juce::String paramId, const int wheelWidth, const int wheelHeight);
    virtual ~Wheel() override;
    void setLaf(WheelLookAndFeel* laf);

private:
    std::unique_ptr<juce::Slider>     slider;
    std::unique_ptr<SliderAttachment> attach;
    static std::unique_ptr<WheelLookAndFeel> wheelLaf;
};