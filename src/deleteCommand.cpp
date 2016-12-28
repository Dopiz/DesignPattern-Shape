#include "deleteCommand.h"

deleteCommand::deleteCommand(vector<Media *> *ms, Media *m, int number)
    : _tmpVector(ms), _media(m), _mediaNum(number) {
    //ctor
}

void deleteCommand::excute() {

    _postion = -1;

    for(Media *m: *_tmpVector) {
        for(Media *mm: *m->getVector()) {
            _postion++;
            if(mm == _media) {
                _comboMedia = m;
                _comboMedia->removeMedia(_media);
                break;
            }
        }
        m->removeMedia(_media);
    }

    _tmpVector->erase(_tmpVector->begin() + _mediaNum);
}

void deleteCommand::undo() {

    _tmpVector->insert(_tmpVector->begin() + _mediaNum, _media);
    if(_postion != -1)
        _comboMedia->getVector()->insert(_comboMedia->getVector()->begin() + _postion, _media);
}

void deleteCommand::redo() {
    this->excute();
}

deleteCommand::~deleteCommand() {
    //dtor
}
