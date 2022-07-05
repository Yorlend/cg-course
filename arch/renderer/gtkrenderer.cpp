#include "gtkrenderer.hpp"
#include <gtkmm/window.h>

GtkRenderer::GtkRenderer(Glib::RefPtr<Gtk::DrawingArea>& drawingArea)
    : drawingArea(drawingArea)
{
    auto bounds = drawingArea->get_allocation();
    pixbuf = Cairo::ImageSurface::create(Cairo::FORMAT_ARGB32, bounds.get_width(), bounds.get_height());
    drawingArea->signal_draw().connect(sigc::mem_fun(*this, &GtkRenderer::drawHandler));
}

void GtkRenderer::clear()
{
    auto ctx = Cairo::Context::create(pixbuf);

    ctx->set_source_rgb(1, 1, 1);
    ctx->paint();

    drawingArea->queue_draw();
}

void GtkRenderer::renderLine(const Vector &p1, const Vector &p2)
{
    auto ctx = Cairo::Context::create(pixbuf);

    auto bounds = drawingArea->get_allocation();
    double cx = bounds.get_width() / 2;
    double cy = bounds.get_height() / 2;

    ctx->set_source_rgb(0, 0, 0);
    ctx->move_to(cx + p1.getX(), cy + p1.getY());
    ctx->line_to(cx + p2.getX(), cy + p2.getY());
    ctx->stroke();

    drawingArea->queue_draw();
}

bool GtkRenderer::drawHandler(const Cairo::RefPtr<Cairo::Context>& ctx)
{
    ctx->set_source(pixbuf, 0, 0);
    ctx->paint();
    
    return true;
}

