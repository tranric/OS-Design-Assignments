//Richard Tran and Daniel Sacchetto

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int c = 0;
int avg = 0;
int max = 0;
int min = 0;

//calculates the average of the numbers
void *findAvg(void *arg){
	//saves each value of each argument to be added
	//to the total to calculate the average
	int *pVal = (int *) arg;
	
	//the total number to be added together for each int to be added into.
    int total = 0;
	
	//the actual function to add all of the argument's numbers together
    for(int i = 0; i < count; i++){
		total = total + pVal[i]
	}
	//as per mean, total divided by number of elements
	avg = (total/count);
	
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















