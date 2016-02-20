/*
* FILE : LinkList.h
* PROJECT : PROG1370 - mini1
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-03
* DESCRIPTION : This file contains the definitiond for the main
*/
#include <stdio.h>
#include <Windows.h>

#define knumBuckets 11
#define kmaxBucketIndet 10
#define kmaxStrLength 20
#define kmaxUserInputLen 83

typedef struct WordNodes
{
	char words[21];
	struct WordNodes *next;
}WordNodes;

unsigned long hash(char *str);