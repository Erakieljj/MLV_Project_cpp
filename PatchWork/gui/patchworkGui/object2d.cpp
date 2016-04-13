#include "object2d.h"
#include "matrix.h"
#include <cstring>
#include <string.h>
using namespace std;

std::string Object2D::getColor() const{
    return color;
}

void Object2D::setColor(string color) {
    this->color = color;
}

void Object2D::updateVertices()
{
    vector<Point> points = this->mat.getPoints();
    for(int i=0; i<points.size(); i++){
        vertices.at(i) = points.at(i);
    }
}

void Object2D::applyTranslation(double x, double y){
    this->mat = *(Matrix::translation(x,y)) * this->mat;
    updateVertices();
}

void Object2D::applyHomethety(double x, double y){
    this->mat = *(Matrix::homothety(x,y)) * this->mat;
    updateVertices();
}

void Object2D::applyRotationDirect(double angle) {
    this->mat = *(Matrix::rotationDirect(angle)) * this->mat;
    updateVertices();
}

void Object2D::applyRotationIndirect(double angle) {
    this->mat = *(Matrix::rotationIndirect(angle)) * this->mat;
    updateVertices();
}

void Object2D::applyAxialSymmetry(double a, double b){
    this->mat = (Matrix::axialSymmetry(a,b)) * this->mat;
    updateVertices();
}

void Object2D::applyCentralSymmetry(double x,double y){
    this->mat = *(Matrix::centralSymmetry(x,y)) * this->mat;
    updateVertices();
}