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

/*
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
*FUNCTION		:	freeMemory
*
*DESCRIPTION	:	This function frees all memory allocated
*
*PARAMETERS		:	songInfo *head				:	the head of the link list
*				:	songInfo *buckets[]			:	the table of buckets
*
*RETURNS		:	void
*
*/
void freeMemory(songInfo *head, songInfo *buckets[]){
	songInfo *curr = NULL;
	songInfo *ptr = head;
	int x = 0;
	//While pointing to data
	while (x <= kNumBuckets){
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
		ptr = buckets[x];
		x++;
	}
}


/*
*FUNCTION		:	searchLinkList
*
*DESCRIPTION	:	This function searches a link list of WordNodes for a selected string
*
*PARAMETERS		:	WordNodes *head				:	head pointer to the link list to search
*				:	const char* str				:	string to be searched for
*
*RETURNS		:	void
*
*/
bool searchLinkList(songInfo *head, const char* str, int *compareCount){
	int compareValue = 0;
	bool returnVal = true;
	songInfo *ptr = head;
	*compareCount = 0;

	while (true){//loop while looking for users word
		if (ptr == NULL){//if at end of list
			returnVal = false;
			break;//break to not do a compare to somthing that doesnt exist
		}
		compareValue = strcmp(ptr->title, str);//compare current list word to users search word
		*compareCount = *(compareCount) + 1;
		if (compareValue == 0){//this is the word looking for
			break;
		}
		else if (compareValue < 0){//not word keep looking
			ptr = ptr->next;
		}
		else{//word not there
			returnVal = false;
			break;
		}
	}
	return returnVal;
}