#include "DescriptionVisitor.h"

DescriptionVisitor::DescriptionVisitor()
    : _description("") {

}

string DescriptionVisitor::getDescription() const {
    return _description;
}

void DescriptionVisitor::visitSimpleMedia(SimpleMedia *s) {
    _description += s->getShape()->description();
}

void DescriptionVisitor::visitCompositeMedia(CompositeMedia *c) {
    _description = "ComboMedia( " + _description + ")";

}

DescriptionVisitor::~DescriptionVisitor() {
    //dtor
}
