#ifndef LINE_H
#define LINE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
#include <QGraphicsScene>
using namespace  std;

class Line : public Object2D
{
private:
    QGraphicsScene *scene;
    public:
        Line(string color,Point p1,Point p2,QGraphicsScene *scene);
        // Inherited method from Object2D
        float getArea();
        float getPerimeter();
        void draw();
        bool isLine(){return true;}

        friend ostream& operator<< (ostream &os, const Line &p);
        Point getCenter();

};

#endif // LINE_H
