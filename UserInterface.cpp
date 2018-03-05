#include "UserInterface.h"

#include <iostream>

using namespace std;

void displayMenu() {
	cout << endl;
	cout << "Music Library" << endl << endl;
	cout << "1) Display all songs" << endl;
	cout << "2) Add new song" << endl;
	cout << "3) Remove song" << endl;
	cout << "4) Search song by artist" << endl;
	cout << "5) Search song by album" << endl;
	cout << "6) Save all and Quit" << endl << endl;

}

/*this function reads in the user's choice. */
char readInCommand() {
	char cmd;

	cmd = readChar(const_cast<char *>("Enter Menu Option: "));
	cout << endl;

	return (cmd);
}


/* This function processes the command passed in.
in: command
in/out: list and listSize
*/
void processCommand(char command, SongList& list) {
	Song song;
	Song deleteSong;
//	char title[MAX_CHAR];
	char artist[MAX_CHAR];
//	char duration[MAX_CHAR];
	char album[MAX_CHAR];
	int index;

	switch (command) {
	case '1': list.printAll();
		break;
	case '2': readInSong(song);
		list.addSong(song);
		break;
	case '3': index = readIndex();
			list.removeSong(index, deleteSong, song);
		break;
	case '4': readSearchArtist(artist);
		if (list.searchArtist(artist, song)) {
		//	song.getTitle(title);
		//	song.getArtist(artist);
		//	song.getDuration(duration);
		//	song.getAlbum(album);
		}
		else {
			cout << endl << "Seach Complete." << endl << endl;
		}
		break;

	case '5': readSearchAlbum(album);
		if (list.searchAlbum(album, song)) {
		//	cout << "test" << endl;
		//	song.getTitle(title);
		//	song.getArtist(artist);
		//	song.getDuration(duration);
		//	song.getAlbum(album);
			
		}
		else {
			cout << endl << "Seach Complete." << endl << endl;
		}
		break;

	default: cout << endl << "Invalid input." << endl;
		break;
	}
}

/*
this function reads in a song.
out: aSong
*/
void readInSong(Song& aSong) {
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];

	//read in song details
	readString("Song Title: ", title, MAX_CHAR);
	readString("Artist Name: ", artist, MAX_CHAR);
	readString("Song Duration: ", duration, MAX_CHAR);
	readString("Album Title: ", album, MAX_CHAR);

	//could put my tolower functions here maybe

	//populate the passed in object
	aSong.setTitle(title);
	aSong.setArtist(artist);
	aSong.setDuration(duration);
	aSong.setAlbum(album);
}

void readSearchArtist(char artist[]) {
	readString("Enter the Artist name you'd like to search for: ", artist, MAX_CHAR); 
}

void readSearchAlbum(char album[]) {
	//if (album != nullptr)
	readString("Enter the Album name you'd like to search for: ", album, MAX_CHAR);
}

int readIndex() {
	int index; 
	
	index = readInt("Enter the song index you'd like to remove: ");
	
	return index;
}