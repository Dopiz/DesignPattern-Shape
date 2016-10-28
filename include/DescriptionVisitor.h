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
        void visitSimpleMedia(SimpleMedia *sm);
        void visitCompositeMedia(CompositeMedia *cm);
        void visitTextMedia(TextMedia *tm);
        ~DescriptionVisitor();
};

#endif // DESCRIPTIONVISITOR_H
