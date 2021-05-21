#include "Controller.h"

Controller::Controller(QMainWindow *view, std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<BaseLoader> loader)
{
    this->view = view;
    facade = std::shared_ptr<Facade>(new Facade());
    this->drawer = drawer;
    this->loader = loader;
}
void Controller::load()
{
    LoadCommand com(loader, sourceName);
    facade->executeCommand(com);
    DrawCommand drawCom(drawer);
    facade->executeCommand(drawCom);
}
void Controller::undo()
{
    UndoCommand com;
    facade->executeCommand(com);
    DrawCommand drawCom(drawer);
    facade->executeCommand(drawCom);
}
void Controller::moveModel(double dx, double dy, double dz)
{
    MoveObjectCommand com(dx, dy, dz);
    facade->executeCommand(com);
    DrawCommand drawCom(drawer);
    facade->executeCommand(drawCom);
}
void Controller::scaleModel(double kx, double ky, double kz)
{
    ScaleObjectCommand com(kx, ky, kz);
    facade->executeCommand(com);
    DrawCommand drawCom(drawer);
    facade->executeCommand(drawCom);
}
void Controller::rotateModel(double ax, double ay, double az)
{
    RotateObjectCommand com(ax, ay, az);
    facade->executeCommand(com);
    DrawCommand drawCom(drawer);
    facade->executeCommand(drawCom);
}
void Controller::moveCamera(double dx, double dy, double dz)
{
    MoveCameraCommand com(dx, dy, dz);
    facade->executeCommand(com);
    DrawCommand drawCom(drawer);
    facade->executeCommand(drawCom);
}
void Controller::rotateCamera(double ax, double ay, double az)
{
    RotateCameraCommand com(ax, ay, az);
    facade->executeCommand(com);
    DrawCommand drawCom(drawer);
    facade->executeCommand(drawCom);
}