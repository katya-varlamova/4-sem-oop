#ifndef POINTS2D_H
#define POINTS2D_H

#include <stdlib.h>

#include "point2D.h"

typedef struct
{
    point2D_t *points_arr;
    size_t n;
} points2D_t;

error_t alloc_points2D(points2D_t &points, size_t n);

void init_points2D(points2D_t &points);

void delete_points2D(points2D_t &points);

void transl_to_screen_coords_points2D(points2D_t &points,
                                  const scene_params_t &scene_params,
                                  const screen_params_t &screen_params);

#endif // POINTS2D_H
