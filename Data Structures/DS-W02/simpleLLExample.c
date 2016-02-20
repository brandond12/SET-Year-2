/*
 * Filename: simpleLLExample.c
 * Author:   Carlo Sgro
 * Date:     January 29/06
 * Description: This implements an example of a simple singly-linked list.  
 *              Functionality provided is: enter item, delete all items, and list all items.
 */

#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>

#pragma warning(disable: 4996)



// define linked list structure
 

typedef struct phoneInfo {
	char name[50];
	char address[50];
	char phoneNumber[10];
	struct phoneInfo *next;
} phoneInfo;





// prototypes
phoneInfo *enterNewInfo(phoneInfo *newHead);
void listInfo(phoneInfo *head);
phoneInfo *deleteAllInfo(phoneInfo *head);
void clearCRLF(char *str);



// functions


int main (void)
{
phoneInfo *head = NULL;
char key = 0;
#define kEnter    '1'
#define kList     '2'
#define kDelete   '3'
#define kQuit     '4'
#define kLoopForever   1 

	// loop getting user input until they indicate that they want to quit
	while( kLoopForever ) 
	{
		// display menu and get input

		printf("\n\nMenu\n\n");
		printf("%c . . . Enter new info\n", kEnter);
		printf("%c . . . List all info\n", kList);
		printf("%c . . . Delete all info\n", kDelete);
		printf("%c . . . Quit\n", kQuit);
		printf("Enter your choice . . .");

		key = getch();

		// quit on entry of kQuit ('4')
		if( key == kQuit )
		{
			break;
		}

		switch( key ) 
		{
		case kEnter:
			head = enterNewInfo(head);
			break;

		case kList:
			listInfo(head);
			break;

		case kDelete:
			head = deleteAllInfo(head);
			break;

		default:
			printf("\nInvalid choice\n");
			break;
		}	/* end switch */
	}	/* end while */

	return 0;
}	/* end main() */



/*
 * Function: phoneInfo * enterNewInfo(phoneInfo *newHead)
 *
 * Description:	This function will allocate a new entry in the
 * 		linked list, allow data entry, and append this
 * 		entry to the end of the chain.
 *
 * Parameter: phoneInfo *head: start of the linked list
 * Return Value: new value of the head parameter pointing to the start of the linked list
 */

phoneInfo *enterNewInfo(phoneInfo *newHead)
{
	phoneInfo *newBlock = NULL;
	phoneInfo *ptr = NULL;

	// allocate a block of memory for new record
	newBlock = (phoneInfo *) malloc(sizeof (phoneInfo));
	if( newBlock == NULL ) 
	{
		// we've run out of memory
		printf("Error! No more memory!\n");
		// we can't continue with this entry 
		return newHead;
	}	/* endif */
	
	// obtain information for new record, getting rid of '\n' at end of string, if present
	printf("\nEnter name: ");
	fgets(newBlock->name, sizeof (newBlock->name), stdin);
	clearCRLF(newBlock->name);
	printf("Enter address: ");
	fgets(newBlock->address, sizeof (newBlock->address), stdin);
	clearCRLF(newBlock->address);
	printf("Enter phone number (xxx-xxxx): ");
	fgets(newBlock->phoneNumber, sizeof (newBlock->phoneNumber), stdin);
	clearCRLF(newBlock->phoneNumber);
	newBlock->next = NULL;


	// link this record to the current list
	
	if( newHead == NULL ) 
	{
		// empty list, so set first pointer
		newHead = newBlock;
	}
	else
	{
		// non empty chain, so use newHead ptr to follow links until we reach end of
		// list, where the next field is NULL
	 
		ptr = newHead;
		while( ptr->next != NULL ) 
		{
			ptr = ptr->next;
		}	/* end while */

		// we are at end since ptr->next is NULL

		// append the new record into ptr->next
		ptr->next = newBlock;
	}	/* endif */

	// at this point, the new record linked!
	

	// let's return the new head pointer
	return newHead;

}	/* end enterNewInfo() */




/*
 * Function: void listInfo(phoneInfo *head)
 *
 * Description: This function will print all information in the list to the screen.
 *
 * Parameter: phoneInfo *head: start of the linked list
 * Return Value: none
 */

void listInfo(phoneInfo *head)
{
	phoneInfo *ptr = head;

	// follow the chain until the pointer is null
	

	while( ptr != NULL ) 
	{
		printf("\n");
		printf("Name:         %s\n", ptr->name);
		printf("Address:      %s\n", ptr->address);
		printf("Phone Number: %s\n\n",	ptr->phoneNumber);
		ptr = ptr->next;
	}	/* end while */

	printf("\n\n<End of data>\n");
}	/* end listInfo() */




/*
 * Function: phoneInfo * deleteAllInfo(phoneInfo *head)
 *
 * Description: This function will free all allocated memory in the linked list.
 *
 * Parameter: phoneInfo *head: start of the linked list
 * Return Value: NULL indicating a newly-empty list
 */

phoneInfo *deleteAllInfo(phoneInfo *head)
{
	phoneInfo *curr = NULL;
	phoneInfo *ptr = head;

	// follow the chain until the pointer is null

	while( ptr != NULL ) 
	{
		// first, save ptr to next, then delete current
		curr = ptr;
		ptr = ptr->next;
		free(curr);
	}	/* end while */

	// before we leave, reset the head pointer to NULL since
	// there isn't anything left in the list to work with
	return NULL;
}	/* end deleteAllInfo() */





/*
* Function: void clearCRLF(char *str)
*
* Description: This function will get rid of a \n at the end of a string.
*			   If there isn't one, it doesn't change the string.
*
* Parameter: char *str: start of the string
* Return Value: nothing
*/

void clearCRLF(char *str)
{
	char *whereIsCRLF = strchr(str, '\n');
	if( whereIsCRLF != NULL )	
	{
		*whereIsCRLF = '\0';
	}
}
