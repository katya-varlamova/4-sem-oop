//
// Created by Екатерина on 18.05.2021.
//

#ifndef LAB_03_FILESCENELOADER_H
#define LAB_03_FILESCENELOADER_H

#include "BaseSceneLoader.h"
#include "FileModelLoader.h"
#include "FileCameraLoader.h"
class FileSceneLoader : public BaseSceneLoader{
public:
    FileSceneLoader(FILE *f = NULL);
    virtual std::shared_ptr<BaseObject> load() override;
    virtual void open(std::string name) override;
    virtual void close() override;

protected:
    FILE *f = NULL;
};


#endif //LAB_03_FILESCENELOADER_H
