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
        void visitSimpleMedia(SimpleMedia *sm);
        void visitCompositeMedia(CompositeMedia *cm);
        void visitTextMedia(TextMedia *tm);
        ~AreaVisitor();
};

#endif // AREAVISITOR_H
