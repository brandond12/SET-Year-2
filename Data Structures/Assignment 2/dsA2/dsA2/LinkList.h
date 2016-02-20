/*
* FILE : LinkList.h
* PROJECT : PROG1370 - Assignment 1
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-1-28
* DESCRIPTION : This file contains all function deffinitions for linklist programs
*/

#pragma warning(disable: 4996)

#define kNumBuckets 127

//define struct songinfo
typedef struct songInfo
{
	char* artist;
	char* title;
	struct songInfo *next;
}songinfo;

void freeMemory(songInfo *head, songInfo *buckets[]);
songInfo *addRecord(songInfo *head, songInfo *newBlock);
bool searchLinkList(songInfo *head, const char* str, int *compareCount);
