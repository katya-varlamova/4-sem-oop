#include "Facade.h"
Facade::Facade()
{
    std::vector<double> worldOffset = {0, 0, 700};
    double distance = 400;
    std::shared_ptr<BaseSceneBuilder> builder(new SceneBuilder(distance, worldOffset));
    std::shared_ptr<BaseSceneDirector> director(new SceneDirector());

    this->scene = director->createScene(builder);
    this->caretaker = std::shared_ptr<Caretaker>(new Caretaker);
}
void Facade::moveCamera(double dx, double dy, double dz)
{
    caretaker->addSnapshot(scene->makeSnapshot());
    MoveCameraHandler mh(dx, dy, dz);
    mh.handle(scene);
}
void Facade::rotateCamera(double ax, double ay, double az)
{
    caretaker->addSnapshot(scene->makeSnapshot());
    RotateCameraHandler rh(ax, ay, az);
    rh.handle(scene);
}

void Facade::moveObject(double dx, double dy, double dz)
{
    caretaker->addSnapshot(scene->makeSnapshot());
    MoveObjectHandler mh(dx, dy, dz);
    mh.handle(scene);
}
void Facade::rotateObject(double ax, double ay, double az)
{
    caretaker->addSnapshot(scene->makeSnapshot());
    RotateObjectHandler rh(ax, ay, az);
    rh.handle(scene);
}
void Facade::scaleObject(double kx, double ky, double kz)
{
    caretaker->addSnapshot(scene->makeSnapshot());
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
bool Facade::undo()
{
    std::cout << "here" << std::endl;
    std::shared_ptr<Snapshot> shot = caretaker->popSnapshot();
    if (!shot)
        return false;
    scene->restore(shot);
    return true;
}