// Holds all the info for playing and making sound with the synth

#include "FaugAudioSource.h"
#include "FaustDspSound.cpp"
#include "FaustDspVoice.h"
#include "../faustExp/DspFaust.cpp"

FaugAudioSource::FaugAudioSource(juce::MidiKeyboardState& keyState)
    : keyboardState(keyState)
{
    // This is a mono-synth, only one voice needed
    mFaust = std::make_unique<DspFaust>();
    synth.addVoice(new FaustDspVoice(mFaust.get()));
    synth.addSound(new FaustDspSound());
    keyboardState.addListener(this);
}

FaugAudioSource::~FaugAudioSource()
{
    mFaust->stop();
    mFaust.reset();
    mUI.reset();
}

void FaugAudioSource::setUsingSynthSound()
{
    synth.clearSounds();
}

void FaugAudioSource::prepareToPlay(int /*samplesPerBlockExpected*/, double sampleRate)
{
    mUI = std::make_unique<MapUI>();
    mFaust->buildUserInterface(mUI.get());
    mFaust->start();
    synth.setCurrentPlaybackSampleRate(sampleRate);
    midiCollector.reset(sampleRate);
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
    DBG("Collecting midi event");
    midiCollector.addMessageToQueue(message);
    keyboardState.processNextMidiEvent(message);
}

void FaugAudioSource::handleNoteOn(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity)
{
    DBG("Handle note on");
    synth.noteOn(midiChannel, midiNoteNumber, velocity);
}

void FaugAudioSource::handleNoteOff(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float /*velocity*/)
{
    DBG("Handle note off");
    synth.noteOff(midiChannel, midiNoteNumber, 0, true);
}