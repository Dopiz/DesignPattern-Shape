#include "CommandManager.h"

CommandManager::CommandManager() {
    //ctor
}

void CommandManager::ExecuteCMD(Command *cmd) {
    _redoCmds = stack<Command *>();     // Clear
    cmd->excute();
    _undoCmds.push(cmd);
}

void CommandManager::RedoCMD() {
    if(_redoCmds.empty()) {
        cout << "redoCmds is empty !\n";
        return;
    }
    _redoCmds.top()->redo();
    _undoCmds.push(_redoCmds.top());
    _redoCmds.pop();
}

void CommandManager::UndoCMD() {
    if(_undoCmds.empty()) {
        cout << "undoCmds is empty !\n";
        return;
    }
    _undoCmds.top()->undo();
    _redoCmds.push(_undoCmds.top());
    _undoCmds.pop();
}

CommandManager::~CommandManager() {
    //dtor
}
