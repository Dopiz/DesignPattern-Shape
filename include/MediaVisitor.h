#ifndef MEDIAVISITOR_H
#define MEDIAVISITOR_H
#include "SimpleMedia.h"
#include "CompositeMedia.h"

class MediaVisitor
{
    public:
        MediaVisitor() {};
        virtual void visitSimpleMedia(SimpleMedia *s) = 0;
        virtual void visitCompositeMedia(CompositeMedia *c) = 0;
};

#endif // MEDIAVISITOR_H
