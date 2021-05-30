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
    target = -1;
}
void panel::set_target_floor(int floor)
{
    is_target[floor] = true;

    if (cur_target == -1)
        cur_target = floor;

    if (target == -1)
        target = floor;

    if (dir == STAY || (dir == UP && target < floor) || (dir == DOWN && target > floor))
        target = floor;

    if (dir == STAY ||
    (dir == UP && cur_target > floor && floor >= cur_floor) ||
    (dir == DOWN && cur_target < floor && floor <= cur_floor))
        cur_target = floor;

    dir = (cur_floor > cur_target) ? DOWN : UP;
    emit set_target(cur_target, dir);
}
void panel::achieved_floor(int floor)
{
    state = FREE;
    cur_floor = floor;
    if (cur_floor != cur_target)
        return;
    is_target[cur_target] = false;
    cur_target = -1;
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
    else //if (direction == DOWN)
    {
        for (int i = cur_floor; i > -1; i--)
            if (is_target[i]) {
                cur_target = i;
                break;
            }
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
    if (cur_target != -1) {
        state = BUSY;
        emit set_target(cur_target, dir);
    }
}
void panel::passed_floor(int floor)
{
    state = BUSY;
    cur_floor = floor;
    qDebug() << "Moving... floor:" << floor + 1;
}