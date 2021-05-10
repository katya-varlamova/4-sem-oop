#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "Controller/Controller.h"
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
    Ui::View *ui;
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<Controller> controller;
    std::shared_ptr<BaseDrawer> drawer;
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
