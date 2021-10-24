#include "cRect.hpp"

cRect::cRect()
{
    X = 0;
    Y = 0;
    LengthX = 0;
    LengthY = 0;
    LengthZ = 0;
}

cRect::cRect(float ax, float ay)
{
    X = ax;
    Y = ay;
    LengthX = 0;
    LengthY = 0;
    LengthZ = 0;
}


cRect::~cRect()
{
    //dtor
}

cRect::cRect(const cRect& other)
{
    //copy ctor
}


void cRect::setPositon(float ax, float ay)
{
    X = ax;
    Y = ay;
}
void cRect::setLength(float ax, float ay, float az)
{
    LengthX = ax;
    LengthY = ay;
    LengthZ = az;
}
