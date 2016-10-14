#include "Media.h"

Media::Media() {
    //dtor
}

void Media::add(Media *m) {
    throw string("Cannot add !");
}

void Media::accept(AreaVisitor &v) {

}

void Media::accept(PerimeterVisitor &v) {

}

void Media::accept(DescriptionVisitor &v) {

}

Media::~Media() {
    //dtor
}
