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
    cout <<"get area";
    return 0;
}

float Line::getPerimeter(){
    cout <<"get permimeter";
    return 0;
}

void Line::draw(){
    this->mat.print();
}

ostream & operator<< (ostream & os, const Line & l)
{
    for(Point p : l.vertices) {
        os << p;
    }

    return os;
}
