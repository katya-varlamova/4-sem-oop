//
// Created by Екатерина on 21.05.2021.
//

#ifndef LAB_03_BASELOADERCREATOR_H
#define LAB_03_BASELOADERCREATOR_H

#include "Model/Loader/BaseLoader.h"
class BaseLoaderCreator {
public:
    virtual std::shared_ptr<BaseLoader> createLoader() = 0;
};


#endif //LAB_03_BASELOADERCREATOR_H
