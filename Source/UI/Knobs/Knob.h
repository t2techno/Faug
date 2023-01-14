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

class FloatKnob : public Knob {
    public:
        FloatKnob(juce::AudioProcessorValueTreeState& vts, juce::String paramId, KnobLookAndFeel& laf) : Knob(vts, paramId, laf) {}
        virtual ~FloatKnob() override {}
};

class BigFloatKnob : public Knob {
public:
    BigFloatKnob(juce::AudioProcessorValueTreeState& vts, juce::String paramId, KnobLookAndFeel& laf) : Knob(vts, paramId, laf) {}
    virtual ~BigFloatKnob() override {}
};

class TinyFloatKnob : public Knob {
public:
    TinyFloatKnob(juce::AudioProcessorValueTreeState& vts, juce::String paramId, KnobLookAndFeel& laf) : Knob(vts, paramId, laf) {}
    virtual ~TinyFloatKnob() override {}
};

class IntKnob : public Knob {
public:
    IntKnob(juce::AudioProcessorValueTreeState& vts, juce::String paramId, KnobLookAndFeel& laf) : Knob(vts, paramId, laf) {}
    virtual ~IntKnob() override {}
};

class ScrewFloatKnob : public Knob {
public:
    ScrewFloatKnob(juce::AudioProcessorValueTreeState& vts, juce::String paramId, KnobLookAndFeel& laf) : Knob(vts, paramId, laf) {}
    virtual ~ScrewFloatKnob() override {}
};