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
        /**
         * @brief dist distance entre deux Point
         * @param p1 Point 1
         * @param p2 Point 2
         * @return return la distance en float
         */
        static float dist(Point p1,Point p2);
        //getters
        /**
         * @brief get_x
         * @return
         */
        inline double get_x(){return this -> x;}
        /**
         * @brief get_y
         * @return
         */
        inline double get_y(){return this -> y;}

        //

        //return the point of coordinates (-x, -y)
        /**
         * @brief operator -
         * @return
         */
        Point operator-();

        /**
         * @brief operator =
         * @param A
         * @return
         */
        Point& operator=(Point& A);
        /**
         * @brief operator +=
         * @param A
         * @return
         */
        Point& operator+= (Point& A);
        /**
         * @brief operator -=
         * @param A
         * @return
         */
        Point& operator-= (Point& A);
        /**
         * @brief operator ==
         * @param A
         * @return return true if A == this, false otherwise
         */
        bool operator== (Point A);
        /**
         * @brief operator !=
         * @param A
         * @return return true if A != this, false otherwise
         */
        bool operator!= (Point& A);
        /**
         * @brief operator +
         * @param A
         * @return return the coordinates equal to this + A
         */
        Point operator+ (Point& A);

        /**
         * @brief operator -
         * @param A
         * @return return the coordinates equal to this - A
         */
        Point operator- (Point& A);
        /**
         * @brief operator <<
         * @param os
         * @param p
         * @return
         */
        friend ostream& operator<< (ostream &os, const Point &p);
};

#endif
