#ifndef LINE_H
#define LINE_H
#include "objectinterface.h"
#include <iostream>
#include <vector>
using namespace  std;

class Line : public ObjectInterface
{
    public:
        Line(string color,Point p1,Point p2);
        // Inherited method from ObjectInterface
        float getArea();
        float getPerimeter();
        void draw();

        friend ostream& operator<< (ostream &os, const Line &p);
};

#endif // LINE_H
