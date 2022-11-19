/*
  ==============================================================================

    WheelLookAndFeel.cpp
    Created: 18 Nov 2022 11:12:01pm
    Author:  tytu1

  ==============================================================================
*/

#include <JuceHeader.h>
#include "WheelLookAndFeel.h"
#include "WheelImage.h"
//==============================================================================
WheelLookAndFeel::WheelLookAndFeel()
{
}

WheelLookAndFeel::~WheelLookAndFeel()
{}

void WheelLookAndFeel::setWheelImage(const char* wheelData, const int wheelDataSize, const int wheelWidth, const int wheelHeight){
    wheelImage = std::make_unique<WheelImage>(wheelData, wheelDataSize, wheelWidth, wheelHeight);
}

juce::Font WheelLookAndFeel::getBaseFont()
{
    return juce::Font::bold;
}

juce::Font WheelLookAndFeel::getLabelFont(juce::Label&)
{
    return getBaseFont().withPointHeight(10);
}

juce::Font WheelLookAndFeel::getSliderReadoutFont()
{
    return getBaseFont().withPointHeight(14);
}

void WheelLookAndFeel::drawLabel(juce::Graphics& g, juce::Label& l)
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

void WheelLookAndFeel::drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
    const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider& slider)
{
    const float radius = juce::jmin(width / 2, height / 2) - 2.0f;
    const float centreX = x + width * 0.5f;
    const float centreY = y + height * 0.5f;
    const float rx = centreX - radius;
    const float ry = centreY - radius;
    const float rw = radius * 2.0f;
    const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();

    // Draw the readout
    // Change this to hint box?    
    g.drawImageTransformed(wheelImage->getImage(), transform.rotation(angle, wheelImage->pivotPoint, wheelImage->pivotPoint));


    juce::Colour readoutColour = juce::Colour::fromRGB(254, 173, 29).withAlpha(isMouseOver ? 1.0f : 0.9f);
    const double value = slider.getValue();
    juce::String readoutValue = (value >= 1000.0 ? juce::String(value / 1000.0, 1) + "k" : juce::String(value, 2));
    juce::String readout = readoutValue;

    g.setColour(readoutColour);
    g.setFont(getSliderReadoutFont());
    g.drawText(readout, centreX - radius, centreY - 10.0f, rw, 24.0f, juce::Justification::centred);

    // Draw the track
    g.setColour(slider.findColour(juce::Slider::rotarySliderOutlineColourId));
}
