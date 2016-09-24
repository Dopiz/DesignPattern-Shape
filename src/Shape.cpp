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

Shape *findLargestArea(vector<Shape *> shapes)
{
    double maxArea = 0;
    Shape* maxAreaShape;

    for (Shape *s: shapes)
        if (s->area() > maxArea) {
            maxArea = s->area();
            maxAreaShape = s;
        }

    return maxAreaShape;
}

void sortShapes(vector<Shape *> shapes)
{
    Shape* tempShape;

    for(Shape *s: shapes)
        for(Shape *ss: shapes)
            if(s->area() > ss->area()) {
                tempShape = s;
                s = ss;
                ss = tempShape;
            }
}
