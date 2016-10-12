#include "SimpleMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"

SimpleMedia::SimpleMedia(Shape *shape)
    : _shape(shape) {
    //ctor
}

Shape *SimpleMedia::getShape() {
    return _shape;
}

void SimpleMedia::Accept(AreaVisitor &v) {
    v.visitSimpleMedia(this);
}

void SimpleMedia::Accept(PerimeterVisitor &v) {
    v.visitSimpleMedia(this);
}

SimpleMedia::~SimpleMedia()
{
    //dtor
}
