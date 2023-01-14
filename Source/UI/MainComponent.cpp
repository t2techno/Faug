// Main Component, holds the primary synth UI
// Todo: Move MidiKeyboardComponent to it's own class to be added/removed

#include "MainComponent.h"
#include "../Constants.h"

MainComponent::MainComponent(juce::MidiKeyboardState& keyboardState, juce::AudioProcessorValueTreeState& vts, int window_width, int window_height)
    : m_vts(vts), keyboardComponent(keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard), window_width(window_width), window_height(window_height)

{
    initializeAssets();

    setOpaque(true);

    createKeyboard();

    createController();

    createOscBank();

    createMixer();

    createFilterBank();

    createEnvelope();

    master_volume = std::make_unique<TinyFloatKnob>(m_vts, juce::String(VOLUME), *tinyFloatKnobLaf.get());
    placeElement(*master_volume, VOLUME);

    master_on = std::make_unique<BrownToggle>(m_vts, juce::String(ON), *brownToggleLaf.get());
    placeVerticalButton(*master_on.get(), ON);
    
    setSize(window_width, window_height);

    // wait .4 seconds, then grab keyboard focus to use as potential midi-input
    startTimer(400);
}

MainComponent::~MainComponent()
{
    
}

void MainComponent::initializeAssets()
{
    //knobs
    background     = juce::Drawable::createFromImageData(BinaryData::background_png, BinaryData::background_pngSize);
    floatKnobImage = std::make_unique<juce::Image>(juce::ImageFileFormat::loadFrom(BinaryData::knobOne_png,   BinaryData::knobOne_pngSize));
    intKnobImage   = std::make_unique<juce::Image>(juce::ImageFileFormat::loadFrom(BinaryData::knobTwo_png,   BinaryData::knobTwo_pngSize));
    screwKnobImage = std::make_unique<juce::Image>(juce::ImageFileFormat::loadFrom(BinaryData::screwKnob_png, BinaryData::screwKnob_pngSize));

    floatKnobLaf     = std::make_unique<KnobLookAndFeel>(*floatKnobImage.get(), getElWidth(FLOAT_KNOB_EX));
    tinyFloatKnobLaf = std::make_unique<KnobLookAndFeel>(*floatKnobImage.get(), getElWidth(TINY_FLOAT_KNOB_EX));
    bigFloatKnobLaf  = std::make_unique<KnobLookAndFeel>(*floatKnobImage.get(), getElWidth(BIG_FLOAT_KNOB_EX));
    intKnobLaf       = std::make_unique<KnobLookAndFeel>(*intKnobImage.get(),   getElWidth(INT_KNOB_EX));
    screwKnobLaf     = std::make_unique<KnobLookAndFeel>(*screwKnobImage.get(), getElWidth(SCREW_FLOAT_EX));

    //toggles
    orangeToggle = std::make_unique<juce::Image>(juce::ImageFileFormat::loadFrom(BinaryData::orangeToggle_png, BinaryData::orangeToggle_pngSize));
    blueToggle   = std::make_unique<juce::Image>(juce::ImageFileFormat::loadFrom(BinaryData::blueToggle_png, BinaryData::blueToggle_pngSize));
    brownToggle  = std::make_unique<juce::Image>(juce::ImageFileFormat::loadFrom(BinaryData::brownToggle_png, BinaryData::brownToggle_pngSize));
    whiteToggle  = std::make_unique<juce::Image>(juce::ImageFileFormat::loadFrom(BinaryData::whiteToggle_png, BinaryData::whiteToggle_pngSize));

    orangeToggleLaf    = std::make_unique<ToggleLookAndFeel>(*orangeToggle.get(), getElWidth(ORANGE_TOG_EX), getElHeight(ORANGE_TOG_EX));
    bigOrangeToggleLaf = std::make_unique<ToggleLookAndFeel>(*orangeToggle.get(), getElWidth(BIG_ORANGE_TOG_EX), getElHeight(BIG_ORANGE_TOG_EX));
    blueToggleLaf      = std::make_unique<ToggleLookAndFeel>(*blueToggle.get(), getElWidth(BLUE_TOG_EX), getElHeight(BLUE_TOG_EX));
    brownToggleLaf = std::make_unique<ToggleLookAndFeel>(*brownToggle.get(), getElWidth(BROWN_TOG_EX), getElHeight(BROWN_TOG_EX));
    whiteToggleLaf = std::make_unique<ToggleLookAndFeel>(*whiteToggle.get(), getElWidth(WHITE_TOG_EX), getElHeight(WHITE_TOG_EX));

    //modWheel
    modWheelImage   = std::make_unique<juce::Image>(juce::ImageFileFormat::loadFrom(BinaryData::wheel_png, BinaryData::wheel_pngSize));
    modWheelShading = std::make_unique<juce::Image>(juce::ImageFileFormat::loadFrom(BinaryData::wheelShading_png, BinaryData::wheelShading_pngSize));
    modWheelLaf     = std::make_unique<ModWheelLookAndFeel>(*modWheelImage.get(), *modWheelShading.get(), getElWidth(MOD_WHEEL_EX), getElHeight(MOD_WHEEL_EX));
}

