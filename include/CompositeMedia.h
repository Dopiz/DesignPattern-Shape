#ifndef COMPOSITEMEDIA_H
#define COMPOSITEMEDIA_H
#include "Media.h"

class CompositeMedia : public Media
{
    private:
        vector<Media *> _media;
        string _name;

    public:
        CompositeMedia();
        CompositeMedia(vector<Media *> m);
        void setName(string name);
        string getName() const;
        vector<Media *> *getVector();
        void add(Media *m);
        void removeMedia(Media *m);
        void accept(NameVisitor &v);
        void accept(AreaVisitor &v);
        void accept(PerimeterVisitor &v);
        void accept(DescriptionVisitor &v);
        void accept(ShapeVisitor &v);
        double area() const;
        double perimeter() const;
        string description() const;
        ~CompositeMedia();
};

#endif // COMPOSITEMEDIA_H
