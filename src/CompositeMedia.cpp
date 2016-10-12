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

void CompositeMedia::Accept(AreaVisitor &v) {
    for(vector<Media *>::iterator it = _mediaObj.begin(); it != _mediaObj.end(); ++it)
        (*it)->Accept(v);
}

void CompositeMedia::Accept(PerimeterVisitor &v) {
        for(vector<Media *>::iterator it = _mediaObj.begin(); it != _mediaObj.end(); ++it)
        (*it)->Accept(v);
}

CompositeMedia::~CompositeMedia()
{
    //dtor
}
