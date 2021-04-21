#ifndef VIEWER_H
#define VIEWER_H

#include <QMainWindow>
#include "logic_domain/model/manager.h"

#define WIDTH 1500
#define HEIGHT 1000
#define DOWNLOAD_PATH "/Users/kate/Desktop/oop/lab_01/files/outmodel.txt"
#define UPLOAD_PATH "/Users/kate/Desktop/oop/lab_01/files/model.txt"

QT_BEGIN_NAMESPACE
namespace Ui { class Viewer; }
QT_END_NAMESPACE

class Viewer : public QMainWindow
{
    Q_OBJECT

public:
    Viewer(QWidget *parent = nullptr);
    ~Viewer();
    screen_params_t screen_sizes;
    void paintEvent(QPaintEvent *event);
    void print_error(QString message);
public slots:
    void move_slot_handle();
    void scale_slot_handle();
    void rotate_slot_handle();
    void load_slot_handle();
    void download_slot_handle();
private:
    Ui::Viewer *ui;
};
#endif // VIEWER_H
