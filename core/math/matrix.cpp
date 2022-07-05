#include <cmath>

#include "matrix.hpp"
#include "vector.hpp"

Core::Matrix operator+(const Core::Matrix& lhs, const Core::Matrix& rhs)
{
    // two dimensional matrices addition
    return Core::Matrix{
        lhs.m[0][0] + rhs.m[0][0], lhs.m[0][1] + rhs.m[0][1], lhs.m[0][2] + rhs.m[0][2], lhs.m[0][3] + rhs.m[0][3],
        lhs.m[1][0] + rhs.m[1][0], lhs.m[1][1] + rhs.m[1][1], lhs.m[1][2] + rhs.m[1][2], lhs.m[1][3] + rhs.m[1][3],
        lhs.m[2][0] + rhs.m[2][0], lhs.m[2][1] + rhs.m[2][1], lhs.m[2][2] + rhs.m[2][2], lhs.m[2][3] + rhs.m[2][3],
        lhs.m[3][0] + rhs.m[3][0], lhs.m[3][1] + rhs.m[3][1], lhs.m[3][2] + rhs.m[3][2], lhs.m[3][3] + rhs.m[3][3]
    };
}

Core::Matrix operator-(const Core::Matrix& lhs, const Core::Matrix& rhs)
{
    // two dimensional matrices subtraction
    return Core::Matrix{
        lhs.m[0][0] - rhs.m[0][0], lhs.m[0][1] - rhs.m[0][1], lhs.m[0][2] - rhs.m[0][2], lhs.m[0][3] - rhs.m[0][3],
        lhs.m[1][0] - rhs.m[1][0], lhs.m[1][1] - rhs.m[1][1], lhs.m[1][2] - rhs.m[1][2], lhs.m[1][3] - rhs.m[1][3],
        lhs.m[2][0] - rhs.m[2][0], lhs.m[2][1] - rhs.m[2][1], lhs.m[2][2] - rhs.m[2][2], lhs.m[2][3] - rhs.m[2][3],
        lhs.m[3][0] - rhs.m[3][0], lhs.m[3][1] - rhs.m[3][1], lhs.m[3][2] - rhs.m[3][2], lhs.m[3][3] - rhs.m[3][3]
    };
}

