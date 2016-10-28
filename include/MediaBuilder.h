#ifndef MEDIABUILDER_H
#define MEDIABUILDER_H
#include "Media.h"
#include "Shape.h"

class MediaBuilder
{
    public:
        virtual void buildCompositeMedia(Media * m) {};
        virtual void buildSimpleMedia(Shape *s) {};
        virtual Media *getMedia() const = 0;
};

#endif // MEDIABUILDER_H
