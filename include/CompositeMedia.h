#ifndef COMPOSITEMEDIA_H
#define COMPOSITEMEDIA_H
#include "Media.h"
#include <vector>

class CompositeMedia : public Media
{
    private:
        vector<Media *> _mediaObj;

    public:
        CompositeMedia();
        void add(Media *m);
        void accept(AreaVisitor &v);
        void accept(PerimeterVisitor &v);
        void accept(DescriptionVisitor &v);
        ~CompositeMedia();
};

#endif // COMPOSITEMEDIA_H
