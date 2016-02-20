/*
* FILE : main.c
* PROJECT : PROG1165 - Assignment 2
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-08
* DESCRIPTION : The file cantains the main for the GuessGame program. 
*	This program selects a random number and the user tries to get that random number. 
*	After each guess the program will tell the user if they were to high or to low.
*/

#include "proto.h"
#include <stdio.h> //for debug

int main(void){
	int randNum = 0;
	int userGuess = 0;
	int guessResult = -1; 

	randNum = createRanNum();//get number to be guessed

	while(guessResult != 0){
		userGuess = getAndValidateUserGuess();		//get user guess
		if(userGuess != -1){				//if guess was valid
			guessResult = determineGuessResult(userGuess, randNum);//find guess result
			showUserGuessResult(guessResult);	//tell user their result
		}	
	}
	return 0;
}