#ifndef DESCRIPTIONVISITOR_H
#define DESCRIPTIONVISITOR_H
#include "MediaVisitor.h"

class DescriptionVisitor : public MediaVisitor
{
    private:
        string _description;

    public:
        DescriptionVisitor();
        string getDescription() const;
        virtual void visitSimpleMedia(SimpleMedia *s);
        virtual void visitCompositeMedia(CompositeMedia *c);
        ~DescriptionVisitor();
};

#endif // DESCRIPTIONVISITOR_H
