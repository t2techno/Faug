/*
  ==============================================================================

    SplashAnimation.h
    Created: 4 Aug 2022 10:03:17pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class SplashAnimation  : public juce::SplashScreen,
                         private juce::AnimatedAppComponent
{
public:
    SplashAnimation(const juce::String& title, int width, int height, bool useDropShadow);
    virtual ~SplashAnimation() override;
    
    virtual void update() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplashAnimation)

    juce::Path spinePath;
    int coinWidth;
    int coinHeight;
};
