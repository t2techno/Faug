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

    juce::Rectangle<int> area = getBoundsInParent();

    knob_size = window_height * 0.085;
    small_knob_size = window_height * 0.075;

    toggle_width = small_knob_size;
    toggle_height = toggle_width * 0.538;

    createController();

    createOscBank();

    createMixer();

    int filter_x = window_width * 0.71;
    int filter_y = window_height * 0.15;
    int filterCol_w = window_width * 0.09;
    int filterRow_h = window_height * 0.178;
    createFilterBank(filter_x, filter_y, filterCol_w, filterRow_h);

    int envelope_x = filter_x;
    int envelope_y = window_height * 0.52;
    int envelopeCol_w = filterCol_w;
    createEnvelope(envelope_x, envelope_y, envelopeCol_w);

    setSize(window_width, window_height);

    // wait .4 seconds, then grab keyboard focus to use as potential midi-input
    startTimer(400);
}

MainComponent::~MainComponent()
{}

void MainComponent::createController()
{
    m_glide = std::make_unique<KnobThree>(m_vts, juce::String(GLIDE_RATE), small_knob_size);
    placeElement(*m_glide.get(), GLIDE_RATE, small_knob_size, small_knob_size);
}

void MainComponent::createOscBank()
{
    // OSC ONE
    m_oscOneRange = std::make_unique<KnobTwo>(m_vts, juce::String(OSC1_RANGE), knob_size);
    placeElement(*m_oscOneRange.get(), OSC1_RANGE, knob_size, knob_size);

    m_oscOneWaveForm = std::make_unique<KnobTwo>(m_vts, juce::String(OSC1_WAVE), knob_size);
    placeElement(*m_oscOneWaveForm.get(), OSC1_WAVE, knob_size, knob_size);
    
    // OSC Two
    m_oscTwoRange = std::make_unique<KnobTwo>(m_vts, juce::String(OSC2_RANGE), knob_size);
    placeElement(*m_oscTwoRange.get(), OSC2_RANGE, knob_size, knob_size);

    m_oscTwoDetune = std::make_unique<KnobOne>(m_vts, juce::String(OSC2_DETUNE), knob_size);
    placeElement(*m_oscTwoDetune.get(), OSC2_DETUNE, knob_size, knob_size);

    m_oscTwoWaveForm = std::make_unique<KnobTwo>(m_vts, juce::String(OSC2_WAVE), knob_size);
    placeElement(*m_oscTwoWaveForm.get(), OSC2_WAVE, knob_size, knob_size);

    // OSC Three
    m_oscThreeRange = std::make_unique<KnobTwo>(m_vts, juce::String(OSC3_RANGE), knob_size);
    placeElement(*m_oscThreeRange.get(), OSC3_RANGE, knob_size, knob_size);

    m_oscThreeDetune = std::make_unique<KnobOne>(m_vts, juce::String(OSC3_DETUNE), knob_size);
    placeElement(*m_oscThreeDetune.get(), OSC3_DETUNE, knob_size, knob_size);

    m_oscThreeWaveForm = std::make_unique<KnobTwo>(m_vts,  juce::String(OSC3_WAVE), knob_size);
    placeElement(*m_oscThreeWaveForm.get(), OSC3_WAVE, knob_size, knob_size);
}

