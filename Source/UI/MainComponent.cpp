// Main Component, holds the primary synth UI
// Todo: Move MidiKeyboardComponent to it's own class to be added/removed

#include "MainComponent.h"
#include "../Constants.h"

MainComponent::MainComponent(juce::MidiKeyboardState& keyboardState, juce::AudioProcessorValueTreeState& vts, int window_width, int window_height)
    : m_vts(vts), keyboardComponent(keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard), window_width(window_width), window_height(window_height)

{
    background = juce::Drawable::createFromImageData(BinaryData::background_png, BinaryData::background_pngSize);

    setOpaque(true);
    addAndMakeVisible(keyboardComponent);
    keyboardComponent.setKeyWidth(40);

    createController();

    createOscBank();

    createMixer();

    createFilterBank();

    createEnvelope();

    setSize(window_width, window_height);

    // wait .4 seconds, then grab keyboard focus to use as potential midi-input
    startTimer(400);
}

MainComponent::~MainComponent()
{}

void MainComponent::createController()
{
    m_glide = std::make_unique<KnobOne>(m_vts, juce::String(GLIDE_RATE), getElWidth(GLIDE_RATE));
    placeElement(*m_glide.get(), GLIDE_RATE);
}

void MainComponent::createOscBank()
{
    // OSC ONE
    m_oscOneRange = std::make_unique<KnobTwo>(m_vts, juce::String(OSC1_RANGE), getElWidth(OSC1_RANGE));
    placeElement(*m_oscOneRange.get(), OSC1_RANGE);

    m_oscOneWaveForm = std::make_unique<KnobTwo>(m_vts, juce::String(OSC1_WAVE), getElWidth(OSC1_WAVE));
    placeElement(*m_oscOneWaveForm.get(), OSC1_WAVE);
    
    // OSC Two
    m_oscTwoRange = std::make_unique<KnobTwo>(m_vts, juce::String(OSC2_RANGE), getElWidth(OSC2_RANGE));
    placeElement(*m_oscTwoRange.get(), OSC2_RANGE);

    m_oscTwoDetune = std::make_unique<BigKnobOne>(m_vts, juce::String(OSC2_DETUNE), getElWidth(OSC2_DETUNE));
    placeElement(*m_oscTwoDetune.get(), OSC2_DETUNE);

    m_oscTwoWaveForm = std::make_unique<KnobTwo>(m_vts, juce::String(OSC2_WAVE), getElWidth(OSC2_WAVE));
    placeElement(*m_oscTwoWaveForm.get(), OSC2_WAVE);

    // OSC Three
    m_oscThreeRange = std::make_unique<KnobTwo>(m_vts, juce::String(OSC3_RANGE), getElWidth(OSC3_RANGE));
    placeElement(*m_oscThreeRange.get(), OSC3_RANGE);

    m_oscThreeDetune = std::make_unique<BigKnobOne>(m_vts, juce::String(OSC3_DETUNE), getElWidth(OSC3_DETUNE));
    placeElement(*m_oscThreeDetune.get(), OSC3_DETUNE);

    m_oscThreeWaveForm = std::make_unique<KnobTwo>(m_vts,  juce::String(OSC3_WAVE), getElWidth(OSC3_WAVE));
    placeElement(*m_oscThreeWaveForm.get(), OSC3_WAVE);
}

