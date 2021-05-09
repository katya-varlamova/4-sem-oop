#ifndef LOADHANDLER_H
#define LOADHANDLER_H

#include "BaseHandler.h"
#include <stdio.h>
#include "Model/Figure/VisibleObject/Point/Point.h"
#include "Model/Figure/VisibleObject/Edge/Edge.h"
#include "Model/Figure/ObjectFactory/ObjectFactory.h"
#include "Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModelBuilder/FrameModelDirector.h"
#include "Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModelBuilder/FrameModelBuilder.h"
class LoadHandler : public BaseHandler
{
public:
    LoadHandler(const char *filename);
    void handle(std::shared_ptr<BaseScene> &scene) override;

protected:
    const char *filename;
};

#endif // LOADHANDLER_H
