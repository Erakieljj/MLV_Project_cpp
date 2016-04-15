#ifndef OBJECTINTERFACE_H
#define OBJECTINTERFACE_H
#include <iostream>
#include <stdexcept>
#include <QGraphicsScene>
#include <vector>
#include <QObject>
#include "point.h"

using namespace std;

class ObjectInterface : public QObject
{ 
    Q_OBJECT
    public:
        virtual ~ObjectInterface(){}

        virtual void draw()=0;
        virtual void applyTranslation(double x,double y)=0;
        virtual void applyRotationDirect(double angle)=0;
        virtual void applyRotationCentral(double angle,double x,double y)=0;

        virtual void applyRotationIndirect(double angle)=0;
        virtual void applyHomethety(double x,double y)=0;
        virtual void applyAxialSymmetry(double a,double b)=0;
        virtual void applyCentralSymmetry(double x,double y)=0;

        virtual void setRayon(double x){x=0;}
        virtual void setRlon(double x){x=0;}
        virtual void setRlar(double x){x=0;}

        virtual bool isLine(){return false;}
        virtual bool isEllipse(){return false;}
        virtual bool isPoly(){return false;}
        virtual bool isCircle(){return false;}

        virtual float getArea() =0;
        virtual float getPerimeter() =0;

        virtual std::string getColor(){return "none";}

        virtual Point getCenter() =0;

        virtual vector<Point> getPoints(){return *(new vector<Point>);}


    };

#endif // OBJECTINTERFACE_H
