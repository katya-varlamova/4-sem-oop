#include "Controller.h"

Controller::Controller(QMainWindow *view, std::shared_ptr<BaseDrawer> drawer)
{
    this->view = view;
    facade = std::shared_ptr<Facade>(new Facade());
    this->drawer = drawer;
}
void Controller::load()
{
    facade->loadData("/Users/kate/Desktop/oop/lab_01/files/model.txt");
    facade->draw(drawer);
}
void Controller::moveModel(double dx, double dy, double dz)
{
    facade->moveObject(dx, dy, dz);
    facade->draw(drawer);
}
void Controller::scaleModel(double kx, double ky, double kz)
{
    facade->scaleObject(kx, ky, kz);
    facade->draw(drawer);
}
void Controller::rotateModel(double ax, double ay, double az)
{
    facade->rotateObject(ax, ay, az);
    facade->draw(drawer);
}
void Controller::moveCamera(double dx, double dy, double dz)
{
    facade->moveCamera(dx, dy, dz);
    facade->draw(drawer);

}
void Controller::rotateCamera(double ax, double ay, double az)
{
    facade->rotateCamera(ax, ay, az);
    facade->draw(drawer);
}