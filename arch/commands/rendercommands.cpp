#include "arch/managers/managerprovider.hpp"
#include "arch/managers/rendermanager.hpp"
#include "rendercommands.hpp"

void RenderSceneCommand::execute(ManagerProvider &managerProvider)
{
    managerProvider.get<RenderManager>().renderScene();
}
