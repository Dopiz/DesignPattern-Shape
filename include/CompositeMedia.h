#ifndef COMPOSITEMEDIA_H
#define COMPOSITEMEDIA_H
#include "Media.h"
#include <vector>

class CompositeMedia : public Media
{
    private:
        vector<Media *> _media;

    public:
        CompositeMedia();
        CompositeMedia(vector<Media *> m);
        void add(Media *m);
        void removeMedia(Media *m);
        void accept(MediaVisitor &v);
        double area() const;
        double perimeter() const;
        string description() const;
        ~CompositeMedia();
};

#endif // COMPOSITEMEDIA_H
