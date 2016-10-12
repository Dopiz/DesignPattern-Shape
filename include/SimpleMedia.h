#ifndef SIMPLEMEDIA_H
#define SIMPLEMEDIA_H
#include "Media.h"
#include "Shape.h"

class AreaVisitor;
class PerimeterVisitor;

class SimpleMedia : public Media
{
    private:
        Shape *_shape;

    public:
        SimpleMedia(Shape *shape);
        Shape *getShape();
        void Accept(AreaVisitor &v);
        void Accept(PerimeterVisitor &v);
        virtual ~SimpleMedia();
};

#endif // SIMPLEMEDIA_H
