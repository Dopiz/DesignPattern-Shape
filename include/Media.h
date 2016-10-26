#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <string>
using namespace std;

class MediaVisitor;

class Media
{
    public:
        Media();
        virtual void add(Media *m);
        virtual void accept(MediaVisitor& v);
        virtual double area() const;
        virtual double perimeter() const;
        virtual string description() const;
        virtual ~Media();
};

#endif // MEDIA_H
