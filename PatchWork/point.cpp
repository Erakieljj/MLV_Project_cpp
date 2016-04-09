#include "point.h"

Point::Point(int x, int y): x(x), y(y)
{

}

int Point::getX() const
{
    return x;
}

void Point::setX(int x)
{
    this->x = x;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int y)
{
    this->y = y;
}

ostream & operator<< (ostream & os, const Point & p)
{
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}
