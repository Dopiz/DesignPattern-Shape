#include "TestUI.h"
#include "addCommand.h"
#include "defCommand.h"
#include "deleteCommand.h"
#include "deleteFromCommand.h"

TestUI::TestUI() {
    //ctor
}

void TestUI::enterInstruction() {

    string instruction;
    while(instruction != "exit") {
        cout << ":- ";
        getline(cin, instruction);

        if(instruction[0] == 25) {
            cout << "Redo !\n";
            _commandManager.RedoCMD();
        }

        else if(cin.eof()) {
            cin.clear();
            cout << "Undo !\n";
            _commandManager.UndoCMD();
        }

        else if(instruction != "")
            processCommand(instruction);

    }
}

void TestUI::instructionAnalysis(string instruction, char *delim) {

    _content.clear();

    char *str = new char[instruction.size() + 1];
    strcpy(str, instruction.c_str());
    char *token = strtok(str, delim);

    while(token != NULL)
    {
        string temp(token);
        _content.push_back(temp);
        token = strtok(NULL, delim);
    }
}

string TestUI::processCommand(string instruction) {

    instructionAnalysis(instruction, " ={}\"");

    string Case = _content[0];

    if (Case == "show") {
        return this->showMedia();
    }

    else if (Case == "def" && _content.size() >= 3) {
        return this->defineMedia();
    }

    else if (Case == "add" && _content.size() == 4) {
        return this->addMedia();
    }

    else if (Case == "delete" && _content.size() > 1) {
        if(_content.size() == 4)
            this->deleteFromCompositeMedia();

        else if(_content.size() == 2)
            this->deleteMedia();

        return "";
    }

    else if (Case == "save" && _content.size() == 4) {
        this->saveFile();
    }

    else if (Case == "load" && _content.size() == 2) {
        this->loadFile();
    }

    else if (Case.find('?') != string::npos) {
        return this->askProperties();
    }

    else cout << ">> Error: Invalid type !" << endl;
}

string TestUI::defineMedia() {

    string output;
    string mediaName = _content[1];
    string media     = _content[2];

    if(findMedia(mediaName) != -1) {
        cout << "Error: Media is existed !" << endl;
        output = "Error: Media is existed !";
    }

    else {
        char *mediaContent = new char[media.size()];
        strcpy(mediaContent, media.c_str());

        switch(mediaContent[0])
        {
            // Circle, Triangle, Rectangle.
            case 'C':
            case 'T':
            case 'R':
            {
                double parameters[6];
                int index = 0;
                bool isNegative = false;
                string p;

                for(int j = 1; mediaContent[j] != ')'; j++) {

                    if(mediaContent[j] == '-')
                        isNegative = true;

                    else if((mediaContent[j] >= '0' && mediaContent[j] <= '9') || mediaContent[j] == '.') {

                        p += mediaContent[j];

                        if(!((mediaContent[j + 1] >= '0' && mediaContent[j + 1] <= '9') || mediaContent[j + 1] == '.')) {
                            double temp = atof(p.c_str());
                            parameters[index++] = isNegative ? -1 * temp : temp;
                            isNegative = false;
                            p.clear();
                        }
                    }
                }

                Shape *shape;

                if(mediaContent[0] == 'C')
                    shape = new Circle(parameters[0], parameters[1], parameters[2]);

                else if(mediaContent[0] == 'T')
                    shape = new Triangle(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], parameters[5]);

                else if(mediaContent[0] == 'R')
                    shape = new Rectangle(parameters[0], parameters[1], parameters[2], parameters[3]);

                output = media;

                SimpleMediaBuilder smb;
                smb.buildSimpleMedia(shape);
                smb.getMedia()->setName(mediaName);

                Command *cmd = new defCommand(&_ms, smb.getMedia());
                _commandManager.ExecuteCMD(cmd);

//                _ms.push_back(smb.getMedia());
                break;
            }

            // Combo media.
            case 'c':
            {
                CompositeMediaBuilder cmb;
                cmb.getMedia()->setName(mediaName);

                if(_content.size() > 3) {
                    string shape = _content[3];

                    char *str = new char[shape.size()];
                    strcpy(str, shape.c_str());

                    char *delim = " ,";
                    char *token = strtok(str, delim);

                    while(token != NULL)
                    {
                        string temp(token);
                        _content.push_back(temp);

                        int number = findMedia(temp);
                        if(!(number == -1))
                            cmb.buildCompositeMedia(_ms[number]);

                        token = strtok(NULL, delim);
                    }
                }

                Command *cmd = new defCommand(&_ms, cmb.getMedia());
                _commandManager.ExecuteCMD(cmd);

//                _ms.push_back(cmb.getMedia());
                break;
            }
        }
    }

    return output;
}

