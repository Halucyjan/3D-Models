#include "cCube.hpp"
#include <iostream>

cCube::cCube(float ax,float ay,float al): X(ax),Y(ay),Length(al)
{

    mPoints3[0]= sf::Vector3f(-1,   -1,   -1);
    mPoints3[1]= sf::Vector3f(-1,   -1,    1);
    mPoints3[2]= sf::Vector3f(-1,    1,    1);
    mPoints3[3]= sf::Vector3f(-1,    1,   -1);
    mPoints3[4]= sf::Vector3f( 1,    1,   -1);
    mPoints3[5]= sf::Vector3f( 1,   -1,   -1);
    mPoints3[6]= sf::Vector3f( 1,   -1,    1);
    mPoints3[7]= sf::Vector3f( 1,    1,    1);

    for(int i = 0; i < 8; i++)
    {
        mTempPoints3[i] = mPoints3[i] * Length + sf::Vector3f(X,Y,0);
    }

    this->fillVector2d();
}

cCube::~cCube()
{
    //dtor
    //delete mMatrixOfVector ;
}

cCube::cCube(const cCube& other)
{
    //copy ctor
}

//
//functions
//

sf::Vector2f cCube::vector3to2(const sf::Vector3f& v3)
{
    return sf::Vector2f(v3.x, v3.y);
}
sf::Vector3f cCube::vector2to3(const sf::Vector2f& v2)
{
    return sf::Vector3f(v2.x, v2.y, 0);
}

void cCube::fillVector2d()
{
    for(int i = 0; i < 8; i++)
    {
        mPoints2[i] = vector3to2(this->mTempPoints3[i]);
    }
}

cMatrix cCube::vector3toMatrix(const sf::Vector3f& v3)
{
    cMatrix temp(4, 1);
    int tabLength = 4;
    double tab[tabLength];
    tab[0] = v3.x;
    tab[1] = v3.y;
    tab[2] = v3.z;
    tab[3] = 1;
        //M0.mFill(tablica0,9);

    temp.mFill( tab,tabLength);

    temp.mShow();
    std::cout << "^ wyswietlanie vector3toMatrix" << std::endl;
    return temp;
}

sf::Vector3f cCube::matrixToVector3(const cMatrix& m)
{
    sf::Vector3f temp(m.getVectorX(), m.getVectorY(), m.getVectorZ());
    return temp;
}

void cCube::print() const
{
    std::cout << "V3\n";
    for(int i = 0; i < 8; i++)
    {
        std::cout << i << ". x = " << mPoints3[i].x << " y = " << mPoints3[i].y <<" z = " << mPoints3[i].z << std::endl;
    }

    std::cout << "V2\n";
    for(int i = 0; i < 8; i++)
    {
        std::cout << i << ". x = " << mPoints2[i].x << " y = " << mPoints2[i].y << std::endl;
    }
}

void cCube::rotateX(double angle)
{

    double tx, ty, tz;
    for(int i = 0; i<8; i++)
    {
        tx = this->mPoints3[i].x;
        ty = this->mPoints3[i].y;
        tz = this->mPoints3[i].z;
        this->mPoints3[i].x = tx;
        this->mPoints3[i].y = (ty * cos(angle)- tz * sin(angle));
        this->mPoints3[i].z = (ty * sin(angle)+ tz * cos(angle));
    }
}

void cCube::rotateY(double angle)
{
    double tx, ty, tz;
    for(int i = 0; i<8; i++)
    {
        tx = this->mPoints3[i].x;
        ty = this->mPoints3[i].y;
        tz = this->mPoints3[i].z;
        this->mPoints3[i].x = ( tx * cos(angle)+ tz * sin(angle));
        this->mPoints3[i].y = ty ;
        this->mPoints3[i].z = (-tx * sin(angle)+ tz * cos(angle));
    }
}

void cCube::rotateZ(double angle)
{
    double tx, ty, tz;
    for(int i = 0; i<8; i++)
    {
        tx = this->mPoints3[i].x;
        ty = this->mPoints3[i].y;
        tz = this->mPoints3[i].z;
        this->mPoints3[i].x = ( ty * sin(angle)+ tx * cos(angle));
        this->mPoints3[i].y = ( ty * cos(angle)- tx * sin(angle));
        this->mPoints3[i].z = tz;
    }
}

