#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
    private:
        Point _center;
        double _radius;

    public:
        Circle(double cx, double cy, double radius);
        string content();
        double perimeter() const;
        double area() const;
        ~Circle();
};

#endif // CIRCLE_H
