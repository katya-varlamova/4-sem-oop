//
// Created by Екатерина on 27.05.2021.
//

#include "panel.h"

panel::panel()
{
    state = FREE;
    for (size_t i = 0; i < FLOORS_COUNT; i++)
        is_target[i] = false;
    cur_target = -1;
    cur_floor = 0;
    dir = STAY;
    QObject::connect(this, SIGNAL(make_busy_sig(int)), this,
                     SLOT(make_busy(int)));
}
void panel::make_busy(int floor)
{
    if (floor < 0 || floor >= FLOORS_COUNT)
        return;
    state = BUSY;
    is_target[floor] = true;
    search_target();
    emit set_cabin_target(cur_target, dir);
}
void panel::make_free(int floor)
{
    cur_floor = floor;
    if (cur_floor != cur_target) {
        qDebug() << "Moving... floor:" << floor + 1;
        return;
    }
    state = FREE;
    is_target[cur_target] = false;
    cur_target = -1;
    search_target();
    emit make_busy_sig(cur_target);
}
void panel::search_target()
{
    if (dir == UP)
    {
        for (int i = cur_floor; i < FLOORS_COUNT; i++)
            if (is_target[i]) {
                cur_target = i;
                break;
            }
        if (cur_target == -1) {
            for (int i = cur_floor; i > -1; i--)
                if (is_target[i]) {
                    cur_target = i;
                    break;
                }
            if (cur_target == -1)
                dir = STAY;
            else
                dir = DOWN;
        }
    }
    else
    {
        for (int i = cur_floor; i > -1; i--)
            if (is_target[i]) {
                cur_target = i;
                break;
            }
        if (cur_target == -1)
            dir = STAY;
        else
            dir = DOWN;
        if (cur_target == -1) {
            for (int i = cur_floor; i < FLOORS_COUNT; i++)
                if (is_target[i]) {
                    cur_target = i;
                    break;
                }
            if (cur_target == -1)
                dir = STAY;
            else
                dir = UP;
        }
    }
}