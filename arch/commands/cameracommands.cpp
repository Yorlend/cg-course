#include "arch/managers/managerprovider.hpp"
#include "arch/managers/cameramanager.hpp"
#include "cameracommands.hpp"

void SwitchNextCameraCommand::execute(ManagerProvider &managerProvider)
{
    managerProvider.get<CameraManager>().switchNextCamera();
}
