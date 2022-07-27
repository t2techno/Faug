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
    if (vts.getParameter(label)) {
        // Attach the listener to keep the internal dsp values up to date
        FaustUIBridgeListener* l = new FaustUIBridgeListener(zone);
        listeners.add(l);
        listenerAssignments.add(ParamListenerPair(juce::String(label), l));
        vts.addParameterListener(label, l);
    }
}