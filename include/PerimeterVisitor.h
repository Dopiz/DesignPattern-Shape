#ifndef PERIMETERVISITOR_H
#define PERIMETERVISITOR_H
#include "MediaVisitor.h"

class PerimeterVisitor : public MediaVisitor
{
    private:
        vector<double> _perimeter;

    public:
        PerimeterVisitor();
        vector<double> getPerimeter() const;
        void visitSimpleMedia(SimpleMedia *sm);
        void visitCompositeMedia(CompositeMedia *cm);
        void visitTextMedia(TextMedia *tm);
        ~PerimeterVisitor();
};

#endif // PERIMETERVISITOR_H
