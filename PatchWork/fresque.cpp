#include "fresque.h"
using namespace std;

// Inherited method from ObjectInterface
void draw(){
    for(ObjectInterface o : objects) {
        o.draw();
    }
}

void applyTranslation(float x,float y){
    for(ObjectInterface o : objects) {
        o.applyTranslation(x,y);
    }
}
void applyRotationDirect(float angle){
    for(ObjectInterface o : objects) {
        o.applyRotationDirect(angle);
    }
}
void applyRotationIndirect(float angle){
    for(ObjectInterface o : objects) {
        o.applyRotationIndirect(angle);
    }
}
void applyHomethety(float ratio){
    for(ObjectInterface o : objects) {
        o.applyHomethety(ratio);
    }
}
void applyAxialSymmetry(){
    for(ObjectInterface o : objects) {
        o.applyAxialSymmetry();
    }
}

void applyCentralSymmetry(){
    for(ObjectInterface o : objects) {
        o.applyCentralSymmetry();
    }
}

// Personal method
bool add(ObjectInterface o){
    objects.push_back(o);
}

bool remove(ObjectInterface o){
    std:cout << "Remove";
}
