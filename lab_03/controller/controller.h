#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Drawer/QtDrawer.h"
#include "Model/Facade/Facade.h"
#include "Model/Commands/MoveCameraCommand.h"
#include "Model/Commands/MoveObjectCommand.h"
#include "Model/Commands/RotateCameraCommand.h"
#include "Model/Commands/RotateObjectCommand.h"
#include "Model/Commands/ScaleObjectCommand.h"
#include "Model/Commands/LoadCommand.h"
#include "Model/Commands/DrawCommand.h"
#include "Model/Commands/UndoCommand.h"
#include <QMainWindow.h>
#include "Model/Loader/BaseLoader.h"
#define sourceName "/Users/kate/Desktop/oop/lab_03/files/model.txt"
class Controller
{
public:
    Controller(QMainWindow *view, std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<BaseLoader> loader);
    void moveModel(double dx, double dy, double dz);
    void scaleModel(double kx, double ky, double kz);
    void rotateModel(double ax, double ay, double az);
    void moveCamera(double dx, double dy, double dz);
    void rotateCamera(double ax, double ay, double az);
    void load();
    void undo();

protected:
    QMainWindow *view;
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<Facade> facade;
    std::shared_ptr<BaseDrawer> drawer;
    std::shared_ptr<BaseLoader> loader;
};

#endif // CONTROLLER_H
