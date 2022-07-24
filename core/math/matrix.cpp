#include <cmath>

#include "matrix.hpp"
#include "vector.hpp"

Core::Matrix::Matrix()
{
    for (int i = 0; i < 16; i++)
    {
        m[i] = 0;
    }
}

Core::Matrix::Matrix(double m[16])
{
    for (int i = 0; i < 16; i++)
    {
        this->m[i] = m[i];
    }
}

Core::Matrix::Matrix(double m00, double m01, double m02, double m03,
                     double m10, double m11, double m12, double m13,
                     double m20, double m21, double m22, double m23,
                     double m30, double m31, double m32, double m33)
{
    m[0] = m00;
    m[1] = m01;
    m[2] = m02;
    m[3] = m03;
    m[4] = m10;
    m[5] = m11;
    m[6] = m12;
    m[7] = m13;
    m[8] = m20;
    m[9] = m21;
    m[10] = m22;
    m[11] = m23;
    m[12] = m30;
    m[13] = m31;
    m[14] = m32;
    m[15] = m33;
}

Core::Matrix::Matrix(const Core::Matrix& other)
{
    for (int i = 0; i < 16; i++)
    {
        m[i] = other.m[i];
    }
}

Core::Matrix& Core::Matrix::operator=(const Core::Matrix& other)
{
    for (int i = 0; i < 16; i++)
    {
        m[i] = other.m[i];
    }
    return *this;
}
