/*
* FILE : djb2.cpp
* PROJECT : PROG1370 - mini2
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-03
* DESCRIPTION : This file contains the function to create a hash value for a string
*/

#include "LinkList.h"

/*
*FUNCTION		:	hash
*
*DESCRIPTION	:	Credit to Dan Bernstein creating this function 
*					This function gets a hash value for a given string
*
*PARAMETERS		:	char *str				:	the string to get hash value
*
*RETURNS		:	unsigned long			:	hash value between 0 and 10
*
*/
unsigned long hash(char *str){
	unsigned long hash = 5381;
	int c = 0;
	while ((c = *str++) != '\0'){
		hash = ((hash << 5) + hash) + c;
	}
	return hash % kNumBuckets;
}