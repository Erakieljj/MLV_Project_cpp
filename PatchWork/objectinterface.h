#ifndef OBJECTINTERFACE_H
#define OBJECTINTERFACE_H
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <QObject>
#include "point.h"
#include "objectinterface.h"
#include "matrix.h"

/**
 * @brief La classe ObjectInterface est une classe générique dérivé par les différentes formes géométriques.
 * Elle définit la couleur, le nombre de sommets et la matrice associée à la figure.
 * Elle Dérive de la classe QObject afin d'utiliser les membres des classes filles.
 */
class ObjectInterface : public QObject
{ 
    private:
        void updateVertices();

    protected:
        /**
         * @brief color Couleur de la figure géométrique.
         */
        string color;
        /**
         * @brief vertices Les coordonnées des points des sommets.
         */
        vector<Point> vertices;
        /**
         * @brief mat Matrice Matrice associéà la figure géométrique.
         */
        Matrix mat;

        ObjectInterface(QObject *parent = 0);
        ObjectInterface(string color, QObject *parent = 0);
    public:
        ~ObjectInterface(){}

        // Fonctions virtuelles.
        /**
         * @brief getArea fonction virtuelle qui obtient l'aire de l'objet géométrique.
         * @return Retourne l'aire de l'objet géométrique.
         */
        virtual inline float getArea(){return 0.0;}
        /**
         * @brief getPerimeter fonction virtuelle qui obtient le périmètre de l'objet géométrique.
         * @return Retourne le périmètre de l'objet géométrique.
         */
        virtual inline float getPerimeter(){return 0.0;}
        /**
         * @brief draw Appel de la bonne méthode pour dessiner l'objet géométrique.
         */
        virtual inline void draw(){}

        // Getter/Setter sur les membres accessibles dans les classes filles.
        /**
         * @brief getColor Obtient la couleur de l'objet géométrique.
         * @return Retourne la couleur de l'objet.
         */
        string getColor() const;
        /**
         * @brief setColor Mise à jour de la couleur de l'objet géométrique.
         * @param color la nouvelle couleur de l'objet.
         */
        void setColor(string color);
        /**
         * @brief getPoints Obtient la liste des points de l'objet géométrique.
         * @return Retourne la liste des coordonnées des points.
         */
        vector<Point> getPoints(){return this->vertices;}

        // Fonctions de transformation de la figure géométrique.

        /**
         * @brief translation Effectue l'opération de translation sur l'objet géométrique.
         * @param x Valeur en abcisse de x.
         * @param y Valeur en ordonné de y.
         * @return
         */
        void applyTranslation(double x,double y);
        /**
         * @brief rotationDirect Effectue l'opération de rotation directe sur l'objet géométrique.
         * @param alpha Angle de rotation directe.
         */
        void applyRotationDirect(double angle);
        /**
         * @brief rotationIndirect Effectue l'opération de rotation indirecte sur l'objet géométrique.
         * @param alpha Angle de rotation indirecte.
         */
        void applyRotationIndirect(double angle);
        /**
         * @brief homothety Effectue l'opération d'homothétie sur l'objet géométrique.
         * @param x Valeur en abcisse de x.
         * @param y Valeur en ordonné de y.
         */
        void applyHomethety(double x,double y);
        /**
         * @brief axialSymmetry Effectue l'opération de symétrie axiale sur l'objet géométrique.
         * @param a Valeur en abcisse de x.
         * @param b Valeur en ordonné de y.
         */
        void applyAxialSymmetry(double a, double b);
        /**
         * @brief centralSymmetry Effectue l'opération de symétrie centrale sur l'objet géométrique.
         * @param x Valeur en abcisse de x.
         * @param y Valeur en ordonné de y.
         */
        void applyCentralSymmetry(double x,double y);

    };

#endif // OBJECTINTERFACE_H
