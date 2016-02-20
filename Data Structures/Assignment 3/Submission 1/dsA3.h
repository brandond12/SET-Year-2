/*
* FILE : dsA3.h
* PROJECT : PROG1370 - Assignment 3
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-03-30
* DESCRIPTION : This header contains the struct deffinition for the song info and function deffinitions
*/



#include <list>
#include <stdio.h>
#include <Windows.h>

using namespace std;

#pragma warning(disable: 4996)

#define kNumSongs 3
#define kNoError 0
#define kError 1
#define kStringLen 512

//define struct songinfo
typedef struct songInfo
{
	char* artist;
	char* title;
}songinfo;


list<songInfo> saveSongInfo(list<songInfo> songs, char *fileName);
void conditionInput(char *userInput);
bool sortingFunction(const songInfo first, const songInfo second);
void output(list<songInfo> songs);
