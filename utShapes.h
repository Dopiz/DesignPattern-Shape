#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#include "SimpleMedia.h"
#include "CompositeMedia.h"

const double deviation = 0.00001;

//  Composite Pattern.

TEST (sumOfArea, Shape)
{
    Circle c(0, 0, 10);             //  Area: 314
    Rectangle r(0, 0, 4, 6);        //  Area: 24
    Triangle t(0, 0, 4, 0, 0, 3);   //  Area: 6

    vector<Shape *> ss = {&r, &t, &c};

    DOUBLES_EQUAL(344, sumOfArea(ss), deviation);
}

TEST (sumOfPerimeter, Shape)
{
    Circle c(0, 0, 10);             //  Perimeter: 62.8
    Rectangle r(0, 0, 4, 6);        //  Perimeter: 20
    Triangle t(0, 0, 4, 0, 0, 3);   //  Perimeter: 12

    vector<Shape *> ss = {&r, &t, &c};

    DOUBLES_EQUAL(94.8, sumOfPerimeter(ss), deviation);
}

// find the shapes in a vector which has the largest area.
TEST (findLargestArea, Shape)
{
    Circle c(0, 0, 10);             //  Area: 314
    Rectangle r(0, 0, 4, 6);        //  Area: 24
    Triangle t(0, 0, 4, 0, 0, 3);   //  Area: 6

    vector<Shape *> ss = {&r, &t, &c};

    CHECK(&c == maxArea(ss));
}

// sorts the list of shapes by decreasing order in perimeter, i.e., smallest area first.
TEST (sortShapes, Shape)
{
    Rectangle r(0, 0, 4, 6);        //  Area: 24    , Perimeter: 20
    Rectangle r2(0, 0, 2, 10);      //  Area: 20    , Perimeter: 24
    Triangle t(0, 0, 4, 0, 0, 3);   //  Area: 6     , Perimeter: 12
    Circle c(0, 0, 10);             //  Area: 314   , Perimeter: 62.8

    vector<Shape *> ss = {&r, &r2, &t, &c};
    vector<Shape *> check = {&c, &r2, &r, &t};  // Sort already.

    sortByDecreasingPerimeter(ss);

    CHECK(ss == check);
}

// Circle.
TEST (Perimeter, Circle)
{
    Circle c(0, 0, 10);
    DOUBLES_EQUAL(62.8, c.perimeter(), deviation);
}

TEST (Area, Circle)
{
    Circle c(0, 0, 10);
    DOUBLES_EQUAL(314, c.area(), deviation);
}

// Rectangle.
TEST (Perimeter, Rectangle)
{
    Rectangle r(0, 0, 4, 6);
    DOUBLES_EQUAL(20, r.perimeter(), deviation);
}

TEST (Area, Rectangle)
{
    Rectangle r(0, 0, 4, 6);
    DOUBLES_EQUAL(24, r.area(), deviation);
}

// Triangle.
TEST (isTriangle, Triangle)
{
    Triangle t(0, 0, 1, 1, 8, 8);   // This is not a triangle !

    try {
        t.isTriangle();
    } catch(string s) {
        CHECK(string("This is not a triangle !") == s);
    }
}

TEST (Perimeter, Triangle)
{
    Triangle t(0, 0, 4, 0, 0, 3);
    DOUBLES_EQUAL(12, t.perimeter(), deviation);
}

TEST (Area, Triangle)
{
    Triangle t(0, 0, 4, 0, 0, 3);
    DOUBLES_EQUAL(6, t.area(), deviation);
}

#endif // UTSHAPES_H_INCLUDED
