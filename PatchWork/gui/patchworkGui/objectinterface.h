#ifndef OBJECTINTERFACE_H
#define OBJECTINTERFACE_H
#include <iostream>
#include <stdexcept>
#include <QGraphicsScene>
#include <vector>
#include <QObject>
#include "point.h"

using namespace std;

class ObjectInterface : public QObject
{ 
    Q_OBJECT
    public:
        virtual ~ObjectInterface(){}
        /**
         * @brief draw virtual pure pour dessiner
         */
        virtual void draw()=0;
         /**
         * @brief applyTranslation virtual pure pour appliquer une translation
         * @param x double
         * @param y double
         */
        virtual void applyTranslation(double x,double y)=0;
         /**
         * @brief applyRotationDirect virtual pure pour la rotation
         * @param angle radian
         */
        virtual void applyRotationDirect(double angle)=0;
        /**
         * @brief applyRotationCentral virtual pure pour la rotation centrale
         * @param angle radian
         * @param x double
         * @param y double
         */
        virtual void applyRotationCentral(double angle,double x,double y)=0;
        /**
         * @brief applyRotationIndirect virtual purepour la rotation
         * @param angle radian
         */
        virtual void applyRotationIndirect(double angle)=0;
        /**
         * @brief applyHomethety virtual pure pour homothety
         * @param x double
         * @param y double
         */
        virtual void applyHomethety(double x,double y)=0;
         /**
         * @brief applyAxialSymmetry virtual pure pour symetrie axiale
         * @param a double
         * @param b double
         */
        virtual void applyAxialSymmetry(double a,double b)=0;
        /**
         * @brief applyCentralSymmetry virtual pure pour symetrie centrale
         * @param x double
         * @param y double
         */
        virtual void applyCentralSymmetry(double x,double y)=0;
        /**
         * @brief setRayon
         * @param x
         */
        virtual void setRayon(double x){x=0;}
        /**
         * @brief setRlon
         * @param x
         */
        virtual void setRlon(double x){x=0;}
         /**
         * @brief setRlar
         * @param x
         */
        virtual void setRlar(double x){x=0;}
        /**
         * @brief isLine test is subclass is a line
         * @return
         */
        virtual bool isLine(){return false;}
         /**
         * @brief isEllipse test if subclass is an ellipse
         * @return
         */
        virtual bool isEllipse(){return false;}
        /**
         * @brief isPoly test if subclass is a poly
         * @return
         */
        virtual bool isPoly(){return false;}
        /**
         * @brief isCircle test if subclass is a circle
         * @return
         */
        virtual bool isCircle(){return false;}
         /**
         * @brief getArea virtual pure for area
         * @return
         */
        virtual float getArea() =0;
        virtual float getPerimeter() =0;

        virtual std::string getColor(){return "none";}
        /**
         * @brief getCenter return un point au centre de la l'objet
         * @return
         */
        virtual Point getCenter() =0;

        virtual vector<Point> getPoints(){return *(new vector<Point>);}


    };

#endif // OBJECTINTERFACE_H
