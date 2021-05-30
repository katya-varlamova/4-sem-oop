//
// Created by Екатерина on 27.05.2021.
//

#include "lift.h"
lift::lift()
{
    QObject::connect(&pan, SIGNAL(set_cabin_target(int, direction)), &cab,
                     SLOT(cabin_preparing(int, direction)));
    QObject::connect(&cab, SIGNAL(cabin_passed_floor(int)),
                     &pan, SLOT(make_free(int)));
    QObject::connect(&cab, SIGNAL(cabin_stopped(int)), &pan,
                     SLOT(make_free(int)));
}
void lift::call(int floor)
{
    emit pan.make_busy_sig(floor);
}