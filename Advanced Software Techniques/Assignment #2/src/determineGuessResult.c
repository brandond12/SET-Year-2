/*
* FILE : determineGuessResult.c
* PROJECT : PROG1165 - Assignment 2
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-08
* DESCRIPTION : The file cantains a function to determin if the users guess was too high, too low or correct
*/

#include "proto.h"

/*
*FUNCTION		:	determineGuessResult
*
*DESCRIPTION		:	This function determin if the users guess was too high, too low or correct
*
*PARAMETERS		:	int userGuess		: The users guess
*			:	int randNum		: The number the users trying to guess
*
*RETURNS		:	int result		: 0 if correct
*							1 if too high
*							-1 if too low
*
*/

int determineGuessResult(int userGuess, int randNum){
	int result = 0;

	if(userGuess == randNum){//they guess the answer
		result = 0;
	}
	else if(userGuess < randNum){//guess is too low
		result = -1;
	}
	else{
		result = 1;//guess is too high
	}

	return result;
}