#include "Facade.h"
Facade::Facade()
{
    std::vector<double> worldOffset = {0, 0, 700};
    double distance = 400;
    std::shared_ptr<BaseSceneBuilder> builder(new SceneBuilder(distance, worldOffset));
    std::shared_ptr<BaseSceneDirector> director(new SceneDirector());

    this->scene = director->createScene(builder);
}
void Facade::moveCamera(double dx, double dy, double dz)
{
    MoveCameraHandler mh(dx, dy, dz);
    mh.handle(scene);
}
void Facade::rotateCamera(double ax, double ay, double az)
{
    RotateCameraHandler rh(ax, ay, az);
    rh.handle(scene);
}

void Facade::moveObject(double dx, double dy, double dz)
{
    MoveObjectHandler mh(dx, dy, dz);
    mh.handle(scene);
}
void Facade::rotateObject(double ax, double ay, double az)
{
    RotateObjectHandler rh(ax, ay, az);
    rh.handle(scene);
}
void Facade::scaleObject(double kx, double ky, double kz)
{
    ScaleObjectHandler sh(kx, ky, kz);
    sh.handle(scene);
}
void Facade::loadData(const char *filename)
{
    LoadHandler lh(filename);
    lh.handle(scene);
}
void Facade::draw(std::shared_ptr<BaseDrawer>& drawer)
{
    std::shared_ptr<BaseScene> copyScene(new Scene(scene));

    ProjectionHandler ph;
    ph.handle(copyScene);

    DrawHandler dh(drawer);
    dh.handle(copyScene);
}
