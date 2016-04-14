#include "ellipse.h"

using namespace std;

Ellipse::Ellipse(string color,Point p,double rlon,double rlar,QGraphicsScene *scene):scene(scene),rlon(rlon),rlar(rlar),Object2D(color)
{
    this->vertices.push_back(p);
    this->mat = *(new Matrix(this->vertices));
}

float Ellipse::getArea() {
    return 3.142 * rlon * rlar;
}

float Ellipse::getPerimeter(){
    return 3.142 * (rlar+rlon);
}

void Ellipse::draw(){
    cout << " \n**Ellipse**("<<color<< ")\nRayon large : "<<rlar<<"Rayon longeur : "<<rlon<<endl<<"Matrice : " << endl;
    this->mat.print();
    Point p = vertices.at(vertices.size()-1);
    scene->addEllipse(p.get_x()-rlon/2, p.get_y()-rlar/2, rlon, rlar,
                      QPen(QColor(color.c_str()), 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin));
}
