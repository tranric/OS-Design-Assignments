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
		total = total + pVal[i];
	}
	//as per mean, total divided by number of elements
	avg = (total/c);
	
	
	//need to close the created thread when method is called
	pthread_exit(0);
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
	
	//need to close the created thread when method is called
	pthread_exit(0);
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
	
	//need to close the created thread when method is called
	pthread_exit(0);
	
}



int main(int argc, char *argv[])
{
	//3 threads for each function
	pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
	
	//The array that holds the value, gets size from the number of arguments / argc / argument count -1 due to 
	//calling the file itself being included in arguments to be removed.
	int *numofargs = (int*)malloc((argc-1)*sizeof(int));
	

	for(int i = 1; i < argc; i++){
		
		//gets the arguments and saves it into a variable -1 due to
		//calling the file itself being included in arguments to be removed.
        numofargs[i-1] = strtol(argv[i],NULL,0);
		
		//adds it to c which is the counter for the other functions.
        c++;
        
    }
	//creates the threads and calls the cooresponding method for each thread.
	pthread_create(&thread1,NULL,findAvg,(void*)numofargs);
    pthread_create(&thread2,NULL,findMax,(void*)numofargs);
    pthread_create(&thread3,NULL,findMin,(void*)numofargs);
	
	//joins all of the threads together. 
	pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);    
    pthread_join(thread3,NULL);
	
	//prints the results same as report standards
	printf("Average value is\n%d\n", avg);
    printf("Minimum value is\n%d\n", min);
    printf("Maximum value is\n%d\n", max);
	
	exit(0);
	
}















