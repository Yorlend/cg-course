#pragma once

#include <memory>
#include "icommand.hpp"
#include "arch/managers/managerprovider.hpp"

class Facade
{
public:
    Facade(std::unique_ptr<ManagerProvider> managerProvider);

    void execute(ICommand &command);

private:
    std::unique_ptr<ManagerProvider> managerProvider;
};
