#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
#include <QGraphicsScene>
#include <QObject>
using namespace  std;

/**
 * @brief La classe Ellipse permet de créer une ellipse avec une couleur, un centre de coordonnées x et y,
 * un rayon pour la largeur et un rayon pour la longueur.
 */
class Ellipse :public Object2D
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

    /**
     * @brief scene Scene de la qgraphicsView.
     */
     QGraphicsScene *scene;

public:
    Ellipse(string color,Point p1,double rlon,double rlar);

    // Inherited method from Object2D
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
    void draw(QGraphicsScene *scene);

    /**
     * @brief isEllipse Détermine si l'objet est une ellipse.
     * @return retourne vrai si l'objet est une ellipse sinon faux.
     */
    bool isEllipse(){return true;}

    /**
     * @brief getCenter Récupère le centre de l'ellipse.
     * @return retourne un point qui correspond au centre de l'ellipse.
     */
    Point getCenter();

    /**
     * @brief setRlon Set la longueur de l'ellipse.
     * @param x longueur de l'ellipse.
     */
    void setRlon(double x){rlon*=x;}

    /**
     * @brief setRlar Set la largeur de l'ellipse.
     * @param x largeur de l'ellipse.
     */
    void setRlar(double x){rlar*=x;}

    /**
     * @brief getRlar récupère la largeur de l'ellipse.
     * @return Retourne la largeur de l'ellipse.
     */
    double getRlar(){return rlar;}

    /**
     * @brief getRlon récupère la longueur de l'ellipse.
     * @return Retourne la longueur de l'ellipse.
     */
    double getRlon(){return rlon;}


};
#endif // ELLIPSE_H
