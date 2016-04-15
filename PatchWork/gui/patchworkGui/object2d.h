#ifndef OBJECT2D_H
#define OBJECT2D_H
#include <string.h>
#include <vector>
#include <QGraphicsScene>
#include "point.h"
#include "objectinterface.h"
#include "matrix.h"
#include <QObject>

using namespace std;

class Object2D :public ObjectInterface {
    protected:
        std::string color;
        vector<Point> vertices;
        Matrix mat;
        Object2D(std::string color): color(color){}

    public:
        //Personal method

        virtual float getArea()=0;
        virtual float getPerimeter()=0;

        std::string getColor();
        void setColor(std::string color);
        vector<Point> getPoints(){return this->vertices;}

        virtual void draw()=0;

        void applyTranslation(double x,double y);
        void applyRotationDirect(double angle);
        void applyRotationCentral(double angle,double x,double y);

        void applyRotationIndirect(double angle);
        void applyHomethety(double x,double y);
        void applyAxialSymmetry(double a, double b);
        void applyCentralSymmetry(double x,double y);

        virtual bool isLine(){return false;}
        virtual bool isEllipse(){return false;}
        virtual bool isPoly(){return false;}
        virtual bool isCircle(){return false;}

        virtual Point getCenter() =0;



private:
        void updateVertices();
};
#endif // OBJECT2D_H
