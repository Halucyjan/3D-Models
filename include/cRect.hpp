#ifndef CRECT_HPP
#define CRECT_HPP

#include <SFML/Graphics.hpp>

class cRect:public sf::Drawable
{
    public:
        cRect() ;
        cRect(float, float);
        //cRect(float, float, float,float);
        cRect(const cRect& other);

        virtual ~cRect();

        //funkcje
        void setPositon(float, float);
        void setLength(float, float, float);


    protected:

    private:

        float X,Y,LengthX, LengthY, LengthZ;
};

#endif // CRECT_HPP
