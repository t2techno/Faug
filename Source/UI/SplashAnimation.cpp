/*
  ==============================================================================

    SplashAnimation.cpp
    Created: 4 Aug 2022 10:03:17pm
    Author:  tytu1

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SplashAnimation.h"

//==============================================================================
SplashAnimation::SplashAnimation(const juce::String& title, int width, int height, bool useDropShadow) :
    juce::SplashScreen(title, width, height, useDropShadow)
{
    juce::AnimatedAppComponent::setSize(width, height);
    juce::AnimatedAppComponent::setFramesPerSecond(60);
    loadingCoin = juce::Drawable::createFromImageData(BinaryData::loadingCoin_png, BinaryData::loadingCoin_pngSize);
    coinWidth = 100;
    coinHeight = 100;
}

SplashAnimation::~SplashAnimation()
{
}

void SplashAnimation::paint (juce::Graphics& g)
{
    g.setColour(juce::AnimatedAppComponent::getLookAndFeel().findColour(juce::Slider::thumbColourId));

    auto fishLength = 15;

    juce::Path spinePath;

    if (loadingCoin != 0)
    {
        loadingCoin->drawWithin(g, juce::Rectangle<float>(getFrameCounter()%300, getFrameCounter()%300, 720, 720),
            juce::RectanglePlacement::stretchToFit, 1.000f);
    }

    for (auto i = 0; i < fishLength; ++i)
    {
        int radius = 150;

        juce::Point<float> p(juce::AnimatedAppComponent::getWidth() / 2.0f + 1.0f * radius * std::sin(getFrameCounter() * 0.04f + i * 0.12f),
            juce::AnimatedAppComponent::getHeight() / 2.0f + 1.0f * radius * std::cos(getFrameCounter() * 0.04f + i * 0.12f));

        // draw the circles along the fish
        g.fillEllipse(p.x - i, p.y - i, 2.0f + 2.0f * i, 2.0f + 2.0f * i); // [1]

        if (i == 0)
            spinePath.startNewSubPath(p);  // if this is the first point, start a new path..
        else
            spinePath.lineTo(p);           // ...otherwise add the next point
    }


    // draw an outline around the path that we have created
    g.strokePath(spinePath, juce::PathStrokeType(4.0f));
}

void SplashAnimation::update()
{
    juce::SplashScreen::repaint();
}

void SplashAnimation::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
