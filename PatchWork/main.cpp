#include <iostream>
#include "point.h"
#include "line.h"
#include "fresque.h"
#include "objectinterface.h"
#include "matrix.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    Point p(1,2);
    Point p2(5,2);
    cout << p<<endl;

    Line *l = new Line("red",p,p2);
    l->draw();

    Fresque *f = new Fresque();

    f->add(*l);
    cout << " AFFICHAGE DE LA FRESQUE"<<endl;
    f->draw();
    f->applyHomethety(5,6);
    cout << " AFFICHAGE DE LA FRESQUE apres homothety 5,6"<<endl;
    f->draw();
    cout <<endl;

    Matrix *m1 = new Matrix(3,7);
    Matrix *m2 = Matrix::idMatrix(3);
    Matrix *m3 = Matrix::homothety(2,4);
    Matrix *m4 = Matrix::rotation(90);
    Matrix *m5 = Matrix::translation(10,4);
    m1->print();
    m2->print();
    m3->print();
    m4->print();
    m5->print();

    // Representation matricielle du vecteur de Point
    Matrix *m6 = new Matrix(l->getPoints());

    // Matrix de homothetie * Matrix reprensenté par notre Line
    m3->print();
    m6->print();

    try{
        Matrix mm = *m3 * (*m6) ;
        mm.print();
    } catch(domain_error* e){
        cout <<e->what() <<endl;
    }

    return 0;
}
