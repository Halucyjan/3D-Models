#include "cVector.h"

cVector::cVector(int ax, int ay, int az):x(0), y(0), z(0)
{
    x = ax;
    y = ay;
    z = az;
}
cVector::cVector(int ax, int ay):x(0), y(0), z(0)
{
    x = ax;
    y = ay;
    z = 0;
}
cVector::cVector(int ax):x(0), y(0), z(0)
{
    x = ax;
    y = 0;
    z = 0;
}
cVector::cVector():x(0), y(0), z(0)
{
    x = 0;
    y = 0;
    z = 0;
}

cVector::~cVector()
{
    //dtor
}

cVector::cVector(const cVector& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
}

//operators
cVector& cVector::operator=(const cVector& other)
{
    x = other.x;
    y = other.y;
    z = other.z;

    return *this;
}

cVector cVector::operator+(const cVector& other)
{
    cVector temp;
    temp.x = this->x + other.x;
    temp.y = this->y + other.y;
    temp.z = this->z + other.z;
    return temp;
}

cVector cVector::operator-(const cVector& other)
{
    cVector temp;
    temp.x = this->x - other.x;
    temp.y = this->y - other.y;
    temp.z = this->z - other.z;
    return temp;
}

cVector& cVector::operator+=(const cVector& other)
{
    this->x = this->x + other.x;
    this->y = this->y + other.y;
    this->z = this->z + other.z;
    return *this;
}

cVector& cVector::operator-=(const cVector& other)
{
    this->x = this->x - other.x;
    this->y = this->y - other.y;
    this->z = this->z - other.z;
    return *this;
}

cVector cVector::operator*(double d)
{
    cVector temp;
    temp.x = this->x * d;
    temp.y = this->y * d;
    temp.z = this->z * d;
    return temp;
}


cVector operator*(double d,const cVector & v )
{
    cVector temp;
    temp.x = v.x * d;
    temp.y = v.y * d;
    temp.z = v.z * d;
    return temp;
}

//
//operations
//

double cVector::skalarMulti(const cVector v)
{
    return this->x * v.x + this->y * v.y + this->z * v.z;;
}

cVector cVector::vectorMulti(const cVector v)
{
    cVector temp;
    temp.x = (this->y * v.z) - (this->z * v.y);
    temp.y = (this->z * v.x) - (this->x * v.z);
    temp.z = (this->x * v.y) - (this->y * v.x);
    return temp;
}
