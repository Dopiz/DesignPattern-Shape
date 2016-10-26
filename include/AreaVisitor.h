#ifndef AREAVISITOR_H
#define AREAVISITOR_H
#include "MediaVisitor.h"

class AreaVisitor : public MediaVisitor
{
    private:
        vector<double> _area;

    public:
        AreaVisitor();
        vector<double> getArea() const;
        virtual void visitSimpleMedia(SimpleMedia *s);
        virtual void visitCompositeMedia(CompositeMedia *c);
        ~AreaVisitor();
};

#endif // AREAVISITOR_H
