#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
#include "Point.h"

class Triangle : public Shape
{
    private:
        Point _firstPoint, _secondPoint, _thirdPoint;
        double _lengthA, _lengthB, _lengthC;
        double _slopeAB, _slopeBC, _slopeAC;
        bool _triangleJudge = true;

    public:
        Triangle(double firstPointX, double firstPointY,
                 double secondPointX, double secondPointY,
                 double thirdPointX, double thirdPointY);

        void computeLength();
        void computeSlope();
        bool isTriangle();
        string content();
        double perimeter() const;
        double area() const;
        virtual ~Triangle();
};

#endif // TRIANGLE_H
