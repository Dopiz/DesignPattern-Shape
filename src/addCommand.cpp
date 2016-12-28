#include "addCommand.h"

addCommand::addCommand(Media *A, Media *B)
    : _firstMedia(A), _secondMedia(B) {
    //ctor
}

void addCommand::excute() {
    _secondMedia->add(_firstMedia);
}

void addCommand::undo() {
    _secondMedia->removeMedia(_firstMedia);
}

void addCommand::redo() {
    _secondMedia->add(_firstMedia);
}

addCommand::~addCommand() {
    //dtor
}
