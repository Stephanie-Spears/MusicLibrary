/*
Header file for class Song
*/

#ifndef SONG_H
#define SONG_H

const int MAX_CHAR = 50;

class Song
{
public:
	//constructors
	Song();
	/*NOTES:
	should always include an empty parameter (default) constructor.
	the name of the constructor is the same as the name of the class.
	a constructor, even though it is a function, has no type. it is neither value returning, nor void.
	a class can have more than one constructor, however, all constructors of a class must have the same name--but differ in formal parameter lists (either in the number/order/data type of formal parameters)
	constructors execute automatically when a class object enters it's scope. 
	when a constructor executes depends on the types of values passed to the class object when it's declared.*/

	Song(const char title[], const char artist[], const char duration[], const char album[]);
	/* NOTES:
	const as parameters here means that the const variable cannot be modified. Any attempt to modify it will result in a compile-error.
	if you don't want the function to modify the array, you should declare the array in the formal parameter as a constant
	you can pass a variable by reference and still prevent the function from changing it's value by using const in the formal parameter declaration.
	*/

	//destructor
	~Song();

	//accessor functions
	void getTitle(char title[]) const;
	void getArtist(char artist[]) const;
	void getDuration(char duration[]) const;
	void getAlbum(char album[]) const;
	void print() const;
	/*NOTES:
	const at the end of this function specifies that the function cannot modify the member variables of the variable type (class) Song.
	a member function of a class is called a constant function if it's heading has const at the end.
	a constant member function of a class cannot modify the member variables of that class, so these types of functions are called accessor functions. 
	a constant member function of a class can ONLY call other constant member functions of that class. So be careful when you make a member function constant.
	*/

	//mutator functions
	void setTitle(const char title[]); //const as parameters here means that the const char title[] variable can't be modified. If the function attempts to, it'll give a compile-error.
	void setArtist(const char artist[]); //const char artist[] because we don't want the function to modify the array.
	void setDuration(const char duration[]);
	void setAlbum(const char album[]);


private:
	char *title; //pointer variable: a variable whose content is an address (a memory address)
	char *artist; //"&" is the address of operator, it returns the address of its operand (ex: int x; int *p; ...  p = &x;) <- this sets p = to the address of x. So now x and p both refer to the same memory location.
	char *duration;
	char *album;

 /*
 NOTES:
	the "member access operator arrow" is "->" . Access class (or struct) components using the -> operator
	ex:
	class Song
	{
	char title[];
	char artist[];
	};

	Song aSong; //this is an object of type Song
	Song *aSongPointer; //this is a pointer variable of type Song

	aSongPointer = &aSong; //this stores the address of aSong into aSongPointer.

	(*aSongPointer).artist = "artist name"; //this stores "artist name" in the char artist[] component of the object aSong.
	//an equivilent (and less typo-prone) statement to the above:
	aSongPointer->artist = "artist name";


	*/
};

#endif
