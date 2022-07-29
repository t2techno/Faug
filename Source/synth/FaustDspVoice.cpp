#include "../Source/faustExp/DspFaust.cpp"
#include "FaustDspSound.cpp"
#include "FaustDspVoice.h"
#include "../UI/FaustUIBridge.h"

FaustDspVoice::FaustDspVoice(juce::AudioProcessorValueTreeState& valueTreeState) : vts(valueTreeState)
{
    currentPitch = std::make_unique<int>();
}
FaustDspVoice::~FaustDspVoice(){}

void FaustDspVoice::prepareToPlay(int sampleRate, int samplesPerBlock) {
	mBridge = std::make_unique<FaustUIBridge>(vts);
	mFaust = std::make_unique<mydsp>();
	mFaust->init(sampleRate);
	mFaust->buildUserInterface(mBridge.get());

	outputs = new float* [2];
	for (int channel = 0; channel < 2; ++channel) {
		outputs[channel] = new float[samplesPerBlock];
	}
}

void FaustDspVoice::releaseResources()
{
	mFaust.reset();
	mBridge.reset();
	for (int channel = 0; channel < 2; ++channel) {
		delete outputs[channel];
	}
	delete[] outputs;
}

bool FaustDspVoice::canPlaySound(juce::SynthesiserSound* sound)
{
	return dynamic_cast<FaustDspSound*> (sound) != nullptr;
}

void FaustDspVoice::startNote(int midiNoteNumber, float velocity,
	juce::SynthesiserSound*, int /*currentPitchWheelPosition*/)
{
    *currentPitch = midiNoteNumber;
    keyOn();
}

void FaustDspVoice::stopNote(float /*velocity*/, bool allowTailOff)
{
    *currentPitch = 0;
    keyOff();
	if (!allowTailOff)
	{
		clearCurrentNote();
	}
}

void FaustDspVoice::renderNextBlock(juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
	mFaust->compute(outputBuffer.getNumSamples(), NULL, outputs);

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
    *currentPitch = 0;
}

void FaustDspVoice::setGate(bool on)
{
	vts.getParameterAsValue(GATE).setValue(on);
}

void FaustDspVoice::setFreq() {
    double freq = juce::MidiMessage::getMidiNoteInHertz(*currentPitch);
	vts.getParameterAsValue(FREQ).setValue(freq);
}