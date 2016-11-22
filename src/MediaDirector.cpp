#include "MediaDirector.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Media.h"
#include <cstring>
#include <cstdlib>

MediaDirector::MediaDirector() {
    //ctor
}

void MediaDirector::setMediaBuilder(stack<MediaBuilder *> *mbs) {
    _mb = mbs;
}

void MediaDirector::concrete(string content) {

    int i, j, flag = 0;
    string p;
    Media *cm;

    char *contents = new char[content.size()];
    strcpy(contents, content.c_str());

    for(i = 0; contents[i] != '\0'; ++i)
    {
        switch(contents[i])
        {
            // ComboMedia.
            case 'X': {
                ++flag;
                _mb->push(new CompositeMediaBuilder);
                break;
            }

            // SimpleMedia.
            case 'c':
            case 't':
            case 'r':
            {
                int parameters[6];
                int index = 0;
                p.clear();

                for(j = i; contents[j] != ')'; ++j) {
                    if(contents[j] >= '0' && contents[j] <= '9') {
                        p += contents[j];
                        if(!(contents[j + 1] >= '0' && contents[j + 1] <= '9')) {
                            parameters[index++] = atoi(p.c_str());
                            p.clear();
                        }
                    }
                }

                if(contents[i] == 'c') {
                    Circle *c = new Circle(parameters[0], parameters[1], parameters[2]);
                    _mb->top()->buildSimpleMedia(c);
                }

                else if(contents[i] == 't') {
                    Triangle *t = new Triangle(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], parameters[5]);
                    _mb->top()->buildSimpleMedia(t);
                }

                else if(contents[i] == 'r') {
                    Rectangle *r = new Rectangle(parameters[0], parameters[1], parameters[2], parameters[3]);
                    _mb->top()->buildSimpleMedia(r);
                }

                i = j;
                break;
            }

            case ')': {
                if(--flag) {
                    cm = _mb->top()->getMedia();
                    _mb->pop();
                    _mb->top()->buildCompositeMedia(cm);
                }

                break;
            }

            default:
                break;
        }
    }
}

MediaDirector::~MediaDirector() {
    //dtor
}
