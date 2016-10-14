#include "SimpleMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"

SimpleMedia::SimpleMedia(Shape *shape)
    : _shape(shape) {
    //ctor
}

Shape *SimpleMedia::getShape() {
    return _shape;
}

void SimpleMedia::accept(AreaVisitor &v) {
    v.visitSimpleMedia(this);
}

void SimpleMedia::accept(PerimeterVisitor &v) {
    v.visitSimpleMedia(this);
}

void SimpleMedia::accept(DescriptionVisitor &v) {
    v.visitSimpleMedia(this);
}

SimpleMedia::~SimpleMedia()
{
    //dtor
}
