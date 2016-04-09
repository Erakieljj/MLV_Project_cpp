#include "fresque.h"
using namespace std;

Fresque::Fresque() {
    cout << "Init fresque";
}

// Inherited method from ObjectInterface
void Fresque::draw(){
    for(ObjectInterface o : objects) {
        o.draw();
    }
}

void Fresque::applyTranslation(float x,float y){
    for(ObjectInterface o : objects) {
        o.applyTranslation(x,y);
    }
}
void Fresque::applyRotationDirect(float angle){
    for(ObjectInterface o : objects) {
        o.applyRotationDirect(angle);
    }
}
void Fresque::applyRotationIndirect(float angle){
    for(ObjectInterface o : objects) {
        o.applyRotationIndirect(angle);
    }
}
void Fresque::applyHomethety(float ratio){
    for(ObjectInterface o : objects) {
        o.applyHomethety(ratio);
    }
}
void Fresque::applyAxialSymmetry(){
    for(ObjectInterface o : objects) {
        o.applyAxialSymmetry();
    }
}

void Fresque::applyCentralSymmetry(){
    for(ObjectInterface o : objects) {
        o.applyCentralSymmetry();
    }
}

// Personal method
bool Fresque::add(ObjectInterface o){
    objects.push_back(o);
    return true;
}

bool Fresque::remove(ObjectInterface o){
    cout << "Remove";
    return false;
}
