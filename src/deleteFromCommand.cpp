#include "deleteFromCommand.h"

deleteFromCommand::deleteFromCommand(Media *m, Media *cm)
    : _media(m), _comboMedia(cm) {
    //ctor
}

void deleteFromCommand::excute() {

    _postion = -1;
    for(Media *m: *_comboMedia->getVector()) {
        _postion++;
        if(m == _media) {
            _comboMedia->removeMedia(_media);
            break;
        }
    }
}

void deleteFromCommand::undo() {
    _comboMedia->getVector()->insert(_comboMedia->getVector()->begin() + _postion, _media);
}

void deleteFromCommand::redo() {

    _postion = 0;
    for(Media *m: *_comboMedia->getVector()) {
        _postion++;
        if(m == _media) {
            _comboMedia->removeMedia(_media);
            break;
        }
    }
}

deleteFromCommand::~deleteFromCommand()
{
    //dtor
}
