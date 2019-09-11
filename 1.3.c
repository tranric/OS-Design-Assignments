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
char* rmchr(char* string, char* character) {
	//int stringlength = strlen(string);
	//gets the length of the string as the maximum of the for loop to not break the program
	//while(string != '\0'){
		jumppoint:
	 for (int i = 0; i < strlen(string); i++) {
		 //printf("for loop: i is location: %d\n letter of string is:%c \n", i, string[i]);
		 
		 //if character is found remove character at location
		  if (character[0] == string[i]) {
			  //https://www.tutorialspoint.com/c_standard_library/c_function_memmove.htm
			  //how memmove works above (note for self ~richard)
			  
			  //takes source string and shift the string from the part it found the 
			  //character over one. replacing all of the old letters with the next 
			  //character over, repeats until end of character.
			  memmove(&string[i], &string[i + 1], strlen(string));
			  //due to the current i now a new letter it needs to be rechecked in the for loop
			  //thus moving one back again to recheck before adding another ++ to i.
			  //since it was shifted over to the left once.
				//printf("i is location: %d\n letter of string is:%c \n", i, string[i]);
			    
				/*
				for(int x=0; x <stringlength; x++){
						string[i]=string[i+1];
				}
				*/
				i--;
				//string[i-1];
				//stringlength--;
				//printf("i is location: %d\n letter of string is:%c \n", i, string[i]);
				goto jumppoint;
		 }
	
	}
	//}
	 //original string is overwritten in the for loop returning the modified string (will need to change for 
	 //question 4)
	 return string;	
}

//main just calls the method and returns the new string
int main(int argc, char** argv){

    char *str = rmchr(argv[1], argv[2]);
	//added new line because it prints on same line as command is run.
    printf("%s\n", str);

    return 0;
}


