//
// Created by Екатерина on 10.05.2021.
//

#ifndef LAB_03_CARETAKER_H
#define LAB_03_CARETAKER_H
#include <vector>
#include <memory>
#include "Snapshot.h"
class Caretaker
{
public:
    Caretaker() = default;
    void addSnapshot(std::shared_ptr<Snapshot> snapshot);
    std::shared_ptr<Snapshot> popSnapshot();
protected:
    std::vector<std::shared_ptr<Snapshot>> history;
};

#endif //LAB_03_CARETAKER_H
