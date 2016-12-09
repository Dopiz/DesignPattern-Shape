#ifndef SHAPEVISITOR_H
#define SHAPEVISITOR_H
#include "MediaVisitor.h"
#include <vector>
using namespace std;

class ShapeVisitor : public MediaVisitor
{
    private:
        vector<Media *> _media;

    public:
        ShapeVisitor();
        vector<Media *> getShape() const;
        void visitSimpleMedia(SimpleMedia *sm);
        void visitCompositeMedia(CompositeMedia *cm);
        void visitTextMedia(TextMedia *tm);
        ~ShapeVisitor();
};

#endif // SHAPEVISITOR_H
