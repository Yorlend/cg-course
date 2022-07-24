#pragma once

namespace Core
{
    struct Vector;

    struct Matrix
    {
        double m[16];

        Matrix();
        Matrix(double m[16]);
        Matrix(double m00, double m01, double m02, double m03,
               double m10, double m11, double m12, double m13,
               double m20, double m21, double m22, double m23,
               double m30, double m31, double m32, double m33);
        Matrix(const Matrix& other);

        Matrix& operator=(const Matrix& other);
    };
}

Core::Matrix operator+(const Core::Matrix& lhs, const Core::Matrix& rhs);
Core::Matrix operator-(const Core::Matrix& lhs, const Core::Matrix& rhs);
Core::Matrix operator*(const Core::Matrix& lhs, const Core::Matrix& rhs);

Core::Matrix& operator+=(Core::Matrix& lhs, const Core::Matrix& rhs);
Core::Matrix& operator-=(Core::Matrix& lhs, const Core::Matrix& rhs);
Core::Matrix& operator*=(Core::Matrix& lhs, const Core::Matrix& rhs);

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
