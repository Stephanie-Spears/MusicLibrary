//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

#include <iostream>
#include <cstring> //c string
#include <cctype> //tolower

#include "UserInterface.h"
#include "InputTools.h"
#include "Song.h"
#include "SongList.h"

using namespace std;
//TODO: clean up unused imports, separate headers and implementations more cleanly
// note for compilation/memleak check
// valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -v /Users/wolfmac/clionprojects/musiclibrary/app
//g++ -Wall *.cpp -o app

int main() {
    //enable memory leak detection tools
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    char command;
    char fileName[] = "/Users/wolfmac/CLionProjects/MusicLibrary/songs.txt";
    SongList list(fileName);
    Song aSong;

    displayMenu();
    command = readInCommand();

    while (command != '6') {
        processCommand(command, list);
        displayMenu();
        command = readInCommand();
    }

    list.saveSongs(fileName);

    return 0;
}