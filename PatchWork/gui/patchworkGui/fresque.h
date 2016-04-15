#ifndef FRESQUE_H
#define FRESQUE_H
#include "objectinterface.h"
#include <iostream>
#include <vector>
#include <QGraphicsScene>
#include <QObject>
using namespace std;


/**
 * @brief La classe Fresque
 */
class Fresque : public ObjectInterface
{
    Q_OBJECT
    public:
        Fresque(QGraphicsScene *scene);
        // Inherited method from ObjectInterface
        void draw();
        void applyTranslation(double x,double y);
        void applyRotationDirect(double angle);
        void applyRotationIndirect(double angle);
        void applyRotationCentral(double angle,double x,double y);
        void applyHomethety(double x, double y);
        void applyAxialSymmetry(double a,double b);
        void applyCentralSymmetry(double x,double y);
        Point getCenter(){return *(new Point(0,0));}

        // Personal method
        bool add(ObjectInterface &o);
        bool remove();

        float getArea();
        float getPerimeter();
        std::vector<ObjectInterface*> getObjects(){return objects;}

    private:
        QGraphicsScene *scene;
        std::vector<ObjectInterface*> objects;
};

#endif // FRESQUE_H
