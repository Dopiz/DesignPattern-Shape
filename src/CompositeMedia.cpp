#include "CompositeMedia.h"
#include "MediaVisitor.h"

CompositeMedia::CompositeMedia() {

}

CompositeMedia::CompositeMedia(vector<Media *> m)
    : _media(m) {

}

void CompositeMedia::add(Media *m) {
    _media.push_back(m);
}

void CompositeMedia::removeMedia(Media *m) {

    for(vector<Media *>::iterator it = _media.begin(); it != _media.end(); ++it) {

        if((*it)->description() == m->description()) {
            _media.erase(it);
            break;
        }

        else (*it)->removeMedia(m);
    }
}

void CompositeMedia::accept(MediaVisitor &v) {

    for(Media *m: _media)
        m->accept(v);

    v.visitCompositeMedia(this);
}

double CompositeMedia::area() const {
    double sumOfArea = 0;
    for(Media *m: _media) {
        sumOfArea += m->area();
    }
    return sumOfArea;
}

double CompositeMedia::perimeter() const {
    double sumOfPerimeter = 0;
    for(Media *m: _media)
        sumOfPerimeter += m->perimeter();
    return sumOfPerimeter;
}

string CompositeMedia::description() const {
    string allDescription;
    for(Media *m: _media)
        allDescription += m->description();
    return string("X( ") + allDescription + string(") ");
}

CompositeMedia::~CompositeMedia() {
    //dtor
}
