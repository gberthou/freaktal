#include <SFML/Graphics.hpp>

#include "fragments/Mandelbrot0.hpp"
#include "ParticleSet.hpp"

const size_t WIDTH = 800;
const size_t HEIGHT = 600;
const double DT = 1.f / 60.f;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    Mandelbrot0 fractal(WIDTH, HEIGHT);
    Mandelbrot0 particle0(WIDTH/2, HEIGHT/2);
    ParticleSet particles;
    particles.add(&particle0);

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

