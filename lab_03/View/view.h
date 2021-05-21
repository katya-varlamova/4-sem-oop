#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "Controller/Controller.h"
#include "Drawer/DrawerFactory/QtDrawerCreator.h"
#include "Model/Loader/LoaderCreator/FileLoaderCreator.h"
#include "Model/Solution/Configuration.h"
#include "Model/Solution/GraphicsSolution.h"
#include "Model/Solution/LoaderSolution.h"
#define configName "/Users/kate/Desktop/oop/lab_03/files/config.txt"
QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();

private:
    void registration();
    unique_ptr<BaseDrawerCreator> createQtDrawerCreator();
    unique_ptr<BaseLoaderCreator> createFileLoaderCreator();
    Ui::View *ui;
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<Controller> controller;
    std::shared_ptr<BaseDrawer> drawer;
    std::shared_ptr<BaseLoader> loader;
private slots:
    void on_loadBut_clicked();

    void on_undoBut_clicked();

    void on_moveModelBut_clicked();

    void on_scaleModelBut_clicked();

    void on_rotateModelBut_clicked();

    void on_moveCameraBut_clicked();

    void on_scaleCameraBut_clicked();

    void on_rotateCameraBut_clicked();
};



#endif // VIEW_H
