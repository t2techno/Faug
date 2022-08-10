/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "../ParamsList.h"
#include "PluginEditor.h"
#include "MainComponent.h"

//==============================================================================
FaugAudioProcessorEditor::FaugAudioProcessorEditor (FaugAudioProcessor& p, juce::MidiKeyboardState& state, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    double ratio = 16.0 / 9.0;

    originalScreen = juce::Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    int width = originalScreen.getWidth();
    int height = originalScreen.getHeight();

    m_main = std::make_unique<MainComponent>(state, vts, height * ratio, height);
    addAndMakeVisible(*m_main.get());

    m_scope = std::make_unique<Spectroscope>();
    addAndMakeVisible(*m_scope.get());

    m_scope->setColors(juce::Colour::fromRGBA(255, 186, 34, 255),
        juce::Colour::fromRGBA(253, 174, 25, 255).withAlpha(0.7f),
        juce::Colour::fromRGBA(255, 126, 0, 255).withAlpha(0.7f));

    m_glContext.setComponentPaintingEnabled(true);
    m_glContext.attachTo(*this);

    setResizable(true, false);
    setResizeLimits(1280,1280/ratio,3840,3840/ratio);
    getConstrainer()->setFixedAspectRatio(ratio);
    setSize(height*ratio, height);

}

FaugAudioProcessorEditor::~FaugAudioProcessorEditor()
{
    m_glContext.detach();
}

//==============================================================================
void FaugAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Faug", getLocalBounds(), juce::Justification::centred, 1);
}

void FaugAudioProcessorEditor::resized()
{
    juce::Rectangle<int> resizedWindow = getLocalBounds();

    // keep my aspect ratio
    float scaleAmount = float(resizedWindow.getWidth()) / float(originalScreen.getWidth());
    juce::AffineTransform transform = juce::AffineTransform().scale(scaleAmount);
    m_main->setTransform(transform);

    auto area = getLocalBounds().removeFromBottom(originalScreen.getHeight()*.27).removeFromRight(originalScreen.getWidth() * .35).removeFromLeft(originalScreen.getWidth());
    m_scope->setBounds(area);
}

Spectroscope* FaugAudioProcessorEditor::getScope() {
    return m_scope.get();
}