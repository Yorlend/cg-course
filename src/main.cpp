#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm/window.h>

int main()
{
    auto app = Gtk::Application::create("org.gtkmm.example");

    // Create the application window
    Gtk::Window window;
    window.set_title("Hello World");
    window.set_default_size(200, 200);

    // Show the window and run the application
    window.show();
    return app->run(window);
}
