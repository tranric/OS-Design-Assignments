/* Question 4
 * Using pointers to grab a string and removing letters from another string
 * Daniel Sacchetto - Richard Tran
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* method rmstr that will run as in question 3 but this time it will take the letters and it will run as many times as letters has been given characters */
char* rmstr (char* word, char *letters){
	/*for loop that that grabs to word and will run for the lenght of the word*/
	for(int i = 0; i < strlen(word); i++){
		/*if to compare the first letter of word with the second of letters*/
		if(word[i] == letters[0] ){
		int count = 0; 
		/*for loop that will increase the count when the letter and the letter on the word match*/
		for(int j = 0; j < strlen(letters); j++){
			count++;
		}
		/*if statement that will remove the letter if it matches for the duration of the whole word with all the letters provided*/
		if(count == strlen(letters)){
		/*memmove method that will swap the letters as they appear for the duration of the letters */
		memmove(&word[i], &word[i + strlen(letters)], 1 + strlen(word + strlen(word + strlen(letters))) );
		i--;
		}
		}
	}		
	return word;
}
int main(int argc, char** argv){

	char *word = argv[1];
	char *letters = argv[2];

	word = rmstr(word, letters);
	printf("Result '%s' \n", word);
	return 0;
}
