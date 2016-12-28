#ifndef SIMPLEMEDIA_H
#define SIMPLEMEDIA_H
#include "Media.h"
#include "Shape.h"

class SimpleMedia : public Media
{
    private:
        vector<Media *> _tmp;
        Shape *_shape;
        string _name;

    public:
        SimpleMedia();
        SimpleMedia(Shape *s);
        Shape *getShape() const;
        void setName(string name);
        string getName() const;
        vector<Media *> *getVector();
        void accept(NameVisitor &v);
        void accept(AreaVisitor &v);
        void accept(PerimeterVisitor &v);
        void accept(DescriptionVisitor &v);
        void accept(ShapeVisitor &v);
        double area() const;
        double perimeter() const;
        string description() const;
        ~SimpleMedia();
};

#endif // SIMPLEMEDIA_H
