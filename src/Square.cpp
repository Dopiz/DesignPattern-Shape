#include "Square.h"

Square::Square(double ulx, double uly, double length)
    : Shape("Square"), _upperLeftCorner(Point(ulx, uly)), _length(length) {

}

double Square::area() const {
    return _length * _length;
}

Square::~Square()
{
    //dtor
}
