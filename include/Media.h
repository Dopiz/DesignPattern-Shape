#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <string>
using namespace std;

class AreaVisitor;
class PerimeterVisitor;
class DescriptionVisitor;

class Media
{
    public:
        Media();
        virtual void add(Media *m);
        virtual void accept(AreaVisitor& v);
        virtual void accept(PerimeterVisitor& v);
        virtual void accept(DescriptionVisitor& v);
        virtual ~Media();
};

#endif // MEDIA_H
