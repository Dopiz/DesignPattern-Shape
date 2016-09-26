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

    for (Shape *s: shapes) {
        areaSum += s->area();
    }

    return areaSum;
}

double sumOfPerimeter(vector<Shape *> shapes)
{
    double areaPerimeter = 0;

    for (Shape *s: shapes) {
        areaPerimeter += s->perimeter();
    }

    return areaPerimeter;
}

Shape *findLargestArea(vector<Shape *> shapes)
{
    double maxArea = 0;
    Shape* maxAreaShape;

    for (Shape *s: shapes) {
        if (s->area() > maxArea) {
            maxArea = s->area();
            maxAreaShape = s;
        }
    }

    return maxAreaShape;
}

void sortShapes(vector<Shape *> &shapes)
{
    Shape* tempShape;

    for(int i = 0; i < shapes.size(); ++i) {
        for(int j = i + 1; j < shapes.size(); ++j) {
            if(shapes[i]->area() > shapes[j]->area()) {
                tempShape = shapes[i];
                shapes[i] = shapes[j];
                shapes[j] = tempShape;
            }
        }
    }

}
