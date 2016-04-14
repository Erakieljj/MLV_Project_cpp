#ifndef CIRCLE_H
#define CIRCLE_H
#include "objectinterface.h"

/**
 * @brief La classe Circle permet de créer un cercle avec une couleur, un centre de coordonnées x et y, un rayon.
 * Les méthodes sont hérités de objectInterface.
 */
class Circle : public ObjectInterface
{
    private:
        /**
         * @brief rayon Rayon du Cercle.
         */
        double rayon;
    public:
        Circle(string color,Point p1,double rayon);

        // Inherited method from ObjectInterface
        /**
         * @brief getArea Calcule et obtient l'aire du cercle.
         * @return L'aire du cercle.
         */
        float getArea();
        /**
         * @brief getPerimeter Calcule et obtient le périmètre du cercle.
         * @return Le périmètre du cercle.
         */
        float getPerimeter();
        /**
         * @brief draw Dessine la forme du cercle.
         */
        void draw();
};

#endif // CIRCLE_H
