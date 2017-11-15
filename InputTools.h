/*Header file for the standard input tools.
*/

#ifndef INPUT_TOOLS_H
#define INPUT_TOOLS_H

//function prototypes
int readInt(const char prompt[]);
double readDouble(const char prompt[]);
char readChar(const char prompt[]);
void readString(const char prompt[], char inputStr[], int maxChar);

#endif