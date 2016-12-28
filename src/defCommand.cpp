#include "defCommand.h"

defCommand::defCommand(vector<Media *> *ms, Media *m)
    : _tmpVector(ms), _media(m) {
    //ctor
}

void defCommand::excute() {
    _tmpVector->push_back(_media);
}

void defCommand::undo() {
    _tmpVector->pop_back();
}

void defCommand::redo() {
    _tmpVector->push_back(_media);
}

defCommand::~defCommand() {
    //dtor
}
