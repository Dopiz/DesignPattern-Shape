#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED
#include <vector>
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"

const double deviation = 0.00001;

// Circle Test.
TEST (circlePerimeter, Circle)
{
    Circle c(0, 0, 3);
    DOUBLES_EQUAL(18.84, c.perimeter(), deviation);
}

TEST (circleArea, Circle)
{
    Circle c(0, 0, 3);
    DOUBLES_EQUAL(28.26, c.area(), deviation);
}

// Rectangle Test.
TEST (rectanglePerimeter, Rectangle)
{
    Rectangle r(0, 0, 4, 2.5);
    DOUBLES_EQUAL(13, r.perimeter(), deviation);
}

TEST (rectangleArea, Rectangle)
{
    Rectangle r(0, 0, 4, 2.5);
    DOUBLES_EQUAL(10.00, r.area(), deviation);
}

// Triangle Test.
TEST (trianglePerimeter, Triangle)
{
    Triangle t(1, 0, 4, 0, 1, 4);
    DOUBLES_EQUAL(12, t.perimeter(), deviation);
}

TEST (triangleArea, Triangle)
{
    Triangle t(1, 0, 4, 0, 1, 4);
    DOUBLES_EQUAL(6, t.area(), deviation);
}

// Others.
TEST (sumOfArea, Shape)
{
    Circle c(0, 0, 3);              //  Area: 28.26
    Rectangle r(0, 0, 4, 2.5);      //  Area: 10
    Triangle t(1, 0, 4, 0, 1, 4);   //  Area: 6

    std::vector<Shape *> ss;
    ss.push_back(&c);
    ss.push_back(&r);
    ss.push_back(&t);
    DOUBLES_EQUAL(44.26, sumOfArea(ss), deviation);
}

TEST (sumOfPerimeter, Shape)
{
    Circle c(0, 0, 3);              //  Perimeter: 18.84
    Rectangle r(0, 0, 4, 2.5);      //  Perimeter: 13
    Triangle t(1, 0, 4, 0, 1, 4);   //  Perimeter: 12

    std::vector<Shape *> ss;
    ss.push_back(&c);
    ss.push_back(&r);
    ss.push_back(&t);
    DOUBLES_EQUAL(43.84, sumOfPerimeter(ss), deviation);
}

TEST (findLargestArea, Shape)
{
    Circle c(0, 0, 3);              //  Area: 28.26
    Rectangle r(0, 0, 4, 2.5);      //  Area: 10
    Triangle t(1, 0, 4, 0, 1, 4);   //  Area: 6

    std::vector<Shape *> ss;
    ss.push_back(&c);
    ss.push_back(&r);
    ss.push_back(&t);

    DOUBLES_EQUAL(28.26, findLargestArea(ss)->area(), deviation);
}

TEST (sortShapes, Shape)
{
    Circle c(0, 0, 3);              //  Area: 28.26
    Rectangle r(0, 0, 4, 2.5);      //  Area: 10
    Triangle t(1, 0, 4, 0, 1, 4);   //  Area: 6
    Rectangle r2(0, 0, 4, 1);       //  Area: 4

    std::vector<Shape *> ss;
    ss.push_back(&r);
    ss.push_back(&c);
    ss.push_back(&t);
    ss.push_back(&r2);

    sortShapes(ss);

    DOUBLES_EQUAL(4, ss[0]->area(), deviation);
}
#endif // UTSHAPES_H_INCLUDED
