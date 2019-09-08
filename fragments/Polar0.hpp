#ifndef POLAR0_HPP
#define POLAR0_HPP

#include "../FractalContext.hpp"

class Polar0 : public FractalContext
{
    public:
        Polar0(size_t width, size_t height);
        virtual void update(double delta_t);

    private:
};

#endif

