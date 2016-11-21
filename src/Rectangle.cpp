#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle(double ulx, double uly, double length, double width)
    : Shape("r"), _upperLeftCorner(Point(ulx, uly)), _length(length), _width(width) {

}

string Rectangle::description() {
    ostringstream oss;
    oss << getName() << "(" << _upperLeftCorner.x << ", " << _upperLeftCorner.y << ", " << _length << ", " << _width << ") ";
    return oss.str();
}

double Rectangle::perimeter() const {
    return ( _length + _width ) * 2;
}

double Rectangle::area() const {
    return _length * _width;
}

Rectangle::~Rectangle() {
    //dtor
}
