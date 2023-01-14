#pragma once

#include <JuceHeader.h>
#include "../Constants.h"

class mydsp;

class FaustDspVoice : public juce::SynthesiserVoice {
public:
	FaustDspVoice(juce::AudioProcessorValueTreeState& valueTreeState, mydsp& faustDsp);
	virtual ~FaustDspVoice() override;

	void prepareToPlay(int sampleRate, int samplesPerBlock);
	void releaseResources();

	bool canPlaySound(juce::SynthesiserSound* sound) override;

	void startNote(int midiNoteNumber, float velocity,
		juce::SynthesiserSound*, int /*currentPitchWheelPosition*/) override;
	void stopNote(float /*velocity*/, bool allowTailOff) override;
	void pitchWheelMoved(int newPitchWheelValue) override;
	void controllerMoved(int controllerNumber, int newControllerValue) override;
	void renderNextBlock(juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;

	void keyOn();
	void keyOff();
	void setGate(bool on);
	void setFreq();

	int currentFreq;

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FaustDspVoice)
	juce::AudioProcessorValueTreeState& vts;
	mydsp& mFaust;

	float** outputs;
};