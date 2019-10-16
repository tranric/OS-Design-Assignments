//Richard Tran and Daniel Sacchetto

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *findAvg(void *arg){
	
	
}

void *findMax(void *arg){
	
	
	
}

void *findMin(void *arg){
	
}



int main(int argc, char *argv[])
{
	//3 threads for each function
	pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
	
	//gets the arguments and saves it into a variable -1 due to
	//calling the file itself being included in arguments to be removed.
	int *numofargs = (int*)malloc((argc-1)*sizeof(int));
	
	
	
}















