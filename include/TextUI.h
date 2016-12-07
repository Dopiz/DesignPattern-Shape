#ifndef TEXTUI_H
#define TEXTUI_H
#include "TextUIHeader.h"
class TextUI
{
    private:
        vector<string> _content;
        vector<Media *> _ms;

    public:
        TextUI();
        void processCommand();
        void defineMedia();
        void askProperties();
        void addMedia();
        void deleteMedia();
        void saveFile();
        void loadFile();
        void showMedia();
        int findMedia(string name);
        virtual ~TextUI();
};
#endif // TEXTUI_H
