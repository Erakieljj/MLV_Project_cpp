#ifndef OBJECTINTERFACE_H
#define OBJECTINTERFACE_H
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "point.h"
#include "objectinterface.h"
#include "matrix.h"

using namespace std;

class ObjectInterface
{ 
    private:
        void updateVertices();

    protected:
        std::string color;
        vector<Point> vertices;
        Matrix mat;

        ObjectInterface(){}
        ObjectInterface(std::string color): color(color){}

    public:
        ~ObjectInterface(){}

        inline float getArea(){return 0.;}
        inline float getPerimeter(){return 0.;}
        void draw(){}

        void applyTranslation(double x,double y);
        void applyRotationDirect(double angle);
        void applyRotationIndirect(double angle);
        void applyHomethety(double x,double y);
        void applyAxialSymmetry(double a, double b);
        void applyCentralSymmetry(double x,double y);

        std::string getColor() const;
        void setColor(std::string color);
        vector<Point> getPoints(){return this->vertices;}
    };

#endif // OBJECTINTERFACE_H
