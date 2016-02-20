/*
* FILE : LinkList.cpp
* PROJECT : PROG1370 - mini2
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-03
* DESCRIPTION : This file contains the functions needed to add a node to a sorted link list, search a link listand free the memory of link lists in of a array of buckets
*/

#include "LinkList.h"

/*
*FUNCTION		:	addRecord
*
*DESCRIPTION	:	This function gets the songInfo head pointer and the newBlock pointer. It adds the newBlock to the link list sorted by title then artist
*
*PARAMETERS		:	WordNodes *head				:	the head of the link list
*					WordNodes *newBlock			:	the record to be added to the sorted link list
*
*RETURNS		:	WordNodes *head				:	the head of the link list
*
*/
WordNodes *addRecord(WordNodes *head, WordNodes *newBlock){
	WordNodes *ptr = NULL;
	WordNodes *last = head;
	int flag = 1;
	int strcmpResult = 0;

	if (head == NULL){//No table yet
		head = newBlock;
	}
	else{//Find location needed in table                                                                                                                                                                           
		ptr = head;
		last = head;

		while (flag == 1){
			strcmpResult = stricmp(ptr->words, newBlock->words);

			if (strcmpResult >= 0){ // this is its location
				flag = 0;
			}

			else if (strcmpResult < 0){//Saved title less than new title
				last = ptr;
				ptr = ptr->next;
				if (ptr == NULL){//End of list
					flag = 0;
				}
			}

		}//End of while

		if (head == NULL){//if end of string
			newBlock->next = NULL;
		}
		
		if (ptr != head){//if possition to add is not head
			last->next = newBlock;
			newBlock->next = ptr;
		}
		else{//if possition is head, replace head
			newBlock->next = head;
			head = newBlock;
		}
	}
	return head;
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
void searchLinkList(WordNodes *head, const char* str){
	int returnVal = 0;
	int compareValue = 0;
	WordNodes *ptr = head;

	while (true){//loop while looking for users word
		if (ptr == NULL){//if at end of list
			printf("Not there!\n\n");
			break;//break to not do a compare to somthing that doesnt exist
		}
		compareValue = strcmp(ptr->words, str);//compare current list word to users search word
		if (compareValue == 0){//this is the word looking for
			printf("Success!\n\n");
			break;
		}
		else if (compareValue < 0){//not word keep looking
			printf("Comparing to %s\n", ptr->words);
			ptr = ptr->next;
		}
		else{//word not there
			printf("Not there!\n\n");
			break;
		}
	}
}


/*
*FUNCTION		:	freeMemory
*
*DESCRIPTION	:	This function frees all memory allocated
*
*PARAMETERS		:	WordNodes* list[]				:	array of pointers to the buckets of link lists
*
*RETURNS		:	void
*
*/
void freeMemory(WordNodes* list[]){
	WordNodes *curr = NULL;
	WordNodes *ptr = NULL;
	int counter = 0;

	while (counter <= kmaxBucketIndet){
		ptr = list[counter];
		//While pointing to data
		while (ptr != NULL){
			//Save current record pointer
			curr = ptr;
			//Save pointer to next item in link list
			ptr = ptr->next;
			//Free memory for current record
			free(curr);
		}
		counter++;//go to next bucket
	}
}