#ifndef LINE_H
#define LINE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
using namespace  std;

class Line : public Object2D,public ObjectInterface
{
    public:
        Line(string color,Point p1,Point p2);
        // Inherited method from Object2D
        float getArea();
        float getPerimeter();

        // Inherited method from ObjectInterface
        virtual void draw();
        void applyTranslation(float x,float y);
        void applyRotationDirect(float angle);
        void applyRotationIndirect(float angle);
        void applyHomethety(float ratio);
        void applyAxialSymmetry();
        void applyCentralSymmetry();

        friend ostream& operator<< (ostream &os, const Line &p);
};

#endif // LINE_H
