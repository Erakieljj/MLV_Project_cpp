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
    /**
     * @brief rayon Rayon du Cercle.
     */
    double rayon;
    /**
     * @brief scene Scene de la qgraphicsView.
     */
    QGraphicsScene *scene;
    public:

        /**
         * @brief Circle Constructeur.
         */
        Circle(string color,Point p1,double rayon);

        // Inherited method from Object2D
        /**
         * @brief getArea Calcule l'aire du cercle.
         * @return Retourne l'aire du cercle.
         */
        float getArea();

        /**
         * @brief getPerimeter Calcule le périmètre du cercle.
         * @return Retourne le périmètre du cercle.
         */
        float getPerimeter();

        /**
         * @brief setRayon Set le rayon du cercle.
         * @param x Taille du rayon.
         * @return Retourne le périmètre du cercle.
         */
        void setRayon(double x){rayon*=x;}

        /**
         * @brief draw Dessine la forme du cercle.
         */
        void draw(QGraphicsScene *scene);

        /**
         * @brief isCircle Détermine si l'objet est un cercle.
         * @return retourne vrai si l'objet est un cercle sinon faux.
         */
        bool isCircle(){return true;}

        /**
         * @brief getCenter Récupère le centre du cercle.
         * @return retourne un point qui correspond au centre du cercle.
         */
        Point getCenter();

        /**
         * @brief getRayon Récupère le rayon du cercle.
         * @return retourne la taille du rayon du cercle.
         */
        double getRayon(){return rayon;}

};

#endif // CIRCLE_H
