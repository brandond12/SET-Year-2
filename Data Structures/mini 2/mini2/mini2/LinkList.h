/*
* FILE : LinkList.h
* PROJECT : PROG1370 - mini1
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-03
* DESCRIPTION : This file contains all function deffinitions for linklist functions
*/

#include "mini2.h"

WordNodes *addRecord(WordNodes *head, WordNodes *newBlock);
void searchLinkList(WordNodes *head, const char* str);
void freeMemory(WordNodes* list[]);