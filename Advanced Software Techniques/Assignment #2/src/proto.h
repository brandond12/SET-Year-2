/*
* FILE : proto.h
* PROJECT : PROG1165 - Assignment 2
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-08
* DESCRIPTION : The file cantains the function prototypes for the Assignment 2
*/


#define kmaxGuessNumber 100

int createRanNum(void);
int getAndValidateUserGuess(void);
void showUserGuessResult(int result);
int determineGuessResult(int userGuess, int randNum);