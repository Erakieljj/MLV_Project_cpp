#ifndef CIRCLE_H
#define CIRCLE_H
#include "objectinterface.h"
#include <iostream>
#include <vector>
using namespace  std;

class Circle : public ObjectInterface
{
    private:
        double rayon;
    public:
        Circle(string color,Point p1,double rayon);

        // Inherited method from ObjectInterface
        float getArea();
        float getPerimeter();
        void draw();
};

#endif // CIRCLE_H
