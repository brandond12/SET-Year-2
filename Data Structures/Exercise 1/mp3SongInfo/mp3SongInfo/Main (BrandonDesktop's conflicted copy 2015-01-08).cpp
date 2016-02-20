/* */

#include <stdio.h>
#include <Windows.h>

#pragma warning(disable: 4996)

//define struct songinfo
struct songInfo
{
	char* artist;
	char* title;
};


int getSongInfo(struct songInfo *allSongs);
void output(struct songInfo allSongs[]);
int freeMemory(struct songInfo allSongs[]);

int main(void){
	int counter = 0;
	int errorLevel = 0;
	//define array of songinfo
	struct songInfo allSongs[10];

	while (counter <= 9){
		if (getSongInfo(&allSongs[counter]) != 0){
			//error free memory and quit
			freeMemory(allSongs);
			errorLevel = 1;
			break;
		}
		counter++;
	}

	if (errorLevel == 0){
		output(allSongs);
		freeMemory(allSongs);
	}

	return errorLevel;
}


//function take pointer to struct songinfo
int getSongInfo(struct songInfo *allSongs){
	char userInput[81] = "";
	int charCounter = 0;
	int charCounter2 = 0;
	char* pAllocatedMem = NULL;
	int memSize = 0;
	int errorLevel = 0;

	//get user input
	fgets(userInput, 80, stdin);

	//pars Artist data
	while (userInput[charCounter] != '-'){
		charCounter++;
	}

	//Alocate Artist memory
	memSize = sizeof(char)*charCounter + 1;
	pAllocatedMem = (char*)malloc(memSize);
	if (pAllocatedMem == NULL){
		errorLevel = 1;
	}
	else{
		allSongs->artist = pAllocatedMem;
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
		errorLevel = 1;
	}
	else{
		allSongs->title = pAllocatedMem;
	}

	//save Title and Artist
	strncpy(allSongs->artist, userInput, charCounter);
	strncpy(allSongs->title, &userInput[charCounter + 1], ((charCounter2 - charCounter) - 1));

	//All null terminator to the end of the strings
	*((allSongs->artist) + charCounter) = '\0';
	*((allSongs->title) + (charCounter2 - charCounter - 1)) = '\0';

	return errorLevel;
}


void output(struct songInfo allSongs[]){
	int counter = 0;
	while (counter <= 9){
		printf("Artist: %s\t Title: %s\n", allSongs[counter].artist, allSongs[counter].title);
		counter++;
	}
}


int freeMemory(struct songInfo allSongs[]){
	int counter = 0;
	int errorLevel = 0;
	while (counter <= 9){
		if (allSongs[counter].artist != NULL){
			free(allSongs[counter].artist);
		}
		else{
			break;
		}
		if (allSongs[counter].title != NULL){
			free(allSongs[counter].title);
		}
		else{
			break;
		}
		counter++;
	}
	return 0;
}