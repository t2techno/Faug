/*
  ==============================================================================

    ToggleLookAndFeel.h
    Created: 10 Aug 2022 9:48:34pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class ToggleImage;

//==============================================================================
/*
*/
class ToggleLookAndFeel  : public juce::LookAndFeel_V4
{
public:
    ToggleLookAndFeel();
    ToggleLookAndFeel(const char* toggleData, const int toggleDataSize, int toggleWidth, int toggleHeight);
    virtual ~ToggleLookAndFeel() override;

    void drawTickBox(juce::Graphics&, juce::Component&,
        float x, float y, float w, float h,
        bool ticked, bool isEnabled,
        bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;

    void setToggleImage(const char* toggleData, const int toggleDataSize, int toggleWidth, int toggleHeight);

    juce::Font getBaseFont();
    juce::Font getLabelFont(juce::Label&) override;
    juce::Font getSliderReadoutFont();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleLookAndFeel)
    std::unique_ptr<ToggleImage> toggleImage;
    juce::AffineTransform transform = juce::AffineTransform();
};