#include "Point.h"

Point::Point(double x, double y)
    : Shape("Point"), _x(x), _y(y) {

}

double Point::x() {
    return this->_x;
}

double Point::y() {
    return this->_y;
}

Point::~Point()
{
    //dtor
}
