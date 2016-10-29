#ifndef MEDIABUILDER_H
#define MEDIABUILDER_H
#include "Media.h"
#include "Shape.h"

class MediaBuilder
{
    public:
        virtual void buildCompositeMedia(Media * m) = 0;
        virtual void buildSimpleMedia(Shape *s) = 0;
        virtual Media *getMedia() const = 0;
};

#endif // MEDIABUILDER_H
