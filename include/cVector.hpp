#ifndef CVECTOR_HPP
#define CVECTOR_HPP


class cVector
{
public:
    //constructors
    cVector(int, int,int);
    cVector(int, int);
    cVector(int);
    cVector();
    cVector(const cVector& other);

    //operators
    cVector& operator=(const cVector&);
    cVector operator+(const cVector&);
    cVector operator-(const cVector&);
    cVector& operator+=(const cVector&);
    cVector& operator-=(const cVector&);
    cVector operator*(double);

    friend cVector operator*(double, const cVector&);

    //operations
    double skalarMulti(const cVector);
    cVector vectorMulti(const cVector);

    virtual ~cVector();

    int x,y,z;
protected:

private:
};

#endif // CVECTOR_HPP
