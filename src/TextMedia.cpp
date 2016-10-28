#include "TextMedia.h"
#include "MediaVisitor.h"

TextMedia::TextMedia(Rectangle bBox, string text)
    : _boundingBox(bBox), _text(text) {
    //ctor
}

Rectangle TextMedia::getBoundingBox() const {
    return _boundingBox;
}

void TextMedia::accept(MediaVisitor &v) {
    v.visitTextMedia(this);
}

double TextMedia::perimeter() const {
    return _boundingBox.perimeter();
}

double TextMedia::area() const {
    return _boundingBox.area();
}

string TextMedia::description() const {
    return _text;
}

TextMedia::~TextMedia() {
    //dtor
}
