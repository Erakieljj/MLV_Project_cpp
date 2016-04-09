#ifndef FRESQUE_H
#define FRESQUE_H
#include "objectinterface.h"
#include <iostream>
#include <vector>

class Fresque : public ObjectInterface
{
public:
    Fresque();
    std::vector<ObjectInterface> objects;
    // Inherited method from ObjectInterface

    void draw();
    void applyTranslation(float x,float y);
    void applyRotationDirect(float angle);
    void applyRotationIndirect(float angle);
    void applyHomethety(float ratio);
    void applyAxialSymmetry();
    void applyCentralSymmetry();

    // Personal method
    bool add(ObjectInterface o);
    bool remove(ObjectInterface o);
};

#endif // FRESQUE_H
