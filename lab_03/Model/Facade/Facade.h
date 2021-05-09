#ifndef FACADE_H
#define FACADE_H
#include "Drawer/QtDrawer.h"
#include "Model/Scene/Scene.h"
#include "Model/Scene/SceneBuilder/SceneBuilder.h"
#include "Model/Scene/SceneBuilder/SceneDirector.h"
#include "Model/Handlers/LoadHandler.h"
#include "Model/Handlers/MoveCameraHandler.h"
#include "Model/Handlers/MoveObjectHandler.h"
#include "Model/Handlers/ScaleObjectHandler.h"
#include "Model/Handlers/RotateCameraHandler.h"
#include "Model/Handlers/RotateObjectHandler.h"
#include "Model/Handlers/DrawHandler.h"
#include "Model/Handlers/ProjectionHandler.h"
class Facade
{
public:
    Facade();
    void moveCamera(double dx, double dy, double dz);
    void rotateCamera(double ax, double ay, double az);
    //void scaleCamera(double kx, double ky, double kz);

    void moveObject(double dx, double dy, double dz);
    void rotateObject(double ax, double ay, double az);
    void scaleObject(double kx, double ky, double kz);


    void loadData(const char * filename);
    void draw(std::shared_ptr<BaseDrawer>& drawer);

    bool undo();

protected:
    std::shared_ptr<BaseScene> scene;
};

#endif // FACADE_H
