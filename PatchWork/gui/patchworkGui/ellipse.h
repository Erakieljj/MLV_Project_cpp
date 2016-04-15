#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
#include <QGraphicsScene>
#include <QObject>
using namespace  std;

class Ellipse :public Object2D
{
Q_OBJECT
private:
    double rlon;
    double rlar;
     QGraphicsScene *scene;
public:
    Ellipse(string color,Point p1,double rlon,double rlar,QGraphicsScene *scene);

    // Inherited method from Object2D
    float getArea();
    float getPerimeter();
    void draw();
    bool isEllipse(){return true;}
    Point getCenter();

    void setRlon(double x){rlon*=x;}
    void setRlar(double x){rlar*=x;}

    double getRlar(){double rlar;}
    double getRlon(){double rlon;}


};
#endif // ELLIPSE_H
