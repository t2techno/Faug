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
#include "../../ParamsList.h"

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

        KnobOne(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int knobSize) : Knob(vts, paramId, knobSize)
        {
            knobLaf->setKnobImage(BinaryData::knobOne_png, BinaryData::knobOne_pngSize, knobSize);
            setLaf(knobLaf.get());
        }
        virtual ~KnobOne() override {};

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

class KnobThree : public Knob
{
    public:

        KnobThree(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int knobSize) : Knob(vts, paramId, knobSize)
        {
            knobLaf->setKnobImage(BinaryData::knobOne_png, BinaryData::knobOne_pngSize, knobSize);
            setLaf(knobLaf.get());
        }
        virtual ~KnobThree() override {}

    private:
        static std::unique_ptr<KnobLookAndFeel> knobLaf;
};