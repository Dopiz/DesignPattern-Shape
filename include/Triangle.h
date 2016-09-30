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

        string content();
        void computeLength();
        double perimeter() const;
        double area() const;
        virtual ~Triangle();
};

#endif // TRIANGLE_H
