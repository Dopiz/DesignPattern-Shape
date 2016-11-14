#include "TextMedia.h"
#include "MediaVisitor.h"

TextMedia::TextMedia() {

}

TextMedia::TextMedia(Text *t)
    : _text(t) {

}

void TextMedia::accept(MediaVisitor &v) {
    v.visitTextMedia(this);
}

double TextMedia::perimeter() const {
    return _text->getBoundingBox()->perimeter();
}

double TextMedia::area() const {
    return _text->getBoundingBox()->area();
}

string TextMedia::description() const {
    return _text->getText();
}

TextMedia::~TextMedia() {
    //dtor
}
