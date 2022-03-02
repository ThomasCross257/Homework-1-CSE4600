//pipe1a.cpp
// Any modifications made exclusively by Thomas Cross
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{


  FILE *fpi;				//for reading a pipe
  char buffer[BUFSIZ+1];		//BUFSIZ defined in <stdio.h>

  char arg[20]; // Defining array to hold command
  
  int chars_read;
  
  memset (buffer, 0,sizeof(buffer));	//clear buffer

  strcpy(arg, argv[0]); //Copies first letter of command
  for (int i = 1; i < argc; i++) // loops until the argument is has been filled.
  {
    strcat(arg, argv[i]);
  }
  
  fpi = popen (arg, "r");	//pipe to command whatever the user specifies. 

  if (fpi != NULL) {
    //read data from pipe into buffer
    chars_read = fread(buffer, sizeof(char), BUFSIZ, fpi);  
    if (chars_read > 0)
     cout << "Output from pipe: " << buffer << endl;
    pclose (fpi); 			//close the pipe
    return 0; 
  }

  return 1;
}