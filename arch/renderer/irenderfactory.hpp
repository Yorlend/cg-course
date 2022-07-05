#pragma once

#include <memory>
#include "irenderer.hpp"

class IRenderFactory
{
public:
    virtual ~IRenderFactory() = default;

    virtual std::shared_ptr<IRenderer> createRenderer() = 0;
};
