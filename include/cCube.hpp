#ifndef CCUBE_HPP
#define CCUBE_HPP

#include "cRect.hpp"
#include "cMatrix.h"
#include "shape3d.hpp"
#include <cmath>

class cCube: public shape3d
{
    public:
        cCube(float ,float ,float );
        cCube() = delete;
        virtual ~cCube();
        cCube(const cCube& other);


        sf::Vector2f vector3to2(const sf::Vector3f& v3);
        sf::Vector3f vector2to3(const sf::Vector2f& v2);
        cMatrix vector3toMatrix(const sf::Vector3f& v3);
        sf::Vector3f matrixToVector3(const cMatrix& m);

        void update();
        void reverseUpdate();

        void rotateX(double angle);
        void rotateY(double angle);
        void rotateZ(double angle);

        void addPerspective();
        void getZ0();

        void fillVector2d();
        void print() const;


    protected:

    private:

         void draw(sf::RenderTarget& target,sf::RenderStates states)const override;

        float X,Y,Length,Z0;
        sf::Vector3f mPoints3[8];
        sf::Vector2f mPoints2[8]; // tylko do wyswietlania
        sf::Vector3f mTempPoints3[8];
        //cMatrix *mMatrixOfVector = new cMatrix(1, 4);
};

#endif // CCUBE_HPP
