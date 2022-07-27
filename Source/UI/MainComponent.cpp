// Main Component, holds the primary synth UI
// Todo: Move MidiKeyboardComponent to it's own class to be added/removed

#include "MainComponent.h"
#include "../synth/ParamsList.h"

typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

MainComponent::MainComponent(juce::MidiKeyboardState& keyboardState, juce::AudioProcessorValueTreeState& vts)
    : m_vts(vts),
    keyboardComponent(keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)

{
    setOpaque(true);
    addAndMakeVisible(keyboardComponent);

    addAndMakeVisible(&m_decaySlider);
    m_decaySlider.setRange(1, 1000, 0);
    m_decaySlider.setBounds(200, 150, 100, 100);
    m_decaySlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    m_decaySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 80, 20);


    addAndMakeVisible(&m_decayLabel);
    m_decayLabel.setFont(juce::Font(15.00f, juce::Font::plain));
    m_decayLabel.setText("Decay", juce::dontSendNotification);
    m_decayLabel.setJustificationType(juce::Justification::centred);
    m_decayLabel.setEditable(false, true, false);
    m_decayLabel.setColour(juce::Label::textColourId, juce::Colour(0xffff8917));
    m_decayLabel.attachToComponent(&m_decaySlider, false);

    m_decayAttach.reset(new SliderAttachment(m_vts, juce::String(DECAY), m_decaySlider));

    setSize(1000, 500);

    // wait .4 seconds, then grab keyboard focus to use as potential midi-input
    startTimer(400);
}

MainComponent::~MainComponent()
{}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void MainComponent::resized()
{
    auto area = getLocalBounds();
    keyboardComponent.setBounds(area.removeFromTop(80).reduced(8));
}

void MainComponent::timerCallback()
{
    keyboardComponent.grabKeyboardFocus();
    stopTimer();
}