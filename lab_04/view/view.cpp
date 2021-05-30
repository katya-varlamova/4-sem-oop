#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
}
void View::on_floor_1_but_clicked()
{
    lif.call(0);
}
void View::on_floor_2_but_clicked()
{
    lif.call(1);
}
void View::on_floor_3_but_clicked()
{
    lif.call(2);
}
void View::on_floor_4_but_clicked()
{
    lif.call(3);
}
void View::on_floor_5_but_clicked()
{
    lif.call(4);
}
void View::on_floor_6_but_clicked()
{
    lif.call(5);
}
void View::on_floor_7_but_clicked()
{
    lif.call(6);
}
void View::on_floor_8_but_clicked()
{
    lif.call(7);
}
View::~View()
{
    delete ui;
}

