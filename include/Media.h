#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MediaVisitor;

class Media
{
    public:
        Media();
        virtual void setName(string name);
        virtual string getName() const;
        virtual vector<Media *> getVector() const;
        virtual void add(Media *m);
        virtual void removeMedia(Media *m);
        virtual void accept(MediaVisitor& v) = 0;
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual string description() const = 0;
        virtual ~Media();
};

#endif // MEDIA_H
