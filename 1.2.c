/* Question 2
 * Euler-phi function
 * Daniel Sacchetto - Richard Tran
 * 2019-09-10
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//checks if its prime by running through until it equals 0
int isprime(int a, int b){
	if (a==0){
		return b;
	}
	return isprime(b%a,a);
}

int phi(int a){
	//starts at 2 since 1 is always included
	int number =1; 
	for (int i = 2; i < a; i++){		
		if (isprime(i,a)==1)
			number++;
	}
	return number;		
}



int main(int argc, char *argv[]){
	
		int arglist = 0;
	
	//argc contains the number of arguments
	//to know how many times to call the phi method to
	//process each arg
	//starts at 1 because 0 is the file name
	for (int  i = 1; i < argc; i++){
		
		
		arglist = atoi(argv[i]);
		printf("The number of primes for %d is %d\n",arglist,phi(arglist));
		
		
	}
	
	
	
}