void MainComponent::createMixer()
{


    // Saturation/Drive
    //m_load = std::make_unique<KnobThree>(m_vts, juce::String(LOAD), small_knob_size);
    //m_load->setBounds(upl_x + 2 * col_w, upl_y - 0.75*row_h, small_knob_size, small_knob_size);
    //addAndMakeVisible(m_load.get());

    // Oscillators
    m_oscOneGain = std::make_unique<KnobOne>(m_vts, juce::String(OSC1_GAIN), getElWidth(OSC3_WAVE));
    placeElement(*m_oscOneGain.get(), OSC1_GAIN);

    m_oscOnePowerButton = std::make_unique<BlueToggle>(m_vts, juce::String(OSC1_ON), getElWidth(OSC1_ON),
                                                                                     getElHeight(OSC1_ON));
    placeElement(*m_oscOnePowerButton.get(), OSC1_ON);

    m_oscTwoGain = std::make_unique<KnobOne>(m_vts, juce::String(OSC2_GAIN), getElWidth(OSC2_GAIN));
    placeElement(*m_oscTwoGain.get(), OSC2_GAIN);

    m_oscTwoPowerButton = std::make_unique<BlueToggle>(m_vts, juce::String(OSC2_ON), getElWidth(OSC2_ON),
                                                                                     getElHeight(OSC2_ON));
    placeElement(*m_oscTwoPowerButton.get(), OSC2_ON);

    m_oscThreeGain = std::make_unique<KnobOne>(m_vts, juce::String(OSC3_GAIN), getElWidth(OSC3_GAIN));
    placeElement(*m_oscThreeGain.get(), OSC3_GAIN);

    m_oscThreePowerButton = std::make_unique<BlueToggle>(m_vts, juce::String(OSC3_ON), getElWidth(OSC3_ON),
                                                                                       getElHeight(OSC3_ON));
    placeElement(*m_oscThreePowerButton.get(), OSC3_ON);

    m_feedbackGain = std::make_unique<KnobOne>(m_vts, juce::String(FEEDBACK_GAIN), getElWidth(FEEDBACK_GAIN));
    placeElement(*m_feedbackGain.get(), FEEDBACK_GAIN);

    m_feedbackOn = std::make_unique<BlueToggle>(m_vts, juce::String(FEEDBACK_ON), getElWidth(FEEDBACK_ON),
                                                                                  getElHeight(FEEDBACK_ON));
    placeElement(*m_feedbackOn.get(), FEEDBACK_ON);

    // Noise
    m_noiseGain = std::make_unique<KnobOne>(m_vts, juce::String(NOISE_GAIN), getElWidth(NOISE_GAIN));
    placeElement(*m_noiseGain.get(), NOISE_GAIN);

    m_noiseOn = std::make_unique<BlueToggle>(m_vts, juce::String(NOISE_ON), getElWidth(NOISE_ON),
                                                                            getElHeight(NOISE_ON));
    placeElement(*m_noiseOn.get(), NOISE_ON);

    //vertical
    m_noiseType = std::make_unique<BlueToggle>(m_vts, juce::String(NOISE_TYPE), getElWidth(NOISE_TYPE),
                                                                                getElHeight(NOISE_TYPE));
    float noiseType_x      = guiPositions.at((NOISE_TYPE))[0] * float(window_width);
    float noiseType_y      = guiPositions.at((NOISE_TYPE))[1] * float(window_height);
    float noiseType_width  = guiPositions.at((NOISE_TYPE))[2] * float(window_width);
    float noiseType_height = guiPositions.at((NOISE_TYPE))[3] * float(window_height);
    m_noiseType->setTransform(juce::AffineTransform().rotated(juce::MathConstants<float>::halfPi, 
                                                            noiseType_x+(noiseType_width/2), noiseType_y+(noiseType_height/2)));
    m_noiseType->setBounds(noiseType_x, noiseType_y, noiseType_width, noiseType_height);
    addAndMakeVisible(m_noiseType.get());
}

void MainComponent::createFilterBank()
{
    // Row One - Filter Frequency
    m_filterCutoff = std::make_unique<KnobOne>(m_vts,  juce::String(F_CUTOFF), getElWidth(F_CUTOFF));
    placeElement(*m_filterCutoff.get(), F_CUTOFF);

    m_filterQ = std::make_unique<KnobOne>(m_vts,  juce::String(F_Q), getElWidth(F_Q));
    placeElement(*m_filterQ.get(), F_Q);

    m_filterContourAmount = std::make_unique<KnobOne>(m_vts,  juce::String(F_ENV_AMOUNT), getElWidth(F_ENV_AMOUNT));
    placeElement(*m_filterContourAmount.get(), F_ENV_AMOUNT);


    // Row Two - Filter Envelope
    m_filterAttack = std::make_unique<KnobOne>(m_vts,  juce::String(F_ATTACK), getElWidth(F_ATTACK));
    placeElement(*m_filterAttack.get(), F_ATTACK);

    m_filterDecay = std::make_unique<KnobOne>(m_vts,  juce::String(F_DECAY), getElWidth(F_DECAY));
    placeElement(*m_filterDecay.get(), F_DECAY);

    m_filterSustain = std::make_unique<KnobOne>(m_vts,  juce::String(F_SUSTAIN), getElWidth(F_SUSTAIN));
    placeElement(*m_filterSustain.get(), F_SUSTAIN);
}

void MainComponent::createEnvelope()
{
    m_attack = std::make_unique<KnobOne>(m_vts,  juce::String(ATTACK), getElWidth(ATTACK));
    placeElement(*m_attack.get(), ATTACK);

    m_decay = std::make_unique<KnobOne>(m_vts,  juce::String(DECAY), getElWidth(DECAY));
    placeElement(*m_decay.get(), DECAY);

    m_sustain = std::make_unique<KnobOne>(m_vts,  juce::String(SUSTAIN), getElWidth(SUSTAIN));
    placeElement(*m_sustain.get(), SUSTAIN);
}

void MainComponent::placeElement(juce::Component& comp, std::string label)
{
    comp.setBounds(guiPositions.at(label)[0] * window_width,
        guiPositions.at(label)[1] * window_height,
        getElWidth(label), getElHeight (label));
    addAndMakeVisible(comp);
}

int MainComponent::getElWidth(std::string label)
{
    return guiPositions.at(label)[2] * window_width;
}

int MainComponent::getElHeight(std::string label)
{
    return guiPositions.at(label)[3] * window_height;
}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    jassert(background != 0);
    if (background != 0)
    {
        background->drawWithin(g, juce::Rectangle<float>(0, 0, window_width, window_height),
            juce::RectanglePlacement::stretchToFit, 1.000f);
    }

}

void MainComponent::resized()
{    auto area = getLocalBounds().removeFromBottom(window_height * .28).removeFromRight(window_width * 0.6).removeFromLeft(window_width * 0.98);
    keyboardComponent.setBounds(area);
}

void MainComponent::timerCallback()
{
    keyboardComponent.grabKeyboardFocus();
    stopTimer();
}