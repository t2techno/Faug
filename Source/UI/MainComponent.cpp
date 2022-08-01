// Main Component, holds the primary synth UI
// Todo: Move MidiKeyboardComponent to it's own class to be added/removed

#include "MainComponent.h"
#include "../ParamsList.h"

MainComponent::MainComponent(juce::MidiKeyboardState& keyboardState, juce::AudioProcessorValueTreeState& vts)
    : m_vts(vts),
    keyboardComponent(keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)

{
    background = juce::Drawable::createFromImageData(BinaryData::background_png, BinaryData::background_pngSize);
    setSize(WIDTH, HEIGHT);

    setOpaque(true);
    addAndMakeVisible(keyboardComponent);
    keyboardComponent.setKeyWidth(52);

    // OSCILLATORS
    // 
    // OSC ONE
    m_oscOnePowerButton = std::make_unique<juce::ToggleButton>("Osc1");
    createButtonAndLabel(NULL, "Osc1", m_oscOnePowerButton.get(),
        725, 80, SLIDE_SIZE, SLIDE_SIZE);
    m_oscOnePowerAttach.reset(new ButtonAttachment(m_vts, juce::String(OSC1_POWER), *m_oscOnePowerButton.get()));

    m_oscOneGainSlider = std::make_unique<juce::Slider>();
    m_oscOneGainLabel = std::make_unique<juce::Label>();
    createSliderAndLabel(m_oscOneGainLabel.get(), "Osc1 Gain", m_oscOneGainSlider.get(),
        625, 80, SLIDE_SIZE, SLIDE_SIZE);
    m_oscOneGainAttach.reset(new SliderAttachment(m_vts, juce::String(OSC1_GAIN), *m_oscOneGainSlider.get()));

    // OSC TWO
    m_oscTwoPowerButton = std::make_unique<juce::ToggleButton>("Osc2");
    createButtonAndLabel(NULL, "Osc2", m_oscTwoPowerButton.get(),
        725, 180, SLIDE_SIZE, SLIDE_SIZE);
    m_oscTwoPowerAttach.reset(new ButtonAttachment(m_vts, juce::String(OSC2_POWER), *m_oscTwoPowerButton.get()));

    m_oscTwoGainSlider = std::make_unique<juce::Slider>();
    m_oscTwoGainLabel = std::make_unique<juce::Label>();
    createSliderAndLabel(m_oscTwoGainLabel.get(), "Osc2 Gain", m_oscTwoGainSlider.get(),
        625, 180, SLIDE_SIZE, SLIDE_SIZE);
    m_oscTwoGainAttach.reset(new SliderAttachment(m_vts, juce::String(OSC2_GAIN), *m_oscTwoGainSlider.get()));



    // OSC THREE
    m_oscThreePowerButton = std::make_unique<juce::ToggleButton>("Osc3");
    createButtonAndLabel(NULL, "Osc3", m_oscThreePowerButton.get(),
        725, 280, SLIDE_SIZE, SLIDE_SIZE);
    m_oscThreePowerAttach.reset(new ButtonAttachment(m_vts, juce::String(OSC3_POWER), *m_oscThreePowerButton.get()));

    m_oscThreeGainSlider = std::make_unique<juce::Slider>();
    m_oscThreeGainLabel = std::make_unique<juce::Label>();
    createSliderAndLabel(m_oscThreeGainLabel.get(), "Osc3 Gain", m_oscThreeGainSlider.get(),
        625, 280, SLIDE_SIZE, SLIDE_SIZE);
    m_oscThreeGainAttach.reset(new SliderAttachment(m_vts, juce::String(OSC3_GAIN), *m_oscThreeGainSlider.get()));

    // ENVELOPE
    m_decaySlider = std::make_unique<juce::Slider>();
    m_decayLabel = std::make_unique<juce::Label>();
    createSliderAndLabel(m_decayLabel.get(), "Decay", m_decaySlider.get(),
        970, 265, SLIDE_SIZE, SLIDE_SIZE);
    m_decayAttach.reset(new SliderAttachment(m_vts, juce::String(DECAY), *m_decaySlider.get()));


    // wait .4 seconds, then grab keyboard focus to use as potential midi-input
    startTimer(400);
}

MainComponent::~MainComponent()
{}

void MainComponent::createSliderAndLabel(juce::Label* label, std::string labelText, juce::Slider* slider,
                                         int x, int y, int width, int height)
{
    addAndMakeVisible(slider);
    slider->setBounds(x, y, width, height);
    slider->setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    slider->setTextBoxStyle(juce::Slider::NoTextBox, true, 80, 20);

    addAndMakeVisible(label);
    label->setFont(juce::Font(15.00f, juce::Font::plain));
    label->setText(labelText, juce::dontSendNotification);
    label->setJustificationType(juce::Justification::centred);
    label->setEditable(false, true, false);
    label->setColour(juce::Label::textColourId, juce::Colour(0xffff8917));
    label->attachToComponent(slider, false);
}

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
{    auto area = getLocalBounds().removeFromBottom(275).removeFromRight(WIDTH-15).removeFromLeft(WIDTH - 30);
    keyboardComponent.setBounds(area);
}

void MainComponent::timerCallback()
{
    keyboardComponent.grabKeyboardFocus();
    stopTimer();
}