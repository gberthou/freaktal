#include <cmath>

#include "Mandelbrot0.hpp"

Mandelbrot0::Mandelbrot0(size_t width, size_t height):
    FractalContext(width, height, "fragments/mandelbrot0"),
    position(-1, -1, 2.5),
    k(0.5),
    p(2.)
{
    shader.setUniform("minIterations",10);
    shader.setUniform("color1", sf::Vector3f(.7, .7, 1));
    shader.setUniform("color2", sf::Vector3f(1, 0, 1));
    shader.setUniform("color3", sf::Vector3f(0, 0, 0));
    shader.setUniform("rotation", 0.f);
    shader.setUniform("outputSize", sf::Vector2f(width, height));
}

void Mandelbrot0::update(double delta_t)
{
    FractalContext::update(delta_t);

    if(p > 0)
        p -= .001f;
    else if(p <= -2.f)
        p -= .01f;
    else
        p = -2.f;
    
    //k += .002;

    sf::Vector2f size(width*k, height*k);
    shader.setUniform("cameraPosition", position);
    shader.setUniform("size", size);
    shader.setUniform("bailout", 84.f + 80.f*(float)cos(2.f*M_PI*t));
    shader.setUniform("power", p);
}

void Mandelbrot0::setPosition(const sf::Vector3f &position)
{
    shader.setUniform("cameraPosition", position);
}

void Mandelbrot0::setSize(const sf::Vector2f &size)
{
    shader.setUniform("size", size);
}

void Mandelbrot0::setBailout(float bailout)
{
    shader.setUniform("bailout", bailout);
}

void Mandelbrot0::setPower(float power)
{
    shader.setUniform("power", power);
}

