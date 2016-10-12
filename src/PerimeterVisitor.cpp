#include "PerimeterVisitor.h"

PerimeterVisitor::PerimeterVisitor()
{
    //ctor
}

double PerimeterVisitor::getPerimeter() {
    return _perimeter;
}

void PerimeterVisitor::visitSimpleMedia(SimpleMedia *s) {
    _perimeter += s->getShape()->perimeter();
}

void PerimeterVisitor::visitCompositeMedia(CompositeMedia *c) {

}

PerimeterVisitor::~PerimeterVisitor()
{
    //dtor
}
