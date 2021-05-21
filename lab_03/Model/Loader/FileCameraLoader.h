//
// Created by Екатерина on 19.05.2021.
//

#ifndef LAB_03_FILECAMERALOADER_H
#define LAB_03_FILECAMERALOADER_H

#include "BaseCameraLoader.h"
class FileCameraLoader : public BaseCameraLoader{
public:
    FileCameraLoader(FILE *f = NULL);
    virtual std::shared_ptr<BaseObject> load() override;
    virtual void open(std::string name) override;
    virtual void close() override;

protected:
    FILE  *f;
};


#endif //LAB_03_FILECAMERALOADER_H
