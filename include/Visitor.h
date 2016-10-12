#ifndef VISITOR_H
#define VISITOR_H
#include "SimpleMedia.h"
#include "CompositeMedia.h"

class Visitor
{
    public:
        Visitor() {};
        virtual void visitSimpleMedia(SimpleMedia *s) = 0;
        virtual void visitCompositeMedia(CompositeMedia *c) = 0;
};

#endif // VISITOR_H
