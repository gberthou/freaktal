#include "../FractalContext.hpp"

class Mandelbrot0 : public FractalContext
{
    public:
        Mandelbrot0(size_t width, size_t height);
        virtual void update(double delta_t);

        void setPosition(const sf::Vector3f &position);
        void setSize(const sf::Vector2f &size);
        void setBailout(float bailout);
        void setPower(float power);

    private:
        sf::Vector3f position;
        float k;
        float p;
};
