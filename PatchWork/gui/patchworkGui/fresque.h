#ifndef FRESQUE_H
#define FRESQUE_H
#include "objectinterface.h"
#include <iostream>
#include <vector>
#include <QGraphicsScene>
using namespace std;

class Fresque : public ObjectInterface
{
    public:
        Fresque(QGraphicsScene *scene);
        // Inherited method from ObjectInterface
        void draw();
        void applyTranslation(double x,double y);
        void applyRotationDirect(double angle);
        void applyRotationIndirect(double angle);
        void applyHomethety(double x, double y);
        void applyAxialSymmetry(double a,double b);
        void applyCentralSymmetry(double x,double y);

        // Personal method
        bool add(ObjectInterface &o);
        bool remove(ObjectInterface &o);

        float getArea();
        float getPerimeter();

    private:
        QGraphicsScene *scene;
        std::vector<ObjectInterface*> objects;
};

#endif // FRESQUE_H
