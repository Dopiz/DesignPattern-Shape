#ifndef UTCOMMAND_H_INCLUDED
#define UTCOMMAND_H_INCLUDED
#include "TestUI.h"
#include <string>
using namespace std;

TEST (define_media, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    CHECK(string("cSmall \n") == ui.processCommand("show"));
}

TEST (add_media, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui.processCommand("def cMedia = combo{}");
    ui.processCommand("add cSmall to cMedia");
    CHECK(string("cSmall \ncMedia{ cSmall }\n") == ui.processCommand("show"));
}

TEST (delete_media_1, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui.processCommand("delete cSmall");
    CHECK(string("") == ui.processCommand("show"));
}

TEST (delete_media_2, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui.processCommand("def cMedia = combo{}");
    ui.processCommand("add cSmall to cMedia");
    ui.processCommand("delete cSmall");
    CHECK(string("cMedia{ }\n") == ui.processCommand("show"));
}

TEST (delete_media_from_compositeMeida, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui.processCommand("def cMedia = combo{}");
    ui.processCommand("add cSmall to cMedia");
    ui.processCommand("delete cSmall from cMedia");
    CHECK(string("cSmall \ncMedia{ }\n") == ui.processCommand("show"));
}

TEST (undo_define_media, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui._commandManager.UndoCMD();
    CHECK(string("") == ui.processCommand("show"));
}

TEST (redo_define_media, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui._commandManager.UndoCMD();
    CHECK(string("") == ui.processCommand("show"));
    ui._commandManager.RedoCMD();
    CHECK(string("cSmall \n") == ui.processCommand("show"));
}

TEST (undo_add_media, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui.processCommand("def cMedia = combo{}");
    ui.processCommand("add cSmall to cMedia");
    CHECK(string("cSmall \ncMedia{ cSmall }\n") == ui.processCommand("show"));
    ui._commandManager.UndoCMD();
    CHECK(string("cSmall \ncMedia{ }\n") == ui.processCommand("show"));
}

TEST (redo_add_media, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui.processCommand("def cMedia = combo{}");
    ui.processCommand("add cSmall to cMedia");
    CHECK(string("cSmall \ncMedia{ cSmall }\n") == ui.processCommand("show"));
    ui._commandManager.UndoCMD();
    CHECK(string("cSmall \ncMedia{ }\n") == ui.processCommand("show"));
    ui._commandManager.RedoCMD();
    CHECK(string("cSmall \ncMedia{ cSmall }\n") == ui.processCommand("show"));
}

TEST (undo_delete_media, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui.processCommand("delete cSmall");
    CHECK(string("") == ui.processCommand("show"));
    ui._commandManager.UndoCMD();
    CHECK(string("cSmall \n") == ui.processCommand("show"));
}

TEST (redo_delete_media, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui.processCommand("delete cSmall");
    CHECK(string("") == ui.processCommand("show"));
    ui._commandManager.UndoCMD();
    CHECK(string("cSmall \n") == ui.processCommand("show"));
    ui._commandManager.RedoCMD();
    CHECK(string("") == ui.processCommand("show"));
}

TEST (undo_delete_media_2, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui.processCommand("def cMedia = combo{}");
    ui.processCommand("add cSmall to cMedia");
    ui.processCommand("delete cSmall");
    CHECK(string("cMedia{ }\n") == ui.processCommand("show"));
    ui._commandManager.UndoCMD();
    CHECK(string("cSmall \ncMedia{ cSmall }\n") == ui.processCommand("show"));
}

TEST (redo_delete_media_2, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui.processCommand("def cMedia = combo{}");
    ui.processCommand("add cSmall to cMedia");
    ui.processCommand("delete cSmall");
    CHECK(string("cMedia{ }\n") == ui.processCommand("show"));
    ui._commandManager.UndoCMD();
    CHECK(string("cSmall \ncMedia{ cSmall }\n") == ui.processCommand("show"));
    ui._commandManager.RedoCMD();
    CHECK(string("cMedia{ }\n") == ui.processCommand("show"));
}

TEST (undo_delete_media_from_compositeMedia, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui.processCommand("def cMedia = combo{}");
    ui.processCommand("add cSmall to cMedia");
    ui.processCommand("delete cSmall from cMedia");
    CHECK(string("cSmall \ncMedia{ }\n") == ui.processCommand("show"));
    ui._commandManager.UndoCMD();
    CHECK(string("cSmall \ncMedia{ cSmall }\n") == ui.processCommand("show"));
}

TEST (redo_delete_media_from_compositeMedia, Command)
{
    TestUI ui;
    ui.processCommand("def cSmall = Circle(0,0,1)");
    ui.processCommand("def cMedia = combo{}");
    ui.processCommand("add cSmall to cMedia");
    ui.processCommand("delete cSmall from cMedia");
    CHECK(string("cSmall \ncMedia{ }\n") == ui.processCommand("show"));
    ui._commandManager.UndoCMD();
    CHECK(string("cSmall \ncMedia{ cSmall }\n") == ui.processCommand("show"));
    ui._commandManager.RedoCMD();
    CHECK(string("cSmall \ncMedia{ }\n") == ui.processCommand("show"));
}

#endif // UTCOMMAND_H_INCLUDED
