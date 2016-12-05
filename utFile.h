#ifndef UTFILE_H_INCLUDED
#define UTFILE_H_INCLUDED

#include "MyDocument.h"
#include "MediaDirector.h"
#include "DescriptionVisitor.h"
#include "TextUI.h"

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
    CHECK(string("combo(r(0 0 3 2) c(0 0 5) combo(r(0 0 5 4) c(0 0 10) )combo(r(0 1 8 7) c(0 1 10) ))") == doc.openDocument(fileName));
}

TEST (buildMedia, Document)
{
    MyDocument doc;
    string fileName = "myShape.txt";
    MediaDirector direct;

    stack<MediaBuilder *> mbs;
    direct.setMediaBuilder(&mbs);
    direct.concrete(doc.openDocument(fileName));

    DescriptionVisitor dv;
    mbs.top()->getMedia()->accept(dv);
    CHECK(string("combo( r(0, 0, 3, 2) c(0, 0, 5) combo( r(0, 0, 5, 4) c(0, 0, 10) ) combo( r(0, 1, 8, 7) c(0, 1, 10) ) ) ") == dv.getDescription());
}

TEST (InsertMedia, TextUI)
{
    TextUI ui;
    ui.processCommand();
}

#endif // UTFILE_H_INCLUDED
