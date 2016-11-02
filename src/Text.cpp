#include "Text.h"

Text::Text(Rectangle boundingBox, string text)
    : _bBox(boundingBox), _text(text) {

}

Rectangle Text::getBoundingBox() const {
    return _bBox;
}

string Text::getText() const {
    return _text;
}

Text::~Text() {
    //dtor
}
