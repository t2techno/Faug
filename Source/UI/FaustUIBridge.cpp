#include "FaustUIBridge.h"

FaustUIBridge::FaustUIBridge(juce::AudioProcessorValueTreeState& valueTreeState) : vts(valueTreeState), 
                                                                                   listenerAssignments(),
                                                                                   listeners(),
                                                                                   labels()
{
}

FaustUIBridge::~FaustUIBridge()
{
    for (int i = 0; i < listenerAssignments.size(); ++i)
    {
        ParameterListenerPair p = listenerAssignments.getUnchecked(i);
        juce::String paramId = p.paramId;
        FaustUIBridgeListener* listener = p.listener;
        vts.removeParameterListener(paramId, listener);
    }
    labels.clear();
    listenerAssignments.clear();
}

void FaustUIBridge::addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
{
    // Create the AudioProcessor parameter if not exists
    // Attach the listener to keep the internal dsp values up to date
    addNormalComponent(label, zone);
    
}

void FaustUIBridge::addButton(const char* label, FAUSTFLOAT* zone)
{
    addNormalComponent(label, zone);
}

void FaustUIBridge::addCheckButton(const char* label, FAUSTFLOAT* zone)
{
    // Create the AudioProcessor parameter if not exists
    addNormalComponent(label, zone);
}

void FaustUIBridge::addNormalComponent(const char* label, FAUSTFLOAT* zone)
{
    juce::String stringLabel = juce::String(label);
    if (vts.getParameter(stringLabel))
    {
        // Attach the listener to keep the internal dsp values up to date

        FaustUIBridgeListener* l = new FaustUIBridgeListener(zone);
        listeners.add(l);
        listenerAssignments.add(ParameterListenerPair(stringLabel, l));
        labels.add(stringLabel);
        vts.addParameterListener(stringLabel, l);
    }
}