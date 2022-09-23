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

    knob_size = window_height * 0.08;
    small_knob_size = window_height * 0.07;

    toggle_width = small_knob_size;
    toggle_height = toggle_width * 0.538;

    int controller_x = window_width * 0.048;
    int controller_y = window_height * 0.11;
    int controllerRow_h = window_height * 0;
    createController();

    int oscBank_x = window_width * 0.18;
    int oscBank_y = window_height * 0.117;
    int oscBankCol_w = window_width * 0.08;
    int oscBankRow_h = window_height * 0.1675;
    createOscBank();

    int mixer_x = window_width * 0.445;
    int mixer_y = window_width * 0.11;
    int mixerCol_w = window_width * 0.077;
    int mixerRow_h = window_height * 0.083;
    createMixer(mixer_x, mixer_y, mixerCol_w, mixerRow_h);

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
    m_glide->setBounds(guiPositions.at((GLIDE_RATE))[0]*window_width, guiPositions.at((GLIDE_RATE))[1]*window_height, small_knob_size, small_knob_size);
    addAndMakeVisible(m_glide.get());
}

void MainComponent::createOscBank()
{
    // OSC ONE
    // col 1
    //    m_oscOneRange->setBounds(guiPositions.at((OSC1_RANGE))[0]*window_width, guiPositions.at((OSC1_RANGE))[1]*window_height, knob_size, knob_size);
    m_oscOneRange = std::make_unique<KnobTwo>(m_vts, juce::String(OSC1_RANGE), knob_size);
    m_oscOneRange->setBounds(0.1821*window_width, 0.083*window_height, knob_size, knob_size);
    addAndMakeVisible(m_oscOneRange.get());

    // col 3
    m_oscOneWaveForm = std::make_unique<KnobTwo>(m_vts, juce::String(OSC1_WAVE), knob_size);
    m_oscOneWaveForm->setBounds(guiPositions.at((OSC1_WAVE))[0], guiPositions.at((OSC1_WAVE))[1], knob_size, knob_size);
    addAndMakeVisible(m_oscOneWaveForm.get());
    
    // OSC Two
    // col 1
    m_oscTwoRange = std::make_unique<KnobTwo>(m_vts, juce::String(OSC2_RANGE), knob_size);
    m_oscTwoRange->setBounds(guiPositions.at((OSC2_RANGE))[0], guiPositions.at((OSC2_RANGE))[1], knob_size, knob_size);
    addAndMakeVisible(m_oscTwoRange.get());

    //col 2
    m_oscTwoDetune = std::make_unique<KnobOne>(m_vts, juce::String(OSC2_DETUNE), knob_size);
    m_oscTwoDetune->setBounds(guiPositions.at((OSC2_DETUNE))[0], guiPositions.at((OSC2_DETUNE))[1], knob_size, knob_size);
    addAndMakeVisible(m_oscTwoDetune.get());

    // col 3
    m_oscTwoWaveForm = std::make_unique<KnobTwo>(m_vts, juce::String(OSC2_WAVE), knob_size);
    m_oscTwoWaveForm->setBounds(guiPositions.at((OSC2_DETUNE))[0], guiPositions.at((OSC2_DETUNE))[1], knob_size, knob_size);
    addAndMakeVisible(m_oscTwoWaveForm.get());

    // OSC Three
    // col 1
    m_oscThreeRange = std::make_unique<KnobTwo>(m_vts, juce::String(OSC3_RANGE), knob_size);
    m_oscThreeRange->setBounds(guiPositions.at((OSC3_RANGE))[0], guiPositions.at((OSC3_RANGE))[1], knob_size, knob_size);
    addAndMakeVisible(m_oscThreeRange.get());

    //col 2
    m_oscThreeDetune = std::make_unique<KnobOne>(m_vts, juce::String(OSC3_DETUNE), knob_size);
    m_oscThreeDetune->setBounds(guiPositions.at((OSC3_DETUNE))[0], guiPositions.at((OSC3_DETUNE))[1], knob_size, knob_size);
    addAndMakeVisible(m_oscThreeDetune.get());

    // col 3
    m_oscThreeWaveForm = std::make_unique<KnobTwo>(m_vts,  juce::String(OSC3_WAVE), knob_size);
    m_oscThreeWaveForm->setBounds(guiPositions.at((OSC3_WAVE))[0], guiPositions.at((OSC3_WAVE))[1], knob_size, knob_size);
    addAndMakeVisible(m_oscThreeWaveForm.get());
}

