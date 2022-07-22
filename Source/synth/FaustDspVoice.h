#pragma once

#include <JuceHeader.h>
#include "FaustDspSound.cpp"
#include "ParamsList.h"

class DspFaust;

class FaustDspVoice : public juce::SynthesiserVoice {
public:
	FaustDspVoice(DspFaust* faust);
	virtual ~FaustDspVoice() override;

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

private:
	DspFaust* mFaust;
	std::unique_ptr<float> level;
	std::unique_ptr<int> currentPitch;
};