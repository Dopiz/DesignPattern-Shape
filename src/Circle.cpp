#include "Circle.h"
#include <sstream>

const double PI = 3.14;

Circle::Circle(double cx, double cy, double radius)
    : Shape("c"), _center(Point(cx, cy)), _radius(radius) {

}

string Circle::description() {
    ostringstream oss;
    oss << "c(" << _center.x << ", " << _center.y << ", " << _radius << ") ";
    return oss.str();
}

double Circle::perimeter() const {
    return 2 * PI * _radius;
}

double Circle::area() const {
    return PI * _radius * _radius;
}

Circle::~Circle() {
    //dtor
}
