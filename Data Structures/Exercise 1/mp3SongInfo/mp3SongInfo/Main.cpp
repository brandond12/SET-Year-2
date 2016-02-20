/*
* FILE : Main.cpp
* PROJECT : PROG1370 - MINI 1
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-1-13
* DESCRIPTION : This program saves song info provided by the user using structs and link lists
*/

#include "Main.h"

#define kNumSongs 3
#define kNoError 0
#define kError 1
#define kStringLen 81


int main(void){
	int counter = 0;
	int errorLevel = kNoError;
	songInfo *head = NULL;

	while (counter < kNumSongs){
		head = getSongInfo(head);
		if (head->artist == NULL){
			//error free memory and quit
			freeMemory(head);
			errorLevel = kError;
			break;
		}
		counter++;
	}

	if (errorLevel == kNoError){
		output(head);
		freeMemory(head);
	}

	return errorLevel;
}


/*
*FUNCTION		:	getSongInfo
*
*DESCRIPTION	:	This function gets the song info from the user, saves it in a struct and adds it to the link list
*
*PARAMETERS		:	songInfo *head				:	the head of the link list
*
*RETURNS		:	songInfo *head				:	the head of the link list
*
*/
songInfo *getSongInfo(songInfo *head){
	songInfo *newBlock = NULL;
	songInfo *ptr = NULL;
	char userInput[kStringLen] = "";
	int charCounter = 0;
	int charCounter2 = 0;
	char* pAllocatedMem = NULL;
	int memSize = 0;
	int errorLevel = kNoError;

	// allocate a block of memory for new record
	newBlock = (songInfo *)malloc(sizeof(songInfo));
	if (newBlock == NULL)
	{
		// we've run out of memory
		printf("Error! No more memory!\n");
	}
	else{
		//get user input
		fgets(userInput, kStringLen-1, stdin);

		//pars Artist data
		while (userInput[charCounter] != '-'){
			charCounter++;
		}

		//Alocate Artist memory
		memSize = sizeof(char)*charCounter + 1;
		pAllocatedMem = (char*)malloc(memSize);
		if (pAllocatedMem == NULL){
			errorLevel = kError;
		}
		else{
			newBlock->artist = pAllocatedMem;
		}

		//pars Title data
		charCounter2 = charCounter;
		while (userInput[charCounter2] != '.'){
			charCounter2++;
		}

		//Alocate Title memory
		memSize = sizeof(char)*(charCounter2 - charCounter);
		pAllocatedMem = (char*)malloc(memSize);
		if (pAllocatedMem == NULL){
			errorLevel = kError;
		}
		else{
			newBlock->title = pAllocatedMem;
		}

		//save Title and Artist
		strncpy(newBlock->artist, userInput, charCounter);
		strncpy(newBlock->title, &userInput[charCounter + 1], ((charCounter2 - charCounter) - 1));

		//All null terminator to the end of the strings
		*((newBlock->artist) + charCounter) = '\0';
		*((newBlock->title) + (charCounter2 - charCounter - 1)) = '\0';

		if (head == NULL){//no table yet
			head = newBlock;
		}
		else{//find end of table
			ptr = head;
			while (ptr->next != NULL){
				ptr = ptr->next;
			}
			ptr->next = newBlock;
		}

		newBlock->next = NULL;
	}
	return head;
}


/*
*FUNCTION		:	output
*
*DESCRIPTION	:	This function outputs all data that is in the link list
*
*PARAMETERS		:	songInfo *head				:	the head of the link list
*
*RETURNS		:	void
*
*/
void output(songInfo *head){
	songInfo *ptr = NULL;
	ptr = head;
	//clear screen
	system("cls");
	//while pointing to data
	while (ptr != NULL){
		printf("Artist: %-40s\t Title: %s\n", ptr->artist, ptr->title);
		//set pointer to next record in list
		ptr = ptr->next;
	}
}


/*
*FUNCTION		:	freeMemory
*
*DESCRIPTION	:	This function frees all memory allo
*
*PARAMETERS		:	songInfo *head				:	the head of the link list
*
*RETURNS		:	void
*
*/
void freeMemory(songInfo *head){
	songInfo *curr = NULL;
	songInfo *ptr = head;
	//while pointing to data
	while (ptr != NULL){
		//save current record pointer
		curr = ptr;
		//save pointer to next item in link list
		ptr = ptr->next;
		//free memory for current record
		free(curr->artist);
		free(curr->title);
		free(curr);
	}
}