#include "ShapeVisitor.h"

ShapeVisitor::ShapeVisitor() {
    //ctor
}

vector<Media *> ShapeVisitor::getShape() const {
    return _media;
}

void ShapeVisitor::visitSimpleMedia(SimpleMedia *sm) {
    _media.push_back(sm);
}

void ShapeVisitor::visitCompositeMedia(CompositeMedia *cm) {
    _media.push_back(cm);
}

void ShapeVisitor::visitTextMedia(TextMedia *tm) {
    _media.push_back(tm);
}

ShapeVisitor::~ShapeVisitor() {
    //dtor
}
