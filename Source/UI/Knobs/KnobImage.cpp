/*
  ==============================================================================

    KnobImage.cpp
    Created: 8 Aug 2022 3:22:40pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class KnobImage : public juce::DrawableImage
{
public:
    KnobImage(juce::Image& knobImageIn, const int knobSize)
    {
        setSize(knobSize, knobSize);
        setImage(knobImageIn.rescaled(knobSize, knobSize));
        pivotPoint = std::make_unique<float>(knobSize / 2.0);
    }

    virtual ~KnobImage() override
    {
    }

    std::unique_ptr<float> pivotPoint;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobImage)
};
