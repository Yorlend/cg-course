#include "main_window.hpp"

#include "arch/solution/solution.hpp"
#include "arch/solution/configuration.hpp"
#include "arch/renderer/irenderfactory.hpp"
#include "arch/renderer/gtkrenderfactory.hpp"
#include "arch/managers/managercreator.hpp"

#include "arch/commands/rendercommands.hpp"
#include "arch/commands/scenecommands.hpp"
#include "arch/commands/cameracommands.hpp"
#include "arch/commands/objectcommands.hpp"

MainWindow::MainWindow(Solution& solution)
    : ui{Gtk::Builder::create_from_file("ui/resources/main_window.glade")}
{
    if (!ui)
    {
        throw std::runtime_error("Failed to load ui/resources/main_window.glade");
    }

    ui->get_widget<Gtk::Box>("topContainer", topContainer);

    // loading sceneBox internals
    sceneName = Glib::RefPtr<Gtk::Label>::cast_static(ui->get_object("sceneName"));
    itemList = Glib::RefPtr<Gtk::ListBox>::cast_static(ui->get_object("itemList"));
    deleteButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("deleteButton"));
    editButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("editButton"));

    // loading paramsBox internals
    dxSpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("dxSpinButton"));
    dySpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("dySpinButton"));
    dzSpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("dzSpinButton"));

    kxSpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("kxSpinButton"));
    kySpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("kySpinButton"));
    kzSpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("kzSpinButton"));

    axSpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("axSpinButton"));
    aySpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("aySpinButton"));
    azSpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("azSpinButton"));

    cxSpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("cxSpinButton"));
    cySpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("cySpinButton"));
    czSpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("czSpinButton"));

    posApplyButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("posApplyButton"));
    rotationApplyButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("rotApplyButton"));
    scaleApplyButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("scaleApplyButton"));

    // loading simulationBox internals
    viscositySpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("viscositySpinButton"));
    densitySpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("densitySpinButton"));
    gravitySpinButton = Glib::RefPtr<Gtk::SpinButton>::cast_static(ui->get_object("gravitySpinButton"));

    applySimButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("applySimButton"));
    resetSimButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("resetSimButton"));

    // loading drawingArea
    drawingArea = Glib::RefPtr<Gtk::DrawingArea>::cast_dynamic(ui->get_object("drawingArea"));

    // loading controlBox
    loadButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("loadButton"));
    saveButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("saveButton"));
    renderButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("renderButton"));
    newSceneButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("newSceneButton"));
    preloadSimulationButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("preloadSimulationButton"));
    startSimulationButton = Glib::RefPtr<Gtk::Button>::cast_static(ui->get_object("startSimulationButton"));

    add(*topContainer);

    auto factory = std::make_shared<GtkRenderFactory>(drawingArea);
    solution.registerRenderFactory(GTK_RENDER_FACTORY, factory);

    auto provider = ManagerCreator().createProvider(solution);
    facade = std::make_shared<Facade>(std::move(provider));

    set_title("Water simulation");
    set_default_size(1400, 800);
    set_position(Gtk::WIN_POS_CENTER);
    set_resizable(true);

    show_all();

    {
        CreateNewSceneCommand cmd;
        facade->execute(cmd);
    }

    {
        ImportObjectCommand cmd("data/models/cube.txt");
        facade->execute(cmd);
    }

    {
        TransformObjectCommand cmd(2, Matrix::translate(Vector(0, 90, -50)));
        facade->execute(cmd);
    }

    {
        RenderSceneCommand cmd;
        facade->execute(cmd);
    }
}

MainWindow::~MainWindow()
{
    delete topContainer;
}
