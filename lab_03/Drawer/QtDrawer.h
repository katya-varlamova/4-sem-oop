#ifndef QTDRAWER_H
#define QTDRAWER_H

#include <QPen>
#include <QBrush>
#include <QGraphicsScene>

#include "Drawer/BaseDrawer.h"

class QtDrawer final: public BaseDrawer
{
public:
    QtDrawer(std::shared_ptr<QGraphicsScene> scene, std::shared_ptr<QBrush> brush, std::shared_ptr<QPen> pen);

    virtual void drawLine(double x1, double y1, double x2, double y2) override;
    void drawPoint(double x, double y) override;

protected:
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<QPen> pen;
    std::shared_ptr<QBrush> brush;
};

#endif // QTDRAWER_H
