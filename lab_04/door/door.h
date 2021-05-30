//
// Created by Екатерина on 27.05.2021.
//

#ifndef LAB_04_DOOR_H
#define LAB_04_DOOR_H
#include <QObject>
#include <QTimer>
#include <QDebug>
#include "constants.h"
typedef enum
{
    OPENING, OPENED, CLOSING, CLOSED
} door_state;
class door : public QObject{
    Q_OBJECT
public:
    door(QObject *parent = nullptr);
signals:
    void doors_closed();
    void doors_opened();

public slots:
    void opening();
    void opened();
    void closing();
    void closed();
private:
    door_state state;
    QTimer doors_open_timer;
    QTimer doors_close_timer;
};


#endif //LAB_04_DOOR_H
