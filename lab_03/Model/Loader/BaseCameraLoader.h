//
// Created by Екатерина on 19.05.2021.
//

#ifndef LAB_03_BASECAMERALOADER_H
#define LAB_03_BASECAMERALOADER_H
#include "BaseLoader.h"
class BaseCameraLoader : public BaseLoader {
public:
    virtual std::shared_ptr<BaseObject> load() override = 0;
    virtual void close() override = 0;
    virtual void open(std::string name) override = 0;

};


#endif //LAB_03_BASECAMERALOADER_H
