//
// Created by Екатерина on 20.05.2021.
//

#ifndef LAB_03_BASEMODELLOADER_H
#define LAB_03_BASEMODELLOADER_H

#include "BaseLoader.h"
class BaseModelLoader : public BaseLoader{
public:
    virtual std::shared_ptr<BaseObject> load() override = 0;
    virtual void close() override = 0;
    virtual void open(std::string name) override = 0;
};


#endif //LAB_03_BASEMODELLOADER_H
