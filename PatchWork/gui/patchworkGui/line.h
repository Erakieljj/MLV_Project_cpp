#ifndef LINE_H
#define LINE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
#include <QGraphicsScene>
#include <QObject>
using namespace  std;

/**
 * @brief La classe Line permet de créer une ligne avec une couleur, deux points x et y
 * qui sont les extrémités de la liagne.
 */
class Line : public Object2D
{
Q_OBJECT
private:
    /**
     * @brief scene Scene de la qgraphicsView.
     */
    QGraphicsScene *scene;

    public:
        Line(string color,Point p1,Point p2,QGraphicsScene *scene);
        // Inherited method from Object2D

        float getArea();
        float getPerimeter();

        /**
         * @brief draw Dessine la ligne.
         */
        void draw();

        /**
         * @brief isLine Détermine si l'objet est une ligne.
         * @return retourne vrai si l'objet est un ligne sinon faux.
         */
        bool isLine(){return true;}

        friend ostream& operator<< (ostream &os, const Line &p);

        /**
         * @brief getCenter Récupère le milieu d'une ligne.
         * @return retourne un point qui correspond au milieu d'une ligne.
         */
        Point getCenter();

};

#endif // LINE_H
