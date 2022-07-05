#pragma once

#include <memory>

#include <gtkmm/window.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/builder.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>

#include "arch/commands/facade.hpp"

class Solution;

class MainWindow : public Gtk::Window
{
public:
    MainWindow(Solution& solution);
    virtual ~MainWindow();

private:
    // Signal handlers:
    void on_button_clicked();

    // std::unique_ptr<Gtk::Box> top_container;
    Gtk::Box* top_container;

    Glib::RefPtr<Gtk::Label> testLabel;
    Glib::RefPtr<Gtk::Button> testButton;
    Glib::RefPtr<Gtk::Builder> ui;
    Glib::RefPtr<Gtk::DrawingArea> drawingArea;

    std::shared_ptr<Facade> facade;
};
