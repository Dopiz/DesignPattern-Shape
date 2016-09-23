#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"
#include "Point.h"

class Square : public Shape
{
    private:
        Point _upperLeftCorner;
        double _length;

    public:
        Square(double ulx, double uly, double length);
        double perimeter() const;
        double area() const;
        virtual ~Square();
};

#endif // SQUARE_H
