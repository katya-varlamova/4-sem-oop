#ifndef INVISIBLEOBJECT_H
#define INVISIBLEOBJECT_H

#include "Model/Figure/BaseObject.h"
class InvisibleObject : public BaseObject
{
public:
    virtual bool isInvisible() override;
};

#endif // INVISIBLEOBJECT_H
