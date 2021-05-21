//
// Created by Екатерина on 19.05.2021.
//

#ifndef LAB_03_FILEMODELLOADER_H
#define LAB_03_FILEMODELLOADER_H

#include "BaseModelLoader.h"
class FileModelLoader : public BaseModelLoader{
public:
    FileModelLoader(FILE *f);
    virtual std::shared_ptr<BaseObject> load() override;
    virtual void open(std::string name) override;
    virtual void close() override;

protected:
    FILE  *f;
};


#endif //LAB_03_FILEMODELLOADER_H
