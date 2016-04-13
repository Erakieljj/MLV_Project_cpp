#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "objectinterface.h"
#include <iostream>
#include <vector>
using namespace  std;

class Ellipse :public ObjectInterface
{
    private:
        double rlon;
        double rlar;
    public:
        Ellipse(string color,Point p1,double rlon,double rlar);

        // Inherited method from ObjectInterface
        float getArea();
        float getPerimeter();
        void draw();
};
#endif // ELLIPSE_H
