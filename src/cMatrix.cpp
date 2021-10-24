#include "cMatrix.h"
#include <iostream>

cMatrix::cMatrix(int x, int y)
{
    row = y;
    col = x;
    mMatrix = new double * [y];
    for(int i = 0; i < y; i++)
        mMatrix[i] = new double[x];

    for(int i = 0; i < y; i++)
        for(int j = 0; j < x; j++)
            mMatrix[i][j] = 0;
    //std::cout << "konstruktor DWUARGUMENTOWYU" << std::endl;
}

cMatrix::cMatrix(int xy)
{
    row = xy;
    col = xy;
    mMatrix = new double * [xy];
    for(int i = 0; i < xy; i++)
        mMatrix[i] = new double[xy];

    for(int i = 0; i < xy; i++)
        for(int j = 0; j < xy; j++)
            mMatrix[i][j] = 0;

    //std::cout << "konstruktor KWADRATOWY" << std::endl;
}

cMatrix::cMatrix(const cMatrix& other)
{
    row = other.row;
    col = other.col;
    mMatrix = new double * [row];
    for(int i = 0; i < row; i++)
        mMatrix[i] = new double[col];

    for(int y = 0; y < row; y++)
        for(int x = 0; x < col; x++)
        {
            this->mMatrix[y][x] = other.mMatrix[y][x];
        }

    //std::cout << "konstruktor kopiujacy" << std::endl;
}

cMatrix::~cMatrix()
{
    for(int i = 0; i < row; i++)
        delete [] mMatrix[i];
    delete [] mMatrix;
    std::cout << "destruktor" << std::endl;
}

void cMatrix::mShow() const
{
    for(int y = 0; y < row; y++)
    {
        for(int x = 0; x < col; x++)
            std::cout << mMatrix[y][x] << " ";
        std::cout << std:: endl;
    }
}

void cMatrix::mFill()
{
    for(int x = 0; x < col; x++)
        for(int y = 0; y < row; y++)
            std::cin >> mMatrix[y][x];
}

void cMatrix::mFill(double aTab[], int tabLength)
{

    int maximum = this->col * this->row;
    int i =0;

    for(int y = 0; y < row; y++)
        for(int x = 0; x < col; x++)
        {
            if(i<maximum )
            {
                if(tabLength>i)
                {
                    this->mMatrix[y][x] = aTab[i];
                    i++;
                }
                else
                {
                    this->mMatrix[y][x] = 0;
                    i++;
                }
            }
            else
            {
                std::cout << "blad " << std::endl;
                break;
            }
        }
}

cMatrix cMatrix::multiMatrix(const cMatrix& other) const
{
    if(this->col == other.row)
    {
        int colA = this->col;
        int rowA = this->row;
        int colB = other.col;
        //int rowB = other.row;
//        std::cout << "colA = " << colA<< std::endl;
//        std::cout << "rowA = " << rowA<< std::endl;
//        std::cout << "colB = " << colB<< std::endl;

        double sum = 0;
        cMatrix temp(rowA, colB);

        for(int i = 0; i < rowA; i++)
        {
            for(int j = 0; j < colB; j++)
            {
                sum = 0;
                for(int k = 0; k < colA; k++)
                {
                    sum+= this->mMatrix[i][k] * other.mMatrix[k][j];
                }
                temp.mMatrix[i][j] = sum;
            }
        }

        temp.mShow();
        std::cout << "^ wymnozona macierz macierzy " << std::endl;
        return temp;
    }
    else
    {
        std::cout << "bledne dane macierzy *" << std::endl;
        return 0;
    }
}

cMatrix cMatrix::multiMatrixAndNumber(double number) const
{
    cMatrix temp(this->col, this->row);
    for(int x = 0; x < this->row; x++)
        for(int y = 0; y < this->col; y++)
            temp.mMatrix[x][y] = this->mMatrix[x][y] * number;

    return temp;
}

cMatrix cMatrix::addMatrix(const cMatrix& other) const
{
    if(this->col == other.col && this->row == other.row)
    {
        cMatrix temp(this->col, this->row);
        for(int x = 0; x < this->row; x++)
            for(int y = 0; y < this->col; y++)
            {

                temp.mMatrix[x][y] = this->mMatrix[x][y] + other.mMatrix[x][y];
            }
        return temp;
    }
    else
    {
        std::cout << "rozne rozmiary macierzy =" << std::endl;
        return 0;
    }
}

cMatrix cMatrix::substractMatrix(const cMatrix& other) const
{
    if(this->col == other.col && this->row == other.row)
    {
        cMatrix temp(this->col, this->row);
        for(int x = 0; x < this->row; x++)
            for(int y = 0; y < this->col; y++)
            {

                temp.mMatrix[x][y] = this->mMatrix[x][y] - other.mMatrix[x][y];
            }
        return temp;
    }
    else
    {
        std::cout << "rozne rozmiary macierzy " << std::endl;
        return 0;
    }
}

double cMatrix::getVectorX() const
{
    return this->mMatrix[0][0];
}
double cMatrix::getVectorY() const
{
    return this->mMatrix[0][1];
}

double cMatrix::getVectorZ() const
{
    return this->mMatrix[0][2];
}

//
//operatory
//
cMatrix& cMatrix::operator=(const cMatrix& other)
{
    std::cout << "start = " << std::endl;
    if(this->col == other.col && this->row == other.row)
    {
        for(int x = 0; x < this->row; x++)
            for(int y = 0; y < this->col; y++)
                this->mMatrix[x][y] = other.mMatrix[x][y];
        std::cout << "end = " << std::endl;
        return *this;
    }
    else
    {
        std::cout << "nieprawidlowe rozmiary macierzy " << std::endl;
        return *this;
    }
}

cMatrix cMatrix::operator+(const cMatrix& other) const
{
    return addMatrix(other);
}
cMatrix cMatrix::operator-(const cMatrix& other) const
{
    return substractMatrix(other);
}
cMatrix& cMatrix::operator+=(const cMatrix& other)
{
    if(this->col == other.col && this->row == other.row)
    {
        for(int x = 0; x < this->row; x++)
            for(int y = 0; y < this->col; y++)
                this->mMatrix[x][y] = this->mMatrix[x][y] + other.mMatrix[x][y];

        return *this;
    }
    else
    {
        std::cout << "nieprawidlowe rozmiary macierzy " << std::endl;
        return *this;
    }
}
cMatrix& cMatrix::operator-=(const cMatrix& other)
{
    if(this->col == other.col && this->row == other.row)
    {
        for(int x = 0; x < this->row; x++)
            for(int y = 0; y < this->col; y++)
                this->mMatrix[x][y] = this->mMatrix[x][y] - other.mMatrix[x][y];

        return *this;
    }
    else
    {
        std::cout << "nieprawidlowe rozmiary macierzy " << std::endl;
        return *this;
    }
}

cMatrix& cMatrix::operator*=(const cMatrix& other)
{
    if(this->col == other.col && this->row == other.row)
    {
        for(int x = 0; x < this->row; x++)
            for(int y = 0; y < this->col; y++)
                this->mMatrix[x][y] = this->mMatrix[x][y] * other.mMatrix[x][y];

        return *this;
    }
    else
    {
        std::cout << "nieprawidlowe rozmiary macierzy " << std::endl;
        return *this;
    }
}
cMatrix cMatrix::operator*(const cMatrix& other) const
{
    return multiMatrix(other);
}
cMatrix cMatrix::operator*(const double& number) const
{
    return multiMatrixAndNumber(number);
}

std::ostream& operator<<(std::ostream& os, const cMatrix other)
{
    other.mShow();
    return os;
}




