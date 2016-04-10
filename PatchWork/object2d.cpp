#include "object2d.h"
#include "matrix.h"

std::string Object2D::getColor() const{
    return color;
}

void Object2D::setColor(string color) {
    this->color = color;
}

void Object2D::applyTranslation(double x, double y){
    this->mat = *(Matrix::translation(x,y)) * this->mat;
}

void Object2D::applyHomethety(double x, double y){
    this->mat = *(Matrix::homothety(x,y)) * this->mat;
}

void Object2D::applyRotationDirect(double angle) {
    this->mat = *(Matrix::rotation(angle)) * this->mat;
}

void Object2D::applyRotationIndirect(double angle) {
    this->mat = *(Matrix::rotation(-angle)) * this->mat;
}

void Object2D::applyAxialSymmetry(){
    this->mat = this->mat;
}

void Object2D::applyCentralSymmetry(){
    this->mat = this->mat;
}
