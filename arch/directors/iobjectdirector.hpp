#pragma once

#include <memory>
#include "arch/entities/baseobject.hpp"
#include "arch/io/ireader.hpp"
#include "arch/builder/basebuilder.hpp"

class IObjectDirector
{
public:
    virtual ~IObjectDirector() = default;

    void setReader(IReader &newReader);
    void setBuilder(BaseObjectBuilder &builder);

    virtual std::unique_ptr<BaseObject> construct() = 0;

protected:
    IReader &getReader();
    BaseObjectBuilder &getBuilder();

private:
    IReader *reader = nullptr;
    BaseObjectBuilder *builder = nullptr;
};
