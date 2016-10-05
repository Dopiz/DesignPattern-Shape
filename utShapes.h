#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include "Circle.h"
#include "Rectangle.h"
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
    Rectangle r(0, 0, 4, 6);
    DOUBLES_EQUAL(20, r.perimeter(), deviation);
}

TEST (rectangleArea, Rectangle)
{
    Rectangle r(0, 0, 4, 6);
    DOUBLES_EQUAL(24, r.area(), deviation);
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
    Triangle t(0, 0, 4, 0, 0, 3);
    DOUBLES_EQUAL(12, t.perimeter(), deviation);
}

TEST (triangleArea, Triangle)
{
    Triangle t(0, 0, 4, 0, 0, 3);
    DOUBLES_EQUAL(6, t.area(), deviation);
}

// Others.
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

    /* Print result */
//    cout << "Find the shapes in a vector which has the largest area:\n";
//    cout << "Area: " << maxArea(ss)->area() << ",\t" << maxArea(ss)->content() << endl;
    /* Print result */

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

    /* Print result */
//    int count = 0;
//    cout << "Sorts the list of shapes by decreasing order in perimeter\n";
//    for(Shape *s: ss) {
//        ++count;
//        cout << count << ". Area: " << s->area() << ",\t" << s->content();
//    }
//    cout << endl;
    /* Print result */

    CHECK(ss == check);
}

TEST (ComboArea, CompositeShape)
{
    Circle c(0, 0, 10);            //  Area: 314   , Perimeter: 62.8
    Rectangle r(0, 0, 4, 6);       //  Area: 24    , Perimeter: 20

    CompositeShape combo("Combo");
    combo.addShape(&c, "cSmall");
    combo.addShape(&r, "rTall");

    /* Print result */
//    cout << combo.content() << endl;
    /* Print result */

    DOUBLES_EQUAL(338, combo.area(), deviation);
}

TEST (ComboPerimeter, CompositeShape)
{
    Circle c(0, 0, 10);            //  Area: 314   , Perimeter: 62.8
    Rectangle r(0, 0, 4, 6);       //  Area: 24    , Perimeter: 20

    CompositeShape combo("Combo");
    combo.addShape(&c, "cSmall");
    combo.addShape(&r, "rTall");

    /* Print result */
//    cout << combo.content() << endl;
    /* Print result */

    DOUBLES_EQUAL(82.8, combo.perimeter(), deviation);
}

TEST (ComboTwoCompositeShape, CompositeShape)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    Rectangle r(0, 0, 4, 6);     //  Area: 24     , Perimeter: 20
    Circle c2(15, 0, 5);         //  Area: 78.5   , Perimeter: 31.4
    Rectangle r2(2, 8, 2, 8);    //  Area: 16     , Perimeter: 20

    CompositeShape combo("Combo1");
    combo.addShape(&c, "Circle");
    combo.addShape(&r, "Rectangle");

    CompositeShape combo2("Combo2");
    combo2.addShape(&c2, "Circ");
    combo2.addShape(&r2, "Rect");

    combo2.addShape(&combo, "Combo1");

    /* Print result */
//    cout << combo2.content() << endl;
    /* Print result */

    DOUBLES_EQUAL(134.2, combo2.perimeter(), deviation);
}

#endif // UTSHAPES_H_INCLUDED
