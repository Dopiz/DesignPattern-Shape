#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <string>
using namespace std;

class AreaVisitor;
class PerimeterVisitor;

class Media
{
    public:
        virtual void add(Media *m);
        virtual void Accept(AreaVisitor& v);
        virtual void Accept(PerimeterVisitor& v);
        virtual ~Media();
};

#endif // MEDIA_H
