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
    Knob(juce::AudioProcessorValueTreeState& vts, juce::String paramId, const int knobSize);
    virtual ~Knob() override;
    void setLaf(KnobLookAndFeel* laf);

private:
    std::unique_ptr<juce::Slider>     slider;
    std::unique_ptr<SliderAttachment> attach;
};


class KnobOne : public Knob
{
public:

    KnobOne(juce::AudioProcessorValueTreeState& vts, juce::String paramId, float knobSize) : Knob(vts, paramId, knobSize)
    {
        knobLaf->setKnobImage(BinaryData::knobOne_png, BinaryData::knobOne_pngSize, knobSize);
        setLaf(knobLaf.get());
    }
    virtual ~KnobOne() override {}

private:
    static std::unique_ptr<KnobLookAndFeel> knobLaf;
};

class BigKnobOne : public Knob
{
    public:

        BigKnobOne(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int knobSize) : Knob(vts, paramId, knobSize)
        {
            knobLaf->setKnobImage(BinaryData::knobOne_png, BinaryData::knobOne_pngSize, knobSize);
            setLaf(knobLaf.get());
        }
        virtual ~BigKnobOne() override {};

    private:
        static std::unique_ptr<KnobLookAndFeel> knobLaf;


};

class TinyKnobOne : public Knob
{
public:

    TinyKnobOne(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int knobSize) : Knob(vts, paramId, knobSize)
    {
        knobLaf->setKnobImage(BinaryData::knobOne_png, BinaryData::knobOne_pngSize, knobSize);
        setLaf(knobLaf.get());
    }
    virtual ~TinyKnobOne() override {};

private:
    static std::unique_ptr<KnobLookAndFeel> knobLaf;


};

class KnobTwo : public Knob
{
    public:

        KnobTwo(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int knobSize) : Knob(vts, paramId, knobSize)
        {
            knobLaf->setKnobImage(BinaryData::knobTwo_png, BinaryData::knobTwo_pngSize, knobSize);
            setLaf(knobLaf.get());
        }
        virtual ~KnobTwo() override {}

    private:
        static std::unique_ptr<KnobLookAndFeel> knobLaf;
};


class ScrewKnob : public Knob
{
public:

    ScrewKnob(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int knobSize) : Knob(vts, paramId, knobSize)
    {
        knobLaf->setKnobImage(BinaryData::screwKnob_png, BinaryData::screwKnob_pngSize, knobSize);
        setLaf(knobLaf.get());
    }
    virtual ~ScrewKnob() override {}

private:
    static std::unique_ptr<KnobLookAndFeel> knobLaf;
};