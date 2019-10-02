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
	
	 switch(fork()) {

      case -1:
		printf("Error forking child process. %s\n", strerror(errno));
		exit(1);

      case 0: 
	  
		close(pipeFds[1]); 
	  
        ssize_t num_bytes_child = read(pipeFds[0], buffer2, sizeof(buffer2));
		
        close(pipeFds[0]);  
		
        int targetDesc = open(dst, O_CREAT | O_WRONLY);
		
        write(targetDesc, buffer2, num_bytes_child);
	  
		
	  default:
	    
		close(pipeFds[0]);
		
        int fileInDesc = open(src, O_RDONLY); 
		
        ssize_t num_bytes = read(fileInDesc, buffer, sizeof(buffer));
		
        write(pipeFds[1], buffer, num_bytes);
		
        close(pipeFds[1]);
	  

	  
    }

    return 0;
	
}