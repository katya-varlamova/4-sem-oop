#ifndef SCENEDIRECTOR_H
#define SCENEDIRECTOR_H

#include "BaseSceneDirector.h"
class SceneDirector : public BaseSceneDirector
{
public:
    virtual std::shared_ptr<BaseScene> createScene(std::shared_ptr<BaseSceneBuilder> &builder) override;
};

#endif // SCENEDIRECTOR_H
