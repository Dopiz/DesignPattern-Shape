#ifndef AREAVISITOR_H
#define AREAVISITOR_H
#include "MediaVisitor.h"

class AreaVisitor : public MediaVisitor
{
    private:
        double _area;

    public:
        AreaVisitor();
        double getArea() const;
        virtual void visitSimpleMedia(SimpleMedia *s);
        virtual void visitCompositeMedia(CompositeMedia *c);
        ~AreaVisitor();
};

#endif // AREAVISITOR_H
