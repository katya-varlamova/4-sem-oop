#ifndef LOADHANDLER_H
#define LOADHANDLER_H

#include "BaseHandler.h"
#include <stdio.h>
#include "Model/Figure/Primitives/Point/Point.h"
#include "Model/Figure/Primitives/Edge/Edge.h"
#include "Model/Figure/ObjectFactory/ObjectFactory.h"
#include "Model/Figure/VisibleObject/FrameModel/FrameModelBuilder/FrameModelDirector.h"
#include "Model/Figure/VisibleObject/FrameModel/FrameModelBuilder/FrameModelBuilder.h"
#include "Model/Loader/BaseLoader.h"
class LoadHandler : public BaseHandler
{
public:
    LoadHandler(std::string &name, std::shared_ptr<BaseLoader> &loader);
    void handle(std::shared_ptr<BaseScene> &scene) override;

protected:
    std::string name;
    std::shared_ptr<BaseLoader> loader;
};

#endif // LOADHANDLER_H
