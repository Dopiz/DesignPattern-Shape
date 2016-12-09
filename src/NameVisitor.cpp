#include "NameVisitor.h"

NameVisitor::NameVisitor()
    : _name("") {
    //ctor
}

string NameVisitor::getName() const {
    return _name;
}

void NameVisitor::visitSimpleMedia(SimpleMedia *sm) {
    _name += sm->getName() + " ";
}

void NameVisitor::visitCompositeMediaPre(CompositeMedia *cm) {
    _name += cm->getName() + "{ ";
}

void NameVisitor::visitCompositeMediaPost(CompositeMedia *cm) {
    _name += "}";
}

void NameVisitor::visitTextMedia(TextMedia *tm) {
    _name = tm->getName();
}

NameVisitor::~NameVisitor() {
    //dtor
}