void MainComponent::createMixer()
{


    // Saturation/Drive
    //m_load = std::make_unique<KnobThree>(m_vts, juce::String(LOAD), small_knob_size);
    //m_load->setBounds(upl_x + 2 * col_w, upl_y - 0.75*row_h, small_knob_size, small_knob_size);
    //addAndMakeVisible(m_load.get());

    // Oscillators
    m_oscOneGain = std::make_unique<KnobThree>(m_vts, juce::String(OSC1_GAIN), small_knob_size);
    placeElement(*m_oscOneGain.get(), OSC1_GAIN, small_knob_size, small_knob_size);

    m_oscOnePowerButton = std::make_unique<BlueToggle>(m_vts, juce::String(OSC1_ON), toggle_width, toggle_height);
    placeElement(*m_oscOnePowerButton.get(), OSC1_ON, toggle_width, toggle_height);

    m_oscTwoGain = std::make_unique<KnobThree>(m_vts, juce::String(OSC2_GAIN), small_knob_size);
    placeElement(*m_oscTwoGain.get(), OSC2_GAIN, small_knob_size, small_knob_size);

    m_oscTwoPowerButton = std::make_unique<BlueToggle>(m_vts, juce::String(OSC2_ON), toggle_width, toggle_height);
    placeElement(*m_oscTwoPowerButton.get(), OSC2_ON, toggle_width, toggle_height);

    m_oscThreeGain = std::make_unique<KnobThree>(m_vts, juce::String(OSC3_GAIN), small_knob_size);
    placeElement(*m_oscThreeGain.get(), OSC3_GAIN, small_knob_size, small_knob_size);

    m_oscThreePowerButton = std::make_unique<BlueToggle>(m_vts, juce::String(OSC3_ON), toggle_width, toggle_height);
    placeElement(*m_oscThreePowerButton.get(), OSC3_ON, toggle_width, toggle_height);

    m_feedbackGain = std::make_unique<KnobThree>(m_vts, juce::String(FEEDBACK_GAIN), small_knob_size);
    placeElement(*m_feedbackGain.get(), FEEDBACK_GAIN, small_knob_size, small_knob_size);

    m_feedbackOn = std::make_unique<BlueToggle>(m_vts, juce::String(FEEDBACK_ON), toggle_width, toggle_height);
    placeElement(*m_feedbackOn.get(), FEEDBACK_ON, toggle_width, toggle_height);

    // Noise

    m_noiseGain = std::make_unique<KnobThree>(m_vts, juce::String(NOISE_GAIN), small_knob_size);
    placeElement(*m_noiseGain.get(), NOISE_GAIN, small_knob_size, small_knob_size);

    m_noiseOn = std::make_unique<BlueToggle>(m_vts, juce::String(NOISE_ON), toggle_width, toggle_height);
    placeElement(*m_noiseOn.get(), NOISE_ON, toggle_width, toggle_height);

    //vertical
    m_noiseType = std::make_unique<BlueToggle>(m_vts, juce::String(NOISE_TYPE), toggle_width, toggle_height);

    float noiseType_x = guiPositions.at((NOISE_TYPE))[0] * float(window_width);
    float noiseType_y = guiPositions.at((NOISE_TYPE))[1] * float(window_height);
    m_noiseType->setTransform(juce::AffineTransform().rotated(juce::MathConstants<float>::halfPi, 
                                                            noiseType_x+(toggle_width/2), noiseType_y+(toggle_height/2)));
    m_noiseType->setBounds(noiseType_x, noiseType_y, toggle_width, toggle_height);
    addAndMakeVisible(m_noiseType.get());
}

void MainComponent::createFilterBank(int upl_x, int upl_y, int col_w, int row_h)
{
    // ROW ONE - FREQUENCY STUFF
    // COL ONE
    m_filterCutoff = std::make_unique<KnobThree>(m_vts,  juce::String(F_CUTOFF), small_knob_size);
    m_filterCutoff->setBounds(upl_x, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_filterCutoff.get());

    // COL TWO
    m_filterQ = std::make_unique<KnobThree>(m_vts,  juce::String(F_Q), small_knob_size);
    m_filterQ->setBounds(upl_x + col_w, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_filterQ.get());

    // COL THREE
    m_filterContourAmount = std::make_unique<KnobThree>(m_vts,  juce::String(F_ENV_AMOUNT), small_knob_size);
    m_filterContourAmount->setBounds(upl_x + 2* col_w, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_filterContourAmount.get());


    // ROW TWO - FILTER ENVELOPE STUFF
    // COL ONE
    m_filterAttack = std::make_unique<KnobThree>(m_vts,  juce::String(F_ATTACK), small_knob_size);
    m_filterAttack->setBounds(upl_x, upl_y + row_h, small_knob_size, small_knob_size);
    addAndMakeVisible(m_filterAttack.get());

    // COL TWO
    m_filterDecay = std::make_unique<KnobThree>(m_vts,  juce::String(F_DECAY), small_knob_size);
    m_filterDecay->setBounds(upl_x + col_w, upl_y + row_h, small_knob_size, small_knob_size);
    addAndMakeVisible(m_filterDecay.get());

    // COL THREE
    m_filterSustain = std::make_unique<KnobThree>(m_vts,  juce::String(F_SUSTAIN), small_knob_size);
    m_filterSustain->setBounds(upl_x + 2* col_w, upl_y + row_h, small_knob_size, small_knob_size);
    addAndMakeVisible(m_filterSustain.get());
}

void MainComponent::createEnvelope(int upl_x, int upl_y, int col_w)
{
    m_attack = std::make_unique<KnobThree>(m_vts,  juce::String(ATTACK), small_knob_size);
    m_attack->setBounds(upl_x, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_attack.get());

    // COL TWO
    m_decay = std::make_unique<KnobThree>(m_vts,  juce::String(DECAY), small_knob_size);
    m_decay->setBounds(upl_x + col_w, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_decay.get());

    // COL THREE
    m_sustain = std::make_unique<KnobThree>(m_vts,  juce::String(SUSTAIN), small_knob_size);
    m_sustain->setBounds(upl_x + 2*col_w, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_sustain.get());
}

void MainComponent::placeElement(juce::Component& comp, std::string label, int compWidth, int compHeight)
{
    comp.setBounds(guiPositions.at((label))[0] * window_width, guiPositions.at((label))[1] * window_height, compWidth, compHeight);
    addAndMakeVisible(comp);
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
{    auto area = getLocalBounds().removeFromBottom(window_height * .28).removeFromRight(window_width * 0.98).removeFromLeft(window_width * .6);
    keyboardComponent.setBounds(area);
}

void MainComponent::timerCallback()
{
    keyboardComponent.grabKeyboardFocus();
    stopTimer();
}