#include "cameramanager.hpp"
#include "arch/solution/solution.hpp"
#include "arch/solution/configuration.hpp"
#include "arch/entities/camera.hpp"

CameraManager::CameraManager(Solution &solution)
    : dataRepository(solution.getDataRepository(DEFAULT_DATA_REPOSITORY))
{
}

void CameraManager::switchNextCamera()
{
    auto &scene = dataRepository->getScene();
    auto camera = dataRepository->getActiveCamera();

    auto iter = scene.findObjectById(camera->getId());

    iter++;

    while (iter != scene.end() && dynamic_cast<Camera*>((*iter).get()) == nullptr)
        iter++;
    
    if (iter == scene.end())
        iter = scene.begin();
    
    while (dynamic_cast<Camera*>((*iter).get()) == nullptr)
        iter++;
    
    dataRepository->setActiveCamera(*iter);
}
