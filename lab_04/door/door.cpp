//
// Created by Екатерина on 27.05.2021.
//

#include "door.h"
door::door(QObject *parent)
{
    state = CLOSED;
    doors_stay_open_timer.setInterval(WAITING_TIME);
    doors_stay_open_timer.setSingleShot(true);
    doors_open_timer.setSingleShot(true);
    doors_close_timer.setSingleShot(true);

    QObject::connect(&doors_open_timer, SIGNAL(timeout()), this, SLOT(opened()));
    QObject::connect(&doors_close_timer, SIGNAL(timeout()), this, SLOT(closed()));

    QObject::connect(this, SIGNAL(doors_opened()), &doors_stay_open_timer,
                     SLOT(start()));
    QObject::connect(&doors_stay_open_timer, SIGNAL(timeout()), this,
                     SLOT(closing()));
}

void door::opened() {
    if (state != OPENING)
        return;

    state = OPENED;
    qDebug() << "The doors are opened!";
    emit doors_opened();
}

void door::closed() {
    if (state != CLOSING && state != CLOSED)
        return;

    state = CLOSED;
    qDebug() << "The doors are closed!";
    emit doors_closed();
}
void door::opening() {
    if (state != CLOSED)
        return;

    state = OPENING;
    qDebug() << "Doors are opening...";
    doors_open_timer.start(DOORS_TIME);
}

void door::closing() {
    if (state == CLOSED) {
        emit doors_closed();
        return;
    }
    if (state != OPENED)
        return;
    state = CLOSING;
    qDebug() << "Doors are closing...";
    doors_close_timer.start(DOORS_TIME);
}