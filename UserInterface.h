#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "Song.h"
#include "SongList.h"
#include "InputTools.h"

void displayMenu();
int readInCommand(); 
void processCommand(char command, SongList& list);
void readInSong(Song& aSong);
int readIndex(); //should i make this void?
void readSearchArtist(char artist[]);
void readSearchAlbum(char album[]);

#endif
