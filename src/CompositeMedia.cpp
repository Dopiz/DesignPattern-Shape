#include "CompositeMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"

CompositeMedia::CompositeMedia()
{
    //ctor
}

void CompositeMedia::Accept(AreaVisitor &v) {
    v.visitCompositeMedia(this);
}

void CompositeMedia::Accept(PerimeterVisitor &v) {
    v.visitCompositeMedia(this);
}

CompositeMedia::~CompositeMedia()
{
    //dtor
}
