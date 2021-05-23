#ifndef COMPOSITEOBJECT_H
#define COMPOSITEOBJECT_H
#include <vector>
#include "Model/Figure/VisibleObject/VisibleObject.h"
class CompositeObject : public BaseObject
{
public:
    CompositeObject() = default;
    CompositeObject(std::vector<std::shared_ptr<BaseObject>> &objects);
    virtual bool isComposite() override;

    void addObject(std::shared_ptr<BaseObject> obj);
    void removeObject(std::vector<std::shared_ptr<BaseObject>>::const_iterator iter);
    std::vector<std::shared_ptr<BaseObject>> getObjects();

    std::vector<std::shared_ptr<BaseObject>>::const_iterator begin();
    std::vector<std::shared_ptr<BaseObject>>::const_iterator end();

    void accept(std::shared_ptr<BaseVisitor> &visitor) override;
    std::shared_ptr<BaseObject> clone() override;
    void transform(Matrix<double> &transformMatrix) override;
    bool isInvisible() override;

protected:
    std::vector<std::shared_ptr<BaseObject>> objects;
};

#endif // COMPOSITEOBJECT_H
