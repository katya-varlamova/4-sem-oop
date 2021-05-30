//
// Created by Екатерина on 27.05.2021.
//

#ifndef LAB_04_PANEL_H
#define LAB_04_PANEL_H

#include <QObject>
#include "constants.h"
#include <QDebug>
typedef enum {
    UP, DOWN, STAY
} direction;
typedef enum
{
    BUSY, FREE
} panel_state;
class panel : public QObject{
    Q_OBJECT
public:
    panel();
    void set_target_floor(int floor);
signals:
    void set_target(int floor, direction direction);
public slots:
    void achieved_floor(int floor);
    void passed_floor(int floor);

private:
    bool is_target[FLOORS_COUNT];
    direction dir;
    int cur_target = -1;
    int target = -1;
    int cur_floor = -1;
    panel_state state;
};


#endif //LAB_04_PANEL_H
