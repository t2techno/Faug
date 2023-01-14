/*
  ==============================================================================

    Toggle.h
    Created: 10 Aug 2022 9:48:06pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ToggleLookAndFeel.h"

typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;

//==============================================================================
/*
*/
class Toggle  : public juce::Component
{
public:
    Toggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, ToggleLookAndFeel& laf);
    virtual ~Toggle() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Toggle)
    std::unique_ptr<juce::ToggleButton> toggle;
    std::unique_ptr<ButtonAttachment>   attach;
};

class BigOrangeToggle : public Toggle
{
    public:
        BigOrangeToggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, ToggleLookAndFeel& laf) : Toggle(vts, paramId, laf){}
        virtual ~BigOrangeToggle() override {};
};


class OrangeToggle : public Toggle
{
    public:
        OrangeToggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, ToggleLookAndFeel& laf) : Toggle(vts, paramId, laf){}
        virtual ~OrangeToggle() override {};
};

class BlueToggle : public Toggle
{
    public:
        BlueToggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, ToggleLookAndFeel& laf) : Toggle(vts, paramId, laf){}
        virtual ~BlueToggle() override {};
};

class BrownToggle : public Toggle
{
    public:
        BrownToggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, ToggleLookAndFeel& laf) : Toggle(vts, paramId, laf){}
        virtual ~BrownToggle() override {};
};

class WhiteToggle : public Toggle
{
    public:
        WhiteToggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, ToggleLookAndFeel& laf) : Toggle(vts, paramId, laf){}
        virtual ~WhiteToggle() override {};
};