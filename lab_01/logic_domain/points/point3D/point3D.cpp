#include "point3D.h"
error_t read_point3D(point3D_t &point, FILE * const f)
{
    if (fscanf(f, "%lf", &point.x) != 1)
        return READ_POINTS_ERROR;
    if (fscanf(f, "%lf", &point.y) != 1)
        return READ_POINTS_ERROR;
    if (fscanf(f, "%lf", &point.z) != 1)
        return READ_POINTS_ERROR;
    return OK;
}
void print_point3D(const point3D_t &point, FILE * const f)
{
    fprintf(f, "%lf %lf %lf", point.x, point.y, point.z);
}
void move_point3D(point3D_t &point, const move_params_t &params)
{
    point.x += params.dx;
    point.y += params.dy;
    point.z += params.dz;
}
static void move_point_to_center(point3D_t &point, const point3D_t &center)
{
    point.x -= center.x;
    point.y -= center.y;
    point.z -= center.z;
}
static void move_point_from_center(point3D_t &point, const point3D_t &center)
{
    point.x += center.x;
    point.y += center.y;
    point.z += center.z;
}
void scale_point3D(point3D_t &point, const scale_params_t &params, const point3D_t &center)
{
    move_point_to_center(point, center);

    point.x *= params.kx;
    point.y *= params.ky;
    point.z *= params.kz;

    move_point_from_center(point, center);
}
static void rotate_around_x(point3D_t &point, double angle)
{
    point3D_t tmp;
    tmp.x = point.x;
    tmp.y = point.y * cos(angle) - point.z * sin(angle);
    tmp.z = point.y * sin(angle) + point.z * cos(angle);
    point.x = tmp.x;
    point.y = tmp.y;
    point.z = tmp.z;
}
static void rotate_around_y(point3D_t &point, double angle)
{
    point3D_t tmp;
    tmp.x = point.x * cos(angle) - point.z * sin(angle);
    tmp.y = point.y;
    tmp.z = point.x * sin(angle) + point.z * cos(angle);
    point.x = tmp.x;
    point.y = tmp.y;
    point.z = tmp.z;
}
static void rotate_around_z(point3D_t &point, double angle)
{
    point3D_t tmp;
    tmp.x = point.x * cos(angle) - point.y * sin(angle);
    tmp.y = point.x * sin(angle) + point.y * cos(angle);
    tmp.z = point.z;
    point.x = tmp.x;
    point.y = tmp.y;
    point.z = tmp.z;
}
void rotate_point3D(point3D_t &point, const rotate_params_t &params, const point3D_t &center)
{
    move_point_to_center(point, center);

    if (params.axis == AXIS_X)
        rotate_around_x(point, params.angle);
    else if (params.axis == AXIS_Y)
        rotate_around_y(point, params.angle);
    else if (params.axis == AXIS_Z)
        rotate_around_z(point, params.angle);

    move_point_from_center(point, center);
}
void projection_point3D(point2D_t &point2D, const point3D_t &point3D, const scene_params_t &params)
{
    point3D_t point;
    // camera rotation (while alpha = 0 and betta = 0 point camera situated at 0,0,camera_z)
    point.x = point3D.x * cos(alpha) - point3D.y * sin(alpha);
    point.y = point3D.x * sin(alpha) * cos(betta) +
              point3D.y * cos(alpha) * cos(betta) -
              point3D.z * sin(betta);
    point.z = point3D.x * sin(alpha) * sin(betta) +
              point3D.y * cos(alpha) * sin(betta) +
              point3D.z * cos(betta);

    // projection (based on similar triangles)
    point.x = point.x * (params.camera_z - params.plane_z) / (params.camera_z - point3D.z);
    point.y = point.y * (params.camera_z - params.plane_z) / (params.camera_z - point3D.z);
    point.z = point.z  - params.plane_z;

    point2D.x = point.x;
    point2D.y = point.y;
}
int compare_x_coordinates(const point3D_t &lhs, const point3D_t &rhs)
{
    if (lhs.x - rhs.x > EPS)
        return 1;
    else if (rhs.x - lhs.x > EPS)
        return -1;
    else
        return 0;
}
int compare_y_coordinates(const point3D_t &lhs, const point3D_t &rhs)
{
    if (lhs.y - rhs.y > EPS)
        return 1;
    else if (rhs.y - lhs.y > EPS)
        return -1;
    else
        return 0;
}
int compare_z_coordinates(const point3D_t &lhs, const point3D_t &rhs)
{
    if (lhs.z - rhs.z > EPS)
        return 1;
    else if (rhs.z - lhs.z > EPS)
        return -1;
    else
        return 0;
}
