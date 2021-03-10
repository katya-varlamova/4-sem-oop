#include "points3D.h"
void init_points3D(points3D_t &points)
{
    points.points_arr = NULL;
    points.n = 0;
}
error_t alloc_points3D(points3D_t &points)
{
    error_t err = OK;
    points.points_arr = (point3D_t *) calloc(points.n, sizeof(point3D_t));
    if (points.points_arr == NULL)
        err = MEMORY_ALLOCATION_ERROR;
    return err;
}
void delete_points3D(points3D_t &points)
{
    free(points.points_arr);
    points.points_arr = NULL;
    points.n = 0;
}
error_t read_points_num(size_t &n, FILE *const f)
{
    error_t err = OK;
    if (fscanf(f, "%lu", &n) != 1 || n < 1)
    {
        n = 0;
        err = READ_POINTS_ERROR;
    }
    return err;
}
error_t read_points3D(points3D_t &points, FILE *const f)
{
    error_t err = read_points_num(points.n, f);

    if (err == OK)
        err = alloc_points3D(points);

    for (size_t i = 0; err == OK && i < points.n; i++)
        err = read_point3D(points.points_arr[i], f);

    if (err != OK)
        delete_points3D(points);

    return err;
}
void print_points_num(FILE * const f, size_t n)
{
    fprintf(f, "%lu\n", n);
}
void print_points3D(FILE * const f, const points3D_t &points)
{
    print_points_num(f, points.n);
    for (size_t i = 0; i < points.n; i++)
    {
        print_point3D(points.points_arr[i], f);
        fprintf(f, "\n");
    }
}
static void find_min_point(point3D_t &min_point, const points3D_t &points,
                                int (*comp)(const point3D_t &, const point3D_t &))
{
    min_point = points.points_arr[0];
    for (size_t i = 0; i < points.n; i++)
    {
        if (comp(points.points_arr[i], min_point) < 0)
            min_point = points.points_arr[i];
    }
}
static void find_max_point(point3D_t &max_point, const points3D_t &points,
                                int (*comp)(const point3D_t &, const point3D_t &))
{
    max_point = points.points_arr[0];
    for (size_t i = 0; i < points.n; i++)
    {
        if (comp(points.points_arr[i], max_point) > 0)
            max_point = points.points_arr[i];
    }
}
static void find_center(point3D_t &center, const points3D_t &points)
{
    point3D_t min_point, max_point;
    find_min_point(min_point, points, compare_x_coordinates);
    find_max_point(max_point, points, compare_x_coordinates);
    center.x = (max_point.x + min_point.x) / 2;

    find_min_point(min_point, points, compare_y_coordinates);
    find_max_point(max_point, points, compare_y_coordinates);
    center.y = (max_point.y + min_point.y) / 2;

    find_min_point(min_point, points, compare_z_coordinates);
    find_max_point(max_point, points, compare_z_coordinates);
    center.z = (max_point.z + min_point.z) / 2;
}
void move_points3D(points3D_t &points, const move_params_t &params)
{
    for (size_t i = 0; i < points.n; i++)
        move_point3D(points.points_arr[i], params);
}
void scale_points3D(points3D_t &points, const scale_params_t &params)
{
    point3D_t center;
    find_center(center, points);
    for (size_t i = 0; i < points.n; i++)
        scale_point3D(points.points_arr[i], params, center);
}
void rotate_points3D(points3D_t &points, const rotate_params_t &params)
{
    point3D_t center;
    find_center(center, points);
    for (size_t i = 0; i < points.n; i++)
        rotate_point3D(points.points_arr[i], params, center);
}
error_t projection_points3D(points2D_t &points2D, const points3D_t &points3D, const scene_params_t &params)
{
    error_t err = alloc_points2D(points2D, points3D.n);
    if (err == OK)
        for (size_t i = 0; i < points3D.n; i++)
            projection_point3D(points2D.points_arr[i], points3D.points_arr[i], params);
    return err;
}

static void find_scene_x_sizes(scene_params_t &params, const points3D_t &points3D)
{
    if (points3D.n == 0)
        return;
    point3D_t min_point, max_point;
    find_min_point(min_point, points3D, compare_x_coordinates);
    find_max_point(max_point, points3D, compare_x_coordinates);
    params.scene_xmin = min_point.x;
    params.scene_xmax = max_point.x;
}
static void find_scene_y_sizes(scene_params_t &params, const points3D_t &points3D)
{
    if (points3D.n == 0)
        return;
    point3D_t min_point, max_point;
    find_min_point(min_point, points3D, compare_y_coordinates);
    find_max_point(max_point, points3D, compare_y_coordinates);
    params.scene_ymin = min_point.y;
    params.scene_ymax = max_point.y;
}
static void find_scene_z_sizes(scene_params_t &params, const points3D_t &points3D)
{
    if (points3D.n == 0)
        return;
    point3D_t min_point, max_point;
    find_min_point(min_point, points3D, compare_z_coordinates);
    find_max_point(max_point, points3D, compare_z_coordinates);
    params.plane_z = min_point.z + (max_point.z - min_point.z) * 2;
    params.camera_z = min_point.z + (max_point.z - min_point.z) * 4;
}
void init_scene_sizes(scene_params_t &params, const points3D_t &points3D)
{
    find_scene_x_sizes(params, points3D);
    find_scene_y_sizes(params, points3D);
    find_scene_z_sizes(params, points3D);
}
