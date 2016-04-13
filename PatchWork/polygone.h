#ifndef POLYGONE_H
#define POLYGONE_H
#include "objectinterface.h"
#include <iostream>
#include <vector>
using namespace  std;


class Polygone : public ObjectInterface
{
    public:
        Polygone(string color,initializer_list<Point> points);
        float getArea();
        float getPerimeter();
        void draw();
};

#endif // POLYGONE_H
