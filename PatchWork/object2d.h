#ifndef OBJECT2D_H
#define OBJECT2D_H
#include <string.h>
#include <vector>
#include "point.h"
#include "objectinterface.h"

using namespace std;

class Object2D{
    protected:
        std::string color;
        vector<Point> vertices;
        Object2D(std::string color): color(color){}
    public:

        //Personal method
        virtual float getArea();
        virtual float getPerimeter();

        std::string getColor() const;
        void setColor(std::string color);

};
#endif // OBJECT2D_H
