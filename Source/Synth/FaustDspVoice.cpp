#include "FaustDspSound.cpp"
#include "FaustDspVoice.h"
#include "../FaustExp/FaugExp.cpp"

FaustDspVoice::FaustDspVoice(juce::AudioProcessorValueTreeState& valueTreeState, mydsp& faustDsp) : vts(valueTreeState), 
																									currentFreq(0.f), 
																									mFaust(faustDsp),
																									outputs(new float* [2])
{

}
FaustDspVoice::~FaustDspVoice(){}

void FaustDspVoice::prepareToPlay(int sampleRate, int samplesPerBlock) 
{
	for (int channel = 0; channel < 2; ++channel) {
		outputs[channel] = new float[samplesPerBlock];
	}
}

void FaustDspVoice::releaseResources()
{
	
}

bool FaustDspVoice::canPlaySound(juce::SynthesiserSound* sound)
{
	return dynamic_cast<FaustDspSound*> (sound) != nullptr;
}

void FaustDspVoice::startNote(int midiNoteNumber, float velocity,
	juce::SynthesiserSound*, int /*currentPitchWheelPosition*/)
{
	currentFreq = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    keyOn();
}

void FaustDspVoice::stopNote(float /*velocity*/, bool allowTailOff)
{
    keyOff();
	if (!allowTailOff)
	{
		clearCurrentNote();
	}
}

void FaustDspVoice::renderNextBlock(juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
	mFaust.compute(outputBuffer.getNumSamples(), NULL, outputs);
	for (int i = 0; i < outputBuffer.getNumSamples(); i++) {
		*outputBuffer.getWritePointer(0, i) = outputs[0][i]; // left
		*outputBuffer.getWritePointer(1, i) = outputs[1][i]; // right
	}
}

void FaustDspVoice::pitchWheelMoved(int newPitchWheelValue){}
void FaustDspVoice::controllerMoved(int controllerNumber, int newControllerValue){}

void FaustDspVoice::keyOn() {
	setFreq();
	setGate(true);
}

void FaustDspVoice::keyOff() {
	setGate(false);
}

void FaustDspVoice::setGate(bool on)
{
	vts.getParameterAsValue(GATE).setValue(on);
}

void FaustDspVoice::setFreq() {
	vts.getParameterAsValue(FREQ).setValue(currentFreq);
}