#ifndef DESCRIPTIONVISITOR_H
#define DESCRIPTIONVISITOR_H
#include "MediaVisitor.h"

class DescriptionVisitor : public MediaVisitor
{
    private:
        string _description;

    public:
        DescriptionVisitor();
        string getDescription();
        virtual void visitSimpleMedia(SimpleMedia *s);
        virtual void visitCompositeMedia(CompositeMedia *c);
        virtual ~DescriptionVisitor();
};

#endif // DESCRIPTIONVISITOR_H
