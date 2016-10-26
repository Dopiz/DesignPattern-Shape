#include "DescriptionVisitor.h"

DescriptionVisitor::DescriptionVisitor()
    : _description("") {

}

string DescriptionVisitor::getDescription() const {
    return _description;
}

void DescriptionVisitor::visitSimpleMedia(SimpleMedia *s) {
    _description = s->description();
}

void DescriptionVisitor::visitCompositeMedia(CompositeMedia *c) {
    _description = "ComboMedia( " + c->description() + ")";
}

DescriptionVisitor::~DescriptionVisitor() {
    //dtor
}
