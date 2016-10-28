#ifndef TEXTMEDIA_H
#define TEXTMEDIA_H
#include "Media.h"
#include "Rectangle.h"

class TextMedia : public Media
{
    private:
        Rectangle _boundingBox;
        string _text;

    public:
        TextMedia(Rectangle bBox, string text);
        Rectangle getBoundingBox() const;
        void accept(MediaVisitor &v);
        double perimeter() const;
        double area() const;
        string description() const;
        ~TextMedia();
};

#endif // TEXTMEDIA_H
