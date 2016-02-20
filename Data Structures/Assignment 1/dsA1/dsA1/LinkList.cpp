/*
* FILE : LinkList.cpp
* PROJECT : PROG1370 - Assignment 1
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-1-28
* DESCRIPTION : This file contains all functions for link lists
*/
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "LinkList.h"

/*d
*FUNCTION		:	addRecord
*
*DESCRIPTION	:	This function gets the songInfo head pointer and the newBlock pointer. It adds the newBlock to the link list sorted by title then artist
*
*PARAMETERS		:	songInfo *head				:	the head of the link list
*					songInfo *newBlock			:	the record to be added to the sorted link list
*
*RETURNS		:	songInfo *head				:	the head of the link list
*
*/
songInfo *addRecord(songInfo *head, songInfo *newBlock){
	songInfo *ptr = NULL;
	songInfo *last = head;
	int flag = 1;
	int strcmpResult = 0;

	if (head == NULL){//No table yet
		head = newBlock;
	}
	else{//Find location needed in table                                                                                                                                                                           
		ptr = head;
		last = head;

		while (flag == 1){
			strcmpResult = stricmp(ptr->title, newBlock->title);
			if (strcmpResult == 0){//Strings equal
				//Compare artists
				while (ptr != NULL && strcmp(ptr->title, newBlock->title) == 0){
					if (strcmp(ptr->artist, newBlock->artist) < 0){
						last = ptr;
						ptr = ptr->next;
					}
					else{
						break;
					}
				}
				flag = 0;
			}

			else if (strcmpResult > 0){//This is its alpha location, unless there is an equal name
				if (ptr->next != NULL && stricmp(ptr->next->title, newBlock->title) == 0){
					last = ptr;
					ptr = ptr->next;
				}
				else{
					flag = 0;
				}
			}

			else if (strcmpResult < 0){//Saved title less than new title
				last = ptr;
				ptr = ptr->next;
				if (ptr == NULL){//End of list
					flag = 0;
				}
			}

		}//End of while
		if (ptr != NULL){
			newBlock->next = ptr;
		}
		//Change pointer to next of last record
		if (ptr != head){
			last->next = newBlock;
		}
		else{
			head = newBlock;
		}
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
	int counter = 1;
	ptr = head;

	//While pointing to data
	while (ptr != NULL){
		while (counter <= 20 && ptr != NULL){
			printf("Artist: %-20s\t Title: %s\n", ptr->artist, ptr->title);
			//Set pointer to next record in list
			ptr = ptr->next;
			counter++;
		}
		if (ptr != NULL){
			printf("Press any key to continue\n");
			_getch();
			counter = 1;
		}
	}
}


/*
*FUNCTION		:	freeMemory
*
*DESCRIPTION	:	This function frees all memory allocated
*
*PARAMETERS		:	songInfo *head				:	the head of the link list
*
*RETURNS		:	void
*
*/
void freeMemory(songInfo *head){
	songInfo *curr = NULL;
	songInfo *ptr = head;
	//While pointing to data
	while (ptr != NULL){
		//Save current record pointer
		curr = ptr;
		//Save pointer to next item in link list
		ptr = ptr->next;
		//Free memory for current record
		free(curr->artist);
		free(curr->title);
		free(curr);
	}
}