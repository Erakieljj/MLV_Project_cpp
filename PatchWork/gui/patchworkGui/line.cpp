#include "line.h"
using namespace std;

Line::Line(string color, Point p1, Point p2):Object2D(color)
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
}

ostream & operator<< (ostream & os, const Line & l)
{
    for(Point p : l.vertices) {
        os << p;
    }

    return os;
}
