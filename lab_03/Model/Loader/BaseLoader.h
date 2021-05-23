//
// Created by Екатерина on 18.05.2021.
//

#ifndef LAB_03_BASELOADER_H
#define LAB_03_BASELOADER_H
#include <string>
#include "Model/Figure/BaseObject.h"
#include "Model/Figure/ObjectFactory/ObjectFactory.h"
#include "Model/Errors/Exception.h"
class BaseLoader {
public:
    virtual void open(std::string name) = 0;
    virtual void close() = 0;
    virtual std::shared_ptr<BaseObject> load() = 0;
};


#endif //LAB_03_BASELOADER_H
