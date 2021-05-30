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
    MOVE, STOP, WAIT_OPENING, WAIT_CLOSING, PREPARED
} cabin_state;
class cabin : public QObject {
    Q_OBJECT
public:
    cabin(QObject *parent = nullptr);

public slots:
    void cabin_move();
    void cabin_stop();
    void cabin_wait_opening();
    void cabin_wait_closing();
    void cabin_preparing(int floor, direction dir);
signals:
    void cabin_passed_floor(int floor);
    void cabin_end_moving();

    void cabin_prepared();
    void cabin_wait_opening_sig();
    void cabin_wait_closing_sig();
    void cabin_stopped(int floor);

private:
    int current_floor;
    int target;
    cabin_state state;
    direction dir;
    QTimer crossing_floor_timer;
    QTimer doors_stay_open_timer;
    door doors;
};


#endif //LAB_04_CABIN_H
