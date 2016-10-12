#ifndef AREAVISITOR_H
#define AREAVISITOR_H
#include "Visitor.h"

class AreaVisitor : public Visitor
{
    private:
        double _area = 0;

    public:
        AreaVisitor();
        double getArea();
        virtual void visitSimpleMedia(SimpleMedia *s);
        virtual void visitCompositeMedia(CompositeMedia *c);
        virtual ~AreaVisitor();
};

#endif // AREAVISITOR_H
