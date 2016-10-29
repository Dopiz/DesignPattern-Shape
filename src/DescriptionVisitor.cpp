#include "DescriptionVisitor.h"

DescriptionVisitor::DescriptionVisitor()
    : _description("") {

}

string DescriptionVisitor::getDescription() const {
    return _description;
}

void DescriptionVisitor::visitSimpleMedia(SimpleMedia *sm) {
    _description = sm->description();
}

void DescriptionVisitor::visitCompositeMedia(CompositeMedia *cm) {
    _description = cm->description();
}

void DescriptionVisitor::visitTextMedia(TextMedia *tm) {
    _description += tm->description();
}

DescriptionVisitor::~DescriptionVisitor() {
    //dtor
}
