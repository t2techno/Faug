// Main Component, holds the primary synth UI
// Todo: Move MidiKeyboardComponent to it's own class to be added/removed

#include "MainComponent.h"
#include "../ParamsList.h"

MainComponent::MainComponent(juce::MidiKeyboardState& keyboardState, juce::AudioProcessorValueTreeState& vts, juce::Rectangle<int> screen)
    : m_vts(vts), screenWidth(screen.getWidth()), screenHeight(screen.getHeight()),
    keyboardComponent(keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)

{
    background = juce::Drawable::createFromImageData(BinaryData::background_png, BinaryData::background_pngSize);

    setOpaque(true);
    addAndMakeVisible(keyboardComponent);
    keyboardComponent.setKeyWidth(40);

    int oscBank_x = screenWidth * 0.1825;
    int oscBank_y = screenHeight * 0.175;
    int oscBankCol_w = screenWidth * 0.085;
    int oscBankRow_h = screenHeight * 0.138;

    knob_size = screenHeight * 0.095;
    small_knob_size = screenHeight * 0.08;
    
    createOscBank(oscBank_x, oscBank_y, oscBankCol_w, oscBankRow_h);

    int mixer_x = screenWidth * 0.45;
    int mixer_y = screenHeight * 0.175;
    int mixerCol_w = screenWidth * 0.085;
    int mixerRow_h = oscBankRow_h/2;
    createMixer(mixer_x, mixer_y, mixerCol_w, mixerRow_h);

    int filter_x = screenWidth * 0.675;
    int filter_y = screenHeight * 0.175;
    int filterCol_w = screenWidth * 0.085;
    int filterRow_h = oscBankRow_h;
    createFilterBank(filter_x, filter_y, filterCol_w, filterRow_h);

    int envelope_x = screenWidth * 0.675;
    int envelope_y = mixer_y + 2* oscBankRow_h;
    int envelopeCol_w = screenWidth * 0.085;
    createEnvelope(envelope_x, envelope_y, envelopeCol_w);

    // wait .4 seconds, then grab keyboard focus to use as potential midi-input
    setSize(screenWidth, screenHeight);
    startTimer(400);
}

MainComponent::~MainComponent()
{}

void MainComponent::createOscBank(int upl_x, int upl_y, int col_w, int row_h)
{
    // OSC ONE
    // col 1
    m_oscOneRange = std::make_unique<KnobTwo>(m_vts, "Osc1 Range", juce::String(OSC1_RANGE), knob_size);
    m_oscOneRange->setBounds(upl_x, upl_y, knob_size, knob_size);
    addAndMakeVisible(m_oscOneRange.get());

    // col 3
    m_oscOneWaveForm = std::make_unique<KnobTwo>(m_vts, "Osc1 Wave", juce::String(OSC1_WAVE), knob_size);
    m_oscOneWaveForm->setBounds(upl_x + 2 * col_w, upl_y, knob_size, knob_size);
    addAndMakeVisible(m_oscOneWaveForm.get());
    
    // OSC Two
    // col 1
    m_oscTwoRange = std::make_unique<KnobTwo>(m_vts, "Osc2 Range", juce::String(OSC2_RANGE), knob_size);
    m_oscTwoRange->setBounds(upl_x, upl_y + row_h, knob_size, knob_size);
    addAndMakeVisible(m_oscTwoRange.get());

    //col 2
    m_oscTwoDetune = std::make_unique<KnobOne>(m_vts, "Osc2 Detune", juce::String(OSC2_DETUNE), knob_size);
    m_oscTwoDetune->setBounds(upl_x + col_w, upl_y + row_h, knob_size, knob_size);
    addAndMakeVisible(m_oscTwoDetune.get());

    // col 3
    m_oscTwoWaveForm = std::make_unique<KnobTwo>(m_vts, "Osc2 Wave", juce::String(OSC2_WAVE), knob_size);
    m_oscTwoWaveForm->setBounds(upl_x + 2 * col_w, upl_y + row_h, knob_size, knob_size);
    addAndMakeVisible(m_oscTwoWaveForm.get());

    // OSC Three
    // col 1
    m_oscThreeRange = std::make_unique<KnobTwo>(m_vts, "Osc3 Range", juce::String(OSC3_RANGE), knob_size);
    m_oscThreeRange->setBounds(upl_x, upl_y + 2* row_h, knob_size, knob_size);
    addAndMakeVisible(m_oscThreeRange.get());

    //col 2
    m_oscThreeDetune = std::make_unique<KnobOne>(m_vts, "Osc3 Detune", juce::String(OSC3_DETUNE), knob_size);
    m_oscThreeDetune->setBounds(upl_x + col_w, upl_y + 2* row_h, knob_size, knob_size);
    addAndMakeVisible(m_oscThreeDetune.get());

    // col 3
    m_oscThreeWaveForm = std::make_unique<KnobTwo>(m_vts, "Osc3 Wave", juce::String(OSC3_WAVE), knob_size);
    m_oscThreeWaveForm->setBounds(upl_x + 2* col_w, upl_y + 2* row_h, knob_size, knob_size);
    addAndMakeVisible(m_oscThreeWaveForm.get());
}

