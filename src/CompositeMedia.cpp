#include "CompositeMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"

CompositeMedia::CompositeMedia()
{
    //ctor
}

void CompositeMedia::add(Media *m) {
    _mediaObj.push_back(m);
}

void CompositeMedia::accept(AreaVisitor &v) {
    for(vector<Media *>::iterator it = _mediaObj.begin(); it != _mediaObj.end(); ++it)
        (*it)->accept(v);
}

void CompositeMedia::accept(PerimeterVisitor &v) {
        for(vector<Media *>::iterator it = _mediaObj.begin(); it != _mediaObj.end(); ++it)
        (*it)->accept(v);
}

CompositeMedia::~CompositeMedia()
{
    //dtor
}
