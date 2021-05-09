#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    scene = std::shared_ptr<QGraphicsScene>(new QGraphicsScene());
    std::shared_ptr<QPen> pen (new QPen(Qt::red));
    std::shared_ptr<QBrush> brush (new QBrush(Qt::white));
    drawer = std::shared_ptr<BaseDrawer>(new QtDrawer(scene, brush, pen));
    controller = std::shared_ptr<Controller>(new Controller(this, drawer));ui->graphicsView->setScene(scene.get());
    connect(ui->loadBut, SIGNAL(clicked()), this, SLOT(on_loadBut_clicked()));
}
View::~View()
{
    delete ui;
}
void View::on_loadBut_clicked()
{
    scene->clear();
    controller->load();
}
void View::on_moveModelBut_clicked()
{
    bool ok;
    double x = ui->moveXModelText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    double y = ui->moveYModelText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    double z = ui->moveZModelText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    scene->clear();
    controller->moveModel(x, y, z);
}

void View::on_scaleModelBut_clicked()
{
    bool ok;
    double x = ui->scaleXModelText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    double y = ui->scaleYModelText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    double z = ui->scaleZModelText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    scene->clear();
    controller->scaleModel(x, y, z);
}

void View::on_rotateModelBut_clicked()
{
    bool ok;
    double x = ui->rotateXModelText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    double y = ui->rotateYModelText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    double z = ui->rotateZModelText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    x *=  M_PI / 180.0;
    y *=  M_PI / 180.0;
    z *=  M_PI / 180.0;
    scene->clear();
    controller->rotateModel(x, y, z);
}

void View::on_moveCameraBut_clicked()
{
    bool ok;
    double x = ui->moveXCameraText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    double y = ui->moveYCameraText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    double z = ui->moveZCameraText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    scene->clear();
    controller->moveCamera(x, y, z);
}

void View::on_scaleCameraBut_clicked()
{

}

void View::on_rotateCameraBut_clicked()
{
    bool ok;
    double x = ui->rotateXCameraText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    double y = ui->rotateYCameraText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    double z = ui->rotateZCameraText->text().toDouble(&ok);
    if (!ok)
    {
        return;
    }
    x *=  M_PI / 180.0;
    y *=  M_PI / 180.0;
    z *=  M_PI / 180.0;
    scene->clear();
    controller->rotateCamera(x, y, z);

}
