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
    doors_stay_open_timer.setInterval(WAITING_TIME);
    doors_stay_open_timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(cabin_prepared()), this,
                     SLOT(cabin_move()));
    QObject::connect(&crossing_floor_timer, SIGNAL(timeout()), this,
                     SLOT(cabin_move()));
    QObject::connect(this, SIGNAL(cabin_end_moving()), this,
                             SLOT(cabin_wait_opening()));
    QObject::connect(this, SIGNAL(cabin_wait_opening_sig()), &doors,
                     SLOT(opening()));
    QObject::connect(&doors, SIGNAL(doors_opened()), this,
                     SLOT(cabin_wait_closing()));

    QObject::connect(this, SIGNAL(cabin_wait_closing_sig()), &doors_stay_open_timer,
                     SLOT(start()));
    QObject::connect(&doors_stay_open_timer, SIGNAL(timeout()), &doors,
                     SLOT(closing()));
    QObject::connect(&doors, SIGNAL(doors_closed()), this, SLOT(cabin_stop()));

}
void cabin::cabin_move() {
    if (state != MOVE && state != PREPARED)
        return;

    if (state == PREPARED && target != -1) {
        state = MOVE;
        if (current_floor == target) {
            emit cabin_end_moving();
        } else {
            crossing_floor_timer.start(CROSSING_FLOOR);
        }
    }

    if (state == MOVE) {
        if (dir == UP)
            current_floor++;
        else if (dir == DOWN)
            current_floor--;
        if (current_floor == target) {
            emit cabin_end_moving();
        } else {
            emit cabin_passed_floor(current_floor);
            crossing_floor_timer.start(CROSSING_FLOOR);
        }
    }
}
void cabin::cabin_stop()
{
    if (state != WAIT_CLOSING)
        return;
    state = STOP;
    target = -1;
    dir = STAY;
    qDebug() << "Staying at floor " << QString::number(current_floor + 1) << ".";
    emit cabin_stopped(current_floor);
}
void cabin::cabin_wait_opening()
{
    if (state != MOVE)
        return;
    state = WAIT_OPENING;
    emit cabin_wait_opening_sig();
}
void cabin::cabin_wait_closing()
{
    if (state != WAIT_OPENING)
        return;
    state = WAIT_CLOSING;
    emit cabin_wait_closing_sig();
}
void cabin::cabin_preparing(int floor, direction dir)
{
    this->dir = dir;
    target = floor;
    if (state != STOP)
        return;
    state = PREPARED;
    emit cabin_prepared();
}