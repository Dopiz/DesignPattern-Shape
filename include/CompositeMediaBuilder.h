#ifndef COMPOSITEMEDIABUILDER_H
#define COMPOSITEMEDIABUILDER_H
#include "MediaBuilder.h"
#include "SimpleMedia.h"
#include "CompositeMedia.h"

class CompositeMediaBuilder : public MediaBuilder
{
    private:
        CompositeMedia *_cMedia;

    public:
        CompositeMediaBuilder();
        void buildCompositeMedia(Media * m);
        void buildSimpleMedia(Shape *s);
        Media *getMedia() const;
        ~CompositeMediaBuilder();
};

#endif // COMPOSITEMEDIABUILDER_H
