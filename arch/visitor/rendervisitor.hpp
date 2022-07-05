#pragma once

#include "arch/renderer/irenderer.hpp"
#include "ivisitor.hpp"

class Camera;

class RenderVisitor : public IVisitor
{
public:
    RenderVisitor(IRenderer& renderer, Camera& camera);

    virtual void visit(Camera &camera) override;
    virtual void visit(Model &model) override;
    virtual void visit(ObjectGroup &group) override;

private:
    IRenderer& renderer;
    Camera& camera;
};
