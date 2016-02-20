/*
* FILE : SETTree.cpp
* PROJECT : PROG1165 - Assignment 5
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-03-30
* DESCRIPTION : This program uses recursion to print a folder tree 
*	starting from the location specified in the command line argument
*/

#include <Windows.h>
#include <stdio.h>

#pragma warning(disable: 4996)

void recursiveSearch(char* fileName, int level);

int main(int argc, char *argv[]){
	char userInput[128] = "";
	if (argc != 2){
		printf("Error: Usage : SETTree <directory ...>\n");
	}
	strcpy(userInput, argv[1]);
	printf("%s\n", userInput);
	//format the given string to the needed pa
	if (userInput[strlen(userInput - 1)] != '\\'){
		strcat(userInput, "\\*");
	}
	else{
		strcat(userInput, "*");
	}
	//start the recersive search
	recursiveSearch(userInput, 1);
	return 0;
}


/*
*FUNCTION		:	recursiveSearch
*
*DESCRIPTION	:	This function prints the current file name and calls itself with the new file name
*
*PARAMETERS		:	char* fileName		:	file directory to search
*				:	int level			:	what level is this call (how far to indent)
*
*RETURNS		:	void
*
*/
void recursiveSearch(char* fileName, int level){
	WIN32_FIND_DATA fileData = { 0 };
	HANDLE fileHandle = NULL;
	char fullFileName[512] = "";
	int levelTabs = level;

	fileHandle = FindFirstFile(fileName, &fileData);
	do{
		if (fileHandle != INVALID_HANDLE_VALUE){
			//File found
			if (strcmp(fileData.cFileName, ".") != 0 && strcmp(fileData.cFileName, "..") != 0){
				levelTabs = level;
				while (levelTabs != 0){//print the indent
					printf("  ");
					levelTabs--;
				}
				printf("%s\n", fileData.cFileName);
				//build file to search
				strcpy(fullFileName, fileName);
				fullFileName[strlen(fullFileName) - 1] = '\0';
				strcat(fullFileName, fileData.cFileName);
				strcat(fullFileName, "\\*");
				//check for another layer
				recursiveSearch(fullFileName, level + 1);
			}
		}
	}while (FindNextFile(fileHandle, &fileData) != NULL);
}