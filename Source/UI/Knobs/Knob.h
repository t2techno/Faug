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
#include "KnobLookAndFeel.h"
#include "KnobImage.h"

typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

class Knob : public juce::Component
{
public:
    Knob(juce::AudioProcessorValueTreeState& vts, juce::String paramId, KnobLookAndFeel& laf);
    virtual ~Knob() override;

private:
    std::unique_ptr<juce::Slider>     slider;
    std::unique_ptr<SliderAttachment> attach;
};