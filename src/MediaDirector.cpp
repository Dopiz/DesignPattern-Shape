#include "MediaDirector.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Media.h"
#include <sstream>

MediaDirector::MediaDirector() {
    //ctor
}

void MediaDirector::setMediaBuilder(stack<MediaBuilder *> *mbs) {
    _mb = mbs;
}

void MediaDirector::concrete(string content){

    for(int i = 0; i < content.size(); ++i) {
        switch(content[i]) {
            case 'c':
            case 'r':
            case 't':
            {
                // is Combo Media.
                if(content[i + 1] == 'o') {
                    _mb->push(new CompositeMediaBuilder);
                }

                // is Shape Media.
                else {
                    int left = content.find_first_of('(', i);
                    int right = content.find_first_of(')', i);

                    Shape *shape;
                    string parameters = content.substr(left + 1, right - left - 1);

                    vector<double> number;
                    stringstream ss(parameters);

                    double value;
                    while(ss >> value) {
                        number.push_back(value);
                    }

                    if(content[i] == 'c')
                        shape = new Circle(number[0], number[1], number[2]);

                    else if(content[i] == 't')
                        shape = new Triangle(number[0], number[1], number[2], number[3], number[4], number[5]);

                    else if(content[i] == 'r')
                        shape = new Rectangle(number[0], number[1], number[2], number[3]);

                    _mb->top()->buildSimpleMedia(shape);
                    i = right;
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
            }

            default:
                break;
        }
    }
}

MediaDirector::~MediaDirector() {
    //dtor
}
