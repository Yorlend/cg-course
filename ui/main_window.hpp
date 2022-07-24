#pragma once

#include <memory>

#include <gtkmm/window.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/builder.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>

#include <gtkmm/listbox.h>
#include <gtkmm/spinbutton.h>

#include "arch/commands/facade.hpp"

class Solution;

class MainWindow : public Gtk::Window
{
public:
    MainWindow(Solution& solution);
    virtual ~MainWindow();

private:
    // std::unique_ptr<Gtk::Box> top_container;
    Gtk::Box* topContainer;
    Glib::RefPtr<Gtk::Builder> ui;

    // sceneBox
    Glib::RefPtr<Gtk::Label> sceneName;
    Glib::RefPtr<Gtk::ListBox> itemList;
    Glib::RefPtr<Gtk::Button> deleteButton;
    Glib::RefPtr<Gtk::Button> editButton;

    // paramsBox
    Glib::RefPtr<Gtk::SpinButton> dxSpinButton;
    Glib::RefPtr<Gtk::SpinButton> dySpinButton;
    Glib::RefPtr<Gtk::SpinButton> dzSpinButton;

    Glib::RefPtr<Gtk::SpinButton> kxSpinButton;
    Glib::RefPtr<Gtk::SpinButton> kySpinButton;
    Glib::RefPtr<Gtk::SpinButton> kzSpinButton;

    Glib::RefPtr<Gtk::SpinButton> axSpinButton;
    Glib::RefPtr<Gtk::SpinButton> aySpinButton;
    Glib::RefPtr<Gtk::SpinButton> azSpinButton;

    Glib::RefPtr<Gtk::SpinButton> cxSpinButton;
    Glib::RefPtr<Gtk::SpinButton> cySpinButton;
    Glib::RefPtr<Gtk::SpinButton> czSpinButton;

    Glib::RefPtr<Gtk::Button> posApplyButton;
    Glib::RefPtr<Gtk::Button> scaleApplyButton;
    Glib::RefPtr<Gtk::Button> rotationApplyButton;

    // simulationBox
    Glib::RefPtr<Gtk::SpinButton> viscositySpinButton;
    Glib::RefPtr<Gtk::SpinButton> densitySpinButton;
    Glib::RefPtr<Gtk::SpinButton> gravitySpinButton;

    Glib::RefPtr<Gtk::Button> applySimButton;   
    Glib::RefPtr<Gtk::Button> resetSimButton;

    // Drawing Area
    Glib::RefPtr<Gtk::DrawingArea> drawingArea;

    // controlBox
    Glib::RefPtr<Gtk::Button> loadButton;
    Glib::RefPtr<Gtk::Button> saveButton;
    Glib::RefPtr<Gtk::Button> newSceneButton;
    Glib::RefPtr<Gtk::Button> renderButton;
    Glib::RefPtr<Gtk::Button> preloadSimulationButton;
    Glib::RefPtr<Gtk::Button> startSimulationButton;

    std::shared_ptr<Facade> facade;
};
