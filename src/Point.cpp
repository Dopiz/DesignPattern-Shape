#include "Point.h"
#include <sstream>

Point::Point(double x, double y)
    : Shape("Point"), _x(x), _y(y) {

}

string Point::content() {
    ostringstream oss;
    oss << getName() << "(" << _x << ", " << _y << ")";
    return oss.str();
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
