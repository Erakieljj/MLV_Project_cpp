#include "circle.h"
#include <QPointF>
#include <QtCore/QtDebug>

using namespace std;

Circle::Circle(string color,Point p,double rayon,QGraphicsScene *scene):Object2D(color),rayon(rayon),scene(scene)
{
    this->vertices.push_back(p);
    this->mat = *(new Matrix(this->vertices));
}

float Circle::getArea() {
    return 3.142 * rayon * rayon;
}

float Circle::getPerimeter(){
    return 3.142 * 2* rayon;
}

void Circle::draw(){
    cout << " \n**CIRCLE**("<<color<< ")\nRayon : "<<rayon<<endl<<"Matrice : " << endl;
    this->mat.print();
    Point p = vertices.at(vertices.size()-1);
    qDebug() << "Point :" <<p.get_x()<<" "<<p.get_y();
    scene->addEllipse(p.get_x()-rayon/2, p.get_y()-rayon/2,rayon, rayon,
                     QPen(QColor(color.c_str()), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

Point Circle::getCenter(){
    Point p1 = vertices.at(0);
    return p1;
}
