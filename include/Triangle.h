#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
#include "Point.h"

class Triangle : public Shape
{
    private:
        Point _firstPoint, _secondPoint, _thirdPoint;
        double _lengthA, _lengthB, _lengthC;

    public:
        Triangle(double firstPointX, double firstPointY,
                 double secondPointX, double secondPointY,
                 double thirdPointX, double thirdPointY);

        void computeLength();
        double computeSlope(Point &pointA, Point &pointB);
        bool isTriangle();
        string content();
        double perimeter() const;
        double area() const;
        ~Triangle();
};

#endif // TRIANGLE_H
