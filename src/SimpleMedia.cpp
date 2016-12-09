#include "SimpleMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"
#include "NameVisitor.h"
#include "ShapeVisitor.h"

SimpleMedia::SimpleMedia() {

}

SimpleMedia::SimpleMedia(Shape *s)
    : _shape(s) {

}

Shape *SimpleMedia::getShape() const {
    return _shape;
}

void SimpleMedia::setName(string name) {
    _name = name;
    _shape->setName(name);
}

string SimpleMedia::getName() const {
    return _name;
}

void SimpleMedia::accept(NameVisitor &v) {
    v.visitSimpleMedia(this);
}

void SimpleMedia::accept(DescriptionVisitor &v) {
    v.visitSimpleMedia(this);
}

void SimpleMedia::accept(ShapeVisitor &v) {
    v.visitSimpleMedia(this);
}

void SimpleMedia::accept(AreaVisitor &v) {
    v.visitSimpleMedia(this);
}

void SimpleMedia::accept(PerimeterVisitor &v) {
    v.visitSimpleMedia(this);
}

double SimpleMedia::area() const {
    return _shape->area();
}

double SimpleMedia::perimeter() const {
    return _shape->perimeter();
}

string SimpleMedia::description() const {
    return _shape->description();
}

SimpleMedia::~SimpleMedia() {
    //dtor
}
