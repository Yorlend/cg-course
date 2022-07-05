#pragma once

#include <gtkmm/window.h>
#include <gtkmm/drawingarea.h>
#include <memory>
#include "arch/commands/facade.hpp"

class Solution;

class MainWindow : public Gtk::Window
{
public:
    MainWindow(Solution& solution);
    virtual ~MainWindow();

private:
    Gtk::DrawingArea drawingArea;
    std::shared_ptr<Facade> facade;
};
