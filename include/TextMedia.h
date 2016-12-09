#ifndef TEXTMEDIA_H
#define TEXTMEDIA_H
#include "Media.h"
#include "Text.h"

class TextMedia : public Media
{
    private:
        Text *_text;

    public:
        TextMedia();
        TextMedia(Text *t);
        void accept(NameVisitor &v);
        void accept(AreaVisitor &v);
        void accept(PerimeterVisitor &v);
        void accept(DescriptionVisitor &v);
        void accept(ShapeVisitor &v);
        double perimeter() const;
        double area() const;
        string description() const;
        ~TextMedia();
};

#endif // TEXTMEDIA_H
