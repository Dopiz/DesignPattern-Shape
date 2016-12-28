#ifndef TESTUI_H
#define TESTUI_H
#include "TextUIHeader.h"
#include "CommandManager.h"
#include <string>
using namespace std;

class TestUI
{
    private:
        vector<string> _content;
        vector<Media *> _ms;

    protected:
        void instructionAnalysis(string instruction, char *delim);
        string defineMedia();
        string askProperties();
        string addMedia();
        void deleteMedia();
        void deleteFromCompositeMedia();
        void saveFile();
        void loadFile();
        int findMedia(string name);

    public:
        CommandManager _commandManager;
        TestUI();
        void enterInstruction();
        string processCommand(string instruction);
        string showMedia();
        virtual ~TestUI();
};
#endif // TESTUI_H
