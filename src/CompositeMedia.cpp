#include "CompositeMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"

CompositeMedia::CompositeMedia() {

}

void CompositeMedia::add(Media *m) {
    _mediaObj.push_back(m);
}

void CompositeMedia::accept(AreaVisitor &v) {

    for(Media *m: _mediaObj)
        m->accept(v);

    v.visitCompositeMedia(this);
}

void CompositeMedia::accept(PerimeterVisitor &v) {

    for(Media *m: _mediaObj)
        m->accept(v);

    v.visitCompositeMedia(this);
}

void CompositeMedia::accept(DescriptionVisitor &v) {

    for(Media *m: _mediaObj)
        m->accept(v);

    v.visitCompositeMedia(this);
}

CompositeMedia::~CompositeMedia() {
    //dtor
}
