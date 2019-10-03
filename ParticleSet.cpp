#include "ParticleSet.hpp"

ParticleSet::ParticleSet()
{
}

void ParticleSet::add(FractalContext *particle)
{
    particles.push_back(particle);
}

void ParticleSet::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(const auto &particle : particles)
        particle->draw(target, states);
}

void ParticleSet::update(double delta_t)
{
    for(auto &particle : particles)
        particle->update(delta_t);
}

