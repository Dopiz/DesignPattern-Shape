#include "Circle.h"
const double PI = 3.14;

Circle::Circle(double cx, double cy, double radius)
    : Shape("Circle"), _center(Point(cx, cy)), _radius(radius) {

}

double Circle::perimeter() const {
    return 2 * PI * _radius;
}

double Circle::area() const {
    return PI * _radius * _radius;
}

Circle::~Circle()
{
    //dtor
}
