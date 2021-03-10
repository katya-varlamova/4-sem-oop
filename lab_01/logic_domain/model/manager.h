#ifndef MANAGER_H
#define MANAGER_H

#include "model3D.h"
#include "model2D.h"

typedef enum
{
    MOVE,
    ROTATE,
    SCALE,
    PROJECTION,
    UPLOAD,
    DOWNLOAD,
    DESTROY
} task_t;

typedef union
{
    move_params_t move_params;
    scale_params_t scale_params;
    rotate_params_t rotate_params;
    load_params_t load_params;
    projection_params_t proj_params;
} params_t;

error_t make_task(model2D_t &model2D, const params_t &params, const task_t &task);

#endif // MANAGER_H