void MainComponent::createMixer(int upl_x, int upl_y, int col_w, int row_h)
{
    int button_upl_y = upl_y + (window_height * 0.018);
    
    // Oscillators
    m_oscOneGain = std::make_unique<KnobThree>(m_vts, juce::String(OSC1_GAIN), small_knob_size);
    m_oscOneGain->setBounds(upl_x, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_oscOneGain.get());

    m_oscOnePowerButton = std::make_unique<BlueToggle>(m_vts, juce::String(OSC1_ON), toggle_width, toggle_height);
    m_oscOnePowerButton->setBounds(upl_x + col_w, button_upl_y, toggle_width, toggle_height);
    addAndMakeVisible(m_oscOnePowerButton.get());

    m_oscTwoGain = std::make_unique<KnobThree>(m_vts, juce::String(OSC2_GAIN), small_knob_size);
    m_oscTwoGain->setBounds(upl_x, upl_y + 2 * row_h, small_knob_size, small_knob_size);
    addAndMakeVisible(m_oscTwoGain.get());

    m_oscTwoPowerButton = std::make_unique<BlueToggle>(m_vts, juce::String(OSC2_ON), toggle_width, toggle_height);
    m_oscTwoPowerButton->setBounds(upl_x + col_w, button_upl_y + 2 * row_h, toggle_width, toggle_height);
    addAndMakeVisible(m_oscTwoPowerButton.get());

    m_oscThreeGain = std::make_unique<KnobThree>(m_vts, juce::String(OSC3_GAIN), small_knob_size);
    m_oscThreeGain->setBounds(upl_x, upl_y + 4 * row_h, small_knob_size, small_knob_size);
    addAndMakeVisible(m_oscThreeGain.get());

    m_oscThreePowerButton = std::make_unique<BlueToggle>(m_vts, juce::String(OSC3_ON), toggle_width, toggle_height);
    m_oscThreePowerButton->setBounds(upl_x + col_w, button_upl_y + 4 * row_h, toggle_width, toggle_height);
    addAndMakeVisible(m_oscThreePowerButton.get());


    // Saturation/Drive
    //m_load = std::make_unique<KnobThree>(m_vts, juce::String(LOAD), small_knob_size);
    //m_load->setBounds(upl_x + 2 * col_w, upl_y - 0.75*row_h, small_knob_size, small_knob_size);
    //addAndMakeVisible(m_load.get());

    m_feedbackOn = std::make_unique<BlueToggle>(m_vts, juce::String(FEEDBACK_ON), toggle_width, toggle_height);
    m_feedbackOn->setBounds(upl_x + col_w, button_upl_y + row_h, toggle_width, toggle_height);
    addAndMakeVisible(m_feedbackOn.get());

    m_feedbackGain = std::make_unique<KnobThree>(m_vts,  juce::String(FEEDBACK_GAIN), small_knob_size);
    m_feedbackGain->setBounds(upl_x+2*col_w, upl_y+row_h, small_knob_size, small_knob_size);
    addAndMakeVisible(m_feedbackGain.get());

    // Noise
    m_noiseOn = std::make_unique<BlueToggle>(m_vts, juce::String(NOISE_ON), toggle_width, toggle_height);
    m_noiseOn->setBounds(upl_x + col_w, button_upl_y + 3 * row_h, toggle_width, toggle_height);
    addAndMakeVisible(m_noiseOn.get());

    m_noiseGain = std::make_unique<KnobThree>(m_vts,  juce::String(NOISE_GAIN), small_knob_size);
    m_noiseGain->setBounds(upl_x+2*col_w, upl_y+3*row_h, small_knob_size, small_knob_size);
    addAndMakeVisible(m_noiseGain.get());

    //vertical
    m_noiseType = std::make_unique<BlueToggle>(m_vts, juce::String(NOISE_TYPE), toggle_width, toggle_height);
    float noiseType_x = upl_x + 2.05 * col_w;
    float noiseType_y = button_upl_y + 4.80 * row_h;
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