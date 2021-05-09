#ifndef BASEEDGE_H
#define BASEEDGE_H
#include <memory>
#include "Model/Figure/VisibleObject/Point/BasePoint.h"
#include "Model/Figure/VisibleObject/VisibleObject.h"
class BaseEdge : public VisibleObject
{
public:
    BaseEdge(std::shared_ptr<BasePoint> &start, std::shared_ptr<BasePoint> &finish);

    virtual bool isComposite() override;
    std::shared_ptr<BasePoint> getStart();
    std::shared_ptr<BasePoint> getFinish();

    void setStart(std::shared_ptr<BasePoint> &start);
    void setFinish(std::shared_ptr<BasePoint> &finish);
protected:
    std::shared_ptr<BasePoint> start, finish;
};

#endif // BASEEDGE_H
