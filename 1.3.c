/*
Question 3 - 
(2 points) Using pointers and avoiding unnecessary local variables, write a function, rmchr
that takes a string and a character as command line arguments. The rmchr function should
remove all occurrences of the character from the string. The rmchr function should not leave
spaces characters in the string where characters have been removed. The resulting string
should be returned using an appropriate data type and printed to the command line.
*/

//Group Members: Daniel Saccheda and Richard Tran

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//remove character method
//checks each character of the string for the second (3rd) argument for the same matching character.
//and removes the matching character and returns the new string output.
char *str;

char* rmchr(char* string, char* character) 
{
	
	 for (int i = 0; i < strlen(string); i++) {
		  while(character[0] == string[i]) {
			  for(int j = i; j < strlen(string); j++){
			  string[j]= string[j + 1];
			  }				
	 }
	 }
	 return string;	
}
//main just calls the method and returns the new string
int main(int argc, char** argv){

	str = argv[1];
	char *c = (char*) argv[2];
    char *str2 = rmchr(str, c);
	//added new line because it prints on same line as command is run.
    printf("\n%s\n", str2);
    
    return 0;
}
