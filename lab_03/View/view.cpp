#include "view.h"
#include "ui_view.h"
unique_ptr<BaseDrawerCreator> View::createQtDrawerCreator()
{
    scene = std::shared_ptr<QGraphicsScene>(new QGraphicsScene());
    std::shared_ptr<QPen> pen (new QPen(Qt::red));
    std::shared_ptr<QBrush> brush (new QBrush(Qt::white));
    return std::unique_ptr<BaseDrawerCreator>(new QtDrawerCreator(scene, pen, brush));
}
unique_ptr<BaseLoaderCreator> View::createFileLoaderCreator()
{
    return std::unique_ptr<BaseLoaderCreator>(new FileLoaderCreator());
}
void View::registration()
{
    Configuration configuration;
    configuration.readConfiguration(configName);
    std::string ds = configuration.getDataSource();
    std::string gl = configuration.getGraphicsLibrary();

    // registration of all DrawerCreators
    GraphicsSolution graphicsSolution;
    graphicsSolution.registration("qt", &View::createQtDrawerCreator);

    // registration of all LoaderCreators
    LoaderSolution loaderSolution;
    loaderSolution.registration("file", &View::createFileLoaderCreator);

    std::shared_ptr<BaseDrawerCreator>drawerCreator(graphicsSolution.create(this, gl));
    drawer = drawerCreator->createDrawer();
    std::shared_ptr<BaseLoaderCreator>loaderCreator(loaderSolution.create(this, ds));
    loader = loaderCreator->createLoader();
}
View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    registration();
    controller = std::shared_ptr<Controller>(new Controller(this, drawer, loader));
    ui->graphicsView->setScene(scene.get());
}
View::~View()
{
    delete ui;
}
void View::on_undoBut_clicked()
{
    scene->clear();
    controller->undo();
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
