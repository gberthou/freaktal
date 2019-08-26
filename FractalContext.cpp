#include <string>

#include <SFML/Graphics.hpp>

#include "FractalContext.hpp"

FractalContext::FractalContext(size_t width, size_t height, std::string fragment_filename):
    width(width),
    height(height),
    t(0.)
{
    shader.loadFromFile(fragment_filename, sf::Shader::Fragment);

    texture.create(width, height);
    sprite.setTexture(texture);
}

void FractalContext::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    target.draw(sprite, &shader);
}

void FractalContext::update(double delta_t)
{
    t += delta_t;
}

