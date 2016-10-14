#include "DescriptionVisitor.h"
#include <sstream>

DescriptionVisitor::DescriptionVisitor()
    : _description("") {
    //ctor
}

string DescriptionVisitor::getDescription() {
    return _description;
}

void DescriptionVisitor::visitSimpleMedia(SimpleMedia *s) {
    _description += s->getShape()->description();
}

void DescriptionVisitor::visitCompositeMedia(CompositeMedia *c) {
    _description = "ComboMedia(" + _description + ")";

}

DescriptionVisitor::~DescriptionVisitor()
{
    //dtor
}
