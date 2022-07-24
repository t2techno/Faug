#pragma once

#include <JuceHeader.h>
#include "ParamsList.h"

class mydsp;
class MapUI;
class SyntheSynthesiserSound;

class FaustDspVoice : public juce::SynthesiserVoice {
public:
	FaustDspVoice();
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

private:
	std::unique_ptr<mydsp> mFaust;
	std::unique_ptr<MapUI> mUI;
	std::unique_ptr<int> currentPitch;
	float** outputs;
};