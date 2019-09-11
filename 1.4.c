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
	int count = 0;

	for(int i = 0; i < strlen(word); i++){
		while(letters[count] == word[i]){
			if(letters[count] == word[i]){
			for(int j = i; j <strlen(word); j++){
				word[j] = word[j + 1];
				printf("%s \n", word);
			}
			count++;
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
