/*
* FILE : dsA1.cpp
* PROJECT : PROG1370 - Assignment 1
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-1-28
* DESCRIPTION : This program accepts user directory through command line. 
* All .mp3 file are taken and song name and artist are added to a sorted link list. The output is placed in 
* alphabetical order. 
*/
#include <stdio.h>
#include <Windows.h>

#include "LinkList.h"

int main(int argc, char *argv[]){
	//Main variables
	int argCounter = 1;		 //What command argument is selected
	char userInput[127] = "";//Copy of selected command argument conditiond for file search

	//File I/O variables
	WIN32_FIND_DATA fileData = { 0 };
	HANDLE fileHandle = NULL; 

	//LinkList Variables
	songInfo *head = NULL;

	if (argc <= 1){
		//Error no arguments
		printf("Error: Usage : dsA1 <directory ...>\n");
	}
	else{
		while (argv[argCounter] != NULL){//While there is an argument
			//Run program
		
			strcpy(userInput, argv[argCounter]);
			conditionInput(userInput);

			/*********File I/O************/
			fileHandle = FindFirstFile(userInput, &fileData);
			if (fileHandle == INVALID_HANDLE_VALUE){
				//Error file not found
				printf("Error: No .mp3 Files Found In Directory: %s\n", argv[argCounter]);
			}
			else{//File found
				do{	
					head = saveSongInfo(head, fileData.cFileName);
				} while (FindNextFile(fileHandle, &fileData) != NULL);//While files in directory
			}
			FindClose(fileHandle);
			argCounter++;//Move to next argument
		}
		output(head);
	}
	freeMemory(head);
	return 0;
}


/*
*FUNCTION		:	saveSongInfo
*
*DESCRIPTION	:	This function gets the song info from the parameter fileName, saves it in a struct and adds it to the link list
*
*PARAMETERS		:	songInfo *head				:	the head of the link list
					char *fileName				:	string of the fileName to save
*
*RETURNS		:	songInfo *head				:	the head of the link list
*
*/
songInfo *saveSongInfo(songInfo *head, char *fileName){
	songInfo *newBlock = NULL;
	int endArtist = 0;
	int endTitle = 0;
	char* pAllocatedArtistMem = NULL;
	char* pAllocatedTitleMem = NULL;
	char* pArtistLocal = NULL;
	int memSize = 0;

	while (true){//Used to break out of code if hits an error

		// Allocate a block of memory for new record
		newBlock = (songInfo *)malloc(sizeof(songInfo));
		if (newBlock == NULL)
		{
			// We've run out of memory
			printf("Error! No more memory!\n");
		}
		else{
			//Pars Artist data
			pArtistLocal = strchr(fileName, '-');
			if (pArtistLocal == NULL){
				break;
			}
			else{
				endArtist = pArtistLocal - fileName;
			}
			//Pars Title data
			pArtistLocal = strstr(fileName, ".mp3");
			if (pArtistLocal == NULL){
				break;
			}
			else{
				endTitle = pArtistLocal - fileName;
			}
			//Allocate Artist memory
			memSize = sizeof(char)*endArtist + 1;
			pAllocatedArtistMem = (char*)malloc(memSize);
			if (pAllocatedArtistMem == NULL){
				break;
			}
			else{
				newBlock->artist = pAllocatedArtistMem;

				//Allocate Title memory
				memSize = sizeof(char)*(endTitle - endArtist);
				pAllocatedTitleMem = (char*)malloc(memSize);
				if (pAllocatedTitleMem == NULL){
					free(pAllocatedArtistMem);
					break;
				}
				else{
					newBlock->title = pAllocatedTitleMem;
				}
			}

			//Save Title and Artist
			strncpy(newBlock->artist, fileName, endArtist);
			strncpy(newBlock->title, &fileName[endArtist + 1], ((endTitle - endArtist) - 1));

			//All null terminator to the end of the strings
			*((newBlock->artist) + endArtist) = '\0';
			*((newBlock->title) + (endTitle - endArtist - 1)) = '\0';

			newBlock->next = NULL;

			head = addRecord(head, newBlock);//Adds newBlock to the sorted link list
		}
		break;//Default leave the loop
	}
	return head;
}


/*
*FUNCTION		:	conditionInput
*
*DESCRIPTION	:	This function takes the user input and conditions it to be used by FindFirstFile to fine all .mp3s in directory
*
*PARAMETERS		:	char *fileDirectory				:	input to give the users directory
*				:	char *userInput					:	output to return the formatted user input string
*
*RETURNS		:	void
*
*/
void conditionInput(char *userInput){
	int inputLength = 0;	//Length of selected cmd argument

	inputLength = strlen(userInput);

	if (userInput[inputLength - 1] == '\\'){
		strcat(userInput, "*.mp3");//If slash at end add *" to end
	}
	else{
		strcat(userInput, "\\*.mp3");//If no slash at end add \*"
	}
}
