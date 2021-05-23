#ifndef BASEDRAWER_H
#define BASEDRAWER_H

#include <memory>
class BaseDrawer
{
public:   
    virtual void drawLine(double x1, double y1, double x2, double y2) = 0;
    virtual void drawPoint(double x, double y) = 0;
    virtual void changeColor(int r, int g, int b, int a) = 0;
};

#endif // BASEDRAWER_H
