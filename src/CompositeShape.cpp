#include "CompositeShape.h"
#include <sstream>

CompositeShape::CompositeShape()
    : Shape("CompositeShape") {
    //ctor
}

string CompositeShape::content() {
    ostringstream oss;
    for(Shape *s: _combo)
        oss << s->content();
    return oss.str();
}

double CompositeShape::perimeter() const {
    return sumOfPerimeter(_combo);
}

double CompositeShape::area() const {
    return sumOfArea(_combo);
}

void CompositeShape::addShape(Shape* shape, string name) {
    shape->setName(name);
    this->_combo.push_back(shape);
}

CompositeShape::~CompositeShape() {
    //dtor
}
