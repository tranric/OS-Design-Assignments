/* Question 4
 * Using pointers to grab a string and removing letters from another string
 * Daniel Sacchetto - Richard Tran
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 
method rmstr that will run as in question 3 but this time it will take the letters 
and it will run as many times as letters has been given characters 
*/
char* rmstr (char* word, char *letters){
	int count = 0;
	//takes the length of the word to run throuh
	for(int i = 0; i < strlen(word); i++){
		//loop for replacing the letters in the world
		while(letters[count] == word[i]){
			//the if statement for tigger to know when to replace letters
			if(letters[count] == word[i]){
				//loops once again for each letter to loop once more through the word for each letter
			for(int j = i; j <strlen(word); j++){
				word[j] = word[j + 1];
				//prints the result
				printf("%s \n", word);
			}
			//increases count for exiting loop and going into the next letter for removal
			count++;
		}
		}
	}
	return word;
}

int main(int argc, char** argv){
	//conversion for args to variables to make it more easy to read
	char *word = argv[1];
	char *letters = argv[2];
	//runs the method
	word = rmstr(word, letters);
	//prints the resulting word for after removing the letters requested in the arg2
	printf("Result '%s' \n", word);
	return 0;
}
