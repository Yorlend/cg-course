#pragma once

namespace Core
{
    struct Vector
    {
        double x, y, z, w;

        Vector() : x(0), y(0), z(0), w(0) {}
        Vector(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}
        Vector(double x, double y, double z) : x(x), y(y), z(z), w(0) {}
        Vector(const Vector& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}
        Vector(Vector&& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}
        Vector& operator=(const Vector& other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            w = other.w;
            return *this;
        }

        double dot(const Vector& other) const;
        Vector cross(const Vector& other) const;
        double length() const;
        Vector normalize() const;
    };
}

Core::Vector operator+(const Core::Vector& lhs, const Core::Vector& rhs);
Core::Vector operator-(const Core::Vector& lhs, const Core::Vector& rhs);
Core::Vector operator*(const Core::Vector& lhs, const Core::Vector& rhs);

Core::Vector operator+=(Core::Vector& lhs, const Core::Vector& rhs);
Core::Vector operator-=(Core::Vector& lhs, const Core::Vector& rhs);
Core::Vector operator*=(Core::Vector& lhs, const Core::Vector& rhs);

Core::Vector operator*(const Core::Vector& lhs, double rhs);
Core::Vector operator*(double lhs, const Core::Vector& rhs);
