/* 
* Ethan Trott
* COS235 - HW2
* Spring 2020
*
* a utility to convert between bases using the Quotient/Remainder method
*/

#include <stdio.h>
#include <math.h>

int main(){
	printf("Base Converter\n");
	printf("by Ethan Trott\n\n");
	
	int input;							//stores the entered base 10 value
	int done = 0;						//controls when loop terminates
	
	//the bases that can be converted to
	const int allowedBases[5] = {2, 3, 4, 8, 16};
	
	while(!done){						//until the user inputs -1
		printf("Enter the number you'd like to convert (b10): ");
		
		//get input and check if it's valid
		if (scanf("%d", &input) && (input >= -1)){
			if (input == -1) done = 1;	//end if -1 is entered
			else{
				int base = -1;			//stores the desired base
				
				//get desired base and check if it's valid
				int temp;
				while (base == -1){
					printf("\nEnter the base you'd like to convert to: ");
					if (scanf("%d", &temp)){
						
						//check if the entered base is allowed
						for (int i=0; i<5; i++)
							if (allowedBases[i] == temp) base = temp;
						
						if (base == -1)	//incorrect base was entered
							printf("You may choose from bases 2, 3, 4, 8, or 16.\n");
					}else{
						printf("Please enter an integer value.\n");
						while (getchar() != '\n');		//clear the input buffer
					}
				}
				
				//convert input to the new base
				
				int digits[32];							//hold converted digits
														//32 is the most we'll need
				int digitsCompleted = 0;
				
				temp = input;							//our initial dividend is input
				
				//keep calculating new digits until there are none left
				//or we run out of space in our array
				while (temp != 0){
					//store the remainder
					digits[digitsCompleted] = temp % base;
					
					//get next value to divide
					temp = temp / base;
					
					digitsCompleted++;
				}
				
				//print output
				printf("The value of %d in base %d is ", input, base);
				
				//print each digit
				for (int i=digitsCompleted-1; i>=0; i--)
					//if the digit is >10 convert to character (for hex)
				
					if (digits[i] < 10)
						printf("%d", digits[i]);
					else
						printf("%c", digits[i]-10 + 65);
				
				printf(".\n");
			}
		}
		else{
			printf("Please enter a non-negative integer value in base 10.\n");
		}
		
		printf("\n");
		while (getchar() != '\n');		//clear the input buffer
	}
	
	return 0;
}