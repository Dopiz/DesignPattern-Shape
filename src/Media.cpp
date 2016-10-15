#include "Media.h"

Media::Media() {

}

void Media::add(Media *m) {
    throw string("Cannot add media!");
}

void Media::accept(AreaVisitor &v) {}

void Media::accept(PerimeterVisitor &v) {}

void Media::accept(DescriptionVisitor &v) {}

Media::~Media() {
    //dtor
}
