#ifndef MEDIADIRECTOR_H
#define MEDIADIRECTOR_H
#include "CompositeMediaBuilder.h"
#include "SimpleMediaBuilder.h"
#include <stack>

class MediaDirector
{
    private:
        stack<MediaBuilder *> *mb;

    public:
        MediaDirector();
        void setMediaBuilder(stack<MediaBuilder *> *mbs);
        void concrete(string content);
        virtual ~MediaDirector();

};

#endif // MEDIADIRECTOR_H
