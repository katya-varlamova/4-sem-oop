//
// Created by Екатерина on 27.05.2021.
//

#include "cabin.h"
cabin::cabin(QObject *parent)
{
    current_floor = 0;
    target = -1;
    state = STOP;
    dir = STAY;
    crossing_floor_timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(door_close()), &doors, SLOT(closing()));
    QObject::connect(&doors, SIGNAL(doors_closed()), this, SLOT(cabin_move()));
    QObject::connect(&crossing_floor_timer, SIGNAL(timeout()), this,
                     SLOT(cabin_move()));
    QObject::connect(this, SIGNAL(cabin_reached_target(int)), this,
                     SLOT(cabin_stop()));
    QObject::connect(this, SIGNAL(cabin_stopped(int)), &doors,
                     SLOT(opening()));
}
void cabin::cabin_move() {
    if (target != -1 && state == LOCKED) {
        state = MOVE;
        if (current_floor == target) {
            emit cabin_reached_target(current_floor);
        } else {
            crossing_floor_timer.start(CROSSING_FLOOR);
        }
        return;
    }
    if (state == MOVE) {
        if (dir == UP)
            current_floor++;
        else if (dir == DOWN)
            current_floor--;
        if (current_floor == target) {
            emit cabin_reached_target(current_floor);
        } else {
            emit cabin_passed_floor(current_floor);
            crossing_floor_timer.start(CROSSING_FLOOR);
        }
    }
}
void cabin::cabin_stop()
{
    if (state != MOVE)
        return;

    state = STOP;
    target = -1;
    dir = STAY;
    qDebug() << "Staying at floor " << QString::number(current_floor + 1) << ".";
    emit cabin_stopped(current_floor);
}

void cabin::cabin_lock(int floor, direction dir)
{
    this->dir = dir;
    target = floor;
    state = LOCKED;
    emit door_close();
}