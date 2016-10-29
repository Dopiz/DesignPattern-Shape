#ifndef SIMPLEMEDIABUILDER_H
#define SIMPLEMEDIABUILDER_H
#include "MediaBuilder.h"
#include "SimpleMedia.h"

class SimpleMediaBuilder : public MediaBuilder
{
    private:
        SimpleMedia *_sMedia;

    public:
        SimpleMediaBuilder();
        void buildCompositeMedia(Media * m);
        void buildSimpleMedia(Shape *s);
        Media *getMedia() const;
        ~SimpleMediaBuilder();
};

#endif // SIMPLEMEDIABUILDER_H
