#include "CompositeMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"
#include "NameVisitor.h"
#include "ShapeVisitor.h"

CompositeMedia::CompositeMedia() {

}

CompositeMedia::CompositeMedia(vector<Media *> m)
    : _media(m) {

}

void CompositeMedia::setName(string name) {
    _name = name;
}

string CompositeMedia::getName() const {
    return _name;
}

vector<Media *> *CompositeMedia::getVector() {
    return &_media;
}

void CompositeMedia::add(Media *m) {
    _media.push_back(m);
}

void CompositeMedia::removeMedia(Media *m) {

    for(vector<Media *>::iterator it = _media.begin(); it != _media.end(); ++it) {

        if((*it)->description() == m->description() && (*it)->getName() == m->getName()) {
            _media.erase(it);
            break;
        }

        else (*it)->removeMedia(m);
    }
}

void CompositeMedia::accept(NameVisitor &v) {

    v.visitCompositeMediaPre(this);

    for(Media *m: _media)
        m->accept(v);

    v.visitCompositeMediaPost(this);
}

void CompositeMedia::accept(AreaVisitor &v) {

    for(Media *m: _media)
        m->accept(v);

    v.visitCompositeMedia(this);
}

void CompositeMedia::accept(ShapeVisitor &v) {

    for(Media *m: _media)
        m->accept(v);

    v.visitCompositeMedia(this);
}

void CompositeMedia::accept(PerimeterVisitor &v) {

    for(Media *m: _media)
        m->accept(v);

    v.visitCompositeMedia(this);
}

void CompositeMedia::accept(DescriptionVisitor &v) {

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
    return string("combo( ") + allDescription + string(") ");
}

CompositeMedia::~CompositeMedia() {
    //dtor
}
