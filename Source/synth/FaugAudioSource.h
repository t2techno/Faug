#pragma once

// Holds all the info for playing and making sound with the synth

#include <JuceHeader.h>

class FaustDspVoice;

class FaugAudioSource : public juce::AudioSource,
							   juce::MidiInputCallback,
					   private juce::MidiKeyboardStateListener 
{
	public:
		FaugAudioSource(juce::MidiKeyboardState& keyState, juce::AudioProcessorValueTreeState& vts);
		virtual ~FaugAudioSource() override;

		void setUsingSynthSound();

		void prepareToPlay(int /*samplesPerBlockExpected*/, double sampleRate) override;
		void releaseResources() override;
		void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;

		juce::MidiMessageCollector* getMidiCollector();
		void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message) override; //MidiInputCallback
		void handleNoteOn(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override; //MidiKeyboardStateListener
		void handleNoteOff(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float /*velocity*/) override; //MidiKeyboardStateListener

	private:
		juce::MidiMessageCollector midiCollector;
		juce::Synthesiser synth;
		std::unique_ptr<FaustDspVoice> mVoice;
		juce::MidiKeyboardState& keyboardState;
};