#ifndef SHAPE3D_HPP
#define SHAPE3D_HPP
#include <SFML/Graphics.hpp>

class shape3d : public sf::Drawable
{
    public:
        shape3d();
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const = 0;

    protected:

    private:
};

#endif // SHAPE3D_HPP
