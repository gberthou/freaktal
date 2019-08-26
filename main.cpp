#include <SFML/Graphics.hpp>

#include "fragments/Mandelbrot0.hpp"

const size_t WIDTH = 800;
const size_t HEIGHT = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    Mandelbrot0 fractal(WIDTH, HEIGHT);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        fractal.update(1.f / 60.f);

        window.clear();
        window.draw(fractal);
        window.display();
    }
    return EXIT_SUCCESS;
}

