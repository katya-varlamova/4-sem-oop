#ifndef ABSTRACTDRAWFACTORY_H
#define ABSTRACTDRAWFACTORY_H

#include <memory>
#include "Drawer/BaseDrawer.h"
class BaseDrawerCreator
{
public:
    virtual std::shared_ptr<BaseDrawer> createDrawer() = 0;
};

#endif // ABSTRACTDRAWFACTORY_H
