#include "manager.h"

error_t make_task(model2D_t &model2D, const params_t &params, const task_t &task)
{
    error_t err = OK;
    static model3D_t model = init_model3D();
    if (task == UPLOAD)
    {
        err = load_model(model, params.load_params);
    } else if (task == DOWNLOAD)
    {
        err = download_model(model, params.load_params);
    } else if (task == MOVE)
    {
        err = move_model(model, params.move_params);
    } else if (task == SCALE)
    {
        err = scale_model(model, params.scale_params);
    } else if (task == ROTATE)
    {
        err = rotate_model(model, params.rotate_params);
    } else if (task == PROJECTION)
    {
        err = projection_model(model2D, params.proj_params, model);
    } else if (task == DESTROY)
    {
        delete_model3D(model);
    }
    else
        err = INCORRECT_COMMAND;
    return err;
}
