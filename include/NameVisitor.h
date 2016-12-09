#ifndef NAMEVISITOR_H
#define NAMEVISITOR_H
#include "MediaVisitor.h"

class NameVisitor : public MediaVisitor
{
    private:
        string _name;

    public:
        NameVisitor();
        string getName() const;
        void visitSimpleMedia(SimpleMedia *sm);
        void visitCompositeMediaPre(CompositeMedia *cm);
        void visitCompositeMediaPost(CompositeMedia *cm);
        void visitTextMedia(TextMedia *tm);
        ~NameVisitor();
};

#endif // NAMEVISITOR_H
