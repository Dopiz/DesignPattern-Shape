#ifndef DELETEFROMCOMMAND_H
#define DELETEFROMCOMMAND_H
#include "Command.h"
#include "Media.h"
#include <vector>
#include <map>
using namespace std;

class deleteFromCommand : public Command
{
    private:
        vector<Media *> *_tmpVector;
        Media *_media;
        Media *_comboMedia;
        int _postion;

    public:
        deleteFromCommand(Media *m, Media *cm);
        void excute();
        void undo();
        void redo();
        virtual ~deleteFromCommand();
};

#endif // DELETEFROMCOMMAND_H
