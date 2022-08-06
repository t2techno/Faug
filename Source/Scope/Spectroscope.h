/*
  ==============================================================================

    Spectroscope.h
    Created: 5 Aug 2022 6:54:55pm
    Author:  tytu1

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Spectroscope  : public juce::Component,
                             juce::Timer
{
public:
    Spectroscope();
    ~Spectroscope() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void timerCallback() override;

    void pushBuffer(juce::AudioSampleBuffer& buffer);
    inline void pushSample(float sample);

    void setColors(juce::Colour strokeColor, juce::Colour fillStartColour, juce::Colour fillStopColour);

    enum
    {
        kFFTOrder = 11,
        kFFTSize = 2048,
        kOutputSize = 1024,
    };

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Spectroscope)

    float m_fifo[kFFTSize];
    float m_fftData[2*kFFTSize];
    float m_outputData[kOutputSize];

    unsigned int m_fifoIndex;
    bool m_fftBlockReady;

    juce::dsp::FFT m_forwardFFT;
    juce::dsp::WindowingFunction<float> m_window;

    juce::Colour m_strokeColor;
    juce::Colour m_fillStartColor;
    juce::Colour m_fillStopColor;
};
