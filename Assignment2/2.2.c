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
	//runs if the pipes and forks are not working properly
      case -1:
		printf("Error forking child process. %s\n", strerror(errno));
		exit(1);

      case 0: 
	  //closes pipes for next fork to make sure it does not runthrough again.
		close(pipeFds[1]); 
	  //sets the size and reads the pipe and saves it to the buffer of the child.
        ssize_t num_bytes_child = read(pipeFds[0], buffer2, sizeof(buffer2));
		//closes the second pipe to ensure nothing else is modified
        close(pipeFds[0]);  
		//sets up the stream for writing using the buffer
        int targetDesc = open(dst, O_CREAT | O_WRONLY);
		//writes data to the destination with the size, and data from buffer. to not overwrite with null values.
        write(targetDesc, buffer2, num_bytes_child);
	  
		
	  default:
	    //ensures it is closed from case 0 
		close(pipeFds[0]);
		//sets up the stream in read only to not be edited.
        int fileInDesc = open(src, O_RDONLY); 
		//sets the size of read from buffer and saves it to num of bytes variable
        ssize_t num_bytes = read(fileInDesc, buffer, sizeof(buffer));
		//writes to the second pipe/child process using the buffer
        write(pipeFds[1], buffer, num_bytes);
		//closes the second pipe to ensure all pipes are closed.
        close(pipeFds[1]);
	  

	  
    }

    return 0;
	
}