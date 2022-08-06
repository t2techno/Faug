/*
  ==============================================================================

    Spectroscope.cpp
    Created: 5 Aug 2022 6:54:55pm
    Author:  tytu1

    // Reference: https://github.com/creativeintent/temper/blob/master/Source/SpectroscopeComponent.cpp

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Spectroscope.h"

//==============================================================================
Spectroscope::Spectroscope() :  m_fifoIndex(0),
                                m_fftBlockReady(false),
                                m_forwardFFT(kFFTOrder),
                                m_window(kFFTSize, juce::dsp::WindowingFunction<float>::hann),
                                m_strokeColor(juce::Colours::white),
                                m_fillStartColor(juce:: Colours::white.withAlpha(0.2f)),
                                m_fillStopColor(juce::Colours::white.withAlpha(0.8f))
{
    juce::zeromem(m_outputData, sizeof(m_outputData));
    setSize(700, 200);
    startTimerHz(30);
}

Spectroscope::~Spectroscope()
{
    stopTimer();
}

void Spectroscope::paint(juce::Graphics& g)
{
    const float width = (float)getWidth();
    const float height = (float)getHeight();

    // Clear the drawing target
    g.setColour(juce::Colours::transparentBlack);
    g.fillAll();

    // The values in the output bins after the FFT have a range that I don't understand
    // and isn't explained in the docs. It seems that if I scale down by the size of the
    // fft buffer, I get somewhat reasonable results on the graph. But in examples I've
    // seen, we would just divide here by the maximum value in the bins at the time of
    // drawing. Seeing as that would be inconsistent between frames, I'm defaulting to the
    // size of the fft here unless the max value in the bins is larger.
    juce::Range<float> maxBin = juce::FloatVectorOperations::findMinAndMax(m_outputData, kOutputSize);
    const float scale = 1.0f / juce::jmax((float)kFFTSize, maxBin.getEnd());

    g.setColour(m_fillStartColor);

    for (int i = 0; i < kOutputSize; ++i)
    {
        float x = std::log10(1 + 39 * ((i + 1.0f) / kOutputSize)) / std::log10(40.0f) * width;

        const float yMag = scale * m_outputData[i];
        const float yDecibel = juce::Decibels::gainToDecibels(yMag);
        const float y = juce::jmap(yDecibel, -90.0f, -12.0f, height, 0.0f);

        g.drawVerticalLine((int)x, y, height);
    }
}

void Spectroscope::resized()
{
}

void Spectroscope::timerCallback()
{
    if (m_fftBlockReady)
    {
        // Compute the frequency transform
        m_window.multiplyWithWindowingTable(m_fftData, kFFTSize);
        m_forwardFFT.performFrequencyOnlyForwardTransform(m_fftData);

        // Copy the frequency bins into the output data buffer, taking
        // max(output[i], fftData[i]) for each bin. Note that after computing the
        // FrequencyOnlyForwardTransform on an array A of size N, A[N/2, N) is full
        // of zeros, and A[0, N/4) is a mirror of A[N/4, N/2). Therefore we only copy
        // kFFTSize / 2 samples into the output data buffer here.
        juce::FloatVectorOperations::max(m_outputData, m_outputData, m_fftData, kOutputSize);

        m_fftBlockReady = false;
    }

    // Decay the output bin magnitudes
    for (int i = 0; i < kOutputSize; ++i)
        m_outputData[i] *= 0.707f;

    repaint();
}

void Spectroscope::pushBuffer(juce::AudioSampleBuffer& buffer)
{
    if (buffer.getNumChannels() > 0)
    {
        const int numSamples = buffer.getNumSamples();
        const float* channelData = buffer.getReadPointer(0);

        for (int i = 0; i < numSamples; ++i)
            pushSample(channelData[i]);
    }
}

inline void Spectroscope::pushSample(float sample)
{
    // When we wrap around the fifo table, we copy the data into the
    // FFT buffer and prepare to perform the transform.
    if (m_fifoIndex == kFFTSize)
    {
        if (!m_fftBlockReady)
        {
            juce::zeromem(m_fftData, sizeof(m_fftData));
            memcpy(m_fftData, m_fifo, sizeof(m_fifo));
            m_fftBlockReady = true;
        }

        m_fifoIndex = 0;
    }

    m_fifo[m_fifoIndex++] = sample;
}

void Spectroscope::setColors(juce::Colour strokeColor, juce::Colour fillStartColor, juce::Colour fillStopColor)
{
    m_strokeColor = strokeColor;
    m_fillStartColor = fillStartColor;
    m_fillStopColor = fillStopColor;
}