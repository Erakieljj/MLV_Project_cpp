#include "fresque.h"
using namespace std;

Fresque::Fresque(QGraphicsScene *scene):scene(scene) {
    cout << "Init fresque"<<endl;
}

// Inherited method from ObjectInterface
void Fresque::draw(){
    for(ObjectInterface* o : objects) {
        o->draw();
    }
}

void Fresque::applyTranslation(double x,double y){
    for(ObjectInterface* o : objects) {
        o->applyTranslation(x,y);
    }
}
void Fresque::applyRotationDirect(double angle){
    for(ObjectInterface* o : objects) {
        o->applyRotationDirect(angle);
    }
}

void Fresque::applyRotationCentral(double angle,double x,double y){
    for(ObjectInterface* o : objects) {
        o->applyRotationCentral(angle,x,y);
    }
}

void Fresque::applyRotationIndirect(double angle){
    for(ObjectInterface* o : objects) {
        o->applyRotationIndirect(angle);
    }
}
void Fresque::applyHomethety(double x,double y){
    for(ObjectInterface* o : objects) {
        o->applyHomethety(x,y);
    }
}
void Fresque::applyAxialSymmetry(double a,double b){
    for(ObjectInterface* o : objects) {
        o->applyAxialSymmetry(a,b);
    }
}

void Fresque::applyCentralSymmetry(double x,double y){
    for(ObjectInterface* o : objects) {
        o->applyCentralSymmetry(x,y);
    }
}

// Personal method
bool Fresque::add(ObjectInterface & o){
    objects.push_back(&o);
    return true;
}

bool Fresque::remove(ObjectInterface &o){
    cout << "Remove";
    return false;
}

float Fresque::getArea(){
    float area = 0;
    for(ObjectInterface* o : objects){
        area+=o->getArea();
    }
    return area;
}

float Fresque::getPerimeter(){
    float perimeter = 0;
    for(ObjectInterface* o : objects){
        perimeter+=o->getPerimeter();
    }
    return perimeter;
}
