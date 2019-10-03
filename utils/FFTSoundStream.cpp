#include <iostream>

#include "FFTSoundStream.hpp"

const float CHUNK_DURATION_S = 20.0e-3; // 20 ms

FFTSoundStream::FFTSoundStream(const sf::SoundBuffer &buffer):
    buffer(buffer),
    currentSample(0),
    chunkSize(CHUNK_DURATION_S * buffer.getSampleRate() * buffer.getChannelCount()),

    fftSize(CHUNK_DURATION_S * buffer.getSampleRate()),
    tin(new double[fftSize]),
    tout(new double[fftSize]),
    fftplan(fftw_plan_r2r_1d(fftSize, tin, tout, FFTW_R2HC, FFTW_ESTIMATE))
{
    // Initialize base class
    initialize(buffer.getChannelCount(), buffer.getSampleRate());
}

FFTSoundStream::~FFTSoundStream()
{
    fftw_destroy_plan(fftplan);
    delete [] tin;
    delete [] tout;
}

bool FFTSoundStream::onGetData(sf::SoundStream::Chunk &data)
{
    data.samples = buffer.getSamples() + currentSample;
    if(currentSample + chunkSize >= buffer.getSampleCount()) // End of stream
    {
        data.sampleCount = buffer.getSampleCount() - currentSample;
        // Don't bother computing a FFT on uncomplete data
        return false;
    }
    // else, process chunkSize samples
    data.sampleCount = chunkSize;
    currentSample   += chunkSize;

    // Now, compute FFT
    for(size_t i = 0, j = 0; i < fftSize; ++i, j += getChannelCount())
        tin[i] = static_cast<double>(data.samples[j]) / 65536.0;
    fftw_execute(fftplan);

    for(size_t i = 0; i < fftSize; ++i)
        std::cout << tout[i] << ", ";
    std::cout << std::endl << std::endl;

    return true;
}

void FFTSoundStream::onSeek(sf::Time timeOffset)
{
    currentSample = timeOffset.asSeconds() * getSampleRate() * getChannelCount();
}

