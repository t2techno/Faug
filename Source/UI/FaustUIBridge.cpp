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

void FaustUIBridge::addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
{
    addNormalComponent(label, zone, init, min, max, step);
}

void FaustUIBridge::addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
{
    addNormalComponent(label, zone, init, min, max, step);
    
}

void FaustUIBridge::addButton(const char* label, FAUSTFLOAT* zone)
{
    addNormalComponent(label, zone, 0.0, 0.0, 1.0, -1.0);
}

void FaustUIBridge::addCheckButton(const char* label, FAUSTFLOAT* zone)
{
    addNormalComponent(label, zone, 0.0, 0.0, 1.0, -1.0);
}

void FaustUIBridge::addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
{
    currentFreqZone = zone;
}

float FaustUIBridge::getCurrentFreq()
{
    return *currentFreqZone;
}

void FaustUIBridge::addNormalComponent(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
{
    if (!vts.getParameter(label))
    {
        // -1 is a button
        bool isDiscrete = (step*step == 1.0);
        bool isBoolean  = (step == -1.0);

        vts.createAndAddParameter(label, label, juce::String(),
            juce::NormalisableRange<float>(min, max), init, nullptr, nullptr,
            false,true, isDiscrete,juce::AudioProcessorParameter::Category::genericParameter, isBoolean);
    }

    juce::String stringLabel = juce::String(label);
    // Attach the listener to keep the internal dsp values up to date
    FaustUIBridgeListener* l = new FaustUIBridgeListener(zone);
    listeners.add(l);
    listenerAssignments.add(ParameterListenerPair(stringLabel, l));
    labels.add(stringLabel);
    vts.addParameterListener(stringLabel, l);
}