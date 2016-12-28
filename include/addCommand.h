#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H
#include "Command.h"
#include "Media.h"

class addCommand : public Command
{
    private:
        Media *_firstMedia;
        Media *_secondMedia;

    public:
        addCommand(Media *A, Media *B);
        void excute();
        void undo();
        void redo();
        virtual ~addCommand();
};

#endif // ADDCOMMAND_H
