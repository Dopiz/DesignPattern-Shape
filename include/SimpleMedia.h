#ifndef SIMPLEMEDIA_H
#define SIMPLEMEDIA_H
#include "Media.h"
#include "Shape.h"

class SimpleMedia : public Media
{
    private:
        Shape *_shape;

    public:
        SimpleMedia(Shape *shape);
        Shape *getShape() const;
        void accept(MediaVisitor &v);
        double area() const;
        double perimeter() const;
        string description() const;
        ~SimpleMedia();
};

#endif // SIMPLEMEDIA_H