string TestUI::askProperties() {

    string output;

    instructionAnalysis(_content[0], " .?");

    if(_content.size() > 1) {

        string mediaName = _content[0];
        string content   = _content[1];

        int index = findMedia(mediaName);

        if(index != -1) {

            if(content == "area") {
                output = _ms[index]->area();
                return output;
            }

            else if(content == "perimeter") {
                output = _ms[index]->perimeter();

            }

            else
                output = ">> Error: Invalid type !";
        }

        else
            output = ">> Error: Can not find this media: '" + mediaName + "' !";
    }

    else
        output = ">> Error: Invalid type !";

    return output;
}

string TestUI::addMedia() {

    string output;
    string shape = _content[1];
    string media = _content[3];

    int sNumber = findMedia(shape);
    int mNumber = findMedia(media);

    if(sNumber == -1)
        output = ">> Error: Can not find this media: '" + shape + "' !";

    else if(mNumber == -1)
        output = ">> Error: Can not find this media: '" + media + "' !";

    else if(!(sNumber == -1 || mNumber == -1)) {

        Command *cmd = new addCommand(_ms[sNumber], _ms[mNumber]);
        _commandManager.ExecuteCMD(cmd);

        // _ms[mNumber]->add(_ms[sNumber]);

        output += _ms[mNumber]->getName() + " = ";

        NameVisitor nv;
        _ms[mNumber]->accept(nv);

        output += nv.getName() + " = " + _ms[mNumber]->description();
    }

    return output;
}

void TestUI::deleteMedia() {

    string shape = _content[1];
    int sNumber = findMedia(shape);

    if(sNumber != -1) {
        Command *cmd = new deleteCommand(&_ms, _ms[sNumber], sNumber);
        _commandManager.ExecuteCMD(cmd);
    }

    else cout << ">> Error: Can not find this media !" << endl;

}

void TestUI::deleteFromCompositeMedia() {

    string shape = _content[1];
    string media = _content[3];
    int sNumber = findMedia(shape);
    int mNumber = findMedia(media);

    if(!(mNumber == -1) && !(sNumber == -1)) {
        Command *cmd = new deleteFromCommand(_ms[sNumber], _ms[mNumber]);
        _commandManager.ExecuteCMD(cmd);
    }

    else cout << ">> Error: Can not find this media !" << endl;
}

void TestUI::saveFile() {

    string media = _content[1];
    string fileName = _content[3];

    int index = findMedia(media);

    if(!(index == -1)) {
        string content;

        NameVisitor nv;
        _ms[index]->accept(nv);

        content  = _ms[index]->description() + "\n";
        content += nv.getName();

        fstream file;
        file.open(fileName, ios::out | ios::trunc);

        file.write(content.c_str(), content.size());
        cout << ">> " << media << " saved to " << fileName << endl;

        file.close();
    }

    else
       cout << ">> Error: Can not find this media: '" << media << "' !" << endl;

}

void TestUI::loadFile() {

    fstream file;
    string fileName = _content[1];

    struct stat fileStatus;
    bool status = stat(fileName.c_str(), &fileStatus);
    bool flag = true;

    if(!status) {

        cout << ">> loading " << fileName << " ..." << endl;

        file.open(fileName, ios::in);
        string buffer, buffer2;
        while(getline(file, buffer)) {

            if(flag)
                buffer2 = buffer;

            else
            {
                instructionAnalysis(buffer, " ,{}");

                MediaDirector direct;
                stack<MediaBuilder *> mbs;
                direct.setMediaBuilder(&mbs);
                direct.concrete(buffer2);

                mbs.top()->getMedia()->setName(_content[0]);

                if(findMedia(_content[0]) != -1) {
                    cout << ">> Error: This media '" << _content[0] << "' is existed" << endl;
                    break;
                }

                ShapeVisitor sv;
                mbs.top()->getMedia()->accept(sv);
                int index = sv.getShape().size() - 1;

                for(Media *m: sv.getShape()) {
                        m->setName(_content[index--]);
                        _ms.push_back(m);
                }
            }

            flag = false;
        }

        cout << _ms[findMedia(_content[0])]->getName() << " = " << buffer << " = " << buffer2 << endl;

        file.close();
    }

    else
        cout << ">> Error: file is not existed !" << endl;
}

string TestUI::showMedia() {

    string output;

    for(Media *m: _ms) {
        NameVisitor nv;
        m->accept(nv);
        output += nv.getName() + "\n";
    }

    return output;
}

int TestUI::findMedia(string name) {

    for(int i = 0; i < _ms.size(); i++) {
        if(name.compare(_ms[i]->getName()) == 0)
            return i;
    }

    return -1;
}

TestUI::~TestUI() {
    //dtor
}
