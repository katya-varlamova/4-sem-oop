//
// Created by Екатерина on 27.05.2021.
//

#ifndef LAB_04_PANEL_H
#define LAB_04_PANEL_H

#include <QObject>
#include "constants.h"
#include <QDebug>
typedef enum {
    UP, DOWN, STAY
} direction;
typedef enum
{
    BUSY, FREE
} panel_state;
class panel : public QObject{
    Q_OBJECT
public:
    panel();

public slots:
    void make_busy(int floor);
    void make_free(int floor);

signals:
    void set_cabin_target(int floor, direction direction);
    void make_busy_sig(int floor);

private:
    void search_target();
    bool is_target[FLOORS_COUNT];
    direction dir;
    int cur_target = -1;
    int cur_floor = -1;
    panel_state state;
};


#endif //LAB_04_PANEL_H
