/*
  ==============================================================================

    ToggleImage.cpp
    Created: 10 Aug 2022 9:49:01pm
    Author:  tytu1

  ==============================================================================
*/

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ToggleImage  : public juce::DrawableImage
{
public:
    ToggleImage(juce::Image& toggleImageIn, int toggleWidth, int toggleHeight)
    {
        setImage(toggleImageIn.rescaled(toggleWidth, toggleHeight));
        pivot_x = toggleWidth / 2;
        pivot_y = toggleHeight / 2;
    }

    ~ToggleImage() override
    {
    }

    int pivot_x;
    int pivot_y;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleImage)
    std::unique_ptr<juce::Image> toggleImage;
};
