#ifndef COMMAND_H
#define COMMAND_H

class Command
{
    public:
        Command() {}
        virtual void excute() = 0;
        virtual void undo() = 0;
        virtual void redo() = 0;
        virtual ~Command() {}
};

#endif // COMMAND_H
