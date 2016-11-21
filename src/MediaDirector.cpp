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
    string number;

    char *contents = new char[content.size()];
    strcpy(contents, content.c_str());

    for(i = 0; contents[i + 1] != '\0'; ++i)
    {
        switch(contents[i])
        {
            case 'X': {
                mb->push(new CompositeMediaBuilder);
                break;
            }

            case 'c':
            case 't':
            case 'r':
            {
                int parameter[6];
                int index = 0;
                number.clear();

                for(j = i; contents[j] != ')'; ++j) {
                    if(contents[j] >= '0' && contents[j] <= '9') {
                        number += contents[j];
                        if(contents[j + 1] == ',' || contents[j + 1] == ')') {
                            parameter[index++] = atoi(number.c_str());
                            number.clear();
                        }
                    }
                }

                if(contents[i] == 'c') {
//                    cout << "Circle(" << parameter[0] << ", " << parameter[1] << ", " << parameter[2] << ") \n";
                    Circle c(parameter[0], parameter[1], parameter[2]);
                    mb->top()->buildSimpleMedia(&c);
                }
                else if(contents[i] == 't') {
//                    cout << "Triangle(" << parameter[0] << ", " << parameter[1] << ", " << parameter[2] << ", " << parameter[3] << ", " << parameter[4] << ", " << parameter[5] << ") \n";
                    Triangle t(parameter[0], parameter[1], parameter[2], parameter[3], parameter[4], parameter[5]);
                    mb->top()->buildSimpleMedia(&t);
                }
                else if(contents[i] == 'r') {
//                    cout << "Rectangle(" << parameter[0] << ", " << parameter[1] << ", " << parameter[2] << ", " << parameter[3] << ") \n";
                    Rectangle r(parameter[0], parameter[1], parameter[2], parameter[3]);
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

    cout << mb->size() << endl;
}

MediaDirector::~MediaDirector() {
    //dtor
}
