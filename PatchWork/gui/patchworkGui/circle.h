#ifndef CIRCLE_H
#define CIRCLE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
#include <QGraphicsScene>
#include <QObject>
using namespace  std;

/**
 * @brief La classe Circle permet de créer un cercle avec une couleur, un centre de coordonnées x et y, un rayon.
 */
class Circle : public Object2D
{
Q_OBJECT
private:
    double rayon;
    QGraphicsScene *scene;
    public:

        Circle(string color,Point p1,double rayon,QGraphicsScene *scene);

        // Inherited method from Object2D
        /**
         * @brief fonction qui calcule l'aire du cercle.
         * @return Retourne l'aire du cercle.
         */
        float getArea();

        /**
         * @brief fonction qui calcule le périmètre du cercle.
         * @return Retourne le périmètre du cercle.
         */
        float getPerimeter();

        /**
         * @brief fonction qui set le rayon du cercle.
         * @param x Taille du rayon.
         * @return Retourne le périmètre du cercle.
         */
        void setRayon(double x){rayon*=x;}

        /**
         * @brief draw Dessine la forme du cercle.
         */
        void draw();

        /**
         * @brief fonction qui détermine si l'objet est un cercle.
         * @return retourne vrai si l'objet est un cercle sinon faux.
         */
        bool isCircle(){return true;}

        /**
         * @brief fonction qui récupère le centre du cercle.
         * @return retourne un point qui correspond au centre du cercle.
         */
        Point getCenter();
        double getRayon(){return rayon;}

};

#endif // CIRCLE_H
