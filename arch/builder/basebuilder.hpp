#pragma once

#include <memory>
#include <string>
#include "arch/math/vector.hpp"
#include "arch/math/edge.hpp"
#include "arch/math/transform.hpp"
#include "arch/entities/baseobject.hpp"

class BaseObjectBuilder
{
public:
    virtual ~BaseObjectBuilder() = default;

    void setId(size_t newId);
    void setName(const std::string &newName);

    void setPosition(const Vector &newPosition);
    void setRotation(const Vector &newRotation);
    void setScale(const Vector &newScale);

    virtual void addPoint(const Vector &point) = 0;
    virtual void addEdge(const Edge &edge) = 0;

    virtual std::unique_ptr<BaseObject> build() = 0;

protected:
    size_t getId();
    const std::string &getName();

    Matrix buildTransform();

private:
    size_t id;
    std::string name;

    Vector position = Vector(0, 0, 0, 1);
    Vector rotation = Vector(0, 0, 0, 0);
    Vector scale = Vector(1, 1, 1, 0);
};
