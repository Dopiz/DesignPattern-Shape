#include "AreaVisitor.h"

AreaVisitor::AreaVisitor() {

}

vector<double> AreaVisitor::getArea() const {
    return _area;
}

void AreaVisitor::visitSimpleMedia(SimpleMedia *sm) {
    _area.push_back(sm->area());
}

void AreaVisitor::visitCompositeMedia(CompositeMedia *cm) {
    _area.push_back(cm->area());
}

void AreaVisitor::visitTextMedia(TextMedia *tm) {
    _area.push_back(tm->area());
}

AreaVisitor::~AreaVisitor() {
    //dtor
}
