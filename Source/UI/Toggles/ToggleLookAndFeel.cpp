/*
  ==============================================================================

    ToggleLookAndFeel.cpp
    Created: 10 Aug 2022 9:48:34pm
    Author:  tytu1

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ToggleLookAndFeel.h"
#include "ToggleImage.cpp"

//==============================================================================

ToggleLookAndFeel::ToggleLookAndFeel()
{}

ToggleLookAndFeel::~ToggleLookAndFeel()
{}

ToggleLookAndFeel::ToggleLookAndFeel(const char* toggleData, const int toggleDataSize, int toggleWidth, int toggleHeight)
{
    setToggleImage(toggleData, toggleDataSize, toggleWidth, toggleHeight);
}

void ToggleLookAndFeel::setToggleImage(const char* toggleData, const int toggleDataSize, int toggleWidth, int toggleHeight)
{
    toggleImage = std::make_unique<ToggleImage>(toggleData, toggleDataSize, toggleWidth, toggleHeight);
}

juce::Font ToggleLookAndFeel::getBaseFont()
{
    return juce::Font::bold;
}

juce::Font ToggleLookAndFeel::getLabelFont(juce::Label&)
{
    return getBaseFont().withPointHeight(10);
}

juce::Font ToggleLookAndFeel::getSliderReadoutFont()
{
    return getBaseFont().withPointHeight(14);
}

void ToggleLookAndFeel::drawTickBox(juce::Graphics& g, juce::Component& button,
    float x, float y, float w, float h,
    bool ticked, bool isEnabled,
    bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    bool flipped = (ticked && !shouldDrawButtonAsDown) || (shouldDrawButtonAsDown && !ticked);
    g.drawImageTransformed(toggleImage->getImage(), transform.rotation(flipped * juce::MathConstants<float>::pi, toggleImage->pivot_x, toggleImage->pivot_y));
}