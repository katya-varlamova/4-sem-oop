#include "QtDrawer.h"

QtDrawer::QtDrawer(std::shared_ptr<QGraphicsScene> &scene, std::shared_ptr<QBrush> &brush, std::shared_ptr<QPen> &pen)
{
    this->scene = scene;
    this->brush = brush;
    this->pen = pen;
}

void QtDrawer::drawLine(double x1, double y1, double x2, double y2)
{
    scene->addLine(x1, y1, x2, y2, *pen);
}
void QtDrawer::drawPoint(double x, double y)
{
    scene->addRect(x, y, 1, 1, *pen);
}