Core::Matrix operator*(const Core::Matrix& lhs, const Core::Matrix& rhs)
{
    // two dimensional matrices multiplication
    return Core::Matrix{
        lhs.m[0][0] * rhs.m[0][0] + lhs.m[0][1] * rhs.m[1][0] + lhs.m[0][2] * rhs.m[2][0] + lhs.m[0][3] * rhs.m[3][0],
        lhs.m[0][0] * rhs.m[0][1] + lhs.m[0][1] * rhs.m[1][1] + lhs.m[0][2] * rhs.m[2][1] + lhs.m[0][3] * rhs.m[3][1],
        lhs.m[0][0] * rhs.m[0][2] + lhs.m[0][1] * rhs.m[1][2] + lhs.m[0][2] * rhs.m[2][2] + lhs.m[0][3] * rhs.m[3][2],
        lhs.m[0][0] * rhs.m[0][3] + lhs.m[0][1] * rhs.m[1][3] + lhs.m[0][2] * rhs.m[2][3] + lhs.m[0][3] * rhs.m[3][3],
        
        lhs.m[1][0] * rhs.m[0][0] + lhs.m[1][1] * rhs.m[1][0] + lhs.m[1][2] * rhs.m[2][0] + lhs.m[1][3] * rhs.m[3][0],
        lhs.m[1][0] * rhs.m[0][1] + lhs.m[1][1] * rhs.m[1][1] + lhs.m[1][2] * rhs.m[2][1] + lhs.m[1][3] * rhs.m[3][1],
        lhs.m[1][0] * rhs.m[0][2] + lhs.m[1][1] * rhs.m[1][2] + lhs.m[1][2] * rhs.m[2][2] + lhs.m[1][3] * rhs.m[3][2],
        lhs.m[1][0] * rhs.m[0][3] + lhs.m[1][1] * rhs.m[1][3] + lhs.m[1][2] * rhs.m[2][3] + lhs.m[1][3] * rhs.m[3][3],

        lhs.m[2][0] * rhs.m[0][0] + lhs.m[2][1] * rhs.m[1][0] + lhs.m[2][2] * rhs.m[2][0] + lhs.m[2][3] * rhs.m[3][0],
        lhs.m[2][0] * rhs.m[0][1] + lhs.m[2][1] * rhs.m[1][1] + lhs.m[2][2] * rhs.m[2][1] + lhs.m[2][3] * rhs.m[3][1],
        lhs.m[2][0] * rhs.m[0][2] + lhs.m[2][1] * rhs.m[1][2] + lhs.m[2][2] * rhs.m[2][2] + lhs.m[2][3] * rhs.m[3][2],
        lhs.m[2][0] * rhs.m[0][3] + lhs.m[2][1] * rhs.m[1][3] + lhs.m[2][2] * rhs.m[2][3] + lhs.m[2][3] * rhs.m[3][3],
        
        lhs.m[3][0] * rhs.m[0][0] + lhs.m[3][1] * rhs.m[1][0] + lhs.m[3][2] * rhs.m[2][0] + lhs.m[3][3] * rhs.m[3][0],
        lhs.m[3][0] * rhs.m[0][1] + lhs.m[3][1] * rhs.m[1][1] + lhs.m[3][2] * rhs.m[2][1] + lhs.m[3][3] * rhs.m[3][1],
        lhs.m[3][0] * rhs.m[0][2] + lhs.m[3][1] * rhs.m[1][2] + lhs.m[3][2] * rhs.m[2][2] + lhs.m[3][3] * rhs.m[3][2],
        lhs.m[3][0] * rhs.m[0][3] + lhs.m[3][1] * rhs.m[1][3] + lhs.m[3][2] * rhs.m[2][3] + lhs.m[3][3] * rhs.m[3][3]
    };
}

