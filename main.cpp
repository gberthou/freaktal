#include <iostream>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "fragments/Mandelbrot0.hpp"
#include "ParticleSet.hpp"

#include "utils/FFTSoundStream.hpp"
#include "utils/FFTNotifier.hpp"

const size_t WIDTH = 800;
const size_t HEIGHT = 600;
const double DT = 1.f / 60.f;

class MyNotifier : public FFTNotifier
{
    public:
        MyNotifier(Mandelbrot0 &fractal):
            mb(fractal),
            formerSum(0.)
        {
        }

        virtual void notify(const double *fftout, size_t size)
        {
            const size_t N_BASS_SAMPLES = 2;
            double sum = 0.;

            for(size_t i = 0; i < N_BASS_SAMPLES && i < size; ++i)
                sum += *fftout++;
            sum /= N_BASS_SAMPLES;

            double d = sum - formerSum;
            if(d > 100)
                std::cout << d << std::endl;

            formerSum = sum;
        }

    protected:
        Mandelbrot0 &mb;
        double formerSum;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    Mandelbrot0 fractal(WIDTH, HEIGHT);
    Mandelbrot0 particle0(WIDTH/2, HEIGHT/2);
    ParticleSet particles;
    particles.add(&particle0);

    sf::SoundBuffer buffer;
    buffer.loadFromFile("le-perv.flac");

    MyNotifier notifier(fractal);
    FFTSoundStream stream(buffer, notifier);
    stream.play();

    float x = 0.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        fractal.update(DT);
        particles.update(DT);

        particle0.setPosition(x += 1, 0);

        window.clear();
        window.draw(fractal);
        window.draw(particles);
        window.display();
    }
    return EXIT_SUCCESS;
}

