#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Shape
{
    private:
        string _name;

    public:
        Shape(string name);
        virtual double perimeter() const;
        virtual double area() const;
        virtual ~Shape();
};

double sumOfArea(vector<Shape *> shapes);
double sumOfPerimeter(vector<Shape *> shapes);
Shape *findLargestArea(vector<Shape *> shapes);
void sortShapes(vector<Shape *> &shapes);

#endif // SHAPE_H
