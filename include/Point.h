#ifndef POINT_H
#define POINT_H
#include "Shape.h"

class Point : public Shape
{
    private:
        double _x, _y;

    public:
        Point(int x, int y);
        int x();
        int y();
        virtual ~Point();
};

#endif // POINT_H
