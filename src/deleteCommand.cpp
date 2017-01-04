#include "deleteCommand.h"

deleteCommand::deleteCommand(vector<Media *> *ms, Media *m, int number)
    : _tmpVector(ms), _media(m), _mediaNum(number) {
    //ctor
}

void deleteCommand::excute() {

    int postion = -1;
    for(Media *m: *_tmpVector) {
        for(Media *mm: *m->getVector()) {
            postion++;
            if(mm == _media) {
                _map.insert(pair<Media *, int>(m, postion));
                m->removeMedia(_media);
                postion = -1;
                break;
            }
        }
        m->removeMedia(_media);
    }

    _tmpVector->erase(_tmpVector->begin() + _mediaNum);
}

void deleteCommand::undo() {

    _tmpVector->insert(_tmpVector->begin() + _mediaNum, _media);

    if(!_map.empty()) {
        map<Media *, int>::iterator it;
        for(it = _map.begin(); it != _map.end(); it++) {
            it->first->getVector()->insert(it->first->getVector()->begin() + it->second, _media);
        }
    }
}

void deleteCommand::redo() {
    this->excute();
}

deleteCommand::~deleteCommand() {
    //dtor
}
