#ifndef POLYGONE_H
#define POLYGONE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
using namespace  std;


class Polygone : public Object2D
{
public:
    Polygone(string color,initializer_list<Point> points);
    float getArea();
    float getPerimeter();
    void draw();
};

#endif // POLYGONE_H
