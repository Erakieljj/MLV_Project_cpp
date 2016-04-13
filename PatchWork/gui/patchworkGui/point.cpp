#include <point.h>
#include <math.h>
using namespace std;

//create a point of coordinates (x,y)
Point::Point(double x, double y)
{
    this -> x = x;
    this -> y = y;
}

float Point::dist(Point p1,Point p2) {
    return sqrt(pow(p2.get_x() - p1.get_x(),2) +pow(p2.get_y()-p1.get_y(),2));
}

//return the coordinates -this
Point Point::operator-()
{
    return Point(-(this -> x), -(this -> y));
}

Point& Point::operator=(Point& A)
{
    this -> x = A.get_x();
    this -> y = A.get_y();
    return (*this);
}

Point& Point::operator+= (Point& A)
{
    this -> x += A.get_x();
    this -> y += A.get_y();
    return (*this);
}

Point& Point::operator-= (Point& A)
{
    this -> x -= A.get_x();
    this -> y -= A.get_y();
    return (*this);
}

//return true if A == this, false otherwise
bool Point::operator== (Point A)
{
    return (is_zero(this -> x - A.get_x())) && (is_zero(this -> y - A.get_y()));
}

//return true if A != this, false otherwise
bool Point::operator!= (Point& A)
{
    return (!is_zero(this -> x - A.get_x())) || (!is_zero(this -> y - A.get_y()));
}

//return the coordinates equal to this + A
Point Point::operator+ (Point& A)
{
    return Point(this -> x + A.get_x(), this -> y + A.get_y());
}

//return the coordinates equal to this - A
Point Point::operator- (Point& A)
{
   return Point(this -> x - A.get_x(), this -> y - A.get_y()); 
}

ostream & operator<< (ostream & os, const Point & p)
{
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}
