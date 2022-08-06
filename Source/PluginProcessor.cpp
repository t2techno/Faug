/*

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "./UI/PluginEditor.h"
#include "ParamsList.h"

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
    m_params(*this, nullptr, juce::Identifier("FAUG"),
        {
            std::make_unique<juce::AudioParameterBool> (GATE, "Gate", false),
            std::make_unique<juce::AudioParameterFloat>(FREQ, "Freq", 1.f,8000.f, 440.f),

            std::make_unique<juce::AudioParameterInt>  (OSC1_RANGE, "OscOneRange",0,6,2),
            std::make_unique<juce::AudioParameterInt>  (OSC1_WAVE, "OscOneWave",0,5,1),
            std::make_unique<juce::AudioParameterFloat>(OSC1_GAIN, "OscOneGain", 0.f,10.f, 10.f),
            std::make_unique<juce::AudioParameterBool> (OSC1_POWER, "OscOnePower", false),

            std::make_unique<juce::AudioParameterInt>  (OSC2_RANGE, "OscTwoRange",0,6,2),
            std::make_unique<juce::AudioParameterFloat>(OSC2_DETUNE, "OscTwoDetune", -7.5,7.5, 0.f),
            std::make_unique<juce::AudioParameterInt>  (OSC2_WAVE, "OscTwoWave",0,5,1),
            std::make_unique<juce::AudioParameterFloat>(OSC2_GAIN, "OscTwoGain", 0.f,10.f, 10.f),
            std::make_unique<juce::AudioParameterBool> (OSC2_POWER, "OscTwoPower", false),

            std::make_unique<juce::AudioParameterInt>  (OSC3_RANGE, "OscThreeRange",0,6,2),
            std::make_unique<juce::AudioParameterFloat>(OSC3_DETUNE, "OscThreeDetune", -7.5,7.5, 0.f),
            std::make_unique<juce::AudioParameterInt>  (OSC3_WAVE, "OscThreeWave",0,5,1),
            std::make_unique<juce::AudioParameterFloat>(OSC3_GAIN, "OscThreeGain", 0.f,10.f, 10.f),
            std::make_unique<juce::AudioParameterBool> (OSC3_POWER, "OscThreePower", false),

            std::make_unique<juce::AudioParameterFloat>(F_CUTOFF, "FilterCutoff", 10.f,32000.f,440.f),
            std::make_unique<juce::AudioParameterFloat>(F_Q, "FilterQ", .707, 25.f, 1.f),
            std::make_unique<juce::AudioParameterFloat>(F_ENV_AMOUNT, "ContourAmount", 0.f, 1.f, 1.f),
            std::make_unique<juce::AudioParameterFloat>(F_ATTACK, "FilterAttack", 1.f, 1000.f, 50.f),
            std::make_unique<juce::AudioParameterFloat>(F_DECAY, "FilterDecay", 1.f, 1000.f, 50.f),
            std::make_unique<juce::AudioParameterFloat>(F_SUSTAIN, "FilterSustain", 0.01, 1.f, 0.8),

            std::make_unique<juce::AudioParameterFloat>(DECAY, "Decay", 1.f, 1000.f, 50.f),
            
        }
    )
{

    splash = new SplashAnimation("FAUG", 720, 720, true);

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
    splash->deleteAfterDelay(juce::RelativeTime::seconds(4), false);
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