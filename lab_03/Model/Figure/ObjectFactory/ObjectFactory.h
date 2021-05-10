#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include <vector>
#include "BaseObjectFactory.h"
#include "Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModelBuilder/FrameModelDirector.h"
#include "Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModelBuilder/FrameModelBuilder.h"
class ObjectFactory final: public BaseObjectFactory
{
public:
    virtual std::shared_ptr<BasePoint> createPoint(double x, double y, double z) override;
    virtual std::shared_ptr<BaseEdge> createEdge(std::shared_ptr<BasePoint> start, std::shared_ptr<BasePoint> finish) override;
    virtual std::shared_ptr<BaseCamera> createCamera(double distance, std::vector<double> &position) override;
    virtual std::shared_ptr<BaseObject> createFrameModel(std::vector<std::shared_ptr<BasePoint>> &points,
                                                 std::vector<std::shared_ptr<BaseEdge>> &edges) override;
};

#endif // OBJECTFACTORY_H
