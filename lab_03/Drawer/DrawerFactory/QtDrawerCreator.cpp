#include "QtDrawerCreator.h"
QtDrawerCreator::QtDrawerCreator(std::shared_ptr<QGraphicsScene> &scene,
                std::shared_ptr<QPen> &pen,
                std::shared_ptr<QBrush> &brush)
{
    this->scene = scene;
    this->brush = brush;
    this->pen = pen;
}
std::shared_ptr<BaseDrawer> QtDrawerCreator::createDrawer()
{
    return std::shared_ptr<BaseDrawer>(new QtDrawer(scene, brush, pen));
}
