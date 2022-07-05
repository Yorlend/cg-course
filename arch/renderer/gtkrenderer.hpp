#pragma once

#include <gtkmm/drawingarea.h>
#include "irenderer.hpp"

class GtkRenderer : public IRenderer
{
public:
    GtkRenderer(Glib::RefPtr<Gtk::DrawingArea>& drawingArea);
    
    virtual void clear() override;
    virtual void renderLine(const Vector &p1, const Vector &p2) override;

private:
    bool drawHandler(const Cairo::RefPtr<Cairo::Context>& ctx);

    Glib::RefPtr<Gtk::DrawingArea> drawingArea;
    Cairo::RefPtr<Cairo::ImageSurface> pixbuf;
};
