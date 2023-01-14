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
    ModWheelLookAndFeel(juce::Image& wheelImage, juce::Image& wheelShading,
                        const int wheelWidth, const int wheelHeight);
    virtual ~ModWheelLookAndFeel() override;

    juce::Font getBaseFont();
    juce::Font getLabelFont(juce::Label&) override;
    juce::Font getSliderReadoutFont();

    void drawLabel(juce::Graphics&, juce::Label&) override;
    void drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height,
        float sliderPos, float minSliderPos, float maxSliderPos,
        const juce::Slider::SliderStyle sliderStyle, juce::Slider& slider) override;

    int wheelWidth;
    int wheelHeight;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModWheelLookAndFeel)
    std::unique_ptr<ModWheelImage> wheelImage;
    std::unique_ptr<juce::Image> wheelShading;
    juce::AffineTransform transform = juce::AffineTransform();
};
