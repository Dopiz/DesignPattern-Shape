#include "Point.h"

Point::Point(int x, int y)
    : Shape("Point"), _x(x), _y(y) {

}

int Point::x() {
    return this->_x;
}

int Point::y() {
    return this->_y;
}

Point::~Point()
{
    //dtor
}
