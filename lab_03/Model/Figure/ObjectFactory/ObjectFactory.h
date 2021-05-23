#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include <vector>
#include "BaseObjectFactory.h"

class ObjectFactory final: public BaseObjectFactory
{
public:
    virtual std::shared_ptr<BaseCamera> createCamera(double distance, std::vector<double> offset) override;
};

#endif // OBJECTFACTORY_H
