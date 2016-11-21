#ifndef UTVISITOR_H_INCLUDED
#define UTVISITOR_H_INCLUDED

#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"

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

    CHECK(string("c(0, 0, 10) ") == dv.getDescription());
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

    CHECK(string("X( c(0, 0, 10) r(0, 0, 4, 6) ) ") == dv.getDescription());
}

TEST (getArea, SimpleMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    SimpleMedia m(&c);
    AreaVisitor av;
    m.accept(av);

    DOUBLES_EQUAL(314, av.getArea().front(), deviation);
}

TEST (getPerimeter, SimpleMedia)
{
    Circle c(0, 0, 10);          //  Area: 314    , Perimeter: 62.8
    SimpleMedia m(&c);
    PerimeterVisitor pv;
    m.accept(pv);

    DOUBLES_EQUAL(62.8, pv.getPerimeter().front(), deviation);
}

#endif // UTVISITOR_H_INCLUDED
