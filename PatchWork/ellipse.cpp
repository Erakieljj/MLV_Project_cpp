#include "ellipse.h"

using namespace std;

Ellipse::Ellipse(string color,Point p,double rlon,double rlar):rlon(rlon),rlar(rlar),ObjectInterface(color)
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
}
