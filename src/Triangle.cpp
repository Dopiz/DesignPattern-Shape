#include "Triangle.h"
#include <math.h>
#include <sstream>

Triangle::Triangle( double firstPointX, double firstPointY, double secondPointX, double secondPointY, double thirdPointX, double thirdPointY)
    : Shape("Triangle"), _firstPoint(Point(firstPointX, firstPointY)), _secondPoint(Point(secondPointX, secondPointY)), _thirdPoint(Point(thirdPointX, thirdPointY))  {

    computeLength();
}

void Triangle::computeLength() {
    _lengthA = sqrt( pow(_firstPoint.x - _secondPoint.x, 2) + pow(_firstPoint.y - _secondPoint.y, 2) );
    _lengthB = sqrt( pow(_firstPoint.x - _thirdPoint.x , 2) + pow(_firstPoint.y - _thirdPoint.y , 2) );
    _lengthC = sqrt( pow(_thirdPoint.x - _secondPoint.x, 2) + pow(_thirdPoint.y - _secondPoint.y, 2) );
}

double Triangle::computeSlope(Point &pointA, Point &pointB) {
    return (pointA.y - pointB.y) / (pointA.x - pointB.x);
}

bool Triangle::isTriangle() {
    int slopeAB, slopeAC, slopeBC;
    bool triangleJudge = true;

    slopeAB = computeSlope(_firstPoint, _secondPoint);
    slopeBC = computeSlope(_secondPoint, _thirdPoint);
    slopeAC = computeSlope(_firstPoint, _thirdPoint);

    if( !((_lengthA + _lengthB > _lengthC) && (_lengthA + _lengthC > _lengthB) && (_lengthC + _lengthB > _lengthA)) )
        triangleJudge = false;
    //  is Collinear ?
    else if((slopeAB == slopeAC) && (slopeAC == slopeBC))
        triangleJudge = false;

    if(triangleJudge)
        return true;
    else {
        this->~Triangle();
        throw string("This is not a triangle !");
    }
}

string Triangle::description() {
    ostringstream oss;

    oss << getName() << "("
        << _firstPoint.x  << ", " << _firstPoint.y  << ", "
        << _secondPoint.x << ", " << _secondPoint.y << ", "
        << _thirdPoint.x  << ", " << _thirdPoint.y  << ") ";

    return oss.str();
}

double Triangle::perimeter() const {
    return _lengthA + _lengthB + _lengthC;
}

double Triangle::area() const {
    double s = perimeter() / 2;
    return sqrt( s * (s - _lengthA) * (s - _lengthB) * (s - _lengthC)  );
}

Triangle::~Triangle() {
    //dtor
}