void MainComponent::createKeyboard() 
{
    addAndMakeVisible(keyboardComponent);
    keyboardComponent.setKeyWidth(40);

    m_glideOn = std::make_unique<WhiteToggle>(m_vts, juce::String(GLIDE_ON), *whiteToggleLaf.get());
    placeElement(*m_glideOn.get(), GLIDE_ON);

    m_decayOn = std::make_unique<WhiteToggle>(m_vts, juce::String(DECAY_ON), *whiteToggleLaf.get());
    placeElement(*m_decayOn.get(), DECAY_ON);

    m_modAmount = std::make_unique<ModWheel>(m_vts, juce::String(MOD_AMOUNT), *modWheelLaf.get());
    placeElement(*m_modAmount.get(), MOD_AMOUNT);

    m_pitchBend = std::make_unique<ModWheel>(m_vts, juce::String(PITCH_BEND), *modWheelLaf.get());
    placeElement(*m_pitchBend.get(), PITCH_BEND);

    m_lfoRate = std::make_unique<TinyFloatKnob>(m_vts, juce::String(LFO_RATE), *tinyFloatKnobLaf.get());
    placeElement(*m_lfoRate.get(), LFO_RATE);
}

void MainComponent::createController()
{
    m_globalDetune = std::make_unique<FloatKnob>(m_vts, juce::String(GLOBAL_DETUNE), *floatKnobLaf.get());
    placeElement(*m_globalDetune, GLOBAL_DETUNE);

    m_glide = std::make_unique<FloatKnob>(m_vts, juce::String(GLIDE_RATE), *floatKnobLaf.get());
    placeElement(*m_glide.get(), GLIDE_RATE);

    m_oscModOn = std::make_unique<BigOrangeToggle>(m_vts, juce::String(OSC_MOD_ON), *bigOrangeToggleLaf.get());
    placeElement(*m_oscModOn.get(), OSC_MOD_ON);

    m_modMix = std::make_unique<FloatKnob>(m_vts, juce::String(MOD_MIX), *floatKnobLaf.get());
    placeElement(*m_modMix.get(), MOD_MIX);

    m_osc3_filterEG_modSrc = std::make_unique<BrownToggle>(m_vts, juce::String(OSC3_FILTEG_MOD), *brownToggleLaf.get());
    placeElement(*m_osc3_filterEG_modSrc.get(), OSC3_FILTEG_MOD);

    m_noise_lfo_modSrc = std::make_unique<BrownToggle>(m_vts, juce::String(NOISE_LFO_MOD), *brownToggleLaf.get());
    placeElement(*m_noise_lfo_modSrc.get(), NOISE_LFO_MOD);
}

