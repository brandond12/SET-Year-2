/*
* FILE : createRandNum.c
* PROJECT : PROG1165 - Assignment 2
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-08
* DESCRIPTION : The file cantains a function to return a random number 
*	between 0 and the constant kmaxGuessNumber defined in proto.h
*/

#include <stdlib.h>
#include <time.h>

#include "proto.h"


/*
*FUNCTION		:	createRanNum
*
*DESCRIPTION		:	This function creates a random number from 0 to the constant kmaxGuessNumber defined in proto.h
*
*PARAMETERS		:	void
*
*RETURNS		:	int randNum		: random number between	0 and kmaxGuessNumber
*
*/
int createRanNum(void){
	int randNum = 0;

	srand(time(NULL));//seed the random function
	randNum = rand() % kmaxGuessNumber;//get ran number between 0 and kmaxGuessNumber

	return randNum;
}