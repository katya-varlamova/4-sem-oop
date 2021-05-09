#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Drawer/QtDrawer.h"
#include "Model/Facade/Facade.h"
#include <QMainWindow.h>
class Controller
{
public:
    Controller(QMainWindow *view, std::shared_ptr<BaseDrawer> drawer);
    void moveModel(double dx, double dy, double dz);
    void scaleModel(double kx, double ky, double kz);
    void rotateModel(double ax, double ay, double az);
    void moveCamera(double dx, double dy, double dz);
    void rotateCamera(double ax, double ay, double az);
    void load();

protected:
    QMainWindow *view;
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<Facade> facade;
    std::shared_ptr<BaseDrawer> drawer;
};

#endif // CONTROLLER_H
