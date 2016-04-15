#include "circle.h"

using namespace std;

double Circle::getRayon() const
{
    return rayon;
}

Circle::Circle(string color,Point p,double rayon):rayon(rayon),ObjectInterface(color)
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
}
