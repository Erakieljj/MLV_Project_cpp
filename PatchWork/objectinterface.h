#ifndef OBJECTINTERFACE_H
#define OBJECTINTERFACE_H


class ObjectInterface
{
public:
    ObjectInterface() {}
    ~ObjectInterface(){}
    virtual void draw(){}
    virtual void applyTranslation(float x,float y){}
    virtual void applyRotationDirect(float angle){}
    virtual void applyRotationIndirect(float angle){}
    virtual void applyHomethety(float ratio){}
    virtual void applyAxialSymmetry(){}
    virtual void applyCentralSymmetry(){}
};

#endif // OBJECTINTERFACE_H
