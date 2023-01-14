#pragma once

#include <JuceHeader.h>
#include "../FaustInclude/UI.h"

//==============================================================================
/**
 This class interfaces with the Faust UI paradigm, mapping control parameters
 into AudioProcessorParameters on a provided AudioProcessorValueTreeState.
 */
class  FaustUIBridge : public UI
{
    
    public:
        FaustUIBridge(juce::AudioProcessorValueTreeState& valueTreeState);
        virtual ~FaustUIBridge() override;

        //==============================================================================
        /** Widget Layout
            The following methods implement the widget layout functions.
            Because we intend for an AudioProcessorEditor to manage the
            visual aspect of the plugin, these methods are no-ops.
        */
        virtual void openTabBox(const char* label) override {};
        virtual void openHorizontalBox(const char* label) override {};
        virtual void openVerticalBox(const char* label) override {};
        virtual void closeBox() override {};

        //==============================================================================
        /** Active Widgets
            The following methods implement the active widget functions
            by constructing an AudioProcessorParameter and installing a
            FaustUIBridgeListener to propagate changes back to the corresponding
            zone.
        */
        virtual void addButton(const char* label, FAUSTFLOAT* zone) override;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) override;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override {};
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override;

        //==============================================================================
        /** Passive Widgets
            The following methods implement the passive widget functions.
            Again, because we intend for an AudioProcessorEditor to manage the
            visual aspect of the plugin, these methods are no-ops.
        */
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override {};
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override;

        // -- soundfiles

        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) override {};

        void addNormalComponent(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, juce::NormalisableRange<float> range, bool isDiscrete, bool isBoolean);

        //==============================================================================
        /** Metadata declarations
            An additional no-op to implement the last piece of the Faust UI interface.
        */
        virtual void declare(FAUSTFLOAT*, const char*, const char*) override {};

        float getCurrentFreq();

        class FaustUIBridgeListener : public juce::AudioProcessorValueTreeState::Listener
        {
        public:
            FaustUIBridgeListener(float* zone) : m_zone(zone) {};
            virtual ~FaustUIBridgeListener() override {};

            virtual void parameterChanged(const juce::String& parameterID, float newValue) override
            {
                *m_zone = newValue;
            };

        private:
            float* m_zone;
        };


private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FaustUIBridge)
    juce::AudioProcessorValueTreeState& vts;
    juce::Array<juce::String> labels;
    float* currentFreqZone;

    struct ParameterListenerPair
    {
        //==============================================================================
        /** Constructor.
         @param paramId        The String Id of the AudioProcessorParameter.
         @param listener       The attached FaustUIBridgeListener.
         */
        ParameterListenerPair(juce::String paramId, FaustUIBridgeListener * listener)
        : paramId(paramId), listener(listener) {};

        juce::String paramId;
        FaustUIBridgeListener* listener;
    };
    // Maintain an array associating AudioProcessorParameters to the Listeners that have been
    // installed on those parameters.
   juce::Array<ParameterListenerPair> listenerAssignments;

    // And an array of listeners to ensure the mapping between internal value tree values
    // match the float* zone members of the faust implementation.
    juce::OwnedArray<juce::AudioProcessorValueTreeState::Listener> listeners;
};