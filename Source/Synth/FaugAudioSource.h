#pragma once

// Holds all the info for playing and making sound with the synth

#include <JuceHeader.h>
class mydsp;
class FaustUIBridge;
class FaustDspVoice;


class FaugAudioSource : public juce::AudioSource,
							   juce::MidiInputCallback,
					   private juce::MidiKeyboardStateListener 
{
	public:
		FaugAudioSource(juce::MidiKeyboardState& keyState, juce::AudioProcessorValueTreeState& vts,
			FaustUIBridge& fBridge, mydsp& fDsp);
		virtual ~FaugAudioSource() override;

		void setUsingSynthSound();

		void prepareToPlay(int /*samplesPerBlockExpected*/, double sampleRate) override;
		void releaseResources() override;
		void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;

		juce::MidiMessageCollector* getMidiCollector();
		void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message) override; //MidiInputCallback
		void handleNoteOn(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override; //MidiKeyboardStateListener
		void handleNoteOff(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float /*velocity*/) override; //MidiKeyboardStateListener

		static const int noteMemory = 10;

	private:
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FaugAudioSource)
		juce::MidiMessageCollector midiCollector;
		juce::Synthesiser synth;
		juce::MidiKeyboardState& keyboardState;
		mydsp& mFaust;
		FaustUIBridge& mBridge;
		juce::AudioProcessorValueTreeState& mVts;

		int currentNote;
		int prevNote;
		int numHeldNotes;
		std::array<int, noteMemory> heldNotes;
};