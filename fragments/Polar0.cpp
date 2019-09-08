#include <cmath>

#include "Polar0.hpp"

Polar0::Polar0(size_t width, size_t height):
    FractalContext(width, height, "fragments/polar0")
{
    shader.setUniform("N", 6);
    shader.setUniform("frequency", 6.f);
    shader.setUniform("outputSize", sf::Vector2f(width, height));
    shader.setUniform("dt", 0.f);
    shader.setUniform("rayscale", 1.f);
    shader.setUniform("rotation", 0.f);
}

void Polar0::update(double delta_t)
{
    FractalContext::update(delta_t);
    shader.setUniform("dt", static_cast<float>(t/6.));
    shader.setUniform("frequency", static_cast<float>(6+t/3.));
    shader.setUniform("rayscale", static_cast<float>(.5*(sin(2*M_PI*t)+1)));
    shader.setUniform("rotation", static_cast<float>(t/2.));
}

