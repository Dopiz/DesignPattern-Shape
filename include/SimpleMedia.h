#ifndef SIMPLEMEDIA_H
#define SIMPLEMEDIA_H
#include "Media.h"
#include "Shape.h"

class AreaVisitor;
class PerimeterVisitor;
class DescriptionVisitor;

class SimpleMedia : public Media
{
    private:
        Shape *_shape;

    public:
        SimpleMedia(Shape *shape);
        Shape *getShape();
        void accept(AreaVisitor &v);
        void accept(PerimeterVisitor &v);
        void accept(DescriptionVisitor &v);
        virtual ~SimpleMedia();
};

#endif // SIMPLEMEDIA_H
