#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

class Point :
{
    public:
        Point(int x,int y);
        ~Point();
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);

        friend ostream& operator<< (ostream &os, const Point &p);

    private :
        int x,y;

};

#endif // POINT_H
