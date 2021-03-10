#include "point2D.h"

void transl_to_screen_coords_point2D(point2D_t &point,
                                  const scene_params_t &scene_params,
                                  const screen_params_t &screen_params)
{
    double kx = (screen_params.screen_xmax - screen_params.screen_xmin) /
            (scene_params.scene_xmax - scene_params.scene_xmin);
    double ky = (screen_params.screen_ymax - screen_params.screen_ymin) /
            (scene_params.scene_ymax - scene_params.scene_ymin);
    double k = std::min(kx, ky);
    double dx = (screen_params.screen_xmin - k * scene_params.scene_xmin +
                 screen_params.screen_xmax - k * scene_params.scene_xmax) / 2.0;
    double dy = (screen_params.screen_ymin - k * scene_params.scene_ymin +
                 screen_params.screen_ymax - k * scene_params.scene_ymax) / 2.0;

    point.x = point.x * k + dx;
    point.y = point.y * k + dy;
}
