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
    mb = mbs;
}

void MediaDirector::concrete(string content) {

    int i, j;
    string p;

    char *contents = new char[content.size()];
    strcpy(contents, content.c_str());

    for(i = 0; contents[i + 1] != '\0'; ++i)
    {
        switch(contents[i])
        {
            // ComboMedia.
            case 'X': {
                mb->push(new CompositeMediaBuilder);
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
//                    cout << "Circle(" << parameters[0] << ", " << parameters[1] << ", " << parameters[2] << ") \n";
                    Circle c(parameters[0], parameters[1], parameters[2]);
                    mb->top()->buildSimpleMedia(&c);
                }

                else if(contents[i] == 't') {
//                    cout << "Triangle(" << parameters[0] << ", " << parameters[1] << ", " << parameters[2] << ", " << parameters[3] << ", " << parameters[4] << ", " << parameters[5] << ") \n";
                    Triangle t(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], parameters[5]);
                    mb->top()->buildSimpleMedia(&t);
                }

                else if(contents[i] == 'r') {
//                    cout << "Rectangle(" << parameters[0] << ", " << parameters[1] << ", " << parameters[2] << ", " << parameters[3] << ") \n";
                    Rectangle r(parameters[0], parameters[1], parameters[2], parameters[3]);
                    mb->top()->buildSimpleMedia(&r);
                }

                i = j;
                break;
            }

            case ')': {
                Media *cm = mb->top()->getMedia();
                mb->pop();
                mb->top()->buildCompositeMedia(cm);
                break;
            }

            default:
                break;
        }
    }

//    cout << this->mb->top()->getMedia()->description() << endl;
}

MediaDirector::~MediaDirector() {
    //dtor
}
