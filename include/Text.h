#ifndef TEXT_H
#define TEXT_H
#include <iostream>
#include <string>
#include "Rectangle.h"
using namespace std;

class Text
{
    private:
        string _text;
        Rectangle *_bBox;

    public:
        Text(Rectangle *boundingBox, string text);
        Rectangle *getBoundingBox() const;
        string getText() const;
        ~Text();
};

#endif // TEXT_H
