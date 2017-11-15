/*Implementation file for InputTools.h.
*/
#include "InputTools.h"
#include <iostream>
using namespace std;

/* Reads an integer from the standard input and throws away the rest of the input line
in: prompt
return: a legal integer
*/
int readInt(const char prompt[])
{
	int		intVal;

	//prompt user for input
	cout << endl << prompt;
	cin >> intVal;

	//check if a valid integer is entered
	while (!cin)
	{
		//clear the error code for cin so that it can work again
		cin.clear();

		//throw away the garbage entered, e.g "None of your business."
		cin.ignore(100, '\n');

		//kindly ask again
		cout << "You've entered an illegal integer. Please try again: ";
		cin >> intVal;
	}

	//throw the rest of the line away, e.g. "99 Yippeeeeeee!"
	cin.ignore(100, '\n');

	return intVal;
}

/* Reads a double from the standard input and throws away the rest of the input line.
in: prompt
return: a legal double
*/
double readDouble(const char prompt[])
{
	double		doubleVal;

	//prompt user for input
	cout << endl << prompt;
	cin >> doubleVal;

	//check if a valid double is entered
	while (!cin)
	{
		//clear the error code for cin so that it can work again
		cin.clear();

		//throw away the garbage entered, e.g "None of your business."
		cin.ignore(100, '\n');

		//kindly ask again
		cout << "You've entered an illegal floating point value. Please try again: ";
		cin >> doubleVal;
	}

	//throw the rest of the line away, e.g. "99 Yippeeeeeee!"
	cin.ignore(100, '\n');

	return doubleVal;
}

/* Reads a char from the standard input and throws away the rest of the input line.
in: prompt
return: a char
*/
char readChar(const char prompt[])
{
	char aChar;

	cout << endl << prompt;

	//ignore any leading spaces
	cin >> aChar;

	//throw away the rest of the line
	cin.ignore(100, '\n');

	return aChar;
}


/* Reads a c-string from the standard input and throws away the rest of the input line.
in: prompt
maxChar: at most maxChar-1 characters can be stored. The rest of the input will be discarded.
out: inputStr
return: none
*/
void readString(const char prompt[], char inputStr[], int maxChar)
{
	cout << endl << prompt;

	//read until it either reaches the maxChar limit or encounters a '\n'
	cin.get(inputStr, maxChar, '\n');
	while (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl << prompt;
		cin.get(inputStr, maxChar, '\n');
	}

	//throw away the '\n'
	cin.ignore(100, '\n');
}