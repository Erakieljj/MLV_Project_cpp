#include "line.h"
using namespace std;

Line::Line(string color, Point p1, Point p2):Object2D(color)
{
    vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    this->vertices.push_back(p1);
    this->vertices.push_back(p2);
}

void Line::applyAxialSymmetry(){
    cout << "symetrie";
}

void Line::applyCentralSymmetry(){
    cout << "symetrie";
}

void Line::applyHomethety(float ratio){
    cout <<"homo";
}

void Line::applyRotationDirect(float angle){
    cout << "roation direct";
}

void Line::applyRotationIndirect(float angle){
    cout << "rotation indirect";
}

void Line::applyTranslation(float x, float y){
    cout << "Translation";
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
    cout << "LINE";
}

ostream & operator<< (ostream & os, const Line & l)
{
    for(Point p : l.vertices) {
        os << p;
    }

    return os;
}
