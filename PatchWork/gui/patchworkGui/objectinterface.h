#ifndef OBJECTINTERFACE_H
#define OBJECTINTERFACE_H
#include <iostream>
#include <stdexcept>
#include <QGraphicsScene>

using namespace std;

class ObjectInterface
{ 
    public:
        virtual ~ObjectInterface(){}

        virtual void draw()=0;
        virtual void applyTranslation(double x,double y)=0;
        virtual void applyRotationDirect(double angle)=0;
        virtual void applyRotationIndirect(double angle)=0;
        virtual void applyHomethety(double x,double y)=0;
        virtual void applyAxialSymmetry(double a,double b)=0;
        virtual void applyCentralSymmetry(double x,double y)=0;

        virtual float getArea() =0;
        virtual float getPerimeter() =0;
    };

#endif // OBJECTINTERFACE_H
