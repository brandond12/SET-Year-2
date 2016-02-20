/*
* FILE : getAndValidateUserGuess.c
* PROJECT : PROG1165 - Assignment 2
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-08
* DESCRIPTION : The file cantains a function to get the users input and validate 
*	it is a number between 0 and the defined constant kmaxGuessNumber
*/

#include <stdio.h>

#include "proto.h"


/*
*FUNCTION		:	getAndValidateUserGuess
*
*DESCRIPTION		:	This function get user input and validates it is a int between 0 and the defined constant kmaxGuessNumber
*
*PARAMETERS		:	void
*
*RETURNS		:	int userInput		: user inputed int
*							-1 if not valid
*
*/

int getAndValidateUserGuess(void){
	char buffer[127] = "";
	int userInput = 0;

	printf("Please enter your guessbetween 0 and %d: \n",  kmaxGuessNumber);
	fgets(buffer, 126, stdin);		//get input
	if (sscanf(buffer, "%d", &userInput) == 1){//got a int input
		if(userInput > kmaxGuessNumber || userInput < 0){//out of range
			userInput = -1;
			printf("Input out of range\n");
		}
	}
	else{//didn't get an int input
		userInput = -1;
		printf("Must input a number\n");
	}
return userInput;
}
