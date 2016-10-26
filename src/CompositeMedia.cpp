#include "CompositeMedia.h"
#include "MediaVisitor.h"

CompositeMedia::CompositeMedia() {

}

void CompositeMedia::add(Media *m) {
    _mediaObj.push_back(m);
}

void CompositeMedia::accept(MediaVisitor &v) {

    for(Media *m: _mediaObj)
        m->accept(v);

    v.visitCompositeMedia(this);
}

double CompositeMedia::area() const {
    double sumOfArea = 0;
    for(Media *m: _mediaObj)
        sumOfArea += m->area();
    return sumOfArea;
}

double CompositeMedia::perimeter() const {
    double sumOfPerimeter = 0;
    for(Media *m: _mediaObj)
        sumOfPerimeter += m->perimeter();
    return sumOfPerimeter;
}

string CompositeMedia::description() const {
    string allDescription;
    for(Media *m: _mediaObj)
        allDescription += m->description();
    return allDescription;
}

CompositeMedia::~CompositeMedia() {
    //dtor
}
