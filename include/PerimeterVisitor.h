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
        virtual void visitSimpleMedia(SimpleMedia *s);
        virtual void visitCompositeMedia(CompositeMedia *c);
        ~PerimeterVisitor();
};

#endif // PERIMETERVISITOR_H
