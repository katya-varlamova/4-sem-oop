#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <memory>
#include "Model/Visitors/BaseVisitor.h"
#include <vector>
class BaseObject
{
public:
    virtual bool isInvisible() = 0;
    virtual bool isComposite() = 0;
    virtual void accept(std::shared_ptr<BaseVisitor>& visitor) = 0;
    virtual std::shared_ptr<BaseObject> clone() = 0;

};

#endif // BASEOBJECT_H
