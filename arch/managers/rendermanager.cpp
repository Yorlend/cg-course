#include "rendermanager.hpp"
#include "arch/solution/solution.hpp"
#include "arch/solution/configuration.hpp"
#include "arch/visitor/rendervisitor.hpp"
#include "arch/entities/camera.hpp"

RenderManager::RenderManager(Solution &solution)
    : dataRepository(solution.getDataRepository(DEFAULT_DATA_REPOSITORY)),
      renderFactory(solution.getRenderFactory(GTK_RENDER_FACTORY))
{
}

void RenderManager::renderScene()
{
    auto &scene = dataRepository->getScene();
    auto camera = dataRepository->getActiveCamera();

    auto renderer = renderFactory->createRenderer();
    auto visitor = RenderVisitor(*renderer, *dynamic_cast<Camera*>(camera.get()));

    renderer->clear();
    scene.accept(visitor);
}
