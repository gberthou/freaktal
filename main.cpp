#include <cmath>

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
    shader.setUniform("minIterations",10);
    shader.setUniform("colorMode", 0);
    shader.setUniform("colorScale", 1);
    shader.setUniform("colorCycle", 1);
    shader.setUniform("colorCycleOffset", 0);
    shader.setUniform("colorCycleMirror", true);
    shader.setUniform("hsv", false);
    shader.setUniform("iterationColorBlend", .1f);
    shader.setUniform("color1", sf::Vector3f(.7, .7, 1));
    shader.setUniform("color2", sf::Vector3f(1, 0, 1));
    shader.setUniform("color3", sf::Vector3f(0, 0, 0));
    shader.setUniform("rotation", 0.f);
    shader.setUniform("outputSize", sf::Vector2f(WIDTH, HEIGHT));

    sf::Texture tex;
    tex.create(WIDTH, HEIGHT);
    sf::Sprite sprite(tex);
    sprite.setPosition(0, 0);


    sf::Vector3f position(-1, -1, 2.5);
    float k = .5;
    float t = 0;
    float p = 2.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        sf::Vector2f size(WIDTH*k, HEIGHT*k);
        shader.setUniform("cameraPosition", position);
        shader.setUniform("size", size);
        shader.setUniform("bailout", 84.f + 80.f*(float)cos(2.f*M_PI*t));
        shader.setUniform("power", p);

        window.clear();
        window.draw(sprite, &shader);
        window.display();

        //k += .002;
        t += 1.f/60.;
        if(p > 0)
            p -= .001f;
        else if(p <= -2.f)
            p -= .01f;
        else
            p = -2.f;
    }
    return EXIT_SUCCESS;
}

