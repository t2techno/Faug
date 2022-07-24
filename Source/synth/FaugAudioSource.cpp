// Holds all the info for playing and making sound with the synth

#include "FaugAudioSource.h"
#include "FaustDspSound.cpp"
#include "FaustDspVoice.h"

FaugAudioSource::FaugAudioSource(juce::MidiKeyboardState& keyState)
    : keyboardState(keyState)
{
    // This is a mono-synth, only one voice needed
    mVoice = std::make_unique<FaustDspVoice>();
    synth.addVoice(mVoice.get());
    synth.addSound(new FaustDspSound());
    keyboardState.addListener(this);
}

FaugAudioSource::~FaugAudioSource()
{
}

void FaugAudioSource::setUsingSynthSound()
{
    synth.clearSounds();
}

void FaugAudioSource::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    mVoice->prepareToPlay(sampleRate, samplesPerBlockExpected);
    synth.setCurrentPlaybackSampleRate(sampleRate);
    midiCollector.reset(sampleRate);
}

void FaugAudioSource::releaseResources() {
    mVoice->releaseResources();
}

void FaugAudioSource::getNextAudioBlock(const juce::AudioSourceChannelInfo & bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
    juce::MidiBuffer incomingMidi;
    midiCollector.removeNextBlockOfMessages(incomingMidi, bufferToFill.numSamples);

    keyboardState.processNextMidiBuffer(incomingMidi, bufferToFill.startSample,
        bufferToFill.numSamples, true);

    synth.renderNextBlock(*bufferToFill.buffer, incomingMidi,
        bufferToFill.startSample, bufferToFill.numSamples);
}

juce::MidiMessageCollector* FaugAudioSource::getMidiCollector()
{
    return &midiCollector;
}

void FaugAudioSource::handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message)
{
    midiCollector.addMessageToQueue(message);
    keyboardState.processNextMidiEvent(message);
}

void FaugAudioSource::handleNoteOn(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity)
{
    synth.noteOn(midiChannel, midiNoteNumber, velocity);
}

void FaugAudioSource::handleNoteOff(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float /*velocity*/)
{
    synth.noteOff(midiChannel, midiNoteNumber, 0, false);
}