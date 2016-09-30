#include "Square.h"
#include <sstream>

Square::Square(double ulx, double uly, double length)
    : Shape("Square"), _upperLeftCorner(Point(ulx, uly)), _length(length) {

}

string Square::content() {
    ostringstream oss;
    oss << getName() << "(" << _upperLeftCorner.x() << ", " << _upperLeftCorner.y() << ", " << _length << ")\n";
    return oss.str();
}

double Square::perimeter() const {
    return 4 * _length;
}

double Square::area() const {
    return _length * _length;
}

Square::~Square()
{
    //dtor
}
