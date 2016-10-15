#include "AreaVisitor.h"

AreaVisitor::AreaVisitor()
    : _area(0) {

}

double AreaVisitor::getArea() const {
    return _area;
}

void AreaVisitor::visitSimpleMedia(SimpleMedia *s) {
    _area += s->getShape()->area();
}

void AreaVisitor::visitCompositeMedia(CompositeMedia *c) {

}

AreaVisitor::~AreaVisitor() {
    //dtor
}
