#ifndef FRESQUE_H
#define FRESQUE_H
#include "objectinterface.h"
#include <iostream>
#include <vector>
using namespace std;

class Fresque : public ObjectInterface
{
    public:
        Fresque();
        // Inherited method from ObjectInterface
        void draw();
        void applyTranslation(float x,float y);
        void applyRotationDirect(float angle);
        void applyRotationIndirect(float angle);
        void applyHomethety(float ratio);
        void applyAxialSymmetry();
        void applyCentralSymmetry();

        // Personal method
        bool add(ObjectInterface &o);
        bool remove(ObjectInterface &o);

    private:
        std::vector<ObjectInterface*> objects;
};

#endif // FRESQUE_H
