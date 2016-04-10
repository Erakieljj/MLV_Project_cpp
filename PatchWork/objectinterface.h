#ifndef OBJECTINTERFACE_H
#define OBJECTINTERFACE_H
#include "iostream"
using namespace std;


class ObjectInterface
{
public:
    ObjectInterface() {}

    virtual void draw()=0;
    virtual void applyTranslation(double x,double y){}
    virtual void applyRotationDirect(double angle){}
    virtual void applyRotationIndirect(double angle){}
    virtual void applyHomethety(double x,double y){}
    virtual void applyAxialSymmetry(){}
    virtual void applyCentralSymmetry(){}
};

#endif // OBJECTINTERFACE_H
