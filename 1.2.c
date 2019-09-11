/* Question 2
 * Euler-phi function
 * Daniel Sacchetto - Richard Tran
 * 2019-09-10
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//checks if its coprime by running through until it equals 0
int isprime(int a, int b){
	if (a==0){
		return b;
	}
	return isCoprime(b%a,a);
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
	
	
	
	
	
}
