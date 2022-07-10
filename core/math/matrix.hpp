#pragma once

namespace Core
{
    struct Vector;

    struct Matrix
    {
        double m[4][4];
        
        Matrix()
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    m[i][j] = 0;
                }
            }
        }
        
        Matrix(double m00, double m01, double m02, double m03,
               double m10, double m11, double m12, double m13,
               double m20, double m21, double m22, double m23,
               double m30, double m31, double m32, double m33)
        {
            m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
            m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
            m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
            m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
        }
        
        Matrix(const Matrix& other)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    m[i][j] = other.m[i][j];
                }
            }
        }
        
        Matrix(Matrix&& other)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    m[i][j] = other.m[i][j];
                }
            }
        }
        
        Matrix& operator=(const Matrix& other)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    m[i][j] = other.m[i][j];
                }
            }

            return *this;
        }
    };
}

Core::Matrix operator+(const Core::Matrix& lhs, const Core::Matrix& rhs);
Core::Matrix operator-(const Core::Matrix& lhs, const Core::Matrix& rhs);
Core::Matrix operator*(const Core::Matrix& lhs, const Core::Matrix& rhs);

Core::Matrix operator+=(Core::Matrix& lhs, const Core::Matrix& rhs);
Core::Matrix operator-=(Core::Matrix& lhs, const Core::Matrix& rhs);
Core::Matrix operator*=(Core::Matrix& lhs, const Core::Matrix& rhs);

Core::Matrix operator*(const Core::Matrix& lhs, double rhs);
Core::Matrix operator*(double lhs, const Core::Matrix& rhs);

Core::Matrix operator/(const Core::Matrix& lhs, double rhs);

double determinant(const Core::Matrix& m);
Core::Matrix transpone(const Core::Matrix& m);
Core::Matrix inverse(const Core::Matrix& m);
Core::Matrix identity();
Core::Matrix translate(double x, double y, double z);
Core::Matrix translate(const Core::Vector& v);
Core::Matrix scale(double x, double y, double z);
Core::Matrix scale(const Core::Vector& v);
Core::Matrix rotate(double angle, double x, double y, double z);
Core::Matrix rotate(double angle, const Core::Vector& v);
Core::Matrix rotateX(double angle);
Core::Matrix rotateY(double angle);
Core::Matrix rotateZ(double angle);
Core::Matrix perspective(double fov, double aspect, double near, double far);
Core::Matrix orthographic(double left, double right, double bottom, double top, double near, double far);
Core::Matrix lookAt(const Core::Vector& eye, const Core::Vector& center, const Core::Vector& up);
Core::Matrix lookAt(double eyeX, double eyeY, double eyeZ, double centerX, double centerY, double centerZ, double upX, double upY, double upZ);
Core::Matrix lookAt(const Core::Vector& eye, const Core::Vector& center, const Core::Vector& up, double near, double far);
