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
    ToggleLookAndFeel(const char* toggleData, const int toggleDataSize, const int toggleSize);
    ~ToggleLookAndFeel() override;

    void setToggleImage(const char* toggleData, const int toggleDataSize, const int toggleSize);

    juce::Font getBaseFont();
    juce::Font getLabelFont(juce::Label&) override;
    juce::Font getSliderReadoutFont();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleLookAndFeel)
    std::unique_ptr<ToggleImage> toggleImage;
};
