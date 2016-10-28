#include "Media.h"

Media::Media() {

}

void Media::add(Media *m) {
    throw string("Cannot add media!");
}
void Media::accept(MediaVisitor& v) {}

double Media::area() const {}

double Media::perimeter() const {}

string Media::description() const {}

Media::~Media() {
    //dtor
}
