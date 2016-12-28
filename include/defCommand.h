#ifndef DEFCOMMAND_H
#define DEFCOMMAND_H
#include "Command.h"
#include "Media.h"
#include <vector>
using namespace std;

class defCommand : public Command
{
    private:
        vector<Media *> *_tmpVector;
        Media *_media;

    public:
        defCommand(vector<Media *> *ms, Media *m);
        void excute();
        void undo();
        void redo();
        virtual ~defCommand();
};

#endif // DEFCOMMAND_H
