#include "FaustUIBridge.h"

FaustUIBridge::FaustUIBridge(juce::AudioProcessorValueTreeState& valueTreeState) : vts(valueTreeState)
{
}

FaustUIBridge::~FaustUIBridge()
{
}

void FaustUIBridge::addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
{
    // Create the AudioProcessor parameter if not exists
    juce::String stringLabel = juce::String(label);
    if (vts.getParameter(stringLabel)) 
    {
        // Attach the listener to keep the internal dsp values up to date
        FaustUIBridgeListener* l = new FaustUIBridgeListener(zone);
        labels.add(stringLabel);

        // There are two gates, one for envelope and one for filter
        // Envelope is first, each has a different listener based on zone
        // but since they have the same label, they'll be attached to the same vts param
        if (!labels.contains(stringLabel)) 
        {
            listenerAssignments.set(stringLabel, l);
        }
        else 
        {
            // Should be the only param this happens with
            listenerAssignments.set(juce::String("fGate"), l);
        }
        vts.addParameterListener(stringLabel, l);
    }
}