#ifndef POINTS3D_H
#define POINTS3D_H

#include <stdio.h>
#include <stdlib.h>

#include "logic_domain/points/point2D/points2D.h"
#include "point3D.h"

typedef struct
{
    point3D_t *points_arr;
    size_t n;
} points3D_t;

void init_points3D(points3D_t &points);

error_t alloc_points3D(points3D_t &points);

void delete_points3D(points3D_t &points);

error_t read_points3D(points3D_t &points, FILE * const f);

void print_points3D(FILE * const f, const points3D_t &points);

void move_points3D(points3D_t &points, const move_params_t &params);

void scale_points3D(points3D_t &points, const scale_params_t &params);

void rotate_points3D(points3D_t &points, const rotate_params_t &params);

error_t projection_points3D(points2D_t &points2D, const points3D_t &points3D, const scene_params_t &params);

void init_scene_sizes(scene_params_t &params, const points3D_t &points3D);

#endif // POINTS3D_H
