#include "PerimeterVisitor.h"

PerimeterVisitor::PerimeterVisitor()
    : _perimeter(0) {

}

double PerimeterVisitor::getPerimeter() const {
    return _perimeter;
}

void PerimeterVisitor::visitSimpleMedia(SimpleMedia *s) {
    _perimeter += s->getShape()->perimeter();
}

void PerimeterVisitor::visitCompositeMedia(CompositeMedia *c) {

}

PerimeterVisitor::~PerimeterVisitor() {
    //dtor
}
