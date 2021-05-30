//
// Created by Екатерина on 27.05.2021.
//

#include "lift.h"
lift::lift()
{
    QObject::connect(&pan, SIGNAL(set_target(int, direction)), &cab,
                     SLOT(cabin_lock(int, direction)));
    QObject::connect(&cab, SIGNAL(cabin_passed_floor(int)),
                     &pan, SLOT(passed_floor(int)));
    QObject::connect(&cab, SIGNAL(cabin_stopped(int)), &pan,
                     SLOT(achieved_floor(int)));
}
void lift::call(int floor)
{
    pan.set_target_floor(floor);
}