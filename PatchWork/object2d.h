#ifndef OBJECT2D_H
#define OBJECT2D_H
#include <string.h>
#include <vector>
#include "point.h"
#include "objectinterface.h"

using namespace std;

class Object2D :public ObjectInterface{
    protected:
        Object2D(std::string, vector<Point>);
    public:
        std::string color; // le type peut changer
        vector<Point> vertices;
        //createObject2D();

        //Personal method

        virtual float getArea();
        virtual float getPerimeter();

        // Inherited method from ObjectInterface
        void draw();
        void applyTranslation(float x,float y);
        void applyRotationDirect(float angle);
        void applyRotationIndirect(float angle);
        void applyHomethety(float ratio);
        void applyAxialSymmetry();
        void applyCentralSymmetry();

#endif // OBJECT2D_H
