#ifndef VISIBLEOBJECT_H
#define VISIBLEOBJECT_H


#include "Model/Figure/BaseObject.h"
class VisibleObject : public BaseObject
{
public:
    virtual bool isInvisible() override;
};

#endif // VISIBLEOBJECT_H
