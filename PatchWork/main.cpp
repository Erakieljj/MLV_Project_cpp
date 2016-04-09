#include <iostream>
#include "point.h"
#include "line.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    Point p(1,2);
    Point p2(5,2);
    cout << p;

    Line *l = new Line("red",p,p2);
    cout <<l;
    return 0;
}
