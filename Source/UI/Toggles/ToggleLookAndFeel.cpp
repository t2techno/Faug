/*
  ==============================================================================

    ToggleLookAndFeel.cpp
    Created: 10 Aug 2022 9:48:34pm
    Author:  tytu1

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ToggleLookAndFeel.h"
#include "ToggleImage.h"

//==============================================================================

ToggleLookAndFeel::ToggleLookAndFeel()
{}

ToggleLookAndFeel::ToggleLookAndFeel(const char* toggleData, const int toggleDataSize, const int toggleSize)
{
    setToggleImage(toggleData, toggleDataSize, toggleSize);
}

ToggleLookAndFeel::~ToggleLookAndFeel()
{
}

void ToggleLookAndFeel::setToggleImage(const char* toggleData, const int toggleDataSize, const int toggleSize)
{
    toggleImage = std::make_unique<ToggleImage>(toggleData, toggleDataSize, toggleSize);
}