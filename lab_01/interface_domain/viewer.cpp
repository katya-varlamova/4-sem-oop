#include "viewer.h"
#include "ui_viewer.h"
#include <QPainter>

void Viewer::print_error(QString message)
{
    ui->textEdit->setTextColor(Qt::red);
    ui->textEdit->setText(message);
}
double to_rad(double ang)
{
    double ret = ang * (M_PI / 180.0);
    return ret;
}
void Viewer::move_slot_handle()
{
    bool ok;
    double x = ui->x_text->text().toDouble(&ok);
    if (!ok)
    {
        print_error("error reading move x");
        return;
    }
    double y = ui->y_text->text().toDouble(&ok);
    if (!ok)
    {
        print_error("error reading move y");
        return;
    }
    double z = ui->z_text->text().toDouble(&ok);
    if (!ok)
    {
        print_error("error reading move z");
        return;
    }
    print_error("");
    params_t params;
    params.move_params = {x, y, z};
    task_t task = MOVE;
    model2D_t model;
    error_t err = make_task(model, params, task);
    if (err == MODEL_IS_NOT_LOADED_ERROR)
    {
        print_error("model has not been loaded yet");
        return;
    }
    repaint();
}
void Viewer::scale_slot_handle()
{
    bool ok;
    double scale_x = ui->scale_x_text->text().toDouble(&ok);
    if (!ok || scale_x == 0)
    {
        print_error("error reading scale coefficient x");
        return;
    }
    double scale_y =  ui->scale_y_text->text().toDouble(&ok);
    if (!ok || scale_y == 0)
    {
        print_error("error reading scale coefficient y");
        return;
    }
    double scale_z =  ui->scale_z_text->text().toDouble(&ok);
    if (!ok || scale_z == 0)
    {
        print_error("error reading scale coefficient z");
        return;
    }
    print_error("");

    params_t params;
    params.scale_params = {scale_x, scale_y, scale_z};
    task_t task = SCALE;
    model2D_t model;
    error_t err = make_task(model, params, task);
    if (err == MODEL_IS_NOT_LOADED_ERROR)
    {
        print_error("model has not been loaded yet");
        return;
    }
    repaint();
}
void Viewer::rotate_slot_handle()
{
    bool ok;
    double angle =  ui->angle_text->text().toDouble(&ok);
    if (!ok)
    {
        print_error("error reading rotation angle");
        return;
    }
    int axis_int = ui->axis_text->text().toInt(&ok);
    if (!ok || axis_int < 0 || axis_int > 2)
    {
        print_error("error reading rotation axis");
        return;
    }
    axis_t axis;
    if (axis_int == 0)
        axis = AXIS_X;
    else if (axis_int == 1)
        axis = AXIS_Y;
    else
        axis = AXIS_Z;
    print_error("");
    params_t params;
    params.rotate_params = {to_rad(angle), axis};
    task_t task = ROTATE;
    model2D_t model;
    error_t err = make_task(model, params, task);
    if (err == MODEL_IS_NOT_LOADED_ERROR)
    {
        print_error("model has not been loaded yet");
        return;
    }
    repaint();
}
void Viewer::load_slot_handle()
{
    params_t params;
    params.load_params = {UPLOAD_PATH};
    task_t task = UPLOAD;
    model2D_t model;
    error_t err = make_task(model, params, task);
    if (err == MODEL_ALREADY_LOADED_ERROR)
    {
        print_error("model already has been loaded");
        return;
    }
    else if (err == FILE_ERROR)
    {
        print_error("error while opening file");
        return;
    }
    else if (err == READ_POINTS_ERROR)
    {
        print_error("model points have incorrect format");
        return;
    }
    else if (err == MEMORY_ALLOCATION_ERROR)
    {
        print_error("smth went wrong...");
        return;
    }
    else if (err == READ_EDGES_ERROR)
    {
        print_error("model eges have incorrect format");
        return;
    }
    print_error("");
    repaint();
}
void Viewer::download_slot_handle()
{
    params_t params;
    params.load_params = {DOWNLOAD_PATH};
    task_t task = UPLOAD;
    model2D_t model;
    error_t err = make_task(model, params, task);
    if (err == MODEL_IS_NOT_LOADED_ERROR)
    {
        print_error("model has not been loaded yet");
        return;
    }
    else if (err == FILE_ERROR)
    {
        print_error("error while opening file");
        return;
    }
    print_error("");
    repaint();
}
Viewer::Viewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Viewer)
{
    ui->setupUi(this);

    screen_sizes.screen_xmin = ui->groupBox->x();
    screen_sizes.screen_ymin = ui->groupBox->y();
    screen_sizes.screen_xmax = ui->groupBox->x() + ui->groupBox->width();
    screen_sizes.screen_ymax = ui->groupBox->y() + ui->groupBox->height();

    connect(ui->move_but, SIGNAL (clicked()), this, SLOT (move_slot_handle()));

    connect(ui->scale_but, SIGNAL (clicked()), this, SLOT (scale_slot_handle()));

    connect(ui->rotate_but, SIGNAL (clicked()), this, SLOT (rotate_slot_handle()));

    connect(ui->load_but, SIGNAL (clicked()), this, SLOT (load_slot_handle()));

    connect(ui->download_but, SIGNAL (clicked()), this, SLOT (download_slot_handle()));
}
Viewer::~Viewer()
{
    params_t params;
    model2D_t model;
    task_t task = DESTROY;
    make_task(model, params, task);
    delete ui;
}
void Viewer::paintEvent(QPaintEvent *event)
{
    QPainter painter ( this );
    Q_UNUSED(event);
    painter.setPen(Qt::white);
    params_t params;
    task_t task = PROJECTION;
    model2D_t model;
    params.proj_params.screen_params = screen_sizes;
    error_t err = make_task(model, params, task);
    if (err == OK)
    {
        for (size_t i = 0; i < model.edges.n; i++)
        {
            painter.drawLine(
                    model.points2D.points_arr[model.edges.edges_arr[i].v1].x,
                    model.points2D.points_arr[model.edges.edges_arr[i].v1].y,
                    model.points2D.points_arr[model.edges.edges_arr[i].v2].x,
                    model.points2D.points_arr[model.edges.edges_arr[i].v2].y);
        }
        delete_edges(model.edges);
        delete_points2D(model.points2D);
    }
}
