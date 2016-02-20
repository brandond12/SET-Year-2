/*
* FILE : dsA3.cpp
* PROJECT : PROG1370 - Assignment 3
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-03-30
* DESCRIPTION : This program accepts user directory through command line. 
* All .mp3 file are taken and song name and artist are added to a stl list. The output is placed in 
* alphabetical order and printed
*/

#include "dsA3.h"

void freeMemory(list<songInfo> songs);

int main(int argc, char *argv[]){
	//Main variables
	int argCounter = 1;		 //What command argument is selected
	char userInput[kStringLen] = "";//Copy of selected command argument conditiond for file search
	list<songInfo> songs;

	//File I/O variables
	WIN32_FIND_DATA fileData = { 0 };
	HANDLE fileHandle = NULL; 

	if (argc <= 1){
		//Error no arguments
		printf("Error: Usage : dsA3 <directory ...>\n");
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
					songs = saveSongInfo(songs, fileData.cFileName);
				} while (FindNextFile(fileHandle, &fileData) != NULL);//While files in directory
			}
			FindClose(fileHandle);
			argCounter++;//Move to next argument
		}
		songs.sort(sortingFunction);
		output(songs);
	}
	freeMemory(songs);
	return 0;
}


/*
*FUNCTION		:	saveSongInfo
*
*DESCRIPTION	:	This function gets the song info from the parameter fileName, saves it in a struct and adds it to the stl list
*
*PARAMETERS		:	list<songInfo> songs		:	the stl list to save the song to
					char *fileName				:	string of the fileName to save
*
*RETURNS		:	list<songInfo>				:	the updated list
*
*/
list<songInfo> saveSongInfo(list<songInfo> songs, char *fileName){
	songInfo newBlock;
	int endArtist = 0;
	int endTitle = 0;
	char* pAllocatedArtistMem = NULL;
	char* pAllocatedTitleMem = NULL;
	char* pArtistLocal = NULL;
	int memSize = 0;

	// Allocate a block of memory for new record
		//Pars Artist data
		pArtistLocal = strchr(fileName, '-');
		if (pArtistLocal == NULL){
		}
		else{
			endArtist = pArtistLocal - fileName;

			//Pars Title data
			pArtistLocal = strstr(fileName, ".mp3");
			if (pArtistLocal == NULL){
			}
			else{
				endTitle = pArtistLocal - fileName;

				//Allocate Artist memory
				memSize = sizeof(char)*endArtist + 1;
				pAllocatedArtistMem = (char*)malloc(memSize);
				if (pAllocatedArtistMem == NULL){
				}
				else{
					newBlock.artist = pAllocatedArtistMem;

					//Allocate Title memory
					memSize = sizeof(char)*(endTitle - endArtist);
					pAllocatedTitleMem = (char*)malloc(memSize);
					if (pAllocatedTitleMem == NULL){
						free(pAllocatedArtistMem);
					}
					else{
						newBlock.title = pAllocatedTitleMem;

						//Save Title and Artist
						strncpy(newBlock.artist, fileName, endArtist);
						strncpy(newBlock.title, &fileName[endArtist + 1], ((endTitle - endArtist) - 1));

						//All null terminator to the end of the strings
						*((newBlock.artist) + endArtist) = '\0';
						*((newBlock.title) + (endTitle - endArtist - 1)) = '\0';

						songs.push_back(newBlock);
					}
				}
			}
		}
	//}
	return songs;
}


/*
*FUNCTION		:	conditionInput
*
*DESCRIPTION	:	This function takes the user input and conditions it to be used by FindFirstFile to fine all .mp3s in directory
*
*PARAMETERS		:	char *userInput					:	string to prepare for searching for songs
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

/*
*FUNCTION		:	sortingFunction
*
*DESCRIPTION	:	This function takes 2 songInfo structs and determines which one is greater
*
*PARAMETERS		:	const songInfo first		:	first songInfo to compare
*				:	const songInfo second		:	second songInfo to compare
*
*RETURNS		:	bool						:	true if first is less than second
*
*/
bool sortingFunction(const songInfo first, const songInfo second){
	bool returnValue = false;
	if (stricmp(first.title, second.title) < 0){
		returnValue = true;
	}
	else if(stricmp(first.title, second.title) == 0){
		if(stricmp(first.artist, second.artist) < 0){
			returnValue = true;
		}
	}
	return returnValue;
}

/*
*FUNCTION		:	output
*
*DESCRIPTION	:	This function prints all valuse stored in the list
*
*PARAMETERS		:	list<songInfo> songs		:	list to print
*
*RETURNS		:	void
*
*/
void output(list<songInfo> songs){
	for (list<songInfo>::iterator iter = songs.begin(); iter != songs.end(); iter++){
		printf("%s - %s\n", iter->artist, iter->title);
	}
}

/*
*FUNCTION		:	freeMemory
*
*DESCRIPTION	:	This function frees all acllocated memory 
*
*PARAMETERS		:	list<songInfo> songs		:	list to free the memory from
*
*RETURNS		:	void
*
*/
void freeMemory(list<songInfo> songs){
	for (; songs.begin() != songs.end();){
		free(songs.front().artist);
		free(songs.front().title);
		songs.pop_front();
	}
}