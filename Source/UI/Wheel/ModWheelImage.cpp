/*
  ==============================================================================

    WheelLookAndFeel.cpp
    Created: 18 Nov 2022 11:12:01pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class ModWheelImage : public juce::DrawableImage
{
public:
    ModWheelImage(juce::Image& imageIn, const int wheelWidth, const int wheelHeight)
    {
        float wheelScale = float(wheelWidth) / float(imageIn.getWidth());

        wheelImage = std::make_unique<juce::Image>(imageIn.rescaled(wheelWidth, imageIn.getHeight() * wheelScale));

        setSize(wheelWidth, wheelHeight);
        setImage(*wheelImage.get());

        pivotPoint = float(wheelImage->getHeight())/2.0;
    }

    virtual ~ModWheelImage() override
    {
    }

    float pivotPoint;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModWheelImage)
    std::unique_ptr<juce::Image> wheelImage;
};