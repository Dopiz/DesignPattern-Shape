#ifndef AREAVISITOR_H
#define AREAVISITOR_H
#include "MediaVisitor.h"

class AreaVisitor : public MediaVisitor
{
    private:
        double _area;

    public:
        AreaVisitor();
        double getArea();
        virtual void visitSimpleMedia(SimpleMedia *s);
        virtual void visitCompositeMedia(CompositeMedia *c);
        virtual ~AreaVisitor();
};

#endif // AREAVISITOR_H
