#ifndef PARTICLESET_HPP
#define PARTICLESET_HPP

#include <vector>

#include "FractalContext.hpp"

class ParticleSet : public sf::Drawable
{
    public:
        ParticleSet();
        void add(FractalContext *particle);

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void update(double delta_t);

    protected:
        std::vector<FractalContext*> particles;
};

#endif

