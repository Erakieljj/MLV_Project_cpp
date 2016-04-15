#include "line.h"
using namespace std;

Line::Line(string color, Point p1, Point p2,QGraphicsScene *scene):Object2D(color),scene(scene)
{
    vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    this->vertices.push_back(p1);
    this->vertices.push_back(p2);
    this->mat = *(new Matrix(points));
}

float Line::getArea(){
    return 0;
}

float Line::getPerimeter(){
    Point pi = vertices.at(0);
    Point pj = vertices.at(1);
    return Point::dist(pi,pj);
}

void Line::draw(){
    cout << "\n**LINE**("<<color<< ")\n Matrice : " << endl;
    this->mat.print();
    Point p1 = vertices.at(0);
    Point p2 = vertices.at(1);
    scene->addLine(p1.get_x(), p1.get_y(),p2.get_x(), p2.get_y(),
                      QPen(QColor(color.c_str()), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

ostream & operator<< (ostream & os, const Line & l)
{
    for(Point p : l.vertices) {
        os << p;
    }

    return os;
}

Point Line::getCenter(){
    Point p1 = vertices.at(0);
    Point p2 = vertices.at(1);

    return *(new Point((p1.get_x() + p2.get_x())/2,(p1.get_y() + p2.get_y())/2));
}
