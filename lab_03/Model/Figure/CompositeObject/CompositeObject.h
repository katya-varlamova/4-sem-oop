#ifndef COMPOSITEOBJECT_H
#define COMPOSITEOBJECT_H
#include <vector>
#include "Model/Figure/VisibleObject/VisibleObject.h"
class CompositeObject : public BaseObject
{
public:
    virtual bool isComposite() override;

    void addObject(std::shared_ptr<BaseObject> obj);
    void removeObject(std::vector<std::shared_ptr<BaseObject>>::const_iterator iter);

    std::vector<std::shared_ptr<BaseObject>>::const_iterator begin();
    std::vector<std::shared_ptr<BaseObject>>::const_iterator end();

protected:
    std::vector<std::shared_ptr<BaseObject>> objects;
};

#endif // COMPOSITEOBJECT_H
