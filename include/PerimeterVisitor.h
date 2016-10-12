#ifndef PERIMETERVISITOR_H
#define PERIMETERVISITOR_H
#include "Visitor.h"

class PerimeterVisitor : public Visitor
{
    private:
        double _perimeter = 0;

    public:
        PerimeterVisitor();
        double getPerimeter();
        virtual void visitSimpleMedia(SimpleMedia *s);
        virtual void visitCompositeMedia(CompositeMedia *c);
        virtual ~PerimeterVisitor();
};

#endif // PERIMETERVISITOR_H
