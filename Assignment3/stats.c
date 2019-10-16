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
    for(int i = 0; i < c; i++){
		total = total + pVal[i]
	}
	//as per mean, total divided by number of elements
	avg = (total/c);
	
}

void *findMax(void *arg){
	//same as average function, to get each argument to be saved as a var
	//but to be used to compare instead. 
	int *pVal = (int *) arg;
	
	//saves first value to max for if statement to compare to in for loop
	max = pVal[0];
	
	//just like average runs through all of the elements in the argument list
	for(int i = 0; i < c; i++){
		//the if statement to compare the saved maximum value with the next argument
		//if new value is larger it replaces the spot in the max variable.
		if(pVal[i] > max){
		max = pVal[i];
		}
	}
	
}

void *findMin(void *arg){
	
	//same as max/average function
	int *pVal = (int *) arg;
	
	//saves first value to min for if statement to compare to in for loop
	min = pVal[0];
	
	//just like average runs through all of the elements in the argument list
	for(int i = 0; i < c; i++){
		
		//the if statement to compare the saved maximum value with the next argument
		//if new value is larger it replaces the spot in the min variable. same as max execpt flipping the condition.
		if(pVal[i] < min){
		min = pVal[i];
		}
	}
	
	
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















