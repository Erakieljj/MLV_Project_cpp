#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
using namespace  std;

class Ellipse :public Object2D
{
private:
    double rlon;
    double rlar;
public:
    Ellipse(string color,Point p1,double rlon,double rlar);

    // Inherited method from Object2D
    float getArea();
    float getPerimeter();
    void draw();
};
#endif // ELLIPSE_H
