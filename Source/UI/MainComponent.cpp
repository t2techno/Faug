// Main Component, holds the primary synth UI
// Todo: Move MidiKeyboardComponent to it's own class to be added/removed

#include "MainComponent.h"
#include "Knob.h"
#include "../ParamsList.h"

const int MainComponent::UPL_X = 215;
const int MainComponent::UPL_Y = 65;
const int MainComponent::COL_W = 100;
const int MainComponent::ROW_H = 100;
const int MainComponent::COMP_SIZE = 80;

MainComponent::MainComponent(juce::MidiKeyboardState& keyboardState, juce::AudioProcessorValueTreeState& vts)
    : m_vts(vts),
    keyboardComponent(keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)

{
    background = juce::Drawable::createFromImageData(BinaryData::background_png, BinaryData::background_pngSize);

    setOpaque(true);
    addAndMakeVisible(keyboardComponent);
    keyboardComponent.setKeyWidth(40);

    createOscBank();

    createFilterBank();

    // ENVELOPE
    /*m_decaySlider = std::make_unique<juce::Slider>();
    m_decayLabel = std::make_unique<juce::Label>();
    createSliderAndLabel(m_decayLabel.get(), "Decay", m_decaySlider.get(),
        970, 265, SLIDER_SIZE, SLIDER_SIZE);
    m_decayAttach.reset(new SliderAttachment(m_vts, juce::String(DECAY), *m_decaySlider.get()));*/


    // wait .4 seconds, then grab keyboard focus to use as potential midi-input
    setSize(WIDTH, HEIGHT);
    startTimer(400);
}

MainComponent::~MainComponent()
{}

void MainComponent::createButtonAndLabel(juce::Label* label, std::string labelText, juce::Button* button,
    int x, int y, int width, int height) 
{
    addAndMakeVisible(button);
    button->setBounds(x, y, width, height);
    if (label == NULL) {
        return;
    }
    addAndMakeVisible(label);
    label->setFont(juce::Font(15.00f, juce::Font::plain));
    label->setText(labelText, juce::dontSendNotification);
    label->setJustificationType(juce::Justification::centred);
    label->setEditable(false, true, false);
    label->setColour(juce::Label::textColourId, juce::Colour(0xffff8917));
    label->attachToComponent(button, false);
}

void MainComponent::createOscBank()
{
    // OSC ONE
    // col 1
    m_oscOneRange = std::make_unique<Knob>(m_vts, "Osc1 Range", juce::String(OSC1_RANGE), COMP_SIZE);
    m_oscOneRange->setBounds(UPL_X, UPL_Y, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_oscOneRange.get());

    // col 3
    m_oscOneWaveForm = std::make_unique<Knob>(m_vts, "Osc1 Wave", juce::String(OSC1_WAVE), COMP_SIZE);
    m_oscOneWaveForm->setBounds(UPL_X + 2 * COL_W, UPL_Y, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_oscOneWaveForm.get());

    // col 4
    m_oscOneGain = std::make_unique<Knob>(m_vts, "Osc1 Gain", juce::String(OSC1_GAIN), COMP_SIZE);
    m_oscOneGain->setBounds(UPL_X + 3*COL_W, UPL_Y, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_oscOneGain.get());

    // col 5
    m_oscOnePowerButton = std::make_unique<juce::ToggleButton>("Osc1");
    createButtonAndLabel(NULL, "Osc1", m_oscOnePowerButton.get(),
        UPL_X+4*COL_W, UPL_Y, COMP_SIZE, COMP_SIZE);
    m_oscOnePowerAttach.reset(new ButtonAttachment(m_vts, juce::String(OSC1_POWER), *m_oscOnePowerButton.get()));

    
    // OSC Two
    // col 1
    m_oscTwoRange = std::make_unique<Knob>(m_vts, "Osc2 Range", juce::String(OSC2_RANGE), COMP_SIZE);
    m_oscTwoRange->setBounds(UPL_X, UPL_Y+ROW_H, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_oscTwoRange.get());

    //col 2
    m_oscTwoDetune = std::make_unique<Knob>(m_vts, "Osc2 Detune", juce::String(OSC2_DETUNE), COMP_SIZE);
    m_oscTwoDetune->setBounds(UPL_X + COL_W, UPL_Y+ROW_H, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_oscTwoDetune.get());

    // col 3
    m_oscTwoWaveForm = std::make_unique<Knob>(m_vts, "Osc2 Wave", juce::String(OSC2_WAVE), COMP_SIZE);
    m_oscTwoWaveForm->setBounds(UPL_X + 2 * COL_W, UPL_Y+ROW_H, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_oscTwoWaveForm.get());

    // col 4
    m_oscTwoGain = std::make_unique<Knob>(m_vts, "Osc2 Gain", juce::String(OSC2_GAIN), COMP_SIZE);
    m_oscTwoGain->setBounds(UPL_X + 3 * COL_W, UPL_Y+ROW_H, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_oscTwoGain.get());

    // col 5
    m_oscTwoPowerButton = std::make_unique<juce::ToggleButton>("Osc2");
    createButtonAndLabel(NULL, "Osc2", m_oscTwoPowerButton.get(),
        UPL_X + 4 * COL_W, UPL_Y+ROW_H, COMP_SIZE, COMP_SIZE);
    m_oscTwoPowerAttach.reset(new ButtonAttachment(m_vts, juce::String(OSC2_POWER), *m_oscTwoPowerButton.get()));


    // OSC Three
    // col 1
    m_oscThreeRange = std::make_unique<Knob>(m_vts, "Osc3 Range", juce::String(OSC3_RANGE), COMP_SIZE);
    m_oscThreeRange->setBounds(UPL_X, UPL_Y + 2*ROW_H, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_oscThreeRange.get());

    //col 2
    m_oscThreeDetune = std::make_unique<Knob>(m_vts, "Osc3 Detune", juce::String(OSC3_DETUNE), COMP_SIZE);
    m_oscThreeDetune->setBounds(UPL_X + COL_W, UPL_Y + 2*ROW_H, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_oscThreeDetune.get());

    // col 3
    m_oscThreeWaveForm = std::make_unique<Knob>(m_vts, "Osc3 Wave", juce::String(OSC3_WAVE), COMP_SIZE);
    m_oscThreeWaveForm->setBounds(UPL_X + 2*COL_W, UPL_Y + 2*ROW_H, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_oscThreeWaveForm.get());

    // col 4
    m_oscThreeGain = std::make_unique<Knob>(m_vts, "Osc3 Gain", juce::String(OSC3_GAIN), COMP_SIZE);
    m_oscThreeGain->setBounds(UPL_X + 3*COL_W, UPL_Y+ 2*ROW_H, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_oscThreeGain.get());

    // col 5
    m_oscThreePowerButton = std::make_unique<juce::ToggleButton>("Osc3");
    createButtonAndLabel(NULL, "Osc3", m_oscThreePowerButton.get(),
        UPL_X + 4 * COL_W, UPL_Y + 2*ROW_H, COMP_SIZE, COMP_SIZE);
    m_oscThreePowerAttach.reset(new ButtonAttachment(m_vts, juce::String(OSC3_POWER), *m_oscThreePowerButton.get()));
}

