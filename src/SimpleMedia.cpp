#include "SimpleMedia.h"
#include "MediaVisitor.h"


SimpleMedia::SimpleMedia(Shape *shape)
    : _shape(shape) {

}

Shape *SimpleMedia::getShape() const {
    return _shape;
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
