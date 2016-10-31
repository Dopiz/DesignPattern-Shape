#ifndef UTBUILDER_H_INCLUDED
#define UTBUILDER_H_INCLUDED

#include <stack>

#include "TextMedia.h"
#include "SimpleMediaBuilder.h"
#include "CompositeMediaBuilder.h"

//  Builder Pattern.
TEST (buildCircle, SimpleMediaBuilder)
{
    Circle c(0, 0, 5);

    SimpleMediaBuilder mb;
    mb.buildSimpleMedia(&c);

    Media *m = mb.getMedia();
    DescriptionVisitor dv;
    m->accept(dv);
    CHECK(string("Circle(0, 0, 5) ") == dv.getDescription());
}

TEST (buildHouse, CompositeMediaBuilder)   //  Combo ---- Combo ---- Combo ---- Rectangle (&r1)
{                                          //    |          |          |
    stack<MediaBuilder *> mbs;             //    |          |           ------- Circle (&c)
                                           //    |           ---- Rectangle (&r2)
    Circle c(12, 5, 2);                    //     ---- Triangle (&t)
    Circle c2(0, 0, 15);
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

    //  Remove invalid Shape.
    try {
        cm->removeMedia(new SimpleMedia(&c2));
        FAIL("Should not be here!");
    } catch(string s) {
        CHECK(string("Cannot found media !") == s);
    }

}

TEST (buildHouse1, CompositeMediaBuilder)  //  Combo ---- Triangle  (&t)
{                                          //    |
    stack<MediaBuilder *> mbs;             //  Combo ---- Rectangle (&r2)
                                           //    |
    Circle c(12, 5, 2);                    //  Combo ---- Circle    (&c)
    Rectangle r1(10, 0, 15, 5);            //    |
    Rectangle r2(0, 0, 25, 20);            //     ------- Rectangle (&r1)
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

    //  Before remove.
    DescriptionVisitor dv;
    mbs.top()->getMedia()->accept(dv);
    CHECK(string("Combo( Combo( Combo( Rectangle(10, 0, 15, 5) Circle(12, 5, 2) ) Rectangle(0, 0, 25, 20) ) Triangle(0, 20, 16, 32, 25, 20) ) ") == dv.getDescription());

    //  Remove media.
    cm->removeMedia(new SimpleMedia(&r2));

    // After remove.
    DescriptionVisitor dv2;
    mbs.top()->getMedia()->accept(dv2);
    CHECK(string("Combo( Combo( Combo( Rectangle(10, 0, 15, 5) Circle(12, 5, 2) ) ) Triangle(0, 20, 16, 32, 25, 20) ) ") == dv2.getDescription());

}

TEST (boundingBox, TextMedia)
{
    Rectangle r(0, 0, 4, 6);     //  Area: 24     , Perimeter: 20
    TextMedia tm(r, "This is text media !");

    DescriptionVisitor dv;
    tm.accept(dv);

    CHECK(string("This is text media !") == dv.getDescription());

    //  boundingBox area.
    AreaVisitor av;
    tm.accept(av);
    DOUBLES_EQUAL(24, av.getArea().front(), deviation);

    //  boundingBox perimeter.
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

    //  Before remove.
    DescriptionVisitor dv;
    cm.accept(dv);
    CHECK(string("Combo( Circle(0, 0, 10) Rectangle(0, 0, 4, 6) ) ") == dv.getDescription());

    //  Remove media.
    cm.removeMedia(new SimpleMedia(&r));

    //  After remove.
    DescriptionVisitor dv2;
    cm.accept(dv2);
    CHECK(string("Combo( Circle(0, 0, 10) ) ") == dv2.getDescription());
}

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

#endif // UTBUILDER_H_INCLUDED
