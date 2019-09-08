#ifndef FRACTALCONTEXT_HPP
#define FRACTALCONTEXT_HPP

#include <string>

#include <SFML/Graphics.hpp>

class FractalContext : public sf::Sprite
{
    public:
        FractalContext(size_t width, size_t height, std::string fragment_filename);

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        virtual void update(double delta_t);

    protected:
        sf::Shader shader;
        sf::Texture texture;
        sf::Sprite sprite;

        size_t width;
        size_t height;
        double t;
};

#endif

