#include "Media.h"

void Media::add(Media *m) {
    throw string("Cannot add !");
}

Media::~Media()
{
    //dtor
}

void Media::Accept(AreaVisitor &v) {

}

void Media::Accept(PerimeterVisitor &v) {

}
