//Question 1
//Armstrong Function
//Create by Richard Tran
//Group Members: Daniel Saccheda and Richard Tran
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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
		output += digit;
		process /= 10;
	}
	//returns the result at the end, converts back to int from the math.pow's double
	return (int) output;
}

//starts with arg1 instead of arg0 for less confusion since arg0 is the filename itself
// arg1 is the armstrong number
// arg2 is the second argument (low number from examples (0))
// arg3 is the highest number (3rd arg from examples(600000))
int ArmStrongNumber(int arg1, int arg2, int arg3){
	//runs through each number stops at the largest number which is arg3
	for(int i=arg2; i <= arg3; i++){
	//looks through each number and processes each number with the armstrong formula
	//returns the armstrong number if found
	int armstrong = processArmstrong(i, arg1);
	//prints armsrong number if found else does nothing
		if(armstrong==i){
			printf("%d \n", armstrong);
			
		}
	}
}

//main method
void main(int argc, char *argv[]){
	
	ArmStrongNumber(argv[1], argv[2], argv[3]);
}