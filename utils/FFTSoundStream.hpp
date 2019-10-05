#ifndef FFT_SOUND_STREAM
#define FFT_SOUND_STREAM

#include <SFML/Audio.hpp>
#include <fftw3.h>

#include "FFTNotifier.hpp"

class FFTSoundStream : public sf::SoundStream
{
    public:
        FFTSoundStream(const sf::SoundBuffer &buffer, FFTNotifier &notifier);
        ~FFTSoundStream();

        virtual bool onGetData(sf::SoundStream::Chunk &data);
        virtual void onSeek(sf::Time timeOffset);

    protected:
        const sf::SoundBuffer &buffer;
        size_t currentSample;
        size_t chunkSize;

        size_t fftSize;
        double *tin;
        double *tout;
        fftw_plan fftplan;

        FFTNotifier &notifier;
};

#endif

