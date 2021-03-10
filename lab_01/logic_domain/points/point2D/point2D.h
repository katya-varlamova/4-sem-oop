#ifndef POINT2D_H
#define POINT2D_H

#include <algorithm>

#include "logic_domain/model/errors.h"

typedef struct
{
    double x, y;
} point2D_t;

typedef struct
{
    double screen_xmin, screen_xmax;
    double screen_ymin, screen_ymax;
} screen_params_t;

typedef struct
{
    double camera_z, plane_z;
    double scene_xmin, scene_xmax;
    double scene_ymin, scene_ymax;
} scene_params_t;

void transl_to_screen_coords_point2D(point2D_t &point,
                                  const scene_params_t &scene_params,
                                  const screen_params_t &screen_params);
#endif // POINT2D_H
