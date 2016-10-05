#include "Shape.h"
#include <algorithm>

Shape::Shape(string name)
    : _name(name) {

}

string Shape::getName() const {
    return this->_name;
}

void Shape::setName(string name) {
    this->_name = name;
}

double Shape::perimeter() const {
    return 0;
}

double Shape::area() const {
    return 0;
}

Shape::~Shape() {
    //dtor
}

double sumOfArea(const vector<Shape *> &shapes)
{
    double areaSum = 0;

    for (Shape *s: shapes) {
        areaSum += s->area();
    }

    return areaSum;
}

double sumOfPerimeter(const vector<Shape *> &shapes)
{
    double areaPerimeter = 0;

    for (Shape *s: shapes) {
        areaPerimeter += s->perimeter();
    }

    return areaPerimeter;
}

Shape *maxArea(const vector<Shape *> &shapes)
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

void sortByDecreasingPerimeter(vector<Shape *> &shapes)
{
    sort(shapes.begin(), shapes.end(),
         [](Shape* a, Shape* b) { return a->perimeter() > b->perimeter(); });

}