void cCube::addPerspective()
{
    this->getZ0();
    double tx, ty, tz;
    for(int i = 0; i<8; i++)
    {
        tx = this->mPoints3[i].x;
        ty = this->mPoints3[i].y;
        tz = this->mPoints3[i].z;
        this->mPoints3[i].x = (tx * this->Z0) /(this->Z0 + tz);
        this->mPoints3[i].y = (ty * this->Z0) /(this->Z0 + tz);
        this->mPoints3[i].z = tz;

        //mPoints3[i].x;
    }


}

void cCube::getZ0()
{
    this->Z0 = (400 / 2) / (tan(45/2) * 3.14159/180);
}

void cCube::update()
{
    for(int i = 0; i < 8; i++)
    {
        mTempPoints3[i] = mPoints3[i] * Length + sf::Vector3f(X,Y,0); ;
    }
    this->fillVector2d();
}

//void cCube::reverseUpdate()
//{
//    for(int i = 0; i < 8; i++)
//    {
//        mPoints3[i] = mPoints3[i] / this->Length;
//        mPoints3[i] = mPoints3[i] - sf::Vector3f(this->X,this->Y,0);
//    }
//    this->fillVector2d();
//}

void cCube::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
    sf::Vertex line[24];


//    for(int i = 0; i < 7; i+=2)
//    {
//        //line[i-1]=sf::Vertex(mPoints2[i-1],sf::Color::White);
//        line[i]=sf::Vertex(mPoints2[i],sf::Color::White);
//        line[i+1]=sf::Vertex(mPoints2[i+1],sf::Color::White);
//    }
    line[0]=sf::Vertex(mPoints2[0],sf::Color::White);
    line[1]=sf::Vertex(mPoints2[1],sf::Color::White);

    line[2]=sf::Vertex(mPoints2[2],sf::Color::White);
    line[3]=sf::Vertex(mPoints2[3],sf::Color::White);

    line[4]=sf::Vertex(mPoints2[4],sf::Color::White);
    line[5]=sf::Vertex(mPoints2[5],sf::Color::White);

    line[6]=sf::Vertex(mPoints2[6],sf::Color::White);
    line[7]=sf::Vertex(mPoints2[7],sf::Color::White);


    line[18]=sf::Vertex(mPoints2[1],sf::Color::White);
    line[19]=sf::Vertex(mPoints2[2],sf::Color::White);

    line[20]=sf::Vertex(mPoints2[3],sf::Color::White);
    line[21]=sf::Vertex(mPoints2[4],sf::Color::White);

    line[22]=sf::Vertex(mPoints2[5],sf::Color::White);
    line[23]=sf::Vertex(mPoints2[6],sf::Color::White);


    line[8]=sf::Vertex(mPoints2[1],sf::Color::White);
    line[9]=sf::Vertex(mPoints2[6],sf::Color::White);

    line[10]=sf::Vertex(mPoints2[2],sf::Color::White);
    line[11]=sf::Vertex(mPoints2[7],sf::Color::White);

    line[12]=sf::Vertex(mPoints2[4],sf::Color::White);
    line[13]=sf::Vertex(mPoints2[7],sf::Color::White);

    line[14]=sf::Vertex(mPoints2[0],sf::Color::White);
    line[15]=sf::Vertex(mPoints2[5],sf::Color::White);

    line[16]=sf::Vertex(mPoints2[0],sf::Color::White);
    line[17]=sf::Vertex(mPoints2[3],sf::Color::White);

    target.draw(line,24,sf::Lines,states);


//    sf::Vertex line[2];
//line[0]=sf::Vertex(sf::Vector2f(100, 100),sf::Color::White);
//line[1]=sf::Vertex(sf::Vector2f(200, 200),sf::Color::White);
//target.draw(line, 2, sf::Lines, states);
}


//
//matrix
//
//double rotX[16] =  {1, 0,           0,          1,
//                    0, cos(angle), -sin(angle), 1,
//                    0, sin(angle),  cos(angle), 0,
//                    0, 0,           0,          1 };
//
//double rotY[16] =  {1,0,0,1,
//                    0,1,0,1,
//                    0,0,1,0,
//                    0,0,0,1 };
//
//double rotZ[16] =  {1,0,0,1,
//                    0,1,0,1,
//                    0,0,1,0,
//                    0,0,0,1 };
//
//double translation[16] =   {1,0,0,1,
//                            0,1,0,1,
//                            0,0,1,0,
//                            0,0,0,1 };
