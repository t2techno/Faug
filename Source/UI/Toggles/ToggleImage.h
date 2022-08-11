/*
  ==============================================================================

    ToggleImage.h
    Created: 10 Aug 2022 9:49:01pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ToggleImage  : public juce::DrawableImage
{
public:
    ToggleImage(const char* toggleData, const int toggleDataSize, const int toggleSize)
    {
        toggleImage = std::make_unique<juce::Image>(juce::ImageFileFormat::loadFrom(toggleData, toggleDataSize));
        setSize(toggleDataSize, toggleDataSize);
        setImage(toggleImage->rescaled(toggleSize, toggleSize));
    }

    ~ToggleImage() override
    {
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleImage)
    std::unique_ptr<juce::Image> toggleImage;
};
