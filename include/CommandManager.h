#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H
#include "Command.h"
#include <iostream>
#include <stack>
using namespace std;

class CommandManager
{
    private:
        stack<Command *> _undoCmds;
        stack<Command *> _redoCmds;

    public:
        CommandManager();
        void ExecuteCMD(Command *cmd);
        void RedoCMD();
        void UndoCMD();
        virtual ~CommandManager();

};

#endif // COMMANDMANAGER_H
