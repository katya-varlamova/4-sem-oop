//
// Created by Екатерина on 16.05.2021.
//

#ifndef LAB_03_LOADCOMMAND_H
#define LAB_03_LOADCOMMAND_H
#include "BaseCommand.h"
#include "Model/Handlers/LoadHandler.h"
#include "Model/Scene/BaseScene.h"
#include "Model/Loader/BaseLoader.h"
#include <string>
class LoadCommand : public BaseCommand
{
public:
    LoadCommand(std::shared_ptr<BaseLoader> loader, std::string name);
    virtual void execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> &caretaker) override;

protected:
    std::string name;
    std::shared_ptr<BaseLoader> loader;
};


#endif //LAB_03_LOADCOMMAND_H
