/*
  ==============================================================================

    FaugLookAndFeel.h
    Created: 8 Aug 2022 11:55:23am
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class KnobImage;

//==============================================================================
/*
*/
class KnobLookAndFeel : public juce::LookAndFeel_V4
{
    public:
        KnobLookAndFeel();
        KnobLookAndFeel(juce::Image& knobImageIn, const int knobSize);
        virtual ~KnobLookAndFeel() override;

        juce::Font getBaseFont();
        juce::Font getLabelFont(juce::Label&) override;
        juce::Font getSliderReadoutFont();

        void drawLabel(juce::Graphics&,juce::Label&) override;
        void drawRotarySlider(juce::Graphics&, int x, int y, int width, int height,
            float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle,
            juce::Slider&) override;

        int knobSize;

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobLookAndFeel)
        std::unique_ptr<KnobImage> knobImage;
        juce::AffineTransform transform = juce::AffineTransform();
};
