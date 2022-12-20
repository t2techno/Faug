/*
  ==============================================================================

    KnobImage.h
    Created: 8 Aug 2022 3:22:40pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class KnobImage : public juce::DrawableImage
{
public:
    KnobImage(const char * knobData, const int knobDataSize, const int knobSize)
    {
        knobImage = std::make_unique<juce::Image>(juce::ImageFileFormat::loadFrom(knobData, knobDataSize));
        setSize(knobSize, knobSize);
        setImage(knobImage->rescaled(knobSize, knobSize));
        pivotPoint = std::make_unique<float>(knobSize / 2.0);
    }

    virtual ~KnobImage() override
    {
    }

    std::unique_ptr<float> pivotPoint;

private:
    JUCE_HEAVYWEIGHT_LEAK_DETECTOR(KnobImage)
    std::unique_ptr<juce::Image> knobImage;
};
