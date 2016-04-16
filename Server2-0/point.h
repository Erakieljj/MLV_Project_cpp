#ifndef __POINT_H__
#define __POINT_H__
#include <ostream>
using namespace std;

class Point
{
    private:
        double x;
        double y;
        bool is_zero(double a) {return a==0;}

    public:
        //
        Point(double x, double y);

        static float dist(Point p1,Point p2);
        //getters
        inline double get_x(){return this -> x;}
        inline double get_y(){return this -> y;}

        //

        //return the point of coordinates (-x, -y)
        Point operator-();

        Point& operator=(Point& A);

        Point& operator+= (Point& A);

        Point& operator-= (Point& A);
        //return true if A == this, false otherwise
        bool operator== (Point A);
        //return true if A != this, false otherwise
        bool operator!= (Point& A);
        //return the coordinates equal to this + A
        Point operator+ (Point& A);
        //return the coordinates equal to this - A
        Point operator- (Point& A);
        friend ostream& operator<< (ostream &os, const Point &p);
};

#endif
