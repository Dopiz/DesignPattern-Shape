#include "Triangle.h"
#include <math.h>
#include <iostream>

Triangle::Triangle( double firstPointX, double firstPointY, double secondPointX, double secondPointY, double thirdPointX, double thirdPointY)
    : Shape("Triangle"), _firstPoint(Point(firstPointX, firstPointY)), _secondPoint(Point(secondPointX, secondPointY)), _thirdPoint(Point(thirdPointX, thirdPointY))  {

    computeLength();
}

void Triangle::computeLength() {
    _lengthA = sqrt( pow(_firstPoint.x() - _secondPoint.x(), 2) + pow(_firstPoint.y() - _secondPoint.y(), 2) );
    _lengthB = sqrt( pow(_firstPoint.x() - _thirdPoint.x() , 2) + pow(_firstPoint.y() - _thirdPoint.y() , 2) );
    _lengthC = sqrt( pow(_thirdPoint.x() - _secondPoint.x(), 2) + pow(_thirdPoint.y() - _secondPoint.y(), 2) );
}

double Triangle::perimeter() const {
    return _lengthA + _lengthB + _lengthC;
}

double Triangle::area() const {
    double s = this->perimeter() / 2;
    return sqrt( s * (s - _lengthA) * (s - _lengthB) * (s - _lengthC)  );
}

Triangle::~Triangle()
{
    //dtor
}

