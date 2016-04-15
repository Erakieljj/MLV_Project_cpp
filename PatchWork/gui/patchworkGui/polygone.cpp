#include "polygone.h"
using namespace std;

Polygone::Polygone(string color, initializer_list<Point> points,QGraphicsScene *scene):Object2D(color),scene(scene)
{
    if(points.size()<3) {
        throw new invalid_argument("Must have at least 3 Point for a polygone");
    }
    for(Point p : points) {
        this->vertices.push_back(p);
    }
    this->mat = *(new Matrix(this->vertices));
}

Polygone::Polygone(string color, vector<Point> points,QGraphicsScene *scene):Object2D(color),scene(scene)
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

    Point pp = vertices.at(0);
    for(size_t i=1;i<vertices.size();i++){
        Point p = vertices.at(i);
        scene->addLine(pp.get_x(), pp.get_y(),p.get_x(), p.get_y(),
                          QPen(QColor(color.c_str()), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        pp = vertices.at(i);
    }
    Point p = vertices.at(0);
    scene->addLine(pp.get_x(), pp.get_y(),p.get_x(), p.get_y(),
                      QPen(QColor(color.c_str()), 3,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));


}

Point Polygone::getCenter()
{
    double xfinal=0,yfinal = 0;
    double signedArea = 0.0;
    double x0 = 0.0;
    double y0 = 0.0;
    double x1 = 0.0;
    double y1 = 0.0;
    double a = 0.0;

    size_t i = 0;
    for(i=0;i<vertices.size()-1;i++){
        x0 = vertices.at(i).get_x();
        y0 = vertices.at(i).get_y();
        x1 = vertices.at(i+1).get_x();
        y1 = vertices.at(i+1).get_y();
        a = x0*y1 - x1*y0;
        signedArea += a;
        xfinal += (x0 + x1)*a;
        yfinal += (y0 + y1)*a;
    }

    x0 = vertices.at(i).get_x();
    y0 = vertices.at(i).get_y();
    x1 = vertices.at(0).get_x();
    y1 = vertices.at(0).get_y();
    a = x0*y1 - x1*y0;
    signedArea += a;
    xfinal += (x0 + x1)*a;
    yfinal += (y0 + y1)*a;

    signedArea *= 0.5;
    xfinal /= (6.0*signedArea);
    yfinal /= (6.0*signedArea);

    return *(new Point(xfinal,yfinal));
}
