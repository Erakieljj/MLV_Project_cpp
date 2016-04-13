#ifndef LINE_H
#define LINE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
using namespace  std;

class Line : public Object2D
{
    public:
        Line(string color,Point p1,Point p2);
        // Inherited method from Object2D
        float getArea();
        float getPerimeter();
        void draw();

        friend ostream& operator<< (ostream &os, const Line &p);
};

#endif // LINE_H