void MainComponent::createOscBank()
{
    // OSC ONE
    m_oscOneRange = std::make_unique<IntKnob>(m_vts, juce::String(OSC1_RANGE), *intKnobLaf.get());
    placeElement(*m_oscOneRange.get(), OSC1_RANGE);

    m_oscOneWaveForm = std::make_unique<IntKnob>(m_vts, juce::String(OSC1_WAVE), *intKnobLaf.get());
    placeElement(*m_oscOneWaveForm.get(), OSC1_WAVE);
    
    // OSC Two
    m_oscTwoRange = std::make_unique<IntKnob>(m_vts, juce::String(OSC2_RANGE), *intKnobLaf.get());
    placeElement(*m_oscTwoRange.get(), OSC2_RANGE);

    m_oscTwoDetune = std::make_unique<BigFloatKnob>(m_vts, juce::String(OSC2_DETUNE), *bigFloatKnobLaf.get());
    placeElement(*m_oscTwoDetune.get(), OSC2_DETUNE);

    m_oscTwoWaveForm = std::make_unique<IntKnob>(m_vts, juce::String(OSC2_WAVE), *intKnobLaf.get());
    placeElement(*m_oscTwoWaveForm.get(), OSC2_WAVE);

    // OSC Three
    m_oscThreeRange = std::make_unique<IntKnob>(m_vts, juce::String(OSC3_RANGE), *intKnobLaf.get());
    placeElement(*m_oscThreeRange.get(), OSC3_RANGE);

    m_oscThreeDetune = std::make_unique<BigFloatKnob>(m_vts, juce::String(OSC3_DETUNE), *bigFloatKnobLaf.get());
    placeElement(*m_oscThreeDetune.get(), OSC3_DETUNE);

    m_oscThreeWaveForm = std::make_unique<IntKnob>(m_vts,  juce::String(OSC3_WAVE), *intKnobLaf.get());
    placeElement(*m_oscThreeWaveForm.get(), OSC3_WAVE);

    m_osc3Ctrl = std::make_unique<BigOrangeToggle>(m_vts, juce::String(OSC3_CTRL), *bigOrangeToggleLaf.get());
    placeVerticalButton(*m_osc3Ctrl.get(), OSC3_CTRL);
}

void MainComponent::createMixer()
{
    m_load = std::make_unique<ScrewFloatKnob>(m_vts, juce::String(LOAD), *screwKnobLaf.get());
    placeElement(*m_load.get(), LOAD);

    // Oscillators
    m_oscOneGain = std::make_unique<FloatKnob>(m_vts, juce::String(OSC1_GAIN), *floatKnobLaf.get());
    placeElement(*m_oscOneGain.get(), OSC1_GAIN);

    m_oscOnePowerButton = std::make_unique<BlueToggle>(m_vts, juce::String(OSC1_ON), *blueToggleLaf.get());
    placeElement(*m_oscOnePowerButton.get(), OSC1_ON);

    m_oscTwoGain = std::make_unique<FloatKnob>(m_vts, juce::String(OSC2_GAIN), *floatKnobLaf.get());
    placeElement(*m_oscTwoGain.get(), OSC2_GAIN);

    m_oscTwoPowerButton = std::make_unique<BlueToggle>(m_vts, juce::String(OSC2_ON), *blueToggleLaf.get());
    placeElement(*m_oscTwoPowerButton.get(), OSC2_ON);

    m_oscThreeGain = std::make_unique<FloatKnob>(m_vts, juce::String(OSC3_GAIN), *floatKnobLaf.get());
    placeElement(*m_oscThreeGain.get(), OSC3_GAIN);

    m_oscThreePowerButton = std::make_unique<BlueToggle>(m_vts, juce::String(OSC3_ON), *blueToggleLaf.get());
    placeElement(*m_oscThreePowerButton.get(), OSC3_ON);

    m_feedbackGain = std::make_unique<FloatKnob>(m_vts, juce::String(FEEDBACK_GAIN), *floatKnobLaf.get());
    placeElement(*m_feedbackGain.get(), FEEDBACK_GAIN);

    m_feedbackOn = std::make_unique<BlueToggle>(m_vts, juce::String(FEEDBACK_ON), *blueToggleLaf.get());
    placeElement(*m_feedbackOn.get(), FEEDBACK_ON);

    // Noise
    m_noiseGain = std::make_unique<FloatKnob>(m_vts, juce::String(NOISE_GAIN), *floatKnobLaf.get());
    placeElement(*m_noiseGain.get(), NOISE_GAIN);

    m_noiseOn = std::make_unique<BlueToggle>(m_vts, juce::String(NOISE_ON), *blueToggleLaf.get());
    placeElement(*m_noiseOn.get(), NOISE_ON);

    m_noiseType = std::make_unique<BlueToggle>(m_vts, juce::String(NOISE_TYPE), *blueToggleLaf.get());
    placeVerticalButton(*m_noiseType.get(), NOISE_TYPE);
}