void MainComponent::createMixer(int upl_x, int upl_y, int col_w, int row_h)
{
    // row 1
    m_oscOneGain = std::make_unique<KnobThree>(m_vts, "Osc1 Gain", juce::String(OSC1_GAIN), small_knob_size);
    m_oscOneGain->setBounds(upl_x, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_oscOneGain.get());

    m_oscOnePowerButton = std::make_unique<juce::ToggleButton>("Osc1");
    addAndMakeVisible(m_oscOnePowerButton.get());
    m_oscOnePowerButton->setBounds(upl_x + col_w, upl_y, knob_size, knob_size);
    m_oscOnePowerAttach.reset(new ButtonAttachment(m_vts, juce::String(OSC1_POWER), *m_oscOnePowerButton.get()));

    // row 3
    m_oscTwoGain = std::make_unique<KnobThree>(m_vts, "Osc2 Gain", juce::String(OSC2_GAIN), small_knob_size);
    m_oscTwoGain->setBounds(upl_x, upl_y + 2*row_h, small_knob_size, small_knob_size);
    addAndMakeVisible(m_oscTwoGain.get());

    m_oscTwoPowerButton = std::make_unique<juce::ToggleButton>("Osc2");
    addAndMakeVisible(m_oscTwoPowerButton.get());
    m_oscTwoPowerButton->setBounds(upl_x + col_w, upl_y + 2 * row_h, knob_size, knob_size);
    m_oscTwoPowerAttach.reset(new ButtonAttachment(m_vts, juce::String(OSC2_POWER), *m_oscTwoPowerButton.get()));

    // row 5
    m_oscThreeGain = std::make_unique<KnobThree>(m_vts, "Osc3 Gain", juce::String(OSC3_GAIN), small_knob_size);
    m_oscThreeGain->setBounds(upl_x, upl_y + 4 * row_h, small_knob_size, small_knob_size);
    addAndMakeVisible(m_oscThreeGain.get());

    m_oscThreePowerButton = std::make_unique<juce::ToggleButton>("Osc3");
    addAndMakeVisible(m_oscThreePowerButton.get());
    m_oscThreePowerButton->setBounds(upl_x + col_w, upl_y + 4 * row_h, knob_size, knob_size);
    m_oscThreePowerAttach.reset(new ButtonAttachment(m_vts, juce::String(OSC3_POWER), *m_oscThreePowerButton.get()));
}

void MainComponent::createFilterBank(int upl_x, int upl_y, int col_w, int row_h)
{
    // ROW ONE - FREQUENCY STUFF
    // COL ONE
    m_filterCutoff = std::make_unique<KnobThree>(m_vts, "Cutoff", juce::String(F_CUTOFF), small_knob_size);
    m_filterCutoff->setBounds(upl_x, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_filterCutoff.get());

    // COL TWO
    m_filterQ = std::make_unique<KnobThree>(m_vts, "Emphasis", juce::String(F_Q), small_knob_size);
    m_filterQ->setBounds(upl_x + col_w, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_filterQ.get());

    // COL THREE
    m_filterContourAmount = std::make_unique<KnobThree>(m_vts, "Contour Amount", juce::String(F_ENV_AMOUNT), small_knob_size);
    m_filterContourAmount->setBounds(upl_x + 2* col_w, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_filterContourAmount.get());


    // ROW TWO - FILTER ENVELOPE STUFF
    // COL ONE
    m_filterAttack = std::make_unique<KnobThree>(m_vts, "Attack", juce::String(F_ATTACK), small_knob_size);
    m_filterAttack->setBounds(upl_x, upl_y + row_h, small_knob_size, small_knob_size);
    addAndMakeVisible(m_filterAttack.get());

    // COL TWO
    m_filterDecay = std::make_unique<KnobThree>(m_vts, "Decay", juce::String(F_DECAY), small_knob_size);
    m_filterDecay->setBounds(upl_x + col_w, upl_y + row_h, small_knob_size, small_knob_size);
    addAndMakeVisible(m_filterDecay.get());

    // COL THREE
    m_filterSustain = std::make_unique<KnobThree>(m_vts, "Sustain", juce::String(F_SUSTAIN), small_knob_size);
    m_filterSustain->setBounds(upl_x + 2* col_w, upl_y + row_h, small_knob_size, small_knob_size);
    addAndMakeVisible(m_filterSustain.get());
}

void MainComponent::createEnvelope(int upl_x, int upl_y, int col_w)
{
    m_attack = std::make_unique<KnobThree>(m_vts, "Attack", juce::String(ATTACK), small_knob_size);
    m_attack->setBounds(upl_x, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_attack.get());

    // COL TWO
    m_decay = std::make_unique<KnobThree>(m_vts, "Decay", juce::String(DECAY), small_knob_size);
    m_decay->setBounds(upl_x + col_w, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_decay.get());

    // COL THREE
    m_sustain = std::make_unique<KnobThree>(m_vts, "Sustain", juce::String(SUSTAIN), small_knob_size);
    m_sustain->setBounds(upl_x + 2*col_w, upl_y, small_knob_size, small_knob_size);
    addAndMakeVisible(m_sustain.get());
}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    jassert(background != 0);
    if (background != 0)
    {
        background->drawWithin(g, juce::Rectangle<float>(0, 0, screenWidth, screenHeight),
            juce::RectanglePlacement::stretchToFit, 1.000f);
    }

}

void MainComponent::resized()
{    auto area = getLocalBounds().removeFromBottom(200).removeFromRight(screenWidth-40).removeFromLeft(screenWidth - 550);
    keyboardComponent.setBounds(area);
}

void MainComponent::timerCallback()
{
    keyboardComponent.grabKeyboardFocus();
    stopTimer();
}