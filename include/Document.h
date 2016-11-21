#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>
#include <string>
using namespace std;

class Document
{
    protected:
        virtual void openFile(const string name) = 0;
        virtual bool canOpenDocument(const string name) = 0;
        virtual string readFile() = 0;

    public:
        string openDocument(const string name) {
            if(!canOpenDocument(name))
                throw string("file is not existed.");
            openFile(name);
            return readFile();
        }
};

#endif // DOCUMENT_H
