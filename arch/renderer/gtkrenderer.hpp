#pragma once

#include <gtkmm/drawingarea.h>
#include "irenderer.hpp"

class GtkRenderer : public IRenderer
{
public:
    GtkRenderer(Gtk::DrawingArea &drawingArea);
    
    virtual void clear() override;
    virtual void renderLine(const Vector &p1, const Vector &p2) override;

private:
    bool drawHandler(const Cairo::RefPtr<Cairo::Context>& ctx);

    Gtk::DrawingArea &drawingArea;
    Cairo::RefPtr<Cairo::ImageSurface> pixbuf;
};
