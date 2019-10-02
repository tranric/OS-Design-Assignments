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
	
	int pipeFds[2]; 
    char buffer1[100];
    char buffer2[100];
	
	char* src = argv[1];
    char* dst = argv[2];
	

    return 0;
	
}