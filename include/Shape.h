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
        string getName() const;
        void setName(string name);
        virtual string description() = 0;
        virtual double perimeter() const = 0;
        virtual double area() const = 0;
        virtual ~Shape();
};

double sumOfArea(const vector<Shape *> &shapes);
double sumOfPerimeter(const vector<Shape *> &shapes);
Shape *maxArea(const vector<Shape *> &shapes);
void sortByDecreasingPerimeter(vector<Shape *> &shapes);

#endif // SHAPE_H
