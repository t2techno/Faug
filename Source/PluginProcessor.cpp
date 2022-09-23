/*

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "./Synth/FaugAudioSource.h"
#include "PluginProcessor.h"
#include "./UI/PluginEditor.h"
#include "Constants.h"

//==============================================================================
FaugAudioProcessor::FaugAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
    ),
#endif
    m_params(*this, nullptr)
{
    m_keyState = std::make_unique <juce::MidiKeyboardState>();
    m_audioSource = std::make_unique<FaugAudioSource>(*m_keyState.get(), m_params);
}

FaugAudioProcessor::~FaugAudioProcessor()
{
    m_audioSource.reset();
}

//==============================================================================
const juce::String FaugAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FaugAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FaugAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool FaugAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double FaugAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FaugAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FaugAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FaugAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String FaugAudioProcessor::getProgramName (int index)
{
    return {};
}

void FaugAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void FaugAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    m_audioSource->prepareToPlay(samplesPerBlock, sampleRate);
    juce::ValueTree root(juce::Identifier("FAUG"));
    m_params.state = root;
}

void FaugAudioProcessor::releaseResources()
{
    m_audioSource->releaseResources();
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FaugAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void FaugAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    m_keyState->processNextMidiBuffer(midiMessages, 0, midiMessages.getNumEvents(), false);

    juce::AudioSourceChannelInfo bufferToFill;
    bufferToFill.buffer = &buffer;
    bufferToFill.startSample = 0;
    bufferToFill.numSamples = buffer.getNumSamples();
    m_audioSource->getNextAudioBlock(bufferToFill);

    FaugAudioProcessorEditor* editor = static_cast<FaugAudioProcessorEditor*>(getActiveEditor());
    
    if (editor)
        editor->getScope()->pushBuffer(*bufferToFill.buffer);
}

//==============================================================================
bool FaugAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* FaugAudioProcessor::createEditor()
{
   return new FaugAudioProcessorEditor (*this, *m_keyState.get(), m_params);
}

//==============================================================================
void FaugAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FaugAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FaugAudioProcessor();
}
//==============================================================================