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
    Toggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int toggleWidth, int toggleHeight);
    virtual ~Toggle() override;

    void setLaf(ToggleLookAndFeel* laf);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Toggle)
    std::unique_ptr<juce::ToggleButton> toggle;
    std::unique_ptr<ButtonAttachment>   attach;
};

class BigOrangeToggle : public Toggle
{
    public:
        BigOrangeToggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int toggleWidth, int toggleHeight) : Toggle(vts, paramId, toggleWidth, toggleHeight)
        {
            toggleLaf->setToggleImage(BinaryData::orangeToggle_png, BinaryData::orangeToggle_pngSize, toggleWidth, toggleHeight);
            setLaf(toggleLaf.get());
        }
        virtual ~BigOrangeToggle() override {};

    private:
        static std::unique_ptr<ToggleLookAndFeel> toggleLaf;
};


class OrangeToggle : public Toggle
{
    public:
        OrangeToggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int toggleWidth, int toggleHeight) : Toggle(vts, paramId, toggleWidth, toggleHeight)
        {
            toggleLaf->setToggleImage(BinaryData::orangeToggle_png, BinaryData::orangeToggle_pngSize, toggleWidth, toggleHeight);
            setLaf(toggleLaf.get());
        }
        virtual ~OrangeToggle() override {};

    private:
        static std::unique_ptr<ToggleLookAndFeel> toggleLaf;
};

class BlueToggle : public Toggle
{
    public:
        BlueToggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int toggleWidth, int toggleHeight) : Toggle(vts, paramId, toggleWidth, toggleHeight)
        {
            toggleLaf->setToggleImage(BinaryData::blueToggle_png, BinaryData::blueToggle_pngSize, toggleWidth, toggleHeight);
            setLaf(toggleLaf.get());
        }
        virtual ~BlueToggle() override {};

    private:
        static std::unique_ptr<ToggleLookAndFeel> toggleLaf;
};

class BrownToggle : public Toggle
{
public:
    BrownToggle(juce::AudioProcessorValueTreeState& vts, juce::String paramId, int toggleWidth, int toggleHeight) : Toggle(vts, paramId, toggleWidth, toggleHeight)
    {
        toggleLaf->setToggleImage(BinaryData::brownToggle_png, BinaryData::brownToggle_pngSize, toggleWidth, toggleHeight);
        setLaf(toggleLaf.get());
    }
    virtual ~BrownToggle() override {};

private:
    static std::unique_ptr<ToggleLookAndFeel> toggleLaf;
};