#include "ui/main_window.hpp"
#include "arch/solution/solution.hpp"
#include "arch/solution/configuration.hpp"
#include "arch/directors/modeldirector.hpp"
#include "arch/directors/defaultcamdirector.hpp"

#include "core/math/matrix.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    // // random 4x4 matrix
    // Core::Matrix mat{
    //     1, 9, 3, 4,
    //     5, 6, 7, 40,
    //     9, 10, 11, 12,
    //     11, 14, 15, 16
    // };
    
    // // inversed matrix
    // Core::Matrix inv = inverse(mat);

    // Core::Matrix result = mat * identity();

    // // print result matrix
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         std::cout << result.m[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // return 0;

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