#ifndef CMATRIX_H
#define CMATRIX_H
#include <array>
#include <iostream>

class cMatrix
{

public:
    cMatrix(int, int);
    cMatrix(int);
    virtual ~cMatrix();
    cMatrix(const cMatrix& other);

    //functions
    void mFill();
    void mFill(double aTab[],int tabLength);
    void mShow() const;
    cMatrix multiMatrix(const cMatrix& other) const;
    cMatrix multiMatrixAndNumber(double) const;
    cMatrix addMatrix(const cMatrix& other) const;
    cMatrix substractMatrix(const cMatrix& other) const;

    double getVectorX() const;
    double getVectorY() const;
    double getVectorZ() const;


    cMatrix& operator=(const cMatrix&);
    cMatrix operator+(const cMatrix&) const;
    cMatrix operator-(const cMatrix&) const;
    cMatrix operator*(const cMatrix&) const;
    cMatrix operator*(const double&) const;
    cMatrix& operator+=(const cMatrix&);
    cMatrix& operator-=(const cMatrix&);
    cMatrix& operator*=(const cMatrix&);
    friend std::ostream& operator<<(std::ostream& os, const cMatrix other);



protected:

private:
    int  row = 3, col = 3;
    double ** mMatrix;
    //std::array<double, row >mMatrix;
    //mMatrix = new double[col];
};

#endif // CMATRIX_H
