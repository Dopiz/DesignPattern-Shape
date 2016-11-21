#include "SimpleMediaBuilder.h"

SimpleMediaBuilder::SimpleMediaBuilder()
    : _sMedia(0) {
    //ctor
}

void SimpleMediaBuilder::buildCompositeMedia(Media * m) {

}

void SimpleMediaBuilder::buildSimpleMedia(Shape *s) {
    _sMedia = new SimpleMedia(s);
}

Media *SimpleMediaBuilder::getMedia() const {
    return _sMedia;
}

SimpleMediaBuilder::~SimpleMediaBuilder() {
    //dtor
}
