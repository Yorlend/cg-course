#pragma once

#include "arch/math/vector.hpp"

class IRenderer
{
public:
    virtual ~IRenderer() = default;

    virtual void clear() = 0;
    virtual void renderLine(const Vector &p1, const Vector &p2) = 0;
};
