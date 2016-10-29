#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include <stack>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#include "SimpleMedia.h"
#include "CompositeMedia.h"
#include "TextMedia.h"

#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"

#include "SimpleMediaBuilder.h"
#include "CompositeMediaBuilder.h"

const double deviation = 0.00001;

/*HW4*/
//  Builder Pattern.
TEST (buildCircle, SimpleMedia)
{
    Circle c(0, 0, 5);

    SimpleMediaBuilder mb;
    mb.buildSimpleMedia(&c);

    Media *m = mb.getMedia();
    DescriptionVisitor dv;
    m->accept(dv);
    CHECK(string("Circle(0, 0, 5) ") == dv.getDescription());
}

TEST (buildHouse, CompositeMedia)
{
    stack<MediaBuilder *> mbs;

    Circle c(12, 5, 2);
    Rectangle r1(10, 0, 15, 5);
    Rectangle r2(0, 0, 25, 20);
    Triangle t(0, 20, 16, 32, 25, 20);

    mbs.push(new CompositeMediaBuilder);
    mbs.top()->buildSimpleMedia(&t);
    mbs.push(new CompositeMediaBuilder);
    mbs.top()->buildSimpleMedia(&r2);
    mbs.push(new CompositeMediaBuilder);
    mbs.top()->buildSimpleMedia(&r1);
    mbs.top()->buildSimpleMedia(&c);
    Media *cm = mbs.top()->getMedia();
    mbs.pop();
    mbs.top()->buildCompositeMedia(cm);
    cm = mbs.top()->getMedia();
    mbs.pop();
    mbs.top()->buildCompositeMedia(cm);

    DescriptionVisitor dv;
    mbs.top()->getMedia()->accept(dv);
    CHECK(string("Combo( Triangle(0, 20, 16, 32, 25, 20) Combo( Rectangle(0, 0, 25, 20) Combo( Rectangle(10, 0, 15, 5) Circle(12, 5, 2) ) ) ) ") == dv.getDescription());
}

TEST (buildHouse1, CompositeMedia)
{
    stack<MediaBuilder *> mbs;

    Circle c(12, 5, 2);
    Rectangle r1(10, 0, 15, 5);
    Rectangle r2(0, 0, 25, 20);
    Triangle t(0, 20, 16, 32, 25, 20);

    mbs.push(new CompositeMediaBuilder);
    mbs.push(new CompositeMediaBuilder);
    mbs.push(new CompositeMediaBuilder);
    mbs.top()->buildSimpleMedia(&r1);
    mbs.top()->buildSimpleMedia(&c);
    Media *cm = mbs.top()->getMedia();
    mbs.pop();

    mbs.top()->buildCompositeMedia(cm);
    mbs.top()->buildSimpleMedia(&r2);
    cm = mbs.top()->getMedia();
    mbs.pop();

    mbs.top()->buildCompositeMedia(cm);
    mbs.top()->buildSimpleMedia(&t);

    DescriptionVisitor dv;
    mbs.top()->getMedia()->accept(dv);
    CHECK(string("Combo( Combo( Combo( Rectangle(10, 0, 15, 5) Circle(12, 5, 2) ) Rectangle(0, 0, 25, 20) ) Triangle(0, 20, 16, 32, 25, 20) ) ") == dv.getDescription());
}

//    try {
//        cm->removeMedia(new SimpleMedia(&r2));
//        FAIL("Should not be here!");
//    } catch(string s) {
//        CHECK(string("Cannot found media !") == s);
//    }

TEST (boungingBox, TextMedia)
{
    Rectangle r(0, 0, 4, 6);     //  Area: 24     , Perimeter: 20
    TextMedia tm(r, "This is text !");

    DescriptionVisitor dv;
    tm.accept(dv);

    CHECK(string("This is text !") == dv.getDescription());

    //  boungingBox area.
    AreaVisitor av;
    tm.accept(av);
    DOUBLES_EQUAL(24, av.getArea().front(), deviation);

    //  boungingBox perimeter.
    PerimeterVisitor pv;
    tm.accept(pv);
    DOUBLES_EQUAL(20, pv.getPerimeter().front(), deviation);

}

TEST (removeMedia, CompositeMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    Rectangle r(0, 0, 4, 6);     //  Area: 24     , Perimeter: 20
    Rectangle r2(0, 0, 4, 5);

    CompositeMedia cm;
    cm.add(new SimpleMedia(&c));
    cm.add(new SimpleMedia(&r));

    //  before removeMedia.
    DescriptionVisitor dv;
    cm.accept(dv);
    CHECK(string("Combo( Circle(0, 0, 10) Rectangle(0, 0, 4, 6) ) ") == dv.getDescription());

    cm.removeMedia(new SimpleMedia(&r));

    //  After removeMedia.
    DescriptionVisitor dv2;
    cm.accept(dv2);
    CHECK(string("Combo( Circle(0, 0, 10) ) ") == dv2.getDescription());
}

