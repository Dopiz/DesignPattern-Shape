#ifndef MEDIAVISITOR_H
#define MEDIAVISITOR_H
#include "SimpleMedia.h"
#include "CompositeMedia.h"
#include "TextMedia.h"

class MediaVisitor
{
    public:
        virtual void visitSimpleMedia(SimpleMedia *s) = 0;
        virtual void visitCompositeMedia(CompositeMedia *c) {}
        virtual void visitTextMedia(TextMedia *tm) = 0;
};

#endif // MEDIAVISITOR_H
