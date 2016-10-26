#include "AreaVisitor.h"

AreaVisitor::AreaVisitor() {

}

vector<double> AreaVisitor::getArea() const {
    return _area;
}

void AreaVisitor::visitSimpleMedia(SimpleMedia *s) {
    _area.push_back(s->area());
}

void AreaVisitor::visitCompositeMedia(CompositeMedia *c) {
    _area.push_back(c->area());
}

AreaVisitor::~AreaVisitor() {
    //dtor
}
