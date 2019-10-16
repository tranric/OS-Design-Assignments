/*Assignment 2 Question 2 Richard Tran / Daniel Sacchetto*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h> 
#include <fcntl.h> 

int main (int argc, char *argv[]) {

    /*
     * File descriptor array.
     * When we create our pipe, we give pipe() this array and it will
     * put the reading[0] and writing[1] file descriptors for the pipe into it.
     */

    int pipeFds[2]; 
    int fileBytesLength;
    char buffer[100];
    char childBuffer[100];
    
    // Check if 3 arguments were supplied.
    if (argc != 3) {
      perror("Filecopy: filecopy.c [target] [destination]. \n");
      exit(1);
    }
    
    char* srcFile = argv[1];
    char* dstFile = argv[2];

    // pipe creation attempt
    if (pipe(pipeFds) < 0) {
      printf("Something went wrong creating the pipe! %s\n", strerror(errno));
      exit(1);
    }

    // switch for the fork that will terminate the process when done
    switch(fork()) {

      // If the child process is wrong or the wrong infomation is provided 
      case -1:
        printf("Error forking child process. %s\n", strerror(errno));
        exit(1);
      
      // Reads the first file and copies it to the second file
      case 0: 
        // ends the pipe
        close(pipeFds[1]);     
        // reads the file from the childbuffer                                                   
        ssize_t num_bytes_child = read(pipeFds[0], childBuffer, sizeof(childBuffer)); 
        // ends the second pipe when done  
        close(pipeFds[0]);                                                        

        // grabs the second files for writing
        int targetDesc = open(dstFile, O_CREAT | O_WRONLY);   
        // writes the content to the new location                                
        write(targetDesc, childBuffer, num_bytes_child);                            
        
      // Read the file and send it down to the child process to write.
      default: 
        // ends the pipe downstream 
        close(pipeFds[0]); 
        // Read file into file descriptor                                             
        int fileInDesc = open(srcFile, O_RDONLY);    
        // Get number bytes to read                   
        ssize_t num_bytes = read(fileInDesc, buffer, sizeof(buffer));
        // child process takes the byte size.   
        write(pipeFds[1], buffer, num_bytes); 
        // closes the downstream.                         
        close(pipeFds[1]);                                              
    }
    return 0;
}