#ifndef POINT3D_H
#define POINT3D_H

#include <cmath>
#include <stdio.h>

#include "logic_domain/model/errors.h"
#include "logic_domain/points/point2D/point2D.h"
#include "logic_domain/model/model_params.h"

#define EPS 1e-6

typedef struct
{
    double x, y, z;
} point3D_t;

const double alpha = 0;
const double betta = 0;

error_t read_point3D(point3D_t &point, FILE * const f);

void print_point3D(const point3D_t &point, FILE * const f);

void move_point3D(point3D_t &point, const move_params_t &params);

void scale_point3D(point3D_t &point, const scale_params_t &params, const point3D_t &center);

void rotate_point3D(point3D_t &point, const rotate_params_t &params, const point3D_t &center);

void projection_point3D(point2D_t &point2D, const point3D_t &point3D, const scene_params_t &params);

int compare_x_coordinates(const point3D_t &lhs, const point3D_t &rhs);

int compare_y_coordinates(const point3D_t &lhs, const point3D_t &rhs);

int compare_z_coordinates(const point3D_t &lhs, const point3D_t &rhs);

#endif // POINT3D_H
