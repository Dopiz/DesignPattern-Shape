#include "TextMedia.h"
#include "AreaVisitor.h"
#include "NameVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"
#include "ShapeVisitor.h"

TextMedia::TextMedia() {

}

TextMedia::TextMedia(Text *t)
    : _text(t) {

}

void TextMedia::accept(NameVisitor &v) {
    v.visitTextMedia(this);
}

void TextMedia::accept(AreaVisitor &v) {
    v.visitTextMedia(this);
}

void TextMedia::accept(PerimeterVisitor &v) {
    v.visitTextMedia(this);
}

void TextMedia::accept(DescriptionVisitor &v) {
    v.visitTextMedia(this);
}

void TextMedia::accept(ShapeVisitor &v) {
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
