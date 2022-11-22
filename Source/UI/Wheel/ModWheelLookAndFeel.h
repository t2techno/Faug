/*
  ==============================================================================

    WheelLookAndFeel.h
    Created: 18 Nov 2022 11:12:01pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class ModWheelImage;

//==============================================================================
/*
*/
class ModWheelLookAndFeel : public juce::LookAndFeel_V4
{
public:
    ModWheelLookAndFeel();
    virtual ~ModWheelLookAndFeel() override;

    void setWheelImage(const char* wheelData, const int wheelDataSize, const int wheelWidth, const int wheelHeight);

    juce::Font getBaseFont();
    juce::Font getLabelFont(juce::Label&) override;
    juce::Font getSliderReadoutFont();

    void drawLabel(juce::Graphics&, juce::Label&) override;
    void drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height,
        float sliderPos, float minSliderPos, float maxSliderPos,
        const juce::Slider::SliderStyle sliderStyle, juce::Slider& slider) override;

    void drawLinearSliderBackground(juce::Graphics& g,
        int x, int y, int width, int height,
        float sliderPos, float minSliderPos, float maxSliderPos,
        const juce::Slider::SliderStyle sliderStyle, juce::Slider& slider) override;

    void drawLinearSliderThumb(juce::Graphics& g,
        int x, int y, int width, int height,
        float sliderPos, float minSliderPos, float maxSliderPos,
        const juce::Slider::SliderStyle sliderStyle, juce::Slider& slider) override;


private:
    std::unique_ptr<ModWheelImage> wheelImage;
    juce::AffineTransform transform = juce::AffineTransform();
};
