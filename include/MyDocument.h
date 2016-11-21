#ifndef MYDOCUMENT_H
#define MYDOCUMENT_H
#include "Document.h"
#include <fstream>

class MyDocument : public Document
{
    private:
        fstream _file;

    protected:
        void openFile(const string name);
        bool canOpenDocument(const string name);
        string readFile();

    public:
        string openDocument(const string name);
};

#endif // MYDOCUMENT_H
