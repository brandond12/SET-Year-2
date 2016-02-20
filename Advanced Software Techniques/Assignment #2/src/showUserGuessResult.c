/*
* FILE : showUserGuessResult.c
* PROJECT : PROG1165 - Assignment 2
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-08
* DESCRIPTION : The file cantains a function to show the user if their guess was to high, to low or correct
*/

#include <stdio.h>

#include "proto.h"

/*
*FUNCTION		:	showUserGuessResult
*
*DESCRIPTION		:	This function shows the user if their guess was to high, to low or correct
*
*PARAMETERS		:	int result		:	0 - correct
*								1 - to high
*								-1 - to low
*
*RETURNS		:	void
*
*/

void showUserGuessResult(int result){
	switch (result){
		case 0:			//they guessed number
			printf("You guessed the right number!\n");
			break;
		case 1:			//gess was to high
			printf("You guessed to high. Try again:\n");
			break;
		case -1:		//guess was to low
			printf("You guessed to low. Try again:\n");
			break;
	}
}