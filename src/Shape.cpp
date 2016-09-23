#include "Shape.h"

Shape::Shape(string name)
    : _name(name) {

}
double Shape::perimeter() const {
    return 0;
}

double Shape::area() const {
    return 0;
}

Shape::~Shape()
{
    //dtor
}

double sumOfArea(vector<Shape *> shapes)
{
    double areaSum = 0;
    for (Shape *s: shapes)
        areaSum += s->area();
    return areaSum;
}

double sumOfPerimeter(vector<Shape *> shapes)
{
    double areaPerimeter = 0;
    for (Shape *s: shapes)
        areaPerimeter += s->perimeter();
    return areaPerimeter;
}
