// Holds all the info for playing and making sound with the synth
// Add legato button
// Need Last, Low, and High Note priorities

#include "FaugAudioSource.h"
#include "FaustDspSound.cpp"
#include "../UI/FaustUIBridge.h"
#include "FaustDspVoice.h"
#include "../FaustExp/FaugExp.cpp"

FaugAudioSource::FaugAudioSource(juce::MidiKeyboardState& keyState, juce::AudioProcessorValueTreeState& vts)
    : keyboardState(keyState), mVts(vts), numHeldNotes(0), heldNotes()
{
    // This is a mono-synth, only one voice needed
    mFaust = std::make_unique<mydsp>();
    mVoice = std::make_unique<FaustDspVoice>(mVts, *mFaust.get());

    synth.addVoice(mVoice.get());
    synth.addSound(new FaustDspSound());
    synth.setNoteStealingEnabled(true);
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
    mBridge = std::make_unique<FaustUIBridge>(mVts);
    mVoice->prepareToPlay(sampleRate, samplesPerBlockExpected);
    mFaust->init(sampleRate);
    mFaust->buildUserInterface(mBridge.get());
    synth.setCurrentPlaybackSampleRate(sampleRate);
    midiCollector.reset(sampleRate);
}

void FaugAudioSource::releaseResources() {
    mFaust.reset();
    mVoice.reset();
    mBridge.reset();
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
    //Todo: Note priority options. For now, just last note priority

    //If the voice is active, it's currently playing currentNote. Move it to prev_freq for glide
        //If the voice isn't active, set prev_freq to new note so there is no glide

    mVts.getParameterAsValue(PREV_FREQ).setValue(mVoice->isVoiceActive() ? currentNote : midiNoteNumber);
    heldNotes[numHeldNotes++] = midiNoteNumber;
    currentNote = midiNoteNumber;
    synth.noteOn(midiChannel, midiNoteNumber, velocity);
}

void FaugAudioSource::handleNoteOff(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity)
{
    bool shift = false;
    for (int i = 0; i < numHeldNotes; i++)
    {
        if (heldNotes[i] == midiNoteNumber)
        {
            heldNotes[i] = 0;
            shift = true;
            continue;
        }
        
        if (shift)
        {
            heldNotes[i - 1] = heldNotes[i];
        }
    }

    numHeldNotes--;
    bool triggerNewNote = (mVoice->getCurrentlyPlayingNote() == midiNoteNumber && numHeldNotes > 0);
    synth.noteOff(midiChannel, midiNoteNumber, 0, false);
    if (triggerNewNote)
    {
        mVts.getParameterAsValue(PREV_FREQ).setValue(midiNoteNumber);
        currentNote = heldNotes[numHeldNotes-1];
        if (currentNote != 0) {
            synth.noteOn(midiChannel, currentNote, velocity);
        }
    }
}