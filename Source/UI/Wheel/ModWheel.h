/*
  ==============================================================================

    Wheel.h
    Created: 18 Nov 2022 11:11:42pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ModWheelLookAndFeel.h"

typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

class ModWheel : public juce::Component
{
public:
    ModWheel(juce::AudioProcessorValueTreeState& vts, juce::String paramId, const int wheelWidth, const int wheelHeight);
    virtual ~ModWheel() override;
    void setLaf(ModWheelLookAndFeel* laf);

private:
    std::unique_ptr<juce::Slider>     slider;
    std::unique_ptr<SliderAttachment> attach;
    static std::unique_ptr<ModWheelLookAndFeel> modWheelLaf;
};