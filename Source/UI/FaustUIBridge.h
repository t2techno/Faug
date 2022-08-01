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
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override {};

        //==============================================================================
        /** Passive Widgets
            The following methods implement the passive widget functions.
            Again, because we intend for an AudioProcessorEditor to manage the
            visual aspect of the plugin, these methods are no-ops.
        */
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override {};
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override {};

        // -- soundfiles

        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) override {};

        void addNormalComponent(const char* label, FAUSTFLOAT* zone);

        //==============================================================================
        /** Metadata declarations
            An additional no-op to implement the last piece of the Faust UI interface.
        */
        virtual void declare(FAUSTFLOAT*, const char*, const char*) override {};

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
    juce::AudioProcessorValueTreeState& vts;
    juce::Array<juce::String> labels;
    juce::HashMap<juce::String, FaustUIBridgeListener*> listenerAssignments;
};