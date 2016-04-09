#ifndef FRESQUE_H
#define FRESQUE_H
#include "objectinterface.h"

class Fresque : public ObjectInterface
{
public:
    std::vector<ObjectInterface> objects;
    Fresque();
    // Inherited method from ObjectInterface
    void draw();
    void applyTranslation(float x,float y);
    void applyRotationDirect(float angle);
    void applyRotationIndirect(float angle);
    void applyHomethety(float ratio);
    void applyAxialSymmetry();
    void applyCentralSymmetry();

    bool add(ObjectInterface o);
    bool remove(ObjectInterface o);
};

#endif // FRESQUE_H
