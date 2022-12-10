#include <JuceHeader.h>

struct FaustDspSound : public juce::SynthesiserSound
{
public:
    FaustDspSound() {}
    virtual ~FaustDspSound() override {}

    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }
};