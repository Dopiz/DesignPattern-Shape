#include "Rectangle.h"

Rectangle::Rectangle(double ulx, double uly, double length, double width)
    : Shape("Rectangle"), _upperLeftCorner(Point(ulx, uly)), _length(length), _width(width) {

}

double Rectangle::perimeter() const {
    return ( _length + _width ) * 2;
}

double Rectangle::area() const {
    return _length * _width;
}

Rectangle::~Rectangle()
{
    //dtor
}
