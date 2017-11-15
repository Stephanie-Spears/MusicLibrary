/*
Implementation file for class Song.
*/

#include "Song.h"
#include <iostream>	
#include <cstring>
#include <cctype> //toupper islower

using namespace std;

/* Default constructor. It initializes the Song member objects to a default value.
*/
Song::Song()
{
	//sets the value of title to a dynamic array which is the length of "empty title"
	//(or it can be the length of whatever variable gets passed in), and adds +1
	//to the end to set the last char position to a null terminator (an empty spot signifying the end of the array).

	title = new char[strlen("empty title") + 1];
	strcpy(title, "empty title");
	artist = new char[strlen("empty artist") + 1];
	strcpy(artist, "empty artist");
	duration = new char[strlen("empty duration") + 1];
	strcpy(duration, "empty duration");
	album = new char[strlen("empty album") + 1];
	strcpy(album, "empty album"); //*(destination, source)


	/*
	*NOTE:
	the operator "new" has two forms--
	one to alocate a single variable (new dataType;)
	and one to allocate an array of variables. (new dataType[intExp];)

	the operator "new" allocates memory (a variable) of the designated type and returns a pointer to it--
	meaning it returns the address of this allocated memory. The allocated memory is uninitialized.

	int *p;
	char *q;
	int x;
	p = &x; //the address of x is stored in p. however, no new memory is allocated.

	p = new int; // this statement creates a variable during program execution somewhere in memory and stores the address of the allocated memory in p.
				// the allocated memory is accessed via pointer dereferencing--which would be *p.

	q = new char[16]; //this creates an array of 16 char type components and stores the base address of the array in q.
				//because a dynamic variable is unnamed, it cannot be accessed directly. it is accessed indirectly by the pointer returned by new.


	EX:

	int *p; //p is an int type pointer
	char *name; //name is a char type pointer
	string *str; //str is a string type pointer
	p= new in; //allocates memory of type int and stores the address of the memory into p
	*p= 28; // stores 28 in the allocated memory
	name = new char[5]; //allocates memory for an array of five components of char type, and stores the base address of the array in name
	strcpy (name, "John"); //stores John in name
	str = new string; //allocates memory of type string and stores the address of the memory in str
	*str = "Sunny Day"; //stores the string "Sunny Day" in the memory pointed to by str


	*/
	
}

/* Constructor. It initializes the title/artist/etc with the passed in value.
in: title, artist, duration, album, 
*/
Song::Song(const char title[], const char artist[], const char duration[], const char album[])
{

	//we use "this" pointer name because there's naming conflicts.
	//We have title/artist, etc. passed in as parameters (ie. local variable),
	//and we also have title/artist as the instance data member (below).
	//to differentiate between the two, we use "this->" which is a pointer to the current object (arrows are used to point to class member objects)
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);	//this->title refers to the instance variable "title"
	this->artist = new char[strlen(artist) + 1];
	strcpy(this->artist, artist); //this->artist refers to the instance variable "artist"
	this->duration = new char[strlen(duration) + 1];
	strcpy(this->duration, duration);
	this->album = new char[strlen(album) + 1]; 
	strcpy(this->album, album); //strcpy(destination, source)


	/*
	*Notes:
	A member function of a class can (directly) access the member variables of a given object of that class.
	Sometimes, it is necessary for a member function to refer to the object as a whole, rather than the object's individual member variables.
	Every object of a class  maintains a (hidden) pointer to itself, and the name of this pointer is "this".
	When an object invokes a member function, the member function references the pointer "this" of the object. 

	EX (CH 13, page 893):

	test test::one() //member function "one" of class named "test"
	{
	.
	.
	.
	return *this;
	}

	test x; 
	test y; //x and y are objects of type test.

	y = x.one(); //this copies the value of object x into object y. Meaning that the member variables of x are copied into the corresponding member variables of y.
				//when object x invokes function one, the pointer "this" in the definition of member function one refers to object x, so "this" means the address of x and "*this" means the contents of x.
				//conversely, the following statement...
	x = y.one(); // the pointer "this" in the defintion of the member function "one" refres to the object y, and so "this" means the address of y and "*this" means the contents of y.
				//so the statement copies the contents of object y into object x.
	*/

}

