#pragma once

// Holds all the info for playing and making sound with the synth

#include <JuceHeader.h>

class MapUI;
class DspFaust;

class FaugAudioSource : public juce::AudioSource,
							   juce::MidiInputCallback,
					   private juce::MidiKeyboardStateListener 
{
	public:
		FaugAudioSource(juce::MidiKeyboardState& keyState);
		virtual ~FaugAudioSource() override;

		void setUsingSynthSound();

		void prepareToPlay(int /*samplesPerBlockExpected*/, double sampleRate) override;
		void releaseResources() override {};
		void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;

		juce::MidiMessageCollector* getMidiCollector();
		void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message) override; //MidiInputCallback
		void handleNoteOn(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override; //MidiKeyboardStateListener
		void handleNoteOff(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float /*velocity*/) override; //MidiKeyboardStateListener

	private:
		std::unique_ptr<DspFaust> mFaust;
		std::unique_ptr<MapUI> mUI;
		juce::MidiMessageCollector midiCollector;
		juce::Synthesiser synth;
		juce::MidiKeyboardState& keyboardState;
};