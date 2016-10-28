#include "PerimeterVisitor.h"

PerimeterVisitor::PerimeterVisitor()
    : _perimeter(0) {

}

vector<double> PerimeterVisitor::getPerimeter() const {
    return _perimeter;
}

void PerimeterVisitor::visitSimpleMedia(SimpleMedia *sm) {
    _perimeter.push_back(sm->perimeter());
}

void PerimeterVisitor::visitCompositeMedia(CompositeMedia *cm) {
    _perimeter.push_back(cm->perimeter());
}

void PerimeterVisitor::visitTextMedia(TextMedia *tm) {
    _perimeter.push_back(tm->perimeter());
}

PerimeterVisitor::~PerimeterVisitor() {
    //dtor
}
