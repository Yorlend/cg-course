#include "ui/main_window.hpp"
#include "arch/solution/solution.hpp"
#include "arch/solution/configuration.hpp"
#include "arch/directors/modeldirector.hpp"
#include "arch/directors/defaultcamdirector.hpp"

int main(int argc, char *argv[])
{
    Solution solution;

    solution.registerDataRepository(DEFAULT_DATA_REPOSITORY,
        std::make_shared<DataRepository>());
    
    solution.registerObjectDirector(MODEL_DIRECTOR,
        std::shared_ptr<IObjectDirector>(new ModelDirector()));
    
    solution.registerObjectDirector(DEFAULT_CAMERA_DIRECTOR,
        std::shared_ptr<IObjectDirector>(new DefaultCameraDirector()));

    auto app = Gtk::Application::create(argc, argv);

    MainWindow mainWindow(solution);

    return app->run(mainWindow);
}