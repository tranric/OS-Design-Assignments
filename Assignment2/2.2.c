//Richard Tran and daniel assignment 2 question 2

#include<stdio.h> 
#include<stdlib.h> 
#include <string.h>
#include <errno.h> 
#include <fcntl.h>
#include <unistd.h>


int main (int argc, char *argv[]) {
	
	//usage ask requirement
	 if (argc != 3) {
      perror("Usage: filecopy.out [source] [destination]. \n");
      exit(1);
    }

	
	
}