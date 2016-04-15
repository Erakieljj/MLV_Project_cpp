#ifndef POLYGONE_H
#define POLYGONE_H
#include "object2d.h"
#include "objectinterface.h"
#include <iostream>
#include <vector>
#include <QGraphicsScene>
#include <QObject>
using namespace  std;


class Polygone : public Object2D
{
Q_OBJECT
private:
        QGraphicsScene *scene;
public:
     /**
     * @brief Polygone
     * @param color la couleur
     * @param points liste des points
     * @param scene la scene de la QGraphicsView
     */
    Polygone(string color,initializer_list<Point> points,QGraphicsScene *scene);
    /**
    * @brief Polygone
    * @param color la couleur
    * @param points liste des points
    * @param scene la scene de la QGraphicsView
    */
    Polygone(string color,vector<Point> points,QGraphicsScene *scene);
    /**
     * @brief getArea
     * @return float l'aire de la forme
     */
    float getArea();
    /**
     * @brief getPerimeter
     * @return float retourne le perimetre
     */
    float getPerimeter();
    /**
     * @brief draw dessin
     */
    void draw();
    /**
     * @brief isPoly
     * @return
     */
    bool isPoly(){return true;}
    /**
     * @brief getCenter un Point representant le centre du polygone
     * @return
     */
    Point getCenter();
};

#endif // POLYGONE_H
