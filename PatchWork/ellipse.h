#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "objectinterface.h"

/**
 * @brief La classe Ellipse permet de créer une ellipse avec une couleur, un centre de coordonnées x et y,
 * un rayon pour la largeur et un rayon pour la longueur.
 * Les méthodes sont hérités de objectInterface.
 */
class Ellipse :public ObjectInterface
{
    Q_OBJECT
    private:
        /**
         * @brief rlon Rayon pour longueur ellipse.
         */
        double rlon;
        /**
         * @brief rlar Rayon pour largeur ellipse.
         */
        double rlar;
    public:
        Ellipse(string color,Point p1,double rlon,double rlar);

        double getRlon() const;
        double getRlar() const;

        // Inherited method from ObjectInterface
        /**
         * @brief getArea Calcule et obtient l'aire de l'ellipse.
         * @return L'aire de l'ellipse.
         */
        float getArea();
        /**
         * @brief getPerimeter Calcule et obtient le périmètre de l'ellipse.
         * @return Le périmètre de l'ellipse.
         */
        float getPerimeter();
        /**
         * @brief draw Dessine la forme de l'ellipse.
         */
        void draw();
};
#endif // ELLIPSE_H
