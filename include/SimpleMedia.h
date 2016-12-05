#ifndef SIMPLEMEDIA_H
#define SIMPLEMEDIA_H
#include "Media.h"
#include "Shape.h"

class SimpleMedia : public Media
{
    private:
        Shape *_shape;
        string _name;

    public:
        SimpleMedia();
        SimpleMedia(Shape *s);
        Shape *getShape() const;
        void setName(string name);
        string getName() const;
        void accept(MediaVisitor &v);
        double area() const;
        double perimeter() const;
        string description() const;
        ~SimpleMedia();
};

#endif // SIMPLEMEDIA_H
