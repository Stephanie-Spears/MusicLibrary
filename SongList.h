/*
Header file for class SongList.
*/

#ifndef SONGLIST_H //basically says that if this headerfile isn't defined already, than include the following definition. It guards against redundancy (defining the same file multiple times)
#define SONGLIST_H

#include "Song.h" //includes the headerfile for class Song so that we can use it in class Songlist

class SongList
{
public:
	//constructors
	SongList(); //default
	SongList(const char fileName[]); //with parameters (fileName[] is the path of the file to be opened and read.)

	//destructor
	~SongList();

	//accessor functions
	bool get(int index, Song &deleteSong, Song& aSong) const;
	bool searchArtist(const char artist[], Song& match) const; //SHOULD OVERLOAD FUNCTION? INSTEAD OF DIFF SEARCH FUNCTION NAMES, JUST "search" with different parameter lists to indicate which overloaded version of the functino is being called...but these both take identical formal parameter lists, so won't work without fixing that
	bool searchAlbum(const char album[], Song& match) const;
	int getSize() const;
	void printAll() const;
	void saveSongs(const char fileName[]) const;

	//mutator functions
	void addSong(const Song& aSong);
	void addSortedSong(const Song& aSong);
	void removeSong(int index, Song& deleteSong, Song& aSong);
	void loadSongs(const char fileName[]);

private:
	struct Node 
	{
		Song data; //info to be stored
		Node * next; //link which is a pointer to the "next" address in the node list
		Node * back; //link (pointer) to the previous link's memory address.
		Node(const Song& aData) //
		{
			char title[MAX_CHAR];
			char artist[MAX_CHAR];
			char duration[MAX_CHAR];
			char album[MAX_CHAR];
		
			aData.getTitle(title);
			aData.getArtist(artist);
			aData.getDuration(duration);
			aData.getAlbum(album);


			data.setTitle(title);
			data.setArtist(artist);
			data.setDuration(duration);
			data.setAlbum(album);

		}

	};
	Node * first; //pointers 
	Node * last;

	int count;
};
#endif	

/*NOTES
A linked list is a collection of components called NODES. Every node EXCEPT the LAST one contains the address of the NEXT node. 
		Thus, every node in a linked list has two components: one to store data, and one to store the address (called the LINK) of the NEXT node in the list.
		The address of the FIRST node in the list is stored in a separate location called HEAD or FIRST.

		head->info .. the arrow indicates that the address of the node to which it is pointing is stored in that node.
		if head's address is "2000" and the info stored is "17", then the statement head->info will equal "17"--because head's address (2000) is pointing to the data stored there ("17").

		Because each node of a linked list has two components (info/data and the link which points to the address of that info/data),
		we need to declare each node as a CLASS or STRUCT. 
		*/