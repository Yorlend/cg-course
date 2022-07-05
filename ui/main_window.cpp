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
    : ui{Gtk::Builder::create_from_file("ui/resources/design.glade")}
{
    if (!ui)
    {
        throw std::runtime_error("Failed to load ui/resources/design.glade");
    }

    ui->get_widget<Gtk::Box>("top_container", top_container);

    testLabel = Glib::RefPtr<Gtk::Label>::cast_dynamic(ui->get_object("testLabel"));
    testButton = Glib::RefPtr<Gtk::Button>::cast_dynamic(ui->get_object("testButton"));
    drawingArea = Glib::RefPtr<Gtk::DrawingArea>::cast_dynamic(ui->get_object("drawingArea"));
    add(*top_container);

    testButton->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_clicked));

    auto factory = std::make_shared<GtkRenderFactory>(drawingArea);
    solution.registerRenderFactory(GTK_RENDER_FACTORY, factory);

    auto provider = ManagerCreator().createProvider(solution);
    facade = std::make_shared<Facade>(std::move(provider));

    set_title("WATER IN THE FIRE");
    set_default_size(800, 600);
    set_position(Gtk::WIN_POS_CENTER);
    set_resizable(false);

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
    delete top_container;
}

void MainWindow::on_button_clicked()
{
    static int click_count;
    testLabel->set_text("Clicked " + std::to_string(++click_count) + " times.");
}