void MainComponent::createFilterBank()
{
    // filter/controller border
    m_filterModOn = std::make_unique<OrangeToggle>(m_vts, juce::String(F_MOD_ON), *orangeToggleLaf.get());
    placeElement(*m_filterModOn.get(), F_MOD_ON);

    m_keyTrackOne = std::make_unique<OrangeToggle>(m_vts, juce::String(KEY_TRK1), *orangeToggleLaf.get());
    placeElement(*m_keyTrackOne.get(), KEY_TRK1);

    m_keyTrackTwo = std::make_unique<OrangeToggle>(m_vts, juce::String(KEY_TRK2), *orangeToggleLaf.get());
    placeElement(*m_keyTrackTwo.get(), KEY_TRK2);

    // Row One - Filter Frequency
    m_filterCutoff = std::make_unique<FloatKnob>(m_vts,  juce::String(F_CUTOFF), *floatKnobLaf.get());
    placeElement(*m_filterCutoff.get(), F_CUTOFF);

    m_filterQ = std::make_unique<FloatKnob>(m_vts,  juce::String(F_Q), *floatKnobLaf.get());
    placeElement(*m_filterQ.get(), F_Q);

    m_filterContourAmount = std::make_unique<FloatKnob>(m_vts,  juce::String(F_ENV_AMOUNT), *floatKnobLaf.get());
    placeElement(*m_filterContourAmount.get(), F_ENV_AMOUNT);

    // Row Two - Filter Envelope
    m_filterAttack = std::make_unique<FloatKnob>(m_vts,  juce::String(F_ATTACK), *floatKnobLaf.get());
    placeElement(*m_filterAttack.get(), F_ATTACK);

    m_filterDecay = std::make_unique<FloatKnob>(m_vts,  juce::String(F_DECAY), *floatKnobLaf.get());
    placeElement(*m_filterDecay.get(), F_DECAY);

    m_filterSustain = std::make_unique<FloatKnob>(m_vts,  juce::String(F_SUSTAIN), *floatKnobLaf.get());
    placeElement(*m_filterSustain.get(), F_SUSTAIN);
}

void MainComponent::createEnvelope()
{
    m_attack = std::make_unique<FloatKnob>(m_vts,  juce::String(ATTACK), *floatKnobLaf.get());
    placeElement(*m_attack.get(), ATTACK);

    m_decay = std::make_unique<FloatKnob>(m_vts,  juce::String(DECAY), *floatKnobLaf.get());
    placeElement(*m_decay.get(), DECAY);

    m_sustain = std::make_unique<FloatKnob>(m_vts,  juce::String(SUSTAIN), *floatKnobLaf.get());
    placeElement(*m_sustain.get(), SUSTAIN);
}

void MainComponent::placeElement(juce::Component& comp, std::string label)
{
    comp.setBounds(guiPositions.at(label)[0] * window_width,
        guiPositions.at(label)[1] * window_height,
        getElWidth(label), getElHeight(label));
    addAndMakeVisible(comp);
}

void MainComponent::placeVerticalButton(juce::Component& comp, std::string label)
{
    float x = guiPositions.at((label))[0] * float(window_width);
    float y = guiPositions.at((label))[1] * float(window_height);
    float width = guiPositions.at((label))[2] * float(window_width);
    float height = guiPositions.at((label))[3] * float(window_height);
    comp.setTransform(juce::AffineTransform().rotated(juce::MathConstants<float>::halfPi,
        x + (width / 2), y + (height / 2)));
    comp.setBounds(x, y, width, height);
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
{    
    auto area = getLocalBounds().removeFromBottom(window_height * .2925).removeFromRight(window_width * 0.825).removeFromLeft(window_width * 0.8);
    keyboardComponent.setBounds(area);
}

void MainComponent::timerCallback()
{
    if (this->isShowing()) {
        keyboardComponent.grabKeyboardFocus();
    }
    stopTimer();
}