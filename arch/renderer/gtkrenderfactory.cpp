#include <memory>
#include "gtkrenderfactory.hpp"
#include "gtkrenderer.hpp"

GtkRenderFactory::GtkRenderFactory(Gtk::DrawingArea &drawingArea) : drawingArea(drawingArea)
{
}

std::shared_ptr<IRenderer> GtkRenderFactory::createRenderer()
{
    if (!renderer)
        renderer = std::shared_ptr<IRenderer>(new GtkRenderer(drawingArea));
    
    return renderer;
}
