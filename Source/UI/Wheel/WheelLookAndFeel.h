/*
  ==============================================================================

    WheelLookAndFeel.h
    Created: 18 Nov 2022 11:12:01pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class WheelImage;

//==============================================================================
/*
*/
class WheelLookAndFeel : public juce::LookAndFeel_V4
{
public:
    WheelLookAndFeel();
    virtual ~WheelLookAndFeel() override;

    void setWheelImage(const char* wheelData, const int wheelDataSize, const int wheelWidth, const int wheelHeight);

    juce::Font getBaseFont();
    juce::Font getLabelFont(juce::Label&) override;
    juce::Font getSliderReadoutFont();

    void drawLabel(juce::Graphics&, juce::Label&) override;
    void drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height,
        float sliderPos, float minSliderPos, float maxSliderPos,
        const juce::Slider::SliderStyle, juce::Slider& s) override;

private:
    std::unique_ptr<WheelImage> wheelImage;
    juce::AffineTransform transform = juce::AffineTransform();
};
