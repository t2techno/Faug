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
        vts.addParameterListener(stringLabel, l);
    }
}

void FaustUIBridge::addButton(const char* label, FAUSTFLOAT* zone)
{
    juce::String stringLabel = juce::String(label);
    FaustUIBridgeListener* l = new FaustUIBridgeListener(zone);
    if (!labels.contains(stringLabel))
    {
        listenerAssignments.set(stringLabel, l);
        labels.add(stringLabel);
    }
    else
    {
        // Should be the only param this happens with
        listenerAssignments.set(juce::String("fGate"), l);
    }
    vts.addParameterListener(stringLabel, l);
}