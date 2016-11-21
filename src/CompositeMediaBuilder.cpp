#include "CompositeMediaBuilder.h"

CompositeMediaBuilder::CompositeMediaBuilder()
    : _cMedia(new CompositeMedia) {
    //ctor
}

void CompositeMediaBuilder::buildCompositeMedia(Media *m) {
    _cMedia->add(m);
}

void CompositeMediaBuilder::buildSimpleMedia(Shape *s) {
    _cMedia->add(new SimpleMedia(s));
}

Media *CompositeMediaBuilder::getMedia() const {
    return _cMedia;
}

CompositeMediaBuilder::~CompositeMediaBuilder() {
    //dtor
}
