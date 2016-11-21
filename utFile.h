#ifndef UTFILE_H_INCLUDED
#define UTFILE_H_INCLUDED

#include <MyDocument.h>
#include <MediaDirector.h>

TEST (openDocFail, Document)
{
    MyDocument doc;
    string fileName = "notExistedFile.txt";

    try {
        doc.openDocument(fileName);
        FAIL("Should not be here!");
    } catch(string s) {
        CHECK(string("file is not existed.") == s);
    }
}

TEST (openDoc, Document)
{
    MyDocument doc;
    string fileName = "myShape.txt";
    CHECK(string("X( r(0, 0, 3, 2) c(0, 0, 5) X( r(0, 0, 5, 4) c(0, 0, 10) ) X( r(0, 1, 8, 7) c(0, 1, 10) ) ) ") == doc.openDocument(fileName));
}

TEST (buildMedia, Document)
{
    MyDocument doc;
    string fileName = "test.txt";
    MediaDirector direct;

    stack<MediaBuilder *> mb;
    direct.setMediaBuilder(&mb);
    direct.concrete(doc.openDocument(fileName));

//    mb.top()->getMedia()->description();
    /*
    **  pure virtual method called
    **  terminate called without an active exception
    **  This application has requested the Runtime to terminate it in an unusual way.
    **  Please contact the application's support team for more information.
    */

}

#endif // UTFILE_H_INCLUDED