void MainComponent::createFilterBank()
{

    int F_UP_LEFT_X = UPL_X + 6.5 * COL_W;
    // ROW ONE - FREQUENCY STUFF
    // COL ONE
    m_filterCutoff = std::make_unique<Knob>(m_vts, "Cutoff", juce::String(F_CUTOFF), COMP_SIZE);
    m_filterCutoff->setBounds(F_UP_LEFT_X, UPL_Y, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_filterCutoff.get());

    // COL TWO
    m_filterQ = std::make_unique<Knob>(m_vts, "Emphasis", juce::String(F_Q), COMP_SIZE);
    m_filterQ->setBounds(F_UP_LEFT_X + COL_W, UPL_Y, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_filterQ.get());

    // COL THREE
    m_filterContourAmount = std::make_unique<Knob>(m_vts, "Contour Amount", juce::String(F_ENV_AMOUNT), COMP_SIZE);
    m_filterContourAmount->setBounds(F_UP_LEFT_X + 2*COL_W, UPL_Y, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_filterContourAmount.get());


    // ROW TWO - FILTER ENVELOPE STUFF
    // COL ONE
    m_filterAttack = std::make_unique<Knob>(m_vts, "Attack", juce::String(F_ATTACK), COMP_SIZE);
    m_filterAttack->setBounds(F_UP_LEFT_X, UPL_Y + ROW_H, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_filterAttack.get());

    // COL TWO
    m_filterDecay = std::make_unique<Knob>(m_vts, "Decay", juce::String(F_DECAY), COMP_SIZE);
    m_filterDecay->setBounds(F_UP_LEFT_X +COL_W, UPL_Y + ROW_H, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_filterDecay.get());

    // COL THREE
    m_filterSustain = std::make_unique<Knob>(m_vts, "Sustain", juce::String(F_SUSTAIN), COMP_SIZE);
    m_filterSustain->setBounds(F_UP_LEFT_X + 2*COL_W, UPL_Y + ROW_H, COMP_SIZE, COMP_SIZE);
    addAndMakeVisible(m_filterSustain.get());
}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    jassert(background != 0);
    if (background != 0)
    {
        background->drawWithin(g, juce::Rectangle<float>(0, 0, WIDTH, HEIGHT),
            juce::RectanglePlacement::stretchToFit, 1.000f);
    }

}

void MainComponent::resized()
{    auto area = getLocalBounds().removeFromBottom(200).removeFromRight(WIDTH-40).removeFromLeft(WIDTH - 550);
    keyboardComponent.setBounds(area);
}

void MainComponent::timerCallback()
{
    keyboardComponent.grabKeyboardFocus();
    stopTimer();
}