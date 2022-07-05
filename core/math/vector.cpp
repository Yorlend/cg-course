#include "vector.hpp"
#include <cmath>

double Core::Vector::dot(const Vector& other) const
{
    return x * other.x + y * other.y + z * other.z;
}

Core::Vector Core::Vector::cross(const Vector& other) const
{
    return Vector(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

Core::Vector Core::Vector::normalize() const
{
    double length = this->length();
    return Vector(x / length, y / length, z / length);
}

double Core::Vector::length() const
{
    return sqrt(x * x + y * y + z * z);
}

Core::Vector operator+(const Core::Vector& lhs, const Core::Vector& rhs)
{
    return Core::Vector{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
}

Core::Vector operator-(const Core::Vector& lhs, const Core::Vector& rhs)
{
    return Core::Vector{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
}

Core::Vector operator*(const Core::Vector& lhs, const Core::Vector& rhs)
{
    return Core::Vector{lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w};
}

Core::Vector operator+=(Core::Vector& lhs, const Core::Vector& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;
    return lhs;
}

Core::Vector operator-=(Core::Vector& lhs, const Core::Vector& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    lhs.w -= rhs.w;
    return lhs;
}

Core::Vector operator*=(Core::Vector& lhs, const Core::Vector& rhs)
{
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
    lhs.w *= rhs.w;
    return lhs;
}

Core::Vector operator*(const Core::Vector& lhs, double rhs)
{
    return Core::Vector{lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs};
}

Core::Vector operator*(double lhs, const Core::Vector& rhs)
{
    return Core::Vector{lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w};
}
