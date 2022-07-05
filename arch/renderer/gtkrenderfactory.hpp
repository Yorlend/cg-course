#pragma once

#include "irenderfactory.hpp"
#include <gtkmm/drawingarea.h>

class GtkRenderFactory : public IRenderFactory
{
public:
    GtkRenderFactory(Gtk::DrawingArea &drawingArea);

    virtual std::shared_ptr<IRenderer> createRenderer() override;

private:
    Gtk::DrawingArea &drawingArea;
    std::shared_ptr<IRenderer> renderer;
};
