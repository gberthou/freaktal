#include "FFTSoundStream.hpp"

const float CHUNK_DURATION_S = 1.0e-3; // 1 ms

FFTSoundStream::FFTSoundStream(const sf::SoundBuffer &buffer):
    buffer(buffer),
    currentSample(0)
{
    // Initialize base class
    initialize(buffer.getChannelCount(), buffer.getSampleRate());
}

bool FFTSoundStream::onGetData(sf::SoundStream::Chunk &data)
{
    size_t chunkSize = CHUNK_DURATION_S * getSampleRate() * getChannelCount();

    data.samples = buffer.getSamples() + currentSample;

    if(currentSample + chunkSize < buffer.getSampleCount()) // End of stream
    {
        data.sampleCount = buffer.getSampleCount() - currentSample;
        return false;
    }
    // else, process chunkSize samples
    data.sampleCount = chunkSize;
    currentSample   += chunkSize;

    return true;
}

void FFTSoundStream::onSeek(sf::Time timeOffset)
{
    currentSample = timeOffset.asSeconds() * getSampleRate() * getChannelCount();
}

