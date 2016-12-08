#ifndef TEXTUI_H
#define TEXTUI_H
#include "TextUIHeader.h"
class TextUI
{
    private:
        vector<string> _content;
        vector<Media *> _ms;

    protected:
        void processCommand(string instruction);
        void instructionAnalysis(string instruction, char *delim);
        void defineMedia();
        void askProperties();
        void addMedia();
        void deleteMedia();
        void saveFile();
        void loadFile();
        void showMedia();
        int findMedia(string name);

    public:
        TextUI();
        void enterInstruction();
        virtual ~TextUI();
};
#endif // TEXTUI_H
