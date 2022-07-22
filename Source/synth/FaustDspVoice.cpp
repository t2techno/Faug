#include "../Source/faustExp/DspFaust.h"
#include "FaustDspVoice.h"

FaustDspVoice::FaustDspVoice(DspFaust* faust)
{
	mFaust = faust;
	level = std::make_unique<float>();
	*level = 0.0;
    currentPitch = std::make_unique<int>();

}
FaustDspVoice::~FaustDspVoice(){}

bool FaustDspVoice::canPlaySound(juce::SynthesiserSound* sound)
{
	return dynamic_cast<FaustDspSound*> (sound) != nullptr;
}

void FaustDspVoice::startNote(int midiNoteNumber, float velocity,
	juce::SynthesiserSound*, int /*currentPitchWheelPosition*/)
{
    *currentPitch = midiNoteNumber;
    *level = .15f * velocity;
    keyOn();
}

void FaustDspVoice::stopNote(float /*velocity*/, bool allowTailOff)
{
    *currentPitch = 0;
    keyOff();
}

void FaustDspVoice::renderNextBlock(juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
	// This is all handled inside the faust dsp object
}

void FaustDspVoice::pitchWheelMoved(int newPitchWheelValue){}
void FaustDspVoice::controllerMoved(int controllerNumber, int newControllerValue){}

void FaustDspVoice::keyOn() {
	setGate(true);
	setFreq();
	
}

void FaustDspVoice::keyOff() {
	setGate(false);
    *level = 0;
    *currentPitch = 0;
}

void FaustDspVoice::setGate(bool on) 
{
	if (on) {
		mFaust->setParamValue(GATE, 1);
		mFaust->setParamValue(F_ENV_GATE, 1);
	}
	else {
		mFaust->setParamValue(GATE, 0);
		mFaust->setParamValue(F_ENV_GATE, 0);
	}

}

void FaustDspVoice::setFreq() {
    double freq = juce::MidiMessage::getMidiNoteInHertz(*currentPitch);
	mFaust->setParamValue(OSC1_FREQ, freq);
	mFaust->setParamValue(OSC2_FREQ, freq);
	mFaust->setParamValue(OSC3_FREQ, freq);
}