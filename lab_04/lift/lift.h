//
// Created by Екатерина on 27.05.2021.
//

#ifndef LAB_04_LIFT_H
#define LAB_04_LIFT_H
#include <QObject>
#include "cabin/cabin.h"
#include "panel/panel.h"
class lift : public QObject {
    Q_OBJECT
public:
    lift();
    void call(int floor);

private:
    cabin cab;
    panel pan;
};


#endif //LAB_04_LIFT_H
