#include "SimpleMedia.h"
#include "MediaVisitor.h"

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

void SimpleMedia::accept(MediaVisitor &v) {
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
