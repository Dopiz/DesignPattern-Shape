#ifndef DELETECOMMAND_H
#define DELETECOMMAND_H
#include "Command.h"
#include "Media.h"
#include <vector>
#include <map>
using namespace std;

class deleteCommand : public Command
{
    private:
        vector<Media *> *_tmpVector;
        Media *_media;
        Media *_comboMedia;
        int _mediaNum, _postion;

    public:
        deleteCommand(vector<Media *> *ms, Media *m, int number);
        void excute();
        void undo();
        void redo();
        virtual ~deleteCommand();
};

#endif // DELETECOMMAND_H
