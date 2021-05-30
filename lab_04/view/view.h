#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "lift/lift.h"
QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();

public slots:
    void on_floor_1_but_clicked();
    void on_floor_2_but_clicked();
    void on_floor_3_but_clicked();
    void on_floor_4_but_clicked();
    void on_floor_5_but_clicked();
    void on_floor_6_but_clicked();
    void on_floor_7_but_clicked();
    void on_floor_8_but_clicked();
private:
    Ui::View *ui;
    lift lif;
};
#endif // VIEW_H
