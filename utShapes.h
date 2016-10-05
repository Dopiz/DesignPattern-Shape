#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED
#include <vector>
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "CompositeShape.h"

const double deviation = 0.00001;

// Circle Test.
TEST (circlePerimeter, Circle)
{
    Circle c(0, 0, 10);
    DOUBLES_EQUAL(62.8, c.perimeter(), deviation);
}

TEST (circleArea, Circle)
{
    Circle c(0, 0, 10);
    DOUBLES_EQUAL(314, c.area(), deviation);
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
TEST (isTriangle, Triangle)
{
    Triangle t(0, 0, 1, 1, 8, 8);   // This is not a triangle !

    try {
        t.isTriangle();
    } catch(string s) {
        CHECK(string("This is not a triangle !") == s);
    }
}

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

// find the shapes in a vector which has the largest area.
TEST (findLargestArea, Shape)
{
    Circle c(0, 0, 3);              //  Area: 28.26
    Rectangle r(0, 0, 4, 2.5);      //  Area: 10
    Triangle t(1, 0, 4, 0, 1, 4);   //  Area: 6

    std::vector<Shape *> ss;
    ss.push_back(&c);
    ss.push_back(&r);
    ss.push_back(&t);

//    cout << "Find the shapes in a vector which has the largest area:\n";
//    cout << "Area: " << maxArea(ss)->area() << ",\t" << maxArea(ss)->content() << endl;

//    CHECK(&c == maxArea(ss));
    DOUBLES_EQUAL(28.26, maxArea(ss)->area(), deviation);
}

// sorts the list of shapes by decreasing order in perimeter, i.e., smallest area first.
TEST (sortShapes, Shape)
{
    Circle c(0, 0, 3);              //  Area: 28.26 , Perimeter: 18.84
    Rectangle r(0, 0, 4, 2.5);      //  Area: 10    , Perimeter: 13
    Rectangle r2(0, 0, 4, 1);       //  Area: 4     , Perimeter: 10
    Triangle t(1, 0, 4, 0, 1, 4);   //  Area: 6     , Perimeter: 12

    std::vector<Shape *> ss;
    ss.push_back(&c);
    ss.push_back(&r);
    ss.push_back(&r2);
    ss.push_back(&t);

    sortByDecreasingPerimeter(ss);

//    int count = 0;
//    cout << "Sorts the list of shapes by decreasing order in perimeter\n";
//    for(Shape *s: ss) {
//        ++count;
//        cout << count << ". Area: " << s->area() << ",\t" << s->content();
//    }
//    cout << endl;

//    CHECK(&c == ss[1]);
    DOUBLES_EQUAL(18.84, ss[0]->perimeter(), deviation);
}

TEST (ComboArea, CompositeShape)
{
    Circle c(0, 0, 10);            //  Area: 28.26 , Perimeter: 18.84
    Rectangle r(0, 0, 10, 4);      //  Area: 10    , Perimeter: 13

    CompositeShape combo;
    combo.addShape(&c, "cSmall");
    combo.addShape(&r, "rTall");

//    cout << combo.content() << endl;

    DOUBLES_EQUAL(354, combo.area(), deviation);
}

TEST (ComboPerimeter, CompositeShape)
{
    Circle c(0, 0, 10);            //  Area: 28.26 , Perimeter: 18.84
    Rectangle r(0, 0, 4, 10);      //  Area: 10    , Perimeter: 13

    CompositeShape combo;
    combo.addShape(&c, "cSmall");
    combo.addShape(&r, "rTall");

//    cout << combo.content() << endl;

    DOUBLES_EQUAL(90.8, combo.perimeter(), deviation);
}

#endif // UTSHAPES_H_INCLUDED
