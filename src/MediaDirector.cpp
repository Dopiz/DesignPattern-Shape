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

    int i, j;
    Shape *shape;

    char *contents = new char[content.size()];
    strcpy(contents, content.c_str());

    for(i = 0; contents[i] != '\0'; i++)
    {
        switch(contents[i])
        {
            case 'c':
            case 't':
            case 'r':
            {
                // is Combo Media.
                if(contents[i + 1] == 'o') {
                    _mb->push(new CompositeMediaBuilder);
                }

                // is Shape Media.
                else {
                    double parameters[6];
                    int index = 0;
                    bool isNegative = false;
                    string p;

                    for(j = i + 1; contents[j] != ')'; j++) {

                        if(contents[j] == '-')
                            isNegative = true;

                        else if((contents[j] >= '0' && contents[j] <= '9') || contents[j] == '.') {

                            p += contents[j];

                            if(!((contents[j + 1] >= '0' && contents[j + 1] <= '9') || contents[j + 1] == '.')) {
                                double temp = atof(p.c_str());
                                parameters[index++] = isNegative ? -1 * temp : temp;
                                isNegative = false;
                                p.clear();
                            }
                        }
                    }

                    if(contents[i] == 'c')
                        shape = new Circle(parameters[0], parameters[1], parameters[2]);

                    else if(contents[i] == 't')
                        shape = new Triangle(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], parameters[5]);

                    else if(contents[i] == 'r')
                        shape = new Rectangle(parameters[0], parameters[1], parameters[2], parameters[3]);

                    _mb->top()->buildSimpleMedia(shape);
                    i = j;
                }
                break;
            }

            case ')':
            {
                if(_mb->size() > 1) {
                    Media *m = _mb->top()->getMedia();
                    _mb->pop();
                    _mb->top()->buildCompositeMedia(m);
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
