#ifndef OBJECT2D_H
#define OBJECT2D_H
#include <string.h>
#include <vector>
#include "point.h"
#include "objectinterface.h"
#include "matrix.h"

using namespace std;

class Object2D :public ObjectInterface {
    protected:
        std::string color;
        vector<Point> vertices;
        Matrix mat;
        Object2D(std::string color): color(color){}

    public:
        //Personal method
        virtual float getArea() {return 0;}
        virtual float getPerimeter() {return 0;}

        std::string getColor() const;
        void setColor(std::string color);
        vector<Point> getPoints(){return this->vertices;}

        virtual void draw()=0;

        void applyTranslation(double x,double y);
        void applyRotationDirect(double angle);
        void applyRotationIndirect(double angle);
        void applyHomethety(double x,double y);
        void applyAxialSymmetry();
        void applyCentralSymmetry();

};
#endif // OBJECT2D_H
