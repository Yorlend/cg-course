#pragma once

#include <vector>
#include "arch/math/vector.hpp"
#include "arch/math/edge.hpp"

class IModelImpl
{
public:
    virtual ~IModelImpl() = default;

    virtual std::vector<Vector> getPoints() = 0;
    virtual std::vector<Edge> getEdges() = 0;
};
