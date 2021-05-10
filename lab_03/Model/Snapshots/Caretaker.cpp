//
// Created by Екатерина on 10.05.2021.
//

#include "Caretaker.h"
void Caretaker::addSnapshot(std::shared_ptr<Snapshot> snapshot)
{
    history.push_back(snapshot);
}
std::shared_ptr<Snapshot> Caretaker::popSnapshot()
{
    if (history.empty())
        return std::shared_ptr<Snapshot>();
    std::shared_ptr<Snapshot> shot = history.back();
    history.pop_back();
    return shot;
}