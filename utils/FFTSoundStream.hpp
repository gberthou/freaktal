#ifndef FFT_SOUND_STREAM
#define FFT_SOUND_STREAM

#include <SFML/Audio.hpp>

class FFTSoundStream : public sf::SoundStream
{
    public:
        FFTSoundStream(const sf::SoundBuffer &buffer);

        virtual bool onGetData(sf::SoundStream::Chunk &data);
        virtual void onSeek(sf::Time timeOffset);

    protected:
        const sf::SoundBuffer &buffer;
        size_t currentSample;
};

#endif

