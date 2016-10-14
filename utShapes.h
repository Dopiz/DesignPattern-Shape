#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include <math.h>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#include "Media.h"
#include "SimpleMedia.h"
#include "CompositeMedia.h"

#include "MediaVisitor.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"

const double deviation = 0.000001;

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
//    cout << "Area: " << maxArea(ss)->area() << ",\t" << maxArea(ss)->description() << endl;
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
//        cout << count << ". Area: " << s->area() << ",\t" << s->description();
//    }
//    cout << endl;
    /* Print result */

    CHECK(ss == check);
}

//  Media
TEST (Area, SimpleMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    SimpleMedia m(&c);
    AreaVisitor av;
    m.accept(av);

    DOUBLES_EQUAL(314, av.getArea(), deviation);
}

TEST (Perimeter, SimpleMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    SimpleMedia m(&c);
    PerimeterVisitor pv;
    m.accept(pv);

    DOUBLES_EQUAL(62.8, pv.getPerimeter(), deviation);
}

TEST (MediaArea, CompositeMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    Rectangle r(0, 0, 4, 6);     //  Area: 24    , Perimeter: 20

    CompositeMedia cm;
    cm.add(new SimpleMedia(&c));
    cm.add(new SimpleMedia(&r));

    AreaVisitor av;
    cm.accept(av);

    DOUBLES_EQUAL(338, av.getArea(), deviation);
}

TEST (Perimeter, CompositeMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    Rectangle r(0, 0, 4, 6);     //  Area: 24    , Perimeter: 20

    CompositeMedia cm;
    cm.add(new SimpleMedia(&c));
    cm.add(new SimpleMedia(&r));

    PerimeterVisitor pv;
    cm.accept(pv);

    DOUBLES_EQUAL(82.8, pv.getPerimeter(), deviation);
}

TEST (Hexagon, CompositeMedia)
{
    Rectangle r(0, 2 * sqrt(3), 2, 2 * sqrt(3));     //  Area: 6.928203    , Perimeter: 10.928203
    Triangle t1(0, 2 * sqrt(3), 0, 0, -1, sqrt(3));  //  Area: 1.732050    , Perimeter: 7.464101
    Triangle t2(2, 2 * sqrt(3), 2, 0,  3, sqrt(3));  //  Area: 1.732050    , Perimeter: 7.464101

    CompositeMedia combo;
    combo.add(new SimpleMedia(&r));
    combo.add(new SimpleMedia(&t1));

    CompositeMedia comboMedia;
    comboMedia.add(&combo);
    comboMedia.add(new SimpleMedia(&t2));

//    PerimeterVisitor pv;
//    comboMedia.accept(pv);

    AreaVisitor av;
    comboMedia.accept(av);

//    DOUBLES_EQUAL(25.856406, pv.getPerimeter(), deviation);
    DOUBLES_EQUAL(10.392305, av.getArea(), deviation);
}

TEST (getDescription, SimpleMedia)
{
    Circle c(0, 0, 10);
    SimpleMedia m(&c);
    DescriptionVisitor dv;
    m.accept(dv);

    CHECK(string("Circle(0, 0, 10) ") == dv.getDescription());
}

TEST (getDescription, CompositeMedia)
{
    Circle c(0, 0, 10);
    Rectangle r(0, 0, 4, 6);

    CompositeMedia cm;
    cm.add(new SimpleMedia(&c));
    cm.add(new SimpleMedia(&r));

    DescriptionVisitor dv;
    cm.accept(dv);

    CHECK(string("ComboMedia(Circle(0, 0, 10) Rectangle(0, 0, 4, 6) )") == dv.getDescription());
}

#endif // UTSHAPES_H_INCLUDED
