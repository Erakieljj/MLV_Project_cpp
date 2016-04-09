#include <iostream>
#include "point.h"
#include "line.h"
#include "fresque.h"
#include "objectinterface.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    Point p(1,2);
    Point p2(5,2);
    cout << p<<endl;

    ObjectInterface*l = new Line("red",p,p2);
    l->draw();
    //cout <<*l <<endl;

    Fresque *f = new Fresque();

    f->add(*l);
    f->draw();
    return 0;
}
