#ifndef COMPOSITEMEDIA_H
#define COMPOSITEMEDIA_H
#include "Media.h"
#include "Shape.h"
#include <vector>

class AreaVisitor;
class PerimeterVisitor;

class CompositeMedia : public Media
{
    private:
        vector<Media *> _mediaObj;

    public:
        CompositeMedia();
        void add(Media *m);
        void accept(AreaVisitor &v);
        void accept(PerimeterVisitor &v);
        virtual ~CompositeMedia();
};

#endif // COMPOSITEMEDIA_H
