//Question 1
//Armstrong Function
//Create by Richard Tran
//Group Members: Daniel Saccheda and Richard Tran
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//run the compiler with -lm or it will not compile properly
//on some machines since it won't include the math.h sometimes
//eg. gcc 1.1.c -o 1.1.o -lm

//used to prevent messing with the for loop in armstrong number method
//process is the number for the for loop
//digit is the number of digits to look for from the arg1
//pow how it works i forgot and had to relook = pow(base, power)
//note pow uses double must convert to int afterwords
//output is in double for the math.pow method to be more easily
int processArmstrong(int process, int digit){
	double output=0;
	
	while(process){
		//formula to process each digit of the current number for the armstrong formula
		//and processes to the next digit in the number
		double processnumber = pow(process % 10, digit);
		output += processnumber;
		process /= 10;
	}
	//returns the result at the end, converts back to int from the math.pow's double
	return (int) output;
}

//starts with arg1(k) instead of arg0 for less confusion since arg0 is the filename itself
// k is the armstrong number
// p is the second argument (low number from examples (0))
// q is the highest number (3rd arg from examples(600000))
void ArmStrongNumber(int k, int p, int q){
	//runs through each number stops at the largest number which is q
	for(int i=p; i <= q; i++){
	//looks through each number and processes each number with the armstrong formula
	//returns the armstrong number if found
	int armstrong = processArmstrong(i, k);
	//prints armsrong number if found else does nothing
	
		//skips 0 and 1 since they will always count as an armstrong no matter what
		if (i == 0){
			i=2;
		}
		if (i == 1){
			i=2;
		}
		if(armstrong==i){
			printf("%d \n", armstrong);
			
		}
	}
}


//starts with arg1(k) instead of arg0 for less confusion since arg0 is the filename itself
// k is the armstrong number
// p is the second argument (low number from examples (0))
// q is the highest number (3rd arg from examples(600000))
//main method
int main(int argc, char *argv[]){
	
	int k=atoi(argv[1]);
	int p=atoi(argv[2]);
	int q=atoi(argv[3]);
	
	
	ArmStrongNumber(k, p, q);
}