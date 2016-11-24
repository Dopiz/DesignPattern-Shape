#include "MyDocument.h"
#include <sys/stat.h>
#include <cstring>

void MyDocument::openFile(const string name) {
    _file.open(name, ios::in);
}

bool MyDocument::canOpenDocument(const string name) {
    struct stat fileStatus;
    bool status = stat(name.c_str(), &fileStatus);

    if(!status)
        return true;
    return false;
}

string MyDocument::readFile() {
    string buffer;
    while(getline(_file, buffer));
    _file.close();

    return buffer;
}

string MyDocument::openDocument(const string name) {
    if(!canOpenDocument(name))
        throw string("file is not existed.");
    openFile(name);
    return readFile();
}
