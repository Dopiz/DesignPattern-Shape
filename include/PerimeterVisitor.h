#ifndef PERIMETERVISITOR_H
#define PERIMETERVISITOR_H
#include "MediaVisitor.h"

class PerimeterVisitor : public MediaVisitor
{
    private:
        double _perimeter;

    public:
        PerimeterVisitor();
        double getPerimeter();
        virtual void visitSimpleMedia(SimpleMedia *s);
        virtual void visitCompositeMedia(CompositeMedia *c);
        virtual ~PerimeterVisitor();
};

#endif // PERIMETERVISITOR_H
