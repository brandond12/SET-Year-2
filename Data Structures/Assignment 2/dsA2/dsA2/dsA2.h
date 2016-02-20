/*
* FILE : dsA2.h
* PROJECT : PROG1370 - Assignment 2
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-1-28
* DESCRIPTION : This header contains the struct deffinition for the song info and function deffinitions
*/

#include "LinkList.h"


#pragma warning(disable: 4996)

#define kNumSongs 3
#define kNoError 0
#define kError 1
#define kStringLen 127

unsigned long hash(char *str);

songInfo *createNewBlock(char *fileName);
void conditionInput(char *userInput);
