/*
* FILE : Main.h
* PROJECT : PROG1370 - MINI 1
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-1-13
* DESCRIPTION : This header includes all includes, struct definitions and function prototypes.
*/

#include <stdio.h>
#include <Windows.h>

#pragma warning(disable: 4996)

//define struct songinfo
typedef struct songInfo
{
	char* artist;
	char* title;
	struct songInfo *next;
}songinfo;


songInfo *getSongInfo(songInfo *head);
void output(songInfo *head);
void freeMemory(songInfo *head);