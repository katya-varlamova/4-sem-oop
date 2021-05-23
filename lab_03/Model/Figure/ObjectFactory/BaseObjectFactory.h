#ifndef BASEOBJECTFACTORY_H
#define BASEOBJECTFACTORY_H

#include <memory>
#include "Model/Figure/Primitives/Point/Point.h"
#include "Model/Figure/Primitives/Edge/Edge.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"
class BaseObjectFactory
{
public:
    virtual std::shared_ptr<BaseCamera> createCamera(double distance, std::vector<double> offset) = 0;

};

#endif // BASEOBJECTFACTORY_H
