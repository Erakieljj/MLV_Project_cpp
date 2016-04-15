#ifndef CIRCLE_H
#define CIRCLE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
#include <QGraphicsScene>
#include <QObject>
using namespace  std;

class Circle : public Object2D
{
Q_OBJECT
private:
    double rayon;
    QGraphicsScene *scene;
    public:
        Circle(string color,Point p1,double rayon,QGraphicsScene *scene);

        // Inherited method from Object2D
        float getArea();
        float getPerimeter();
        void setRayon(double x){rayon*=x;}

        void draw();
        bool isCircle(){return true;}
        Point getCenter();
        double getRayon(){return rayon;}

};

#endif // CIRCLE_H
