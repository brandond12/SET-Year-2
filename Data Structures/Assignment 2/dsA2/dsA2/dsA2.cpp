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

#include "dsA2.h"

int main(int argc, char *argv[]){
	//Main variables
	int argCounter = 1;		 //What command argument is selected
	int currentLLComps = 0;
	int currentHashComps = 0;
	int totalLLComps = 0;
	int totalHashComps = 0;
	int totalSearches = 0;
	char userInput[127] = "";//Copy of selected command argument conditiond for file search
	bool found = false;


	//File I/O variables
	WIN32_FIND_DATA fileData = { 0 };
	HANDLE fileHandle = NULL; 
	

	//LinkList Variables
	songInfo *head = NULL;
	int bucketSel = 0;
	songInfo *buckets[127] = { NULL };
	songInfo *newBlock = NULL;

	if (argc <= 1){
		//Error no arguments
		printf("Error: Usage : dsA1 <directory ...>\n");
	}
	else{
		while (argv[argCounter] != NULL){//While there is an argument
		
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
					newBlock = createNewBlock(fileData.cFileName);//create the block to be saved in link list
					head = addRecord(head, newBlock);//Adds newBlock to the sorted link list
					newBlock = createNewBlock(fileData.cFileName);//create the block to be saved in hash bucket list
					bucketSel = (int)hash(newBlock->title);//get what bucket it goes it
					buckets[bucketSel] = addRecord(buckets[bucketSel], newBlock);//add the block to the sorded link list in that bucket
				} while (FindNextFile(fileHandle, &fileData) != NULL);//While files in directory
			}
			FindClose(fileHandle);
			argCounter++;//Move to next argument
		}

		//start user input for search
		printf("please enter the title to search for:\n");
		fgets(userInput, 126, stdin);
		while (true){
			if (*userInput == '.' && strlen(userInput) == 2){//user entered only "." (plus \n)
				break;
			}
			//remove the /n
			if (strcmp(userInput+(strlen(userInput)-2),"\n")){
				*(userInput + (strlen(userInput)-1)) = '\0';
			}
			/*search for the input*/
			found = searchLinkList(head, userInput, &currentLLComps);
			bucketSel = hash(userInput);//get hash value
			found = searchLinkList(buckets[bucketSel], userInput, &currentHashComps);
			totalHashComps += currentHashComps;
			totalLLComps += currentLLComps;
			totalSearches++;

			/*output*/
			if (found == true){
				printf("%s was found in the link list in %d comparisons\n", userInput, currentLLComps);
				printf("%s was found in the hash table bucket in %d comparisons\n\n", userInput, currentHashComps);
				printf("please enter another title to search for:\n");
			}
			else{
				printf("%s was Not found in link list in %d comparisons\n", userInput, currentLLComps);
				printf("%s was Not found in hash table bucket in %d comparisons\n\n", userInput, currentHashComps);
				printf("please enter another title to search for:\n");
			}
			fgets(userInput, 126, stdin);//get new title to search
		}
		printf("Total Number Searches: %d\nTotal number comarisons link list: %d\nTotal number comarisons hash table bucket: %d\n", totalSearches, totalLLComps, totalHashComps);
	}
	freeMemory(head, buckets);
	return 0;
}


/*
*FUNCTION		:	createNewBlock
*
*DESCRIPTION	:	This function takes the file name and creates a stuct to add to a link list
*
*PARAMETERS		:	char *fileName				:	songe file nale to be saved
*
*RETURNS		:	songInfo*					:	pointer to the new block made
*
*/
songInfo *createNewBlock(char *fileName){
	songInfo *newBlock = NULL;
	int endArtist = 0;
	int endTitle = 0;
	char* pAllocatedArtistMem = NULL;
	char* pAllocatedTitleMem = NULL;
	char* pArtistLocal = NULL;
	int memSize = 0;
	bool error = false;

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
			error = true;
		}
		else{
			endArtist = pArtistLocal - fileName;
		}
		//Pars Title data
		pArtistLocal = strstr(fileName, ".mp3");
		if (pArtistLocal == NULL || error == true){
			error = true;
		}
		else{
			endTitle = pArtistLocal - fileName;
		}
		//Allocate Artist memory
		memSize = sizeof(char)*endArtist + 1;
		pAllocatedArtistMem = (char*)malloc(memSize);
		if (pAllocatedArtistMem == NULL || error == true){
			error = true;
		}
		else{
			newBlock->artist = pAllocatedArtistMem;

			//Allocate Title memory
			memSize = sizeof(char)*(endTitle - endArtist);
			pAllocatedTitleMem = (char*)malloc(memSize);
			if (pAllocatedTitleMem == NULL || error == true){
				free(pAllocatedArtistMem);
				error = true;
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
	}
	return newBlock;
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
