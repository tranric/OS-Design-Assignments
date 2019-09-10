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



//main just calls the method and returns the new string
int main (int argc, char*argv[]) {

    str = rmchr(argv[1], argv[2]);
    printf("%s", str);

    return 0;
}


