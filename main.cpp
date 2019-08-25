#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

const size_t WIDTH = 800;
const size_t HEIGHT = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    sf::Shader shader;
    shader.loadFromFile("fragments/mandelbrot0", sf::Shader::Fragment);
    shader.setUniform("power", 2.f);
    shader.setUniform("bailout", 4.f);
    shader.setUniform("minIterations",10);
    shader.setUniform("colorMode", 0);
    shader.setUniform("bailoutStyle", 0);
    shader.setUniform("colorScale", 1);
    shader.setUniform("colorCycle", 1);
    shader.setUniform("colorCycleOffset", 0);
    shader.setUniform("colorCycleMirror", true);
    shader.setUniform("hsv", false);
    shader.setUniform("iterationColorBlend", .1f);
    shader.setUniform("color1", sf::Vector3f(1, 1, 1));
    shader.setUniform("color2", sf::Vector3f(0, 0.53, 0.8));
    shader.setUniform("color3", sf::Vector3f(0, 0, 1));
    shader.setUniform("rotation", 0.f);
    shader.setUniform("outputSize", sf::Vector2f(WIDTH, HEIGHT));

    sf::Texture tex;
    tex.create(WIDTH, HEIGHT);
    sf::Sprite sprite(tex);
    sprite.setPosition(0, 0);


    sf::Vector3f position(-1, -1, 2.5);
    float k = .5;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        sf::Vector2f size(WIDTH*k, HEIGHT*k);
        shader.setUniform("cameraPosition", position);
        shader.setUniform("size", size);

        window.clear();
        window.draw(sprite, &shader);
        window.display();

        k += .002;
    }
    return EXIT_SUCCESS;
}

