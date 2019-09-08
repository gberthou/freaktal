#include <SFML/Graphics.hpp>

#include "fragments/Mandelbrot0.hpp"
#include "fragments/Polar0.hpp"

#define ANIM_TYPE Polar0

const size_t WIDTH = 800;
const size_t HEIGHT = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    ANIM_TYPE anim(WIDTH, HEIGHT);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        anim.update(1.f / 60.f);

        window.clear();
        window.draw(anim);
        window.display();
    }
    return EXIT_SUCCESS;
}

