//
// Created by Екатерина on 27.05.2021.
//

#ifndef LAB_04_CABIN_H
#define LAB_04_CABIN_H
#include <QObject>
#include <QTimer>
#include "panel/panel.h"
#include "door/door.h"
typedef enum
{
    MOVE, LOCKED, STOP
} cabin_state;
class cabin : public QObject {
    Q_OBJECT
public:
    cabin(QObject *parent = nullptr);

public slots:
    void cabin_move();
    void cabin_stop();
    void cabin_lock(int floor, direction dir);
signals:
    void cabin_passed_floor(int floor);
    void cabin_reached_target(int floor);
    void cabin_stopped(int floor);
    void door_close();
private:
    int current_floor;
    int target;
    cabin_state state;
    direction dir;
    QTimer crossing_floor_timer;
    door doors;
};


#endif //LAB_04_CABIN_H
