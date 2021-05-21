//
// Created by Екатерина on 21.05.2021.
//

#ifndef LAB_03_FILELOADERCREATOR_H
#define LAB_03_FILELOADERCREATOR_H

#include "Model/Loader/FileSceneLoader.h"
#include "BaseLoaderCreator.h"
class FileLoaderCreator : public BaseLoaderCreator {
public:
    FileLoaderCreator() = default;
    virtual std::shared_ptr<BaseLoader> createLoader() override;

};


#endif //LAB_03_FILELOADERCREATOR_H
