#include "MediaDirector.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Media.h"
#include <sstream>

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
            case 'C':
            case 't':
            case 'T':
            case 'r':
            case 'R':
            {
                // is Combo Media.
                if(contents[i + 1] == 'o')
                    _mb->push(new CompositeMediaBuilder);

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

//void MediaDirector::concrete(string content){
//
//    for(int i = 0; i < content.size(); ++i) {
//
//        switch(content[i]) {
//
//            case 'c':
//            case 'r':
//            case 't':
//            {
//                // is Combo Media.
//                if(content[i + 1] == 'o') {
//                    _mb->push(new CompositeMediaBuilder);
//                    break;
//                }
//
//                // is Shape Media.
//                else {
//
//                    int left = content.find_first_of('(', i);
//                    int right = content.find_first_of(')', i);
//
//                    Shape *shape;
//                    string parameters = content.substr(left + 1, right - left - 1);
//
//                    vector<double> number;
//                    stringstream ss(parameters);
//
//                    double value;
//                    while(ss >> value) {
//                        number.push_back(value);
//                    }
//
//                    if(content[i] == 'c')
//                        shape = new Circle(number[0], number[1], number[2]);
//
//                    else if(content[i] == 't')
//                        shape = new Triangle(number[0], number[1], number[2], number[3], number[4], number[5]);
//
//                    else if(content[i] == 'r')
//                        shape = new Rectangle(number[0], number[1], number[2], number[3]);
//
//                    _mb->top()->buildSimpleMedia(shape);
//                    i = right;
//                    break;
//                }
//            }
//
//            case ')':
//            {
//                if(_mb->size() > 1) {
//                    Media *m = _mb->top()->getMedia();
//                    _mb->pop();
//                    _mb->top()->buildCompositeMedia(m);
//                }
//            }
//
//            default:
//                break;
//        }
//    }
//}

MediaDirector::~MediaDirector() {
    //dtor
}