/* Destructor. It releases the dynamic char array allocated for title/artist/duration/album.
*/
Song::~Song()
{	
	if (title != nullptr)
		delete[] title;
	if (artist != nullptr)
		delete[] artist;
	if (duration != nullptr)
		delete[] duration;
	if (album != nullptr)
		delete[] album;

	/*NOTES:
	the constructors get invoked when the objects get created (ie. new char/new int, etc).
	we use constructors to initialize the state of the object.
	DEstructors get invoked when the object's lifetime is over (destructors automatically execute when the class object goes out of scope).
	so when the object goes out of scope, the destructor gets executed for every object of class "Song"
	for every object that we've created with "new," we must delete it with the destructor. 
	if we forget to destroy the "new" objects, we will get memory leaks (ie. space in memory that has been allocated but is inaccessable).
	*/

	/*
	*NOTES:
	A class can have only one destructor, and it has no parameters.
	The name of a destructor is a tilde ~ followed by the class name (with no spaces)

	-suppose that a base class and it's derived class have destructors.
	when a derived class object goes out of scope, it automatically invokes its destructor. 
	when the destructor of the derived class executes, it automatically invokes the destructor of the base class.
	so when writing the defintion of the destructor of the derived class, an explicit call to the 
	destructor of the base class is not needed. 
	-furthermore, when the destructor of the derived class executes first, it executes its own code and
	then calls the desctructor of the base class. 
	EX(from online):

	// Base class
	class Shape  {
	public:
	void setWidth(int w) {
	width = w;
	}

	void setHeight(int h) {
	height = h;
	}

	protected:
	int width;
	int height;
	};

	// Derived class
	class Rectangle: public Shape {
	public:
	int getArea() {
	return (width * height);
	}
	};

	int main(void) {
	Rectangle Rect;

	Rect.setWidth(5);
	Rect.setHeight(7);

	// Print the area of the object.
	cout << "Total area: " << Rect.getArea() << endl;

	return 0;
	}

	*/
}

/* These functions return the title/artist, etc. of the entry through the parameter.
out: title
*/
void Song::getTitle(char title[]) const 
{
	if (islower(this->title[0]))
	{
		this->title[0] = toupper(this->title[0]);
	}
	strcpy(title, this->title); //strcpy(destination, source), so it's taking the member variable "this->title" and copying it into the passed in parameter "title."
								//since the parameter is passed by value, the new value of "title" is updated in main.
}

void Song::getArtist(char artist[]) const
{
	if (islower(this->artist[0]))
	{	this->artist[0] = toupper(this->artist[0]);
	
	}

	strcpy(artist, this->artist);
}

void Song::getDuration(char duration[]) const
{
	strcpy(duration, this->duration);
}

void Song::getAlbum(char album[]) const
{
	if (islower(this->album[0]))
	{
		this->album[0] = toupper(this->album[0]);
	}
	strcpy(album, this->album);
}

/* Prints the state of the object to stdout.
*/
void Song::print() const //const, so it can't change the values it calls, and a const member function can only return a const pointer or reference to a member <- true?
{
	cout << "Title: " << title << endl; //these are the member variables of class Song. They don't need to be passed in because "print()" is a member function, and all member functions have access to one another without needing to specifically pass them in.
	cout << "Artist: " << artist << endl;
	cout << "Duration: " << duration << endl;
	cout << "Album: " << album << endl;
}

/* Sets the title/artist, etc. to the passed in value.
in: title/artist, etc.
*/
void Song::setTitle(const char title[]) //takes the passed in "const char title[]" which we get from the user (after using the InputTools function for readString--to validate that the input is a usable string) OR it takes the title parameter passed in from reading the input file in Songlist::loadSongs(const char fileName[])
{
	if (this->title != NULL) //checks if the class member variable "title" is NOT null, meaning it checks if the mem var is empty. if it's not empty, the body executes 
	{
		delete[] this->title; //frees the memory allocated for the pointer created by the constructor inside Song()... title = new char[strlen("empty title") +1];
	}
	this->title = new char[strlen(title) + 1];
	/*NOTES:
	after making sure "this->title" is empty, it takes the passed in parameter "title" which we get from the user when they want to add a new song, or from reading in an entry from the input file (from the Songlist::loadSong(const char fileName[]) function.)
	and it allocates memory for a new array of pointers that is the length "strlen" of the passed in title, plus one for it to be null terminated (ie for it to have an empty space at the end).
	*/
	strcpy(this->title, title); //strcpy(destination, source) -- copies the passed in variable into the member variable "this->title."
	
}
void Song::setArtist(const char artist[])
{
	if (this->artist != NULL)
	{
		delete[] this->artist;
	}
	this->artist = new char[strlen(artist) + 1];
	strcpy(this->artist, artist);
}

void Song::setDuration(const char duration[])
{
	if (this->duration != NULL)
	{
		delete[] this->duration;
	}
	this->duration = new char[strlen(duration) + 1];
	strcpy(this->duration, duration);
}

void Song::setAlbum(const char album[])
{
	if (this->album != NULL)
	{
		delete[] this->album;
	}
	this->album = new char[strlen(album) + 1];
	strcpy(this->album, album);
}
