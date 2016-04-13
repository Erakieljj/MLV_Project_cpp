#ifndef CIRCLE_H
#define CIRCLE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
using namespace  std;

class Circle : public Object2D
{
private:
    double rayon;
    public:
        Circle(string color,Point p1,double rayon);

        // Inherited method from Object2D
        float getArea();
        float getPerimeter();
        void draw();
};

#endif // CIRCLE_H
