/*
* FILE : dsA1.h
* PROJECT : PROG1370 - Assignment 1
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-1-28
* DESCRIPTION : This header contains the struct deffinition for the song info and function deffinitions
*/

#pragma warning(disable: 4996)

#define kNumSongs 3
#define kNoError 0
#define kError 1
#define kStringLen 127

//define struct songinfo
typedef struct songInfo
{
	char* artist;
	char* title;
	struct songInfo *next;
}songinfo;


songInfo *saveSongInfo(songInfo *head, char *fileName);
void conditionInput(char *userInput);
