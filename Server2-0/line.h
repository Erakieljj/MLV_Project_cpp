#ifndef LINE_H
#define LINE_H
#include "objectinterface.h"

/**
 * @brief La classe Line permet de créer une ligne avec une couleur et les deux points avec leur coordonnées respectives.
 * Les méthodes sont hérités de objectInterface.
 */
class Line : public ObjectInterface
{
    Q_OBJECT
    public:

        Line( string color,Point p1,Point p2, QObject * parent=0);
        // Inherited method from ObjectInterface
        /**
         * @brief getArea calcule et obtient l'aire de la ligne.
         * @return l'aire de la ligne.
         */
        float getArea();
        /**
         * @brief getPerimeter calcule et obtient le périmètre de la ligne.
         * @return le périmètre de la ligne.
         */
        float getPerimeter();
        /**
         * @brief draw Dessigne la ligne.
         */
        void draw();

        friend ostream& operator<< (ostream &os, const Line &p);
};

#endif // LINE_H
