#include "objectinterface.h"
#include "matrix.h"
#include <cstring>
#include <string>

ObjectInterface::ObjectInterface( QObject *parent) : QObject(parent)
{
}

ObjectInterface::ObjectInterface(string color, QObject *parent) : QObject(parent), color(color)
{
}


std::string ObjectInterface::getColor() const{
    return color;
}

void ObjectInterface::setColor(string color) {
    this->color = color;
}

void ObjectInterface::updateVertices()
{
    vector<Point> points = this->mat.getPoints();
    for(unsigned int i=0; i<points.size(); i++){
        vertices.at(i) = points.at(i);
    }
}

void ObjectInterface::applyTranslation(double x, double y){
    this->mat = *(Matrix::translation(x,y)) * this->mat;
    updateVertices();
}

void ObjectInterface::applyHomethety(double x, double y){
    this->mat = *(Matrix::homothety(x,y)) * this->mat;
    updateVertices();
}

void ObjectInterface::applyRotationDirect(double angle) {
    this->mat = *(Matrix::rotationDirect(angle)) * this->mat;
    updateVertices();
}

void ObjectInterface::applyRotationIndirect(double angle) {
    this->mat = *(Matrix::rotationIndirect(angle)) * this->mat;
    updateVertices();
}

void ObjectInterface::applyAxialSymmetry(double a, double b){
    this->mat = (Matrix::axialSymmetry(a,b)) * this->mat;
    updateVertices();
}

void ObjectInterface::applyCentralSymmetry(double x,double y){
    this->mat = *(Matrix::centralSymmetry(x,y)) * this->mat;
    updateVertices();
}
