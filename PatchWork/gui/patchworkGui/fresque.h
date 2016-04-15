#ifndef FRESQUE_H
#define FRESQUE_H
#include "objectinterface.h"
#include <iostream>
#include <vector>
#include <QGraphicsScene>
#include <QObject>
using namespace std;


/**
 * @brief La classe Fresque regroupe un ensemble de dessins d'élèves.
 * Elle possède un containeur afin d'ajouter les formes géométrique (dessins des élèves).
 */
class Fresque : public ObjectInterface
{
    Q_OBJECT
    public:
        Fresque(QGraphicsScene *scene);
        // Inherited method from ObjectInterface
        /**
         * @brief draw Dessine la fresque à partir des dessins des différents élèves.
         */
        void draw();

        /**
         * @brief applyTranslation Applique une translation à la fresque.
         * @param x Valeur en abcisse de x.
         * @param y Valeur en ordonné de y.
         */
        void applyTranslation(double x,double y);

        /**
         * @brief applyRotationDirect Applique une rotation directe à la fresque.
         * @param angle Angle de rotation indirecte.
         */
        void applyRotationDirect(double angle);

        /**
         * @brief applyRotationIndirect Applique une rotation indirecte à la fresque.
         * @param angle Angle de rotation directe.
         */
        void applyRotationIndirect(double angle);
        void applyRotationCentral(double angle,double x,double y);

        /**
         * @brief applyHomethety Applique une rotation directe à la fresque.
         * @param x Valeur en abcisse de x.
         * @param y Valeur en ordonné de y.
         */
        void applyHomethety(double x, double y);

        /**
         * @brief applyAxialSymmetry Applique une symétrie axiale à la fresque.
         * @param x Valeur en abcisse de a.
         * @param y Valeur en ordonné de b.
         */
        void applyAxialSymmetry(double a,double b);

        /**
         * @brief applyCentralSymmetry Applique une symétrie central à la fresque.
         * @param x Valeur en abcisse de x.
         * @param y Valeur en ordonné de y.
         */
        void applyCentralSymmetry(double x,double y);


        Point getCenter(){return *(new Point(0,0));}

        // Personal method
        /**
         * @brief add Ajoute une figure géometrique à la fresque.
         * @param o Objet géométrique à ajouter.
         * @return Retourne un boolean, 'True' si l'exécution s'est passé normalement, sinon 'False' dans le cas contraire.
         */
        bool add(ObjectInterface &o);

        /**
         * @brief remove Supprime une figure gométrique de la fresque.
         * @param o Objet géométrique à supprimer.
         * @return Retourne un boolean, 'True' si l'exécution s'est passé normalement, sinon 'False' dans le cas contraire.
         */
        bool remove(ObjectInterface &o);

        float getArea();
        float getPerimeter();

        /**
         * @brief getObjects Les différents objets.
         * @return retourne les différents objets.
         */
        std::vector<ObjectInterface*> getObjects(){return objects;}

    private:
        /**
         * @brief scene Scene de la qgraphicsView.
         */
        QGraphicsScene *scene;

        /**
         * @brief objects Les différents objets.
         */
        std::vector<ObjectInterface*> objects;
};

#endif // FRESQUE_H