//  can not found media to remove.
TEST (removeMediaException, CompositeMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    Rectangle r(0, 0, 4, 6);     //  Area: 24     , Perimeter: 20
    Rectangle r2(0, 0, 4, 5);

    CompositeMedia cm;
    cm.add(new SimpleMedia(&c));
    cm.add(new SimpleMedia(&r));

    try {
        cm.removeMedia(new SimpleMedia(&r2));
        FAIL("Should not be here!");
    } catch(string s) {
        CHECK(string("Cannot found media !") == s);
    }
}
/*HW4*/

/*HW3*/
//  Visitor Pattern.
TEST (Area, CompositeMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    Rectangle r(0, 0, 4, 6);     //  Area: 24     , Perimeter: 20

    CompositeMedia cm;
    cm.add(new SimpleMedia(&c));
    cm.add(new SimpleMedia(&r));

    AreaVisitor av;
    cm.accept(av);

    // Step by step.
    vector<double> areas{314, 24, 338};
    int index = 0;
    for(double area: av.getArea()) {
        DOUBLES_EQUAL(area, areas[index], deviation);
        ++index;
    }
}

TEST (Perimeter, CompositeMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    Rectangle r(0, 0, 4, 6);     //  Area: 24     , Perimeter: 20

    CompositeMedia cm;
    cm.add(new SimpleMedia(&c));
    cm.add(new SimpleMedia(&r));

    PerimeterVisitor pv;
    cm.accept(pv);

    // Step by step.
    vector<double> perimeters{62.8, 20, 82.8};
    int index = 0;
    for(double perimeter: pv.getPerimeter()) {
        DOUBLES_EQUAL(perimeter, perimeters[index], deviation);
        ++index;
    }
}

TEST (Hexagon, CompositeMedia)
{
    int index;

    Rectangle r(0, 2 * sqrt(3), 2, 2 * sqrt(3));     //  Area: 6.928203  , Perimeter: 10.928203
    Triangle t1(0, 2 * sqrt(3), 0, 0, -1, sqrt(3));  //  Area: 1.732050  , Perimeter: 7.464101
    Triangle t2(2, 2 * sqrt(3), 2, 0,  3, sqrt(3));  //  Area: 1.732050  , Perimeter: 7.464101

    PerimeterVisitor pv;
    AreaVisitor av;

    CompositeMedia combo;
    combo.add(new SimpleMedia(&r));
    combo.add(new SimpleMedia(&t1));

    CompositeMedia comboMedia;              //  comboMedia ---- combo ---- Rectangle (r)
    comboMedia.add(&combo);                 //    |               |
    comboMedia.add(new SimpleMedia(&t2));   //    |                ------- Triangle (t1)
                                            //     ---- Triangle (t2)
    comboMedia.accept(pv);
    comboMedia.accept(av);

    index = 0;
//                       r         t1        combo     t2        comboMedia
    vector<double> areas{6.928203, 1.732050, 8.660254, 1.732050, 10.392305};
    for(double area: av.getArea()) {
        DOUBLES_EQUAL(area, areas[index], deviation);
        ++index;
    }

    index = 0;
//                            r          t1        combo      t2        comboMedia
    vector<double> perimeters{10.928203, 7.464101, 18.392305, 7.464101, 25.856406};
    for(double perimeter: pv.getPerimeter()) {
        DOUBLES_EQUAL(perimeter, perimeters[index], deviation);
        ++index;
    }
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

    CHECK(string("Combo( Circle(0, 0, 10) Rectangle(0, 0, 4, 6) ) ") == dv.getDescription());
}
/*HW3*/

/*HW2*/
TEST (Area, SimpleMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    SimpleMedia m(&c);
    AreaVisitor av;
    m.accept(av);

    DOUBLES_EQUAL(314, av.getArea().front(), deviation);
}

TEST (Perimeter, SimpleMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    SimpleMedia m(&c);
    PerimeterVisitor pv;
    m.accept(pv);

    DOUBLES_EQUAL(62.8, pv.getPerimeter().front(), deviation);
}

TEST (AddToMedia, CompositeMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    Media m;

    try {
        m.add(new SimpleMedia(&c));
    } catch(string s) {
        CHECK(string("Cannot add media!") == s);
    }
}

//  Others.
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
/*HW2*/

/*HW1*/
// Circle Test.
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

// Rectangle Test.
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
/*HW1*/

#endif // UTSHAPES_H_INCLUDED
