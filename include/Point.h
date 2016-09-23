#ifndef POINT_H
#define POINT_H
#include "Shape.h"

class Point : public Shape
{
    private:
        double _x, _y;

    public:
        Point(double x, double y);
        double x();
        double y();
        virtual ~Point();
};

#endif // POINT_H
