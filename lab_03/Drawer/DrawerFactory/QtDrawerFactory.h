#ifndef QTDRAWERFACTORY_H
#define QTDRAWERFACTORY_H

#include "BaseDrawerFactory.h"
#include "Drawer/QtDrawer.h"
class QtDrawerFactory : public BaseDrawerFactory
{
public:
    QtDrawerFactory(std::shared_ptr<QGraphicsScene> scene,
                    std::shared_ptr<QPen> pen,
                    std::shared_ptr<QBrush> brush);
    virtual std::shared_ptr<BaseDrawer> createDrawer() override;

protected:
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<QPen> pen;
    std::shared_ptr<QBrush> brush;
};

#endif // QTDRAWERFACTORY_H
