#include "FaustUIBridge.h"

FaustUIBridge::FaustUIBridge(juce::AudioProcessorValueTreeState& valueTreeState) : vts(valueTreeState), 
                                                                                   listenerAssignments(),
                                                                                   listeners(),
                                                                                   labels(),
                                                                                   currentFreqZone(new float(0))
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

// freq and prevFreq
void FaustUIBridge::addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
{
    addNormalComponent(label, zone, init, juce::NormalisableRange<float>(min,max), false, false);
}

void FaustUIBridge::addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
{
    juce::NormalisableRange<float> range;
    float skew;
    //time labels are skewed so low values are a larger percent of knob range
    if (label == std::string("glide")) 
    {
        skew = 0.5;
    }
    else
    {
        skew = 1.0;
    }
    range = juce::NormalisableRange<float>(min, max, abs(step), skew);
    addNormalComponent(label, zone, init, range, (step==1.0), false);
}

void FaustUIBridge::addButton(const char* label, FAUSTFLOAT* zone)
{
    addNormalComponent(label, zone, 0.0, juce::NormalisableRange<float>(0.0, 1.0, 1.0), true, true);
}

void FaustUIBridge::addCheckButton(const char* label, FAUSTFLOAT* zone)
{
    addNormalComponent(label, zone, 0.0, juce::NormalisableRange<float>(0.0, 1.0, 1.0), true, true);
}


// Exposing final frequency calculation in faust code for glide
void FaustUIBridge::addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
{
    currentFreqZone = zone;
}

float FaustUIBridge::getCurrentFreq()
{
    return *currentFreqZone;
}

void FaustUIBridge::addNormalComponent(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, juce::NormalisableRange<float> range, bool isDiscrete, bool isBoolean)
{
    if (!vts.getParameter(label))
    {
        vts.createAndAddParameter(label, label, juce::String(),
            range, init, nullptr, nullptr,
            false, true, isDiscrete, juce::AudioProcessorParameter::Category::genericParameter, isBoolean);
    }

    juce::String stringLabel = juce::String(label);
    // Attach the listener to keep the internal dsp values up to date
    FaustUIBridgeListener* l = new FaustUIBridgeListener(zone);
    listeners.add(l);
    listenerAssignments.add(ParameterListenerPair(stringLabel, l));
    labels.add(stringLabel);
    vts.addParameterListener(stringLabel, l);
}