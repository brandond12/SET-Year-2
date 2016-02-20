/*
* FILE : LinkList.h
* PROJECT : PROG1370 - Assignment 1
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-1-28
* DESCRIPTION : This file contains all function deffinitions for linklist programs
*/

#include "dsA1.h"

void freeMemory(songInfo *head);
songInfo *addRecord(songInfo *head, songInfo *newBlock);
void output(songInfo *head);
