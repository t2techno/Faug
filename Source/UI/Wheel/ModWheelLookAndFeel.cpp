/*
  ==============================================================================

    WheelLookAndFeel.cpp
    Created: 18 Nov 2022 11:12:01pm
    Author:  tytu1

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ModWheelLookAndFeel.h"
#include "ModWheelImage.h"
//==============================================================================
ModWheelLookAndFeel::ModWheelLookAndFeel()
{
}

ModWheelLookAndFeel::~ModWheelLookAndFeel()
{}

void ModWheelLookAndFeel::setWheelImages(const char* wheelData, const int wheelDataSize, 
                                         const char* wheelShadingData, const int wheelShadingDataSize,
                                         const int wheelWidth, const int wheelHeight){
    wheelImage   = std::make_unique<ModWheelImage>(wheelData, wheelDataSize, wheelWidth, wheelHeight);

    juce::Image tempImage = juce::ImageFileFormat::loadFrom(wheelShadingData, wheelShadingDataSize);
    wheelShading = std::make_unique<juce::Image>(tempImage.rescaled(wheelWidth, wheelHeight));
}

juce::Font ModWheelLookAndFeel::getBaseFont()
{
    return juce::Font::bold;
}

juce::Font ModWheelLookAndFeel::getLabelFont(juce::Label&)
{
    return getBaseFont().withPointHeight(10);
}

juce::Font ModWheelLookAndFeel::getSliderReadoutFont()
{
    return getBaseFont().withPointHeight(14);
}

void ModWheelLookAndFeel::drawLabel(juce::Graphics& g, juce::Label& l)
{
    juce::Colour labelColour = juce::Colour::fromRGB(149, 89, 17);
    juce::Font labelFont = getLabelFont(l);

    g.setColour(labelColour);
    g.setFont(labelFont);

    juce::Rectangle<int> textArea(l.getBorderSize().subtractedFrom(l.getLocalBounds()));

    g.drawFittedText(l.getText(), textArea, l.getJustificationType(),
        juce::jmax(1, (int)(textArea.getHeight() / labelFont.getHeight())),
        l.getMinimumHorizontalScale());
}

void ModWheelLookAndFeel::drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height,
    float sliderPos, float minSliderPos, float maxSliderPos,
    const juce::Slider::SliderStyle sliderStyle, juce::Slider& slider)
{
    const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();
    //wheelImage->setTransform(transform.translation(0, sliderPos - maxSliderPos));
    g.drawImageAt(wheelImage->getImage(), 0, sliderPos-wheelImage.get()->pivotPoint, false);
    g.drawImageAt(*wheelShading.get(), 0, 0, false);


    // Draw the readout
    // Change this to hint box?    


    /*juce::Colour readoutColour = juce::Colour::fromRGB(254, 173, 29).withAlpha(isMouseOver ? 1.0f : 0.9f);
    const double value = slider.getValue();
    juce::String readoutValue = (value >= 1000.0 ? juce::String(value / 1000.0, 1) + "k" : juce::String(value, 2));
    juce::String readout = readoutValue;

    g.setColour(readoutColour);
    g.setFont(getSliderReadoutFont());
    g.drawText(readout, centreX - radius, centreY - 10.0f, rw, 24.0f, juce::Justification::centred);*/

    // Draw the track
    g.setColour(slider.findColour(juce::Slider::rotarySliderOutlineColourId));
}