Core::Matrix operator+=(Core::Matrix& lhs, const Core::Matrix& rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

Core::Matrix operator-=(Core::Matrix& lhs, const Core::Matrix& rhs)
{
    lhs = lhs - rhs;
    return lhs;
}

Core::Matrix operator*=(Core::Matrix& lhs, const Core::Matrix& rhs)
{
    lhs = lhs * rhs;
    return lhs;
}

Core::Matrix operator*(const Core::Matrix& lhs, double rhs)
{
    return Core::Matrix{
        lhs.m[0][0] * rhs,
        lhs.m[0][1] * rhs,
        lhs.m[0][2] * rhs,
        lhs.m[0][3] * rhs,
        
        lhs.m[1][0] * rhs,
        lhs.m[1][1] * rhs,
        lhs.m[1][2] * rhs,
        lhs.m[1][3] * rhs,
        
        lhs.m[2][0] * rhs,
        lhs.m[2][1] * rhs,
        lhs.m[2][2] * rhs,
        lhs.m[2][3] * rhs,
        
        lhs.m[3][0] * rhs,
        lhs.m[3][1] * rhs,
        lhs.m[3][2] * rhs,
        lhs.m[3][3] * rhs
    };
}

Core::Matrix operator*(double lhs, const Core::Matrix& rhs)
{
    return rhs * lhs;
}

Core::Matrix operator/(const Core::Matrix& lhs, double rhs)
{
    return lhs * (1.0 / rhs);
}

Core::Matrix transpone(const Core::Matrix& m)
{
    return Core::Matrix{
        m.m[0][0], m.m[1][0], m.m[2][0], m.m[3][0],
        m.m[0][1], m.m[1][1], m.m[2][1], m.m[3][1],
        m.m[0][2], m.m[1][2], m.m[2][2], m.m[3][2],
        m.m[0][3], m.m[1][3], m.m[2][3], m.m[3][3]
    };
}

double determinant(const Core::Matrix& m)
{
    // 4x4 determinant
    return m.m[0][0] * (m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[1][2] * m.m[2][3] * m.m[3][1] + m.m[1][3] * m.m[2][1] * m.m[3][2] - m.m[1][1] * m.m[2][3] * m.m[3][2] - m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[1][3] * m.m[2][2] * m.m[3][1]) + m.m[0][1] * (m.m[1][0] * m.m[2][3] * m.m[3][2] + m.m[1][2] * m.m[2][0] * m.m[3][3] + m.m[1][3] * m.m[2][2] * m.m[3][0] - m.m[1][0] * m.m[2][2] * m.m[3][3] - m.m[1][2] * m.m[2][3] * m.m[3][0] - m.m[1][3] * m.m[2][0] * m.m[3][2]) + m.m[0][2] * (m.m[1][0] * m.m[2][1] * m.m[3][3] + m.m[1][1] * m.m[2][3] * m.m[3][0] + m.m[1][3] * m.m[2][0] * m.m[3][1] - m.m[1][0] * m.m[2][3] * m.m[3][1] - m.m[1][1] * m.m[2][0] * m.m[3][3] - m.m[1][3] * m.m[2][1] * m.m[3][0]) + m.m[0][3] * (m.m[1][0] * m.m[2][2] * m.m[3][1] + m.m[1][1] * m.m[2][0] * m.m[3][2] + m.m[1][2] * m.m[2][1] * m.m[3][0] - m.m[1][0] * m.m[2][1] * m.m[3][2] - m.m[1][1] * m.m[2][2] * m.m[3][0] - m.m[1][2] * m.m[2][0] * m.m[3][1]);
}

Core::Matrix inverse(const Core::Matrix& m)
{
    double det = determinant(m);
    if (det == 0.0)
        return identity();
    det = 1.0 / det;
    
    return Core::Matrix{
        det * (m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[1][2] * m.m[2][3] * m.m[3][1] + m.m[1][3] * m.m[2][1] * m.m[3][2] - m.m[1][1] * m.m[2][3] * m.m[3][2] - m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[1][3] * m.m[2][2] * m.m[3][1]),
        det * (m.m[0][1] * m.m[2][3] * m.m[3][2] + m.m[0][2] * m.m[2][1] * m.m[3][3] + m.m[0][3] * m.m[2][2] * m.m[3][1] - m.m[0][1] * m.m[2][2] * m.m[3][3] - m.m[0][2] * m.m[2][3] * m.m[3][1] - m.m[0][3] * m.m[2][1] * m.m[3][2]),
        det * (m.m[0][1] * m.m[1][2] * m.m[3][3] + m.m[0][2] * m.m[1][3] * m.m[3][1] + m.m[0][3] * m.m[1][1] * m.m[3][2] - m.m[0][1] * m.m[1][3] * m.m[3][2] - m.m[0][2] * m.m[1][1] * m.m[3][3] - m.m[0][3] * m.m[1][2] * m.m[3][1]),
        det * (m.m[0][1] * m.m[1][3] * m.m[2][2] + m.m[0][2] * m.m[1][1] * m.m[2][3] + m.m[0][3] * m.m[1][2] * m.m[2][1] - m.m[0][1] * m.m[1][2] * m.m[2][3] - m.m[0][2] * m.m[1][3] * m.m[2][1] - m.m[0][3] * m.m[1][1] * m.m[2][2]),
        det * (m.m[1][1] * m.m[2][3] * m.m[3][2] + m.m[1][2] * m.m[2][1] * m.m[3][3] + m.m[1][3] * m.m[2][2] * m.m[3][1] - m.m[1][1] * m.m[2][2] * m.m[3][3] - m.m[1][2] * m.m[2][3] * m.m[3][1] - m.m[1][3] * m.m[2][1] * m.m[3][2]),
        det * (m.m[0][1] * m.m[2][2] * m.m[3][3] + m.m[0][2] * m.m[2][3] * m.m[3][1] + m.m[0][3] * m.m[2][1] * m.m[3][2] - m.m[0][1] * m.m[2][3] * m.m[3][2] - m.m[0][2] * m.m[2][1] * m.m[3][3] - m.m[0][3] * m.m[2][2] * m.m[3][1]),
        det * (m.m[0][1] * m.m[1][3] * m.m[3][2] + m.m[0][2] * m.m[1][1] * m.m[3][3] + m.m[0][3] * m.m[1][2] * m.m[3][1] - m.m[0][1] * m.m[1][2] * m.m[3][3] - m.m[0][2] * m.m[1][3] * m.m[3][1] - m.m[0][3] * m.m[1][1] * m.m[3][2]),
        det * (m.m[0][1] * m.m[1][2] * m.m[2][3] + m.m[0][2] * m.m[1][3] * m.m[2][1] + m.m[0][3] * m.m[1][1] * m.m[2][2] - m.m[0][1] * m.m[1][3] * m.m[2][2] - m.m[0][2] * m.m[1][1] * m.m[2][3] - m.m[0][3] * m.m[1][2] * m.m[2][1]),
        det * (m.m[0][1] * m.m[1][3] * m.m[2][2] + m.m[0][2] * m.m[1][1] * m.m[2][3] + m.m[0][3] * m.m[1][2] * m.m[2][1] - m.m[0][1] * m.m[1][2] * m.m[2][3] - m.m[0][2] * m.m[1][3] * m.m[2][1] - m.m[0][3] * m.m[1][1] * m.m[2][2]),
        det * (m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[1][2] * m.m[2][3] * m.m[3][1] + m.m[1][3] * m.m[2][1] * m.m[3][2] - m.m[1][1] * m.m[2][3] * m.m[3][2] - m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[1][3] * m.m[2][2] * m.m[3][1]),
        det * (m.m[0][1] * m.m[2][3] * m.m[3][2] + m.m[0][2] * m.m[2][1] * m.m[3][3] + m.m[0][3] * m.m[2][2] * m.m[3][1] - m.m[0][1] * m.m[2][2] * m.m[3][3] - m.m[0][2] * m.m[2][3] * m.m[3][1] - m.m[0][3] * m.m[2][1] * m.m[3][2]),
        det * (m.m[0][1] * m.m[1][2] * m.m[3][3] + m.m[0][2] * m.m[1][3] * m.m[3][1] + m.m[0][3] * m.m[1][1] * m.m[3][2] - m.m[0][1] * m.m[1][3] * m.m[3][2] - m.m[0][2] * m.m[1][1] * m.m[3][3] - m.m[0][3] * m.m[1][2] * m.m[3][1]),
        det * (m.m[0][1] * m.m[1][3] * m.m[2][2] + m.m[0][2] * m.m[1][1] * m.m[2][3] + m.m[0][3] * m.m[1][2] * m.m[2][1] - m.m[0][1] * m.m[1][2] * m.m[2][3] - m.m[0][2] * m.m[1][3] * m.m[2][1] - m.m[0][3] * m.m[1][1] * m.m[2][2]),
        det * (m.m[0][1] * m.m[1][2] * m.m[2][3] + m.m[0][2] * m.m[1][3] * m.m[2][1] + m.m[0][3] * m.m[1][1] * m.m[2][2] - m.m[0][1] * m.m[1][3] * m.m[2][2] - m.m[0][2] * m.m[1][1] * m.m[2][3] - m.m[0][3] * m.m[1][2] * m.m[2][1]),
        det * (m.m[1][1] * m.m[2][3] * m.m[3][2] + m.m[1][2] * m.m[2][1] * m.m[3][3] + m.m[1][3] * m.m[2][2] * m.m[3][1] - m.m[1][1] * m.m[2][2] * m.m[3][3] - m.m[1][2] * m.m[2][3] * m.m[3][1] - m.m[1][3] * m.m[2][1] * m.m[3][2]),
        det * (m.m[0][1] * m.m[2][2] * m.m[3][3] + m.m[0][2] * m.m[2][3] * m.m[3][1] + m.m[0][3] * m.m[2][1] * m.m[3][2] - m.m[0][1] * m.m[2][3] * m.m[3][2] - m.m[0][2] * m.m[2][1] * m.m[3][3] - m.m[0][3] * m.m[2][2] * m.m[3][1])
    };
}

Core::Matrix identity()
{
    return {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
}

Core::Matrix translate(double x, double y, double z)
{
    return {
        1, 0, 0, x,
        0, 1, 0, y,
        0, 0, 1, z,
        0, 0, 0, 1
    };
}

Core::Matrix translate(const Core::Vector& v)
{
    return translate(v.x, v.y, v.z);
}

Core::Matrix scale(double x, double y, double z)
{
    return {
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1
    };
}

Core::Matrix scale(const Core::Vector& v)
{
    return scale(v.x, v.y, v.z);
}

Core::Matrix rotate(double angle, double x, double y, double z)
{
    double c = cos(angle);
    double s = sin(angle);
    double t = 1 - c;
    double xs = x * s;
    double ys = y * s;
    double zs = z * s;
    double xy = x * y;
    double xz = x * z;
    double yz = y * z;
    double x2 = x * x;
    double y2 = y * y;
    double z2 = z * z;
    return {
        x2 * t + c, xy * t + zs, xz * t - ys, 0,
        xy * t - zs, y2 * t + c, yz * t + xs, 0,
        xz * t + ys, yz * t - xs, z2 * t + c, 0,
        0, 0, 0, 1
    };
}

Core::Matrix rotate(double angle, const Core::Vector& v)
{
    return rotate(angle, v.x, v.y, v.z);
}

Core::Matrix rotateX(double angle)
{
    double c = cos(angle);
    double s = sin(angle);
    return {
        1, 0, 0, 0,
        0, c, -s, 0,
        0, s, c, 0,
        0, 0, 0, 1
    };
}

Core::Matrix rotateY(double angle)
{
    double c = cos(angle);
    double s = sin(angle);
    return {
        c, 0, s, 0,
        0, 1, 0, 0,
        -s, 0, c, 0,
        0, 0, 0, 1
    };
}

Core::Matrix rotateZ(double angle)
{
    double c = cos(angle);
    double s = sin(angle);
    return {
        c, -s, 0, 0,
        s, c, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
}

Core::Matrix perspective(double fov, double aspect, double near, double far)
{
    double f = 1 / tan(fov / 2);
    return {
        f / aspect, 0, 0, 0,
        0, f, 0, 0,
        0, 0, (far + near) / (near - far), 2 * far * near / (near - far),
        0, 0, -1, 0
    };
}

Core::Matrix orthographic(double left, double right, double bottom, double top, double near, double far)
{
    return {
        2 / (right - left), 0, 0, -(right + left) / (right - left),
        0, 2 / (top - bottom), 0, -(top + bottom) / (top - bottom),
        0, 0, -2 / (far - near), -(far + near) / (far - near),
        0, 0, 0, 1
    };
}

Core::Matrix lookAt(const Core::Vector& eye, const Core::Vector& center, const Core::Vector& up)
{
    Core::Vector f = (center - eye).normalize();
    Core::Vector u = up.normalize();
    Core::Vector s = f.cross(u).normalize();
    u = s.cross(f);
    return {
        s.x, u.x, -f.x, 0,
        s.y, u.y, -f.y, 0,
        s.z, u.z, -f.z, 0,
        -s.dot(eye), -u.dot(eye), f.dot(eye), 1
    };
}

Core::Matrix lookAt(double eyeX, double eyeY, double eyeZ, double centerX, double centerY, double centerZ, double upX, double upY, double upZ)
{
    return lookAt(Core::Vector(eyeX, eyeY, eyeZ), Core::Vector(centerX, centerY, centerZ), Core::Vector(upX, upY, upZ));
}

Core::Matrix lookAt(const Core::Vector& eye, const Core::Vector& center, const Core::Vector& up, double near, double far)
{
    Core::Vector f = (center - eye).normalize();
    Core::Vector u = up.normalize();
    Core::Vector s = f.cross(u).normalize();
    u = s.cross(f);
    return {
        s.x, u.x, -f.x, 0,
        s.y, u.y, -f.y, 0,
        s.z, u.z, -f.z, 0,
        -s.dot(eye), -u.dot(eye), f.dot(eye), 1
    };
}
