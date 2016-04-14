#ifndef POLYGONE_H
#define POLYGONE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
#include <QGraphicsScene>
using namespace  std;


class Polygone : public Object2D
{
private:
        QGraphicsScene *scene;
public:
    Polygone(string color,initializer_list<Point> points,QGraphicsScene *scene);
    Polygone(string color,vector<Point> points,QGraphicsScene *scene);
    float getArea();
    float getPerimeter();
    void draw();
};

#endif // POLYGONE_H
