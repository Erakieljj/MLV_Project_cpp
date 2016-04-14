#ifndef POLYGONE_H
#define POLYGONE_H
#include "objectinterface.h"

/**
 * @brief La classe Polygone permet de créer un polygone quelconque avec une couleur et une liste des points avec leur coordonnées respectives.
 * Les méthodes sont hérités de objectInterface.
 */
class Polygone : public ObjectInterface
{
    public:
        /**
         * @brief Polygone Constructeur de la classe Polygone.
         * @param color Couleur du polygone.
         * @param points Listes des point avec leur coordonnées x et y.
         */
        Polygone(string color,initializer_list<Point> points);
        // Inherited method from ObjectInterface
        /**
         * @brief getArea Calcule et obtient l'aire du polygone.
         * @return L'aire du polygone.
         */
        float getArea();
        /**
         * @brief getPerimeter Calcule et obtient le périmètre du polygone.
         * @return Le périmètre du polygone.
         */
        float getPerimeter();
        /**
         * @brief draw Dessine la forme du polygone.
         */
        void draw();
};

#endif // POLYGONE_H
