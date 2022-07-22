#pragma once

#include <JuceHeader.h>

struct FaustDspSound : public juce::SynthesiserSound
{
public:
    FaustDspSound() {}
    virtual ~FaustDspSound() {}

    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }
};