#include "SimpleMediaBuilder.h"

SimpleMediaBuilder::SimpleMediaBuilder()
    : _sMedia(0) {
    //ctor
}

void SimpleMediaBuilder::buildSimpleMedia(Shape *s) {
    _sMedia = new SimpleMedia(s);
}

SimpleMedia *SimpleMediaBuilder::getMedia() const{
    return _sMedia;
}

SimpleMediaBuilder::~SimpleMediaBuilder() {
    //dtor
}
