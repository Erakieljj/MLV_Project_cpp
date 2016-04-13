#include "polygone.h"
using namespace std;

Polygone::Polygone(string color, initializer_list<Point> points):ObjectInterface(color)
{
    if(points.size()<3) {
        throw new invalid_argument("Must have at least 3 Point for a polygone");
    }
    for(Point p : points) {
        this->vertices.push_back(p);
    }
    this->mat = *(new Matrix(this->vertices));
}

float Polygone::getArea() {
    float a = 0;
    if(this->vertices.size()<3){
        return a;
    } else {
      int j=vertices.size()-1;
      for (size_t i=0; i<vertices.size(); i++) {
          Point pi = vertices.at(i);
          Point pj = vertices.at(j);
          a+=(pj.get_x()+pi.get_x())*(pj.get_y()-pi.get_y());
          j=i;
      }
      return a*.5;
    }
}

float Polygone::getPerimeter(){
    float p = 0;
    for(size_t i=0;i<vertices.size()-1; i++){
        p += Point::dist(vertices.at(i+1),vertices.at(i));
    }
    return p;
}

void Polygone::draw(){
    cout << "\n**POLYGONE**("<<color<< ")\n Matrice : " << endl;

    this->mat.print();
}
