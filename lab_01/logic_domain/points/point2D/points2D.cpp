#include "points2D.h"
error_t alloc_points2D(points2D_t &points, size_t n)
{
    error_t err = OK;
    points.n = n;
    points.points_arr = (point2D_t *) malloc(n * sizeof(point2D_t));
    if (points.points_arr == NULL)
        err = MEMORY_ALLOCATION_ERROR;
    return err;
}
void init_points2D(points2D_t &points)
{
    points.points_arr = NULL;
    points.n = 0;
}
void delete_points2D(points2D_t &points)
{
    free(points.points_arr);
    points.points_arr = NULL;
    points.n = 0;
}
void transl_to_screen_coords_points2D(points2D_t &points,
                                           const scene_params_t &scene_params,
                                           const screen_params_t &screen_params)
{
    for (size_t i = 0; i < points.n; i++)
        transl_to_screen_coords_point2D(points.points_arr[i], scene_params, screen_params);
}

