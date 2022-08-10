/*
  ==============================================================================

    KnobImage.h
    Created: 8 Aug 2022 3:22:40pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../../ParamsList.h"

class KnobImage : public juce::DrawableImage
{
public:
    KnobImage(const char * knobData, const int knobDataSize, const int knobSize)
    {
        knobImage = std::make_unique<juce::Image>(juce::ImageFileFormat::loadFrom(knobData, knobDataSize));
        setSize(knobSize, knobSize);
        setImage(knobImage->rescaled(knobSize, knobSize));
        pivotPoint = knobSize / 2.0;
    }

    virtual ~KnobImage() override
    {
    }

    float pivotPoint;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobImage)
    std::unique_ptr<juce::Image> knobImage;
};
