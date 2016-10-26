#include "PerimeterVisitor.h"

PerimeterVisitor::PerimeterVisitor()
    : _perimeter(0) {

}

vector<double> PerimeterVisitor::getPerimeter() const {
    return _perimeter;
}

void PerimeterVisitor::visitSimpleMedia(SimpleMedia *s) {
    _perimeter.push_back(s->perimeter());
}

void PerimeterVisitor::visitCompositeMedia(CompositeMedia *c) {
    _perimeter.push_back(c->perimeter());
}

PerimeterVisitor::~PerimeterVisitor() {
    //dtor
